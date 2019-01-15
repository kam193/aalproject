OUTFILE=aal.out
CFLAGS=-Wall --std=c++11
FILES=DataStructure/*.cpp Solver/*.cpp Generator/*.cpp

debug: test
	g++ -g ${CFLAGS} ${FILES} main.cpp -o ${OUTFILE}

release: test
	g++ ${CFLAGS} ${FILES} main.cpp -o ${OUTFILE}

test:
	g++ ${CFLAGS} ${FILES} tests/*.cpp -o test.out
	./test.out