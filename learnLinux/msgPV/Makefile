.PHONY:all
all:reader writer

reader:reader.c
	gcc -o $@ $^

writer:writer.c
	gcc -o $@ $^

.PHONY:clean
	clean:
	rm -f reader writer
