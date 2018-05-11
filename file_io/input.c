/** @file input.c
 *
 * Function definitions for input operations.
 */

# include "header.h"
# include "input.h"

/** @fn
 *
 * read a line of characters from given file descriptor.
 * @param buf Buffer storing read characters.
 * @param fd File descriptor from which data is read.
 * @param size The size of given buffer.
 * @return The number of characters read from file.
 */
int
getline(char *buf, int fd, size_type size) {
    char         ch;
    size_type    n = 0, stat;

    while (n < size) {
        if ((stat = read(fd, &ch, 1)) > 0) {
            if (ch == '\n')
                break;
            *(buf + n++) = ch;
        } else if (stat < 0) {
            // read interrupted by system calls.
            if (errno == EINTR)
                continue;
            err_exit(errno);
        }
    }
    return n;
}
