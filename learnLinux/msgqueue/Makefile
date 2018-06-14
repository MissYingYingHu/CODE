.PHONY:all
all:server client

server:server.c common.c
	gcc -o $@ $^

client:client.c common.c
	gcc -o $@ $^

.PHONY:clean
	rm -f server client
