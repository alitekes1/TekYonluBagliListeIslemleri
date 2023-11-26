all: Program DerleCalistir

Program:derle 
	g++ ./lib/main.o ./lib/Basamak.o ./lib/Sayi.o ./lib/Dugum.o ./lib/SayilarListesi.o -o ./bin/program

derle:
	g++ -I "./include/" -c ./src/main.cpp -o ./lib/main.o
	g++ -I "./include/" -c ./src/Sayi.cpp -o ./lib/Sayi.o
	g++ -I "./include/" -c ./src/Basamak.cpp -o ./lib/Basamak.o
	g++ -I "./include/" -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I "./include/" -c ./src/SayilarListesi.cpp -o ./lib/SayilarListesi.o
	
DerleCalistir:
	./bin/program.exe