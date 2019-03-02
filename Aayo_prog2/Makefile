#
# EE 4374 Assignment 2 Makefile
# Author: Anthony Ayo
#


run: aayo_prog2.o aayo_argtok.o aayo_exec.o
	gcc aayo_prog2.o aayo_argtok.o aayo_exec.o -o run


aayo_prog2.o: aayo_prog2.c
	gcc -c aayo_prog2.c


aayo_argtok.0: aayo_argtok.c aayo_argtok.h
	gcc -c aayo_argtok.c


aayo_exec.o: aayo_exec.c aayo_exec.h
	gcc -c aayo_exec.c


clean:
	rm *.o; rm aayo_prog2 run
