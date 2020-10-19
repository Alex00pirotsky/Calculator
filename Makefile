all:
	gcc ./src/*.c
clean:
	rm -rf ./headers/*.gch ./src/*.gch a.out
