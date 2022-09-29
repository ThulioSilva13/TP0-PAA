

all: 
	gcc figuras.c main.c -o main
run:
	main
clean:
	rm ./bin/* ./obj/*
