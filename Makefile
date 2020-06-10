all: server client

server:
	g++	-Wall  -Wno-nullability-completeness	-g -o bin/server src/server.cpp src/chat.cpp

client:
	g++	-Wall  -Wno-nullability-completeness	-g -o bin/client src/client.cpp src/chat.cpp

clean:
	cd bin && rm -f server client
