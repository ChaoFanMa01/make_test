CC=cc
CFLAGS=-std=c99
objects=main.o input.o output.o queue.o
bin : $(objects)
	$(CC) $(CFLAGS) $(objects) -o bin
$(objects) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
.PHONY : clean
clean :
	rm bin $(objects)
