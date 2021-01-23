
set(
    SRCS
    main.c
)

if(NOT HAVE_MEMCPY)
    list(APPEND SRCS stdc/memcpy.c)
endif()
if(NOT HAVE_MEMSET)
    list(APPEND SRCS stdc/memset.c)
endif()
if(NOT HAVE_STRNCMP)
    list(APPEND SRCS stdc/strncmp.c)
endif()

add_library(gdbstub STATIC ${SRCS})
