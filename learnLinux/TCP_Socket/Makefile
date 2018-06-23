.PHONY:all
all:service client

service:service.c
	gcc -o $@ $^

client:client.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f service client
