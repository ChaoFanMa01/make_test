/** @file output.c
 *
 * Definitions for output operations.
 */

# include "header.h"
# include "queue.h"
# include "input.h"
# include "output.h"

int
write_paragraph(pqueue pq, int fd) {
    char *line;
    int n = 0;

    if (pq == NULL)
        return ERROR;

    while (!is_empty_queue(pq)) {
        line = dequeue(pq);
        n += char_num(line);
        writeline(line, fd);
    }

    return n;
}

int
writeline(char *line, int fd) {
    int n;
    char newline = '\n';

    for (n = 0; *(line + n) != '\0'; )
        if (write(fd, line + n++, 1) < 0)
            if (errno == EINTR)
                continue;
            else
                err_exit(errno);
    write(fd, &newline, 1);

    return n;
}
