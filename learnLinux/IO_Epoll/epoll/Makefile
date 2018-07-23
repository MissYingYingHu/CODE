.PHONY:all
all:server client

server:epoll_server.c
	gcc -o $@ $^

client:client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f server client
