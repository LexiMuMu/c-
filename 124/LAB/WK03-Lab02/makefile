main:	main.o dna.o freq.o
	g++ -o main main.o dna.o freq.o

main.o:	main.cpp dna.h freq.h
	g++ -c main.cpp

dna.o: dna.cpp dna.h
	g++ -c dna.cpp

freq.o:	freq.cpp freq.h
	g++ -c freq.cpp

clean:
	rm main.o dna.o freq.o