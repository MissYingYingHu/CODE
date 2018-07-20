.PHONY:all
all:server client

server:select_server.c
	gcc -o $@ $^ 

client:client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f client server
