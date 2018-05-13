# include <sys/stat.h>
# include "header.h"
# include "queue.h"
# include "input.h"
# include "output.h"

int
main(int argc, char *argv[]) {
    pqueue pq;
    int fd;

    if (argc != 2)
        sys_err("parameter error.");

    if ((fd = open(argv[1], O_WRONLY | O_CREAT, 
                    S_IRWXU | S_IRWXG | S_IRWXO)) < 0)
        sys_err("open error.");
    pq = create_queue();
    get_paragraph(pq);
    write_paragraph(pq, fd);

    return 0;
}
