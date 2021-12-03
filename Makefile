CPP = g++
FLAGS = -pedantic-errors -std=c++11

main: main.o guessing_random_number.o
  $(CPP) main.o guessing_random_number.o -o main

.PHONY: clean
clean: main.o guessing_random_number.o main
  rm *.o
  rm main
  
main.o: main.cpp guessing_random_number.h
  $(CPP) $(FLAGS) -c main.cpp

guessing_random_number.o: guessing_random_number.cpp guessing_random_number.h
  $(CPP) $(FLAGS) -c guessing_random_number.cpp
