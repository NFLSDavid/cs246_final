CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = board.o main.o block.o iblock.o cell.o szblock.o oblock.o tblock.o jblock.o lblock.o abc_board.o level.o level0.o level1.o level2.o level3.o level4.o heavy.o blind.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
