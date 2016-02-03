CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++0x -MMD -O3
OBJECTS  = main.o Dict.o Dice.o Solution.o Board.o
DEPENDS  = ${OBJECTS:.o=.d}
EXEC     = boggle

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include {$DEPENDS}

clean :
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS}
