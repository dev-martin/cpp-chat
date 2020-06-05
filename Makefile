all: server client

server:
	g++	-Wall -g -o server server.c

client:
	g++	-Wall -g -o client client.c

clean:
	cd bin && rm -f server client
