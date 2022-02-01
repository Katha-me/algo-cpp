all: CoordinateDecrypter
	make clean;

CoordinateDecrypter: main.o decrypter.o  
	g++ -o CoordinateDecrypter main.o decrypter.o

main.o:
	g++ -c main.cpp

decrypter.o:
	g++ -c decrypter.cpp
	
clean:
	rm *.o;
