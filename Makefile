CC = g++
PROGRAM = program.out
SRCS = calculator.cpp
INCS =
OPTS =

.PHONY : all run clean

all: ${PROGRAM}

${PROGRAM}: ${SRCS} ${INCS} Makefile
	${CC} -o $@ ${SRCS} ${OPTS}


run : ${PROGRAM}
	./${PROGRAM}

clean :
	rm ${PROGRAM}

