EXE = main

OBJS_EXE = main.o person.o 

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD  = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm


all: ${EXE}

$(EXE): $(OBJS_EXE)
		  $(LD) $(OBJS_EXE) $(LDFLAGS) -o $(EXE)

person.o: person.cpp person.h
		$(CXX) $(CXXFLAGS) person.cpp -o $@

main.o: main.c person.h
		$(CXX) $(CXXFLAGS) main.c -o main.o

clean:
	-rm -f *.o $(EXE)
