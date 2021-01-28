/**
 *  @file       rle.c
 *  @copyright  2021 Sierra Wireless Inc.
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Run-length encoding functions for GDB protocol.
 */
#include "rle.h"

#include "gdbstub.h"
#include "debug/debug.h"

#define ENCODING_MIN_THRESHOLD 3    ///< No encoding is done for runs of this size or smaller.
#define ENCODING_MAX_THRESHOLD 98   ///< Runs of longer than this size are split up.

/**
 * Format a normal RLE entry.  The provided value and repeats must result in valid encodings.
 */
static void format_rle
(
    char            *destination,   ///< [out] Buffer into which to write RLE entry.
    char             value,         ///< [in]  Character being encoded.
    unsigned long    repeats        ///< [in]  Number of repeats of the character being encoded.
)
{
    assert(destination != NULL);
    assert(repeats >= ENCODING_MIN_THRESHOLD);
    assert(repeats <= ENCODING_MAX_THRESHOLD);

    destination[0] = value;
    destination[1] = '*';
    destination[2] = (char) (repeats + '\x1D');

    assert(destination[2] >= ' ');
    assert(destination[2] != '#');
    assert(destination[2] != '$');
    assert(destination[2] <= '~');
}

/**
 * Encode a single run of characters.
 *
 * @return Number of characters written to the destination buffer.
 */
static unsigned long encode
(
    char            *destination,   ///< [out] Buffer into which to write the encoded run.
    const char      *source,        ///< [in]  Buffer to read unencoded data from.
    unsigned long    run            ///< [in]  Number of characters in the run.
)
{
    char          character;
    unsigned long count = 0;
    unsigned long i;

    while (run > 0)
    {
        character = source[0];

        if (run <= ENCODING_MIN_THRESHOLD)
        {
            // Runs of up to three characters are copied verbatim.
            for (i = 0; i < run; ++i)
            {
                destination[i] = character;
            }

            count += i;
            run = 0;
        }
        else if (run <= 6)
        {
            // Runs of between 4 and 6 characters are encoded using the normal RLE.
            format_rle(destination, character, run - 1);

            count += 3;
            run = 0;
        }
        else if (run == 7)
        {
            // Runs of 7 characters are encoded using the normal RLE for 6, plus an extra instance
            // of the character (due to # being reserved).
            format_rle(destination, character, 6 - 1);
            destination[3] = character;

            count += 4;
            run = 0;
        }
        else if (run == 8)
        {
            // Runs of 8 characters are encoded using the normal RLE for 6, plus two extra instances
            // of the character (due to $ being reserved).
            format_rle(destination, character, 6 - 1);
            destination[3] = character;
            destination[4] = character;

            count += 5;
            run = 0;
        }
        else if (run <= ENCODING_MAX_THRESHOLD)
        {
            // Runs of 9 to ENCODING_MAX_THRESHOLD characters are encoded using the normal RLE.
            format_rle(destination, character, run - 1);

            count += 3;
            run = 0;
        }
        else
        {
            // Runs of more than ENCODING_MAX_THRESHOLD characters are broken into smaller chunks.
            format_rle(destination, character, ENCODING_MAX_THRESHOLD - 1);

            destination += 3;
            count += 3;
            run -= ENCODING_MAX_THRESHOLD;
        }
    }

    return count;
}

/**
 * Run-length encode a buffer using the GDB protocol RLE scheme.
 */
void run_length_encode
(
    char            *buffer, ///< [in,out] Buffer of data to be encoded.  This data is encoded
                             ///<          in-place, as the result will always be the same length or
                             ///<          shorter.
    unsigned long   *size    ///< [in,out] As input, the length of the incoming data buffer.  As
                             ///<          output, the length of the encoded data now occupying the
                             ///<          buffer.
)
{
    unsigned long e = 0;
    unsigned long run;
    unsigned long s;
    unsigned long w = 0;

    assert(buffer != NULL);
    assert(size != NULL);

    for (;;)
    {
        // Break when we run off the end of the buffer.
        s = e;
        if (s >= *size)
        {
            break;
        }

        // Calculate run length.
        while (buffer[e] == buffer[s])
        {
            ++e;
            if (e >= *size)
            {
                break;
            }
        }
        run = e - s;

        // Encode the current run.
        w += encode(&buffer[w], &buffer[s], run);
        s += run;
    }

    *size = w;
}
