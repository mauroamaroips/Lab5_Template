default:
	gcc -Wall -o prog main.c input.c fortnite.c
debug:
	gcc -Wall -o prog -g main.c input.c fortnite.c
clean:
	rm -f prog
