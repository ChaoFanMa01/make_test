/** @file input.c
 *
 * Function definitions for input operations.
 */

# include "header.h"
# include "queue.h"
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
    *(buf + n) = '\0';
    return n;
}

/** @fn
 *
 * Get multiple line from terminal.
 * @param pq A queue storing each line.
 * @return Number of lines stored in the queue.
 */
int
get_paragraph(pqueue pq) {
    char cmd, *buf;
    
    if (pq == NULL)
        return ERROR;

    printf("Enter a new line? (y/n))");
    cmd = getchar();
    while (cmd != 'n') {
        printf("Input: ");
        buf = (char *) malloc(sizeof(char) * BUF_SIZE);
        if (getline(buf, STDIN_FILENO, BUF_SIZE) <= 0) {
            free(buf);
        } else {
            enqueue(pq, buf);
        }
        printf("Enter a new line? (y/n))");
        while (getchar() != '\n') ;
        cmd = getchar();
    }
    return queue_size(pq);
}

/** @fn
 *
 * A statistics on the number of characters in a line.
 */
int
char_num(char *line) {
    int n;

    if (line == NULL)
        return ERROR;

    for (n = 0; *(line + n) != '\0'; n++) ;

    return n;
}
