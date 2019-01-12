OUTFILE=aal.out
CFLAGS=-Wall --std=c++11

debug:
	g++ -g ${CFLAGS} **/*.cpp main.cpp -o ${OUTFILE}

release:
	g++ ${CFLAGS} **/*.cpp main.cpp -o ${OUTFILE}