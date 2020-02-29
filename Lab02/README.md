### Jack Stoetzel

# Lab 02

## Task 6

Write a shell script using for loop to print the following
patterns on the screen:

a.

    1
    22
    333
    4444
    55555

b.
   
    *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
    

c. Your program asks a number between 5 to 9. If an input is not
   between 5 and 9, display error message and ask again

            1
           2 2
          3 3 3
         4 4 4 4
        5 5 5 5 5
       6 6 6 6 6 6
      7 7 7 7 7 7 7
     8 8 8 8 8 8 8 8
    9 9 9 9 9 9 9 9 9


## Task 7

Write a script named task7.sh to calculating factorial of given number by using while loop. The shell accepts one integer argument as a parameter and calculates factorial and display the result.

## Task 8

Write a script named "task8.sh" to print given numbers sum of all digit. The shell accepts one integer argument as a parameter. Your program must check number of arguments is one. If the number of arguments is not one, your program must display error message and exit.

Ex.)
    
    [separk@sejong] ./sumdigit.sh 345
    Sum of digit for number is 12
    
    [separk@sejong] ./sumdigit.sh
    You need to pass one numerical argument

## Task 9

Write a bash script that searches a word in a file as follows:
1. Ask user for a directory in which to find the file
    * If not a valid directory, quit with an appropriate error message
2. Ask user for the name of a readable file in that directory, giving the user three attempts to name one
    * If no readable file is named, quit with an appropriate error message
3. Ask user for a word to find in the file
    * If word is in the file, "word" FOUND! is printed
    * Otherwise, "word" NOT FOUND is printed
4. Exit codes are:

    0   Success
    
    1   No such directory
    
    2   No such file (after three attempts)
    
    3   File is not readable
    
    4   Word not found in the file
