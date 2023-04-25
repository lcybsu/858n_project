CC = mpicc
CFLAGS = -O2 -Wall
LDFLAGS = -lmpi -lopen-rte -lstdc++
EXEC = kmp

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ) $(EXEC)

