.PHONY:all
all:client server

client:client.cpp
	g++ -o $@ $^ -std=c++17 -lpthread

server:server.cpp
	g++ -o $@ $^ -std=c++17 -lpthread 

.PHONY:clean
clean:
	rm -f client server