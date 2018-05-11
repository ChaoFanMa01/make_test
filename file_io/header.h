/** @file header.h
 *
 * This file defines macros used across files.
 */

# ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>  /* for ssize_t, size_t */

#define CHAR_TYPE

# define OK     0
# define ERROR -1

# define TRUE   1
# define FALSE  0

# ifdef CHAR_TYPE
typedef char      value_type;
# elif defined (DOUBLE_TYPE)
typedef double    value_type;
# elif defined (FLOAT_TYPE)
typedef float     value_type;
# elif defined (LONF_TYPE)
typedef long      value_type;
# elif defined (SHORT_TYPE)
typedef short     value_type;
# else
typedef int       value_type;
#endif

typedef ssize_t   size_type;

# define print_msg(str, var...) (printf(str "\n", ## var))

# define sys_err(str, var...) ({\
    printf(str "\n", ## var);\
    exit(ERROR);\
})

# define err_exit(error) ({\
    printf("%s" "\n", strerror(error));\
    exit(ERROR);\
})

# define null_return(str, var...) ({\
    printf(str "\n", ## var);\
    return NULL;\
})

# endif
