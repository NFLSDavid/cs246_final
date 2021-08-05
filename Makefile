CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = board.o main.o block.o iblock.o cell.o szblock.o oblock.o tblock.o jblock.o lblock.o abc_board.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
