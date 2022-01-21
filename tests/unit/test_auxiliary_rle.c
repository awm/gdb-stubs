/**
 *  @file       test_auxiliary_rle.c
 *
 *  @remark
 *      SPDX-License-Identifier: MPL-2.0
 *
 *  @brief      Unit test cases for run length encoding implementation.
 */
#include "auxiliary/rle.c"

/*********************************** Begin Test Implementation ************************************/
#include "tap.h"

static const unsigned long TEST_COUNT = 93 + 216 + 8;

static void test_format_rle(void)
{
    char buffer[8];

#define TFE(c, n, e, d)                         \
    do                                          \
    {                                           \
        memset(buffer, 0, sizeof(buffer));      \
        format_rle(buffer, (c), (n));           \
        TAP_OK(strcmp(buffer, (e)) == 0, (d));  \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TFE('A', 3, "A* ", "3 repeats");
    TFE('A', 4, "A*!", "4 repeats");
    TFE('A', 5, "A*\"", "5 repeats");

    TFE('A', 9, "A*&", "9 repeats");
    TFE('A', 10, "A*'", "10 repeats");
    TFE('A', 11, "A*(", "11 repeats");
    TFE('A', 12, "A*)", "12 repeats");
    TFE('A', 13, "A**", "13 repeats");
    TFE('A', 14, "A*+", "14 repeats");
    TFE('A', 15, "A*,", "15 repeats");
    TFE('A', 16, "A*-", "16 repeats");
    TFE('A', 17, "A*.", "17 repeats");
    TFE('A', 18, "A*/", "18 repeats");
    TFE('A', 19, "A*0", "19 repeats");
    TFE('A', 20, "A*1", "20 repeats");
    TFE('A', 21, "A*2", "21 repeats");
    TFE('A', 22, "A*3", "22 repeats");
    TFE('A', 23, "A*4", "23 repeats");
    TFE('A', 24, "A*5", "24 repeats");
    TFE('A', 25, "A*6", "25 repeats");
    TFE('A', 26, "A*7", "26 repeats");
    TFE('A', 27, "A*8", "27 repeats");
    TFE('A', 28, "A*9", "28 repeats");
    TFE('A', 29, "A*:", "29 repeats");
    TFE('A', 30, "A*;", "30 repeats");
    TFE('A', 31, "A*<", "31 repeats");
    TFE('A', 32, "A*=", "32 repeats");
    TFE('A', 33, "A*>", "33 repeats");
    TFE('A', 34, "A*?", "34 repeats");
    TFE('A', 35, "A*@", "35 repeats");
    TFE('A', 36, "A*A", "36 repeats");
    TFE('A', 37, "A*B", "37 repeats");
    TFE('A', 38, "A*C", "38 repeats");
    TFE('A', 39, "A*D", "39 repeats");
    TFE('A', 40, "A*E", "40 repeats");
    TFE('A', 41, "A*F", "41 repeats");
    TFE('A', 42, "A*G", "42 repeats");
    TFE('A', 43, "A*H", "43 repeats");
    TFE('A', 44, "A*I", "44 repeats");
    TFE('A', 45, "A*J", "45 repeats");
    TFE('A', 46, "A*K", "46 repeats");
    TFE('A', 47, "A*L", "47 repeats");
    TFE('A', 48, "A*M", "48 repeats");
    TFE('A', 49, "A*N", "49 repeats");
    TFE('A', 50, "A*O", "50 repeats");
    TFE('A', 51, "A*P", "51 repeats");
    TFE('A', 52, "A*Q", "52 repeats");
    TFE('A', 53, "A*R", "53 repeats");
    TFE('A', 54, "A*S", "54 repeats");
    TFE('A', 55, "A*T", "55 repeats");
    TFE('A', 56, "A*U", "56 repeats");
    TFE('A', 57, "A*V", "57 repeats");
    TFE('A', 58, "A*W", "58 repeats");
    TFE('A', 59, "A*X", "59 repeats");
    TFE('A', 60, "A*Y", "60 repeats");
    TFE('A', 61, "A*Z", "61 repeats");
    TFE('A', 62, "A*[", "62 repeats");
    TFE('A', 63, "A*\\", "63 repeats");
    TFE('A', 64, "A*]", "64 repeats");
    TFE('A', 65, "A*^", "65 repeats");
    TFE('A', 66, "A*_", "66 repeats");
    TFE('A', 67, "A*`", "67 repeats");
    TFE('A', 68, "A*a", "68 repeats");
    TFE('A', 69, "A*b", "69 repeats");
    TFE('A', 70, "A*c", "70 repeats");
    TFE('A', 71, "A*d", "71 repeats");
    TFE('A', 72, "A*e", "72 repeats");
    TFE('A', 73, "A*f", "73 repeats");
    TFE('A', 74, "A*g", "74 repeats");
    TFE('A', 75, "A*h", "75 repeats");
    TFE('A', 76, "A*i", "76 repeats");
    TFE('A', 77, "A*j", "77 repeats");
    TFE('A', 78, "A*k", "78 repeats");
    TFE('A', 79, "A*l", "79 repeats");
    TFE('A', 80, "A*m", "80 repeats");
    TFE('A', 81, "A*n", "81 repeats");
    TFE('A', 82, "A*o", "82 repeats");
    TFE('A', 83, "A*p", "83 repeats");
    TFE('A', 84, "A*q", "84 repeats");
    TFE('A', 85, "A*r", "85 repeats");
    TFE('A', 86, "A*s", "86 repeats");
    TFE('A', 87, "A*t", "87 repeats");
    TFE('A', 88, "A*u", "88 repeats");
    TFE('A', 89, "A*v", "89 repeats");
    TFE('A', 90, "A*w", "90 repeats");
    TFE('A', 91, "A*x", "91 repeats");
    TFE('A', 92, "A*y", "92 repeats");
    TFE('A', 93, "A*z", "93 repeats");
    TFE('A', 94, "A*{", "94 repeats");
    TFE('A', 95, "A*|", "95 repeats");
    TFE('A', 96, "A*}", "96 repeats");
    TFE('A', 97, "A*~", "97 repeats");

    TFE('@', 57, "@*V", "Different character");
}

static void test_encode(void)
{
    char buffer[512];

#define TE(c, n, es, d)                                         \
    do                                                          \
    {                                                           \
        memset(buffer, (c), sizeof(buffer));                    \
        TAP_OK(encode(buffer, buffer, (n)) == strlen(es)        \
                   && memcmp(buffer, (es), strlen(es)) == 0,    \
               (d));                                            \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TE('z', 0, "", "Run of 0");
    TE('z', 1, "z", "Run of 1");
    TE('z', 2, "zz", "Run of 2");
    TE('z', 3, "zzz", "Run of 3");
    TE('z', 4, "z* ", "Run of 4");
    TE('z', 5, "z*!", "Run of 5");
    TE('z', 6, "z*\"", "Run of 6");
    TE('z', 7, "z*\"z", "Run of 7");
    TE('z', 8, "z*\"zz", "Run of 8");
    TE('z', 9, "z*\"zzz", "Run of 9");
    TE('z', 10, "z*&", "Run of 10");
    TE('z', 11, "z*'", "Run of 11");
    TE('z', 12, "z*(", "Run of 12");
    TE('z', 13, "z*)", "Run of 13");
    TE('z', 14, "z**", "Run of 14");
    TE('z', 15, "z*+", "Run of 15");
    TE('z', 16, "z*,", "Run of 16");
    TE('z', 17, "z*-", "Run of 17");
    TE('z', 18, "z*.", "Run of 18");
    TE('z', 19, "z*/", "Run of 19");
    TE('z', 20, "z*0", "Run of 20");
    TE('z', 21, "z*1", "Run of 21");
    TE('z', 22, "z*2", "Run of 22");
    TE('z', 23, "z*3", "Run of 23");
    TE('z', 24, "z*4", "Run of 24");
    TE('z', 25, "z*5", "Run of 25");
    TE('z', 26, "z*6", "Run of 26");
    TE('z', 27, "z*7", "Run of 27");
    TE('z', 28, "z*8", "Run of 28");
    TE('z', 29, "z*9", "Run of 29");
    TE('z', 30, "z*:", "Run of 30");
    TE('z', 31, "z*;", "Run of 31");
    TE('z', 32, "z*<", "Run of 32");
    TE('z', 33, "z*=", "Run of 33");
    TE('z', 34, "z*>", "Run of 34");
    TE('z', 35, "z*?", "Run of 35");
    TE('z', 36, "z*@", "Run of 36");
    TE('z', 37, "z*A", "Run of 37");
    TE('z', 38, "z*B", "Run of 38");
    TE('z', 39, "z*C", "Run of 39");
    TE('z', 40, "z*D", "Run of 40");
    TE('z', 41, "z*E", "Run of 41");
    TE('z', 42, "z*F", "Run of 42");
    TE('z', 43, "z*G", "Run of 43");
    TE('z', 44, "z*H", "Run of 44");
    TE('z', 45, "z*I", "Run of 45");
    TE('z', 46, "z*J", "Run of 46");
    TE('z', 47, "z*K", "Run of 47");
    TE('z', 48, "z*L", "Run of 48");
    TE('z', 49, "z*M", "Run of 49");
    TE('z', 50, "z*N", "Run of 50");
    TE('z', 51, "z*O", "Run of 51");
    TE('z', 52, "z*P", "Run of 52");
    TE('z', 53, "z*Q", "Run of 53");
    TE('z', 54, "z*R", "Run of 54");
    TE('z', 55, "z*S", "Run of 55");
    TE('z', 56, "z*T", "Run of 56");
    TE('z', 57, "z*U", "Run of 57");
    TE('z', 58, "z*V", "Run of 58");
    TE('z', 59, "z*W", "Run of 59");
    TE('z', 60, "z*X", "Run of 60");
    TE('z', 61, "z*Y", "Run of 61");
    TE('z', 62, "z*Z", "Run of 62");
    TE('z', 63, "z*[", "Run of 63");
    TE('z', 64, "z*\\", "Run of 64");
    TE('z', 65, "z*]", "Run of 65");
    TE('z', 66, "z*^", "Run of 66");
    TE('z', 67, "z*_", "Run of 67");
    TE('z', 68, "z*`", "Run of 68");
    TE('z', 69, "z*a", "Run of 69");
    TE('z', 70, "z*b", "Run of 70");
    TE('z', 71, "z*c", "Run of 71");
    TE('z', 72, "z*d", "Run of 72");
    TE('z', 73, "z*e", "Run of 73");
    TE('z', 74, "z*f", "Run of 74");
    TE('z', 75, "z*g", "Run of 75");
    TE('z', 76, "z*h", "Run of 76");
    TE('z', 77, "z*i", "Run of 77");
    TE('z', 78, "z*j", "Run of 78");
    TE('z', 79, "z*k", "Run of 79");
    TE('z', 80, "z*l", "Run of 80");
    TE('z', 81, "z*m", "Run of 81");
    TE('z', 82, "z*n", "Run of 82");
    TE('z', 83, "z*o", "Run of 83");
    TE('z', 84, "z*p", "Run of 84");
    TE('z', 85, "z*q", "Run of 85");
    TE('z', 86, "z*r", "Run of 86");
    TE('z', 87, "z*s", "Run of 87");
    TE('z', 88, "z*t", "Run of 88");
    TE('z', 89, "z*u", "Run of 89");
    TE('z', 90, "z*v", "Run of 90");
    TE('z', 91, "z*w", "Run of 91");
    TE('z', 92, "z*x", "Run of 92");
    TE('z', 93, "z*y", "Run of 93");
    TE('z', 94, "z*z", "Run of 94");
    TE('z', 95, "z*{", "Run of 95");
    TE('z', 96, "z*|", "Run of 96");
    TE('z', 97, "z*}", "Run of 97");
    TE('z', 98, "z*~", "Run of 98");
    TE('z', 99, "z*~z", "Run of 99");
    TE('z', 100, "z*~zz", "Run of 100");
    TE('z', 101, "z*~zzz", "Run of 101");
    TE('z', 102, "z*~z* ", "Run of 102");
    TE('z', 103, "z*~z*!", "Run of 103");
    TE('z', 104, "z*~z*\"", "Run of 104");
    TE('z', 105, "z*~z*\"z", "Run of 105");
    TE('z', 106, "z*~z*\"zz", "Run of 106");
    TE('z', 107, "z*~z*\"zzz", "Run of 107");
    TE('z', 108, "z*~z*&", "Run of 108");
    TE('z', 109, "z*~z*'", "Run of 109");
    TE('z', 110, "z*~z*(", "Run of 110");
    TE('z', 111, "z*~z*)", "Run of 111");
    TE('z', 112, "z*~z**", "Run of 112");
    TE('z', 113, "z*~z*+", "Run of 113");
    TE('z', 114, "z*~z*,", "Run of 114");
    TE('z', 115, "z*~z*-", "Run of 115");
    TE('z', 116, "z*~z*.", "Run of 116");
    TE('z', 117, "z*~z*/", "Run of 117");
    TE('z', 118, "z*~z*0", "Run of 118");
    TE('z', 119, "z*~z*1", "Run of 119");
    TE('z', 120, "z*~z*2", "Run of 120");
    TE('z', 121, "z*~z*3", "Run of 121");
    TE('z', 122, "z*~z*4", "Run of 122");
    TE('z', 123, "z*~z*5", "Run of 123");
    TE('z', 124, "z*~z*6", "Run of 124");
    TE('z', 125, "z*~z*7", "Run of 125");
    TE('z', 126, "z*~z*8", "Run of 126");
    TE('z', 127, "z*~z*9", "Run of 127");
    TE('z', 128, "z*~z*:", "Run of 128");
    TE('z', 129, "z*~z*;", "Run of 129");
    TE('z', 130, "z*~z*<", "Run of 130");
    TE('z', 131, "z*~z*=", "Run of 131");
    TE('z', 132, "z*~z*>", "Run of 132");
    TE('z', 133, "z*~z*?", "Run of 133");
    TE('z', 134, "z*~z*@", "Run of 134");
    TE('z', 135, "z*~z*A", "Run of 135");
    TE('z', 136, "z*~z*B", "Run of 136");
    TE('z', 137, "z*~z*C", "Run of 137");
    TE('z', 138, "z*~z*D", "Run of 138");
    TE('z', 139, "z*~z*E", "Run of 139");
    TE('z', 140, "z*~z*F", "Run of 140");
    TE('z', 141, "z*~z*G", "Run of 141");
    TE('z', 142, "z*~z*H", "Run of 142");
    TE('z', 143, "z*~z*I", "Run of 143");
    TE('z', 144, "z*~z*J", "Run of 144");
    TE('z', 145, "z*~z*K", "Run of 145");
    TE('z', 146, "z*~z*L", "Run of 146");
    TE('z', 147, "z*~z*M", "Run of 147");
    TE('z', 148, "z*~z*N", "Run of 148");
    TE('z', 149, "z*~z*O", "Run of 149");
    TE('z', 150, "z*~z*P", "Run of 150");
    TE('z', 151, "z*~z*Q", "Run of 151");
    TE('z', 152, "z*~z*R", "Run of 152");
    TE('z', 153, "z*~z*S", "Run of 153");
    TE('z', 154, "z*~z*T", "Run of 154");
    TE('z', 155, "z*~z*U", "Run of 155");
    TE('z', 156, "z*~z*V", "Run of 156");
    TE('z', 157, "z*~z*W", "Run of 157");
    TE('z', 158, "z*~z*X", "Run of 158");
    TE('z', 159, "z*~z*Y", "Run of 159");
    TE('z', 160, "z*~z*Z", "Run of 160");
    TE('z', 161, "z*~z*[", "Run of 161");
    TE('z', 162, "z*~z*\\", "Run of 162");
    TE('z', 163, "z*~z*]", "Run of 163");
    TE('z', 164, "z*~z*^", "Run of 164");
    TE('z', 165, "z*~z*_", "Run of 165");
    TE('z', 166, "z*~z*`", "Run of 166");
    TE('z', 167, "z*~z*a", "Run of 167");
    TE('z', 168, "z*~z*b", "Run of 168");
    TE('z', 169, "z*~z*c", "Run of 169");
    TE('z', 170, "z*~z*d", "Run of 170");
    TE('z', 171, "z*~z*e", "Run of 171");
    TE('z', 172, "z*~z*f", "Run of 172");
    TE('z', 173, "z*~z*g", "Run of 173");
    TE('z', 174, "z*~z*h", "Run of 174");
    TE('z', 175, "z*~z*i", "Run of 175");
    TE('z', 176, "z*~z*j", "Run of 176");
    TE('z', 177, "z*~z*k", "Run of 177");
    TE('z', 178, "z*~z*l", "Run of 178");
    TE('z', 179, "z*~z*m", "Run of 179");
    TE('z', 180, "z*~z*n", "Run of 180");
    TE('z', 181, "z*~z*o", "Run of 181");
    TE('z', 182, "z*~z*p", "Run of 182");
    TE('z', 183, "z*~z*q", "Run of 183");
    TE('z', 184, "z*~z*r", "Run of 184");
    TE('z', 185, "z*~z*s", "Run of 185");
    TE('z', 186, "z*~z*t", "Run of 186");
    TE('z', 187, "z*~z*u", "Run of 187");
    TE('z', 188, "z*~z*v", "Run of 188");
    TE('z', 189, "z*~z*w", "Run of 189");
    TE('z', 190, "z*~z*x", "Run of 190");
    TE('z', 191, "z*~z*y", "Run of 191");
    TE('z', 192, "z*~z*z", "Run of 192");
    TE('z', 193, "z*~z*{", "Run of 193");
    TE('z', 194, "z*~z*|", "Run of 194");
    TE('z', 195, "z*~z*}", "Run of 195");
    TE('z', 196, "z*~z*~", "Run of 196");
    TE('z', 197, "z*~z*~z", "Run of 197");
    TE('z', 198, "z*~z*~zz", "Run of 198");
    TE('z', 199, "z*~z*~zzz", "Run of 199");
    TE('z', 200, "z*~z*~z* ", "Run of 200");
    TE('z', 201, "z*~z*~z*!", "Run of 201");
    TE('z', 202, "z*~z*~z*\"", "Run of 202");
    TE('z', 203, "z*~z*~z*\"z", "Run of 203");
    TE('z', 204, "z*~z*~z*\"zz", "Run of 204");
    TE('z', 205, "z*~z*~z*\"zzz", "Run of 205");
    TE('z', 206, "z*~z*~z*&", "Run of 206");
    TE('z', 207, "z*~z*~z*'", "Run of 207");
    TE('z', 208, "z*~z*~z*(", "Run of 208");
    TE('z', 209, "z*~z*~z*)", "Run of 209");

    TE('.', 97, ".*}", "Different character (run of 97)");
    TE('.', 98, ".*~", "Different character (run of 98)");
    TE('.', 99, ".*~.", "Different character (run of 99)");
    TE('.', 100, ".*~..", "Different character (run of 100)");
    TE('.', 101, ".*~...", "Different character (run of 101)");
    TE('.', 102, ".*~.* ", "Different character (run of 102)");
}

/*
void run_length_encode
(
    char            *buffer, ///< [in,out] Buffer of data to be encoded.  This data is encoded
                             ///<          in-place, as the result will always be the same length or
                             ///<          shorter.
    unsigned long   *size    ///< [in,out] As input, the length of the incoming data buffer.  As
                             ///<          output, the length of the encoded data now occupying the
                             ///<          buffer.
)
*/

static void test_run_length_encode(void)
{
    char            buffer[512];
    unsigned long   size;

#define TRLE(i, o, d)                                                           \
    do                                                                          \
    {                                                                           \
        strcpy(buffer, (i));                                                    \
        size = strlen(i);                                                       \
        run_length_encode(buffer, &size);                                       \
        TAP_OK(size == strlen(o) && memcmp(buffer, (o), strlen(o)) == 0, (d));  \
    } while (0)

    TAP_DIAG("In %s", __func__);

    TRLE("", "", "Empty string");
    TRLE("7", "7", "Single character string");
    TRLE("007", "007", "Three character string");
    TRLE("ABCCCCCCDDDEEEEF", "ABC*\"DDDE* F", "Mixed string");
    TRLE("qqqqqqqqqqqqqqqqq", "q*-", "Single run");
    TRLE("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"
         "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"
         "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr",
         "r*~r*~r*`",
         "Long single run");
    TRLE("qqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"
         "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"
         "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"
         "rrrrrrrrrrrrrrrrrs",
         "q*-r*~r*~r*`s",
         "Mixed long string");
    TRLE("G0000000012345678fefefefe1111111100000000000000004444BBBBFC100000",
         "G0*\"0012345678fefefefe1*\"110*,4* B* FC10*!",
         "Sample command");
}

int main(void)
{
    TAP_PLAN(TEST_COUNT);

    test_format_rle();
    test_encode();
    test_run_length_encode();

    TAP_END_PLAN();
}
