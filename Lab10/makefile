all: clean clear make

make: clear
	gcc -o msgQsnd msgQsnd.c
	gcc -o msgQrcv msgQrcv.c
	gcc -o task2 task2.c -pthread
	gcc -o task3 task3.c -pthread

clean:
	rm msgQsnd msgQrcv task2 task3

clear:
	clear
