CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++0x -MMD
OBJECTS  = main.o Boggle.o
DEPENDS  = ${OBJECTS:.o=.d}
EXEC     = boggle

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include {$DEPENDS}

clean :
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS}