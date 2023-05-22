CC=g++

all: hw06

hw06: listType.h listType.o stock.h stock.o stockList.h stockList.o
	$(CC) main.cpp -o hw06 listType.o stock.o stockList.o

listType.o: listType.h listType.o
	$(CC) -c listType.cpp -o listType.o

stock.o: stock.h stock.cpp
	$(CC) -c stock.cpp -o stock.o

stockList.o: stockList.h stockList.cpp
	$(CC) -c stockList.cpp -o stockList.o

clean:
	rm -f *.o all