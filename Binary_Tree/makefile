# Basic Makefile 



# all is the default target and is called when just â€˜makeâ€™ with

# no options is run.

all: myprog



# define myprog and the files it requires to compile.  If main_driver.o or

# binTree.o are not up to date they will be called upon to be updated before

# myprog is compiled together.  Note that tabs are required

myprog: binTree.o main_driver.o

	g++ -o pgm main_driver.o binTree.o



# to compile main.o the file main.cpp is checked for updates.  If main_driver.cpp

# is not present an error will be presented.  If main_driver.cpp has not changed

# since the last build it will not be recompiled.

main_driver.o: main_driver.cpp

	g++ -Wall -c -o main_driver.o main_driver.cpp



binTree.o: binTree.cpp

	g++ -Wall -c -o binTree.o binTree.cpp

