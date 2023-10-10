all: calc
calc: calc.c
	  gcc -o calc calc.c
	  ./calc
clean:
	rm -f calc