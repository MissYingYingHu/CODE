.PHONY:all
all:server client

server:epoll_server_ET.c
	gcc -o $@ $^

client:client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f server client
