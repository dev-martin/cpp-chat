all: server client

server:
	g++	-Wall -g -o bin/server src/server.cpp

client:
	g++	-Wall -g -o bin/client src/client.cpp

clean:
	cd bin && rm -f server client
