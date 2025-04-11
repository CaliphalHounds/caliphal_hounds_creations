all: wordle

wordle: wordle.c
	gcc -o $@ $^
	cp $@ ../deploy/bin/$@
	cp $@ ../dist/$@