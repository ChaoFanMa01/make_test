/** @file input.h
 *
 * Function declarations for input operations.
 */

# ifndef INPUT_H
# define INPUT_H

# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 200

int getline(char *, int, size_type);
int get_paragraph(pqueue);
int char_num(char *);


# endif
