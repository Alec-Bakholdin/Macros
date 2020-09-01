CC := g++
CFLAGS := -Wall -Werror

cpp_files := $(wildcard */*.cpp)

objects := $(patsubst %.cpp, %.o, $(cpp_files))

all_objects := $(wildcard */*.o)


all: Macros.cpp $(objects)
	$(CC) Macros.cpp -o Macros.exe $(objects) $(CFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f */*.o Macros.exe

print:
	