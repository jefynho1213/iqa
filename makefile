all:iqa

pi:iqa.c
	gcc -std=c11 iqa.c -o iqa -wall
