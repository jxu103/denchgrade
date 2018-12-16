CC = g++ -std=c++17

SRCS=$(wildcard src/*.cpp)

all: $(SRCS)
	$(CC) -o run $(SRCS)
	
clean:
	@rm -f run