CC := g++
CFLAGS := -Wall -Werror
objects := $(wildcard *.cpp)
objects := $(filter-out Macros.cpp, $(objects))

all: Macros.cpp $(objects:.cpp=.o)
	$(CC) Macros.cpp -o Macros.exe $(objects:.cpp=.o) $(CFLAGS)

%.o: %.c
	$(CC) -c -o Objects $@ $< $(CFLAGS)

clean:
	rm -f *.o Macros.exe