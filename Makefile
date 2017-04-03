CCFLAGS = -g -std=c++11

lab9:	main.cpp QS.cpp 
	g++ $(CCFLAGS)  -o lab9 main.cpp QS.cpp

