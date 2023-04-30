main: funkcijosClass.o studentas.o
	g++ -O3 -o program mainClass.cpp funkcijosClass.o studentas.o

funkcijos.o: funkcijosClass.cpp
	g++ -O3 -c funkcijosClass.cpp

studentas.o: studentas.cpp
	g++ -O3 -c studentas.cpp

clean:
	del -f *.o *.exe ..\data\zaliocikai*.txt ..\data\eiliniai*.txt