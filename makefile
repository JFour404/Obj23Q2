main: funkcijos.o
	g++ -O3 -o program main.cpp funkcijos.o

funkcijos.o: funkcijos.cpp
	g++ -O3 -c funkcijos.cpp

clean:
	del -f *.o *.exe zaliocikai*.txt eiliniai*.txt