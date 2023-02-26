HDR_PATH = include
LIB_PATH = lib
SRC_PATH = src

CC = g++
CFLAGS = -c -std=c++11 -g
LDFLAGS = -g -lsdl2 -L ${LIB_PATH}
SRC = ${wildcard ${SRC_PATH}/*.cpp}
HDR = ${wildcard ${HDR_PATH}/*.hpp}
OBJ = ${SRC:.cpp=.o}
EXEC = main

all: ${SRC} ${OBJ} ${EXEC}

debug: all
debug: CFLAGS += -DDEBUG

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o: %.cpp ${HDR}
	${CC} ${CFLAGS} $< -o $@ -I ${HDR_PATH}

clean:
	rm src/*.o ${EXEC}