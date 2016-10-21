main:	main.o ass1.o ass1.h
	g++ -o main main.o ass1.o
main.o:	main.cpp ass1.h
	g++ -c main.cpp
ass1.o:	ass1.cpp ass1.h
	g++ -c ass1.cpp
clean:
	rm main.o ass1.o
