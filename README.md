# CompilerForSpecialLanguage
First two phases of the Compiler (LA &amp; SyA) for C++ Language in C/C++.

Implemented LL(1) Algo.
CFG, find out First( ) and Follow( ) and Parsing Table on the page.
Hard Code this Parsing Table

/* Program to match the Guessed number */
int hidden = 3;
float test = 3.0429;
int guess;
cout<<”Enter (1 - 10) to guess the hidden number”;
cin>>guess; //take input in variable guess
if(guess < hidden)
 cout<<"Your number is smaller";
else if(guess > hidden)
 cout<<"Your number
    is greater";
else
 cout<<"You GUESSED the exact number...";
