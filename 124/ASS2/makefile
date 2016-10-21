all: sortints sortmoves

sortints: main1.o sort1.o sort.h movement.o movement.h
	g++ main1.o sort1.o -o sortints

sortmoves: main2.o sort2.o sort.h movement.o movement.h
	g++ main2.o -D MOVEMENT movement.o sort2.o -o sortmoves 

main1.o: main1.cpp sort.h
	g++ -c main1.cpp

main2.o: main2.cpp sort.h movement.o movement.h
	g++ -c -D MOVEMENT main2.cpp

movement.o: movement.cpp movement.h
	g++ -c movement.cpp

sort1.o: sort.cpp sort.h
	g++ -c -o sort1.o sort.cpp 

sort2.o: sort.cpp sort.h
	g++ -c -o sort2.o -D MOVEMENT sort.cpp

clean:
	rm main1.o main2.o movement.o sort1.o sort2.o 
