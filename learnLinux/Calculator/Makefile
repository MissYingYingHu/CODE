.PHONY:all
all:Calculator_client Calculator_service

Calculator_client:Calculator_client.c
	gcc -o $@ $^

Calculator_service:Calculator_service.c
	gcc -o $@ $^

.PHONY:clean
	clean:
	rm -f Calculator_client Calculator_service
