OPTIMIZATION_LEVELS := O3 O2 O1
DEFAULT_OPTIMIZATION_LEVEL := O3

$(info Prieinami optimizacijos lygiai: $(OPTIMIZATION_LEVELS))

ifdef OPT
ifeq ($(filter $(OPT),$(OPTIMIZATION_LEVELS)),)
$(error Neinkamas optimizacijos lygis: $(OPT))
endif
OPTIMIZATION_LEVEL := $(OPT)
else
OPTIMIZATION_LEVEL := $(DEFAULT_OPTIMIZATION_LEVEL)
endif

CXXFLAGS := -$(OPTIMIZATION_LEVEL)

main: funkcijos.o studentas.o
	g++ $(CXXFLAGS) -o program main.cpp funkcijos.o studentas.o


funkcijos.o: funkcijos.cpp
	g++ -O3 -c funkcijos.cpp

studentas.o: studentas.cpp
	g++ -O3 -c studentas.cpp

clean:
	del -f *.o *.exe ..\data\zaliocikai*.txt ..\data\eiliniai*.txt
