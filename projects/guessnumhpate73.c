//
//  guessnamehpate73.c
//  guessnumhpate73
//
//  Created by Harshil Patel on 1/19/17.
//  Copyright © 2017 Harshil Patel. All rights reserved.
//

//this program convert given three digit number backwards and subtract it from input and than reverses it aging and adds it to to the answer it got
//from previous time and revels the number and also tests each value to see if there are any bad numbers that will not work for this game!!


#include <stdio.h>

// Display name and program information
void displayIdentifyingInformation()
{
    printf("\n");
    printf("Harshil Patel                \n");
    printf("Program: #1, Guess Number    \n");
    printf("TA: Praval Jain, Tues 3      \n");
    printf("Jan 23,2017                  \n");
    printf("\n");
}

//prints the wlcome screen and tells user what to do and asks user for input and stored it in userinput
void displayInstructions()
{
    printf("Welcome to the number guessing game!\n");
    printf("If you concentrate, sometimes you can connect to the electrons in the computer!\n");
    printf("Let's try it. Think of a three digit number.(To make it harder, make the digits \nall different from each other).");
    printf("Type in your number: ");
}
int main(void) {
    //declaring variables and characters
    int userinput;
    int a, i;
    int ans;
    char c;
    
    
    displayIdentifyingInformation();
    displayInstructions();
    scanf("%d", &userinput);
    a = userinput;
    
    //takes the three digit number and saparates each digit
    int rightDigit   = (userinput % 10);
    userinput        = (userinput / 10);
    int middleDigit  = (userinput % 10);
    int firstDigit   =   (userinput/10);
    
    //this if statement checks if there are any same digits in the number thats been entered
    if ((rightDigit==middleDigit)||(middleDigit==firstDigit)||(firstDigit==rightDigit))
    {
        printf("\n*** All three digits are not different.  Exiting program...\n\n");
        return 0;
    }
    
    //this multiplies the last digit with hundred and middle digit to ten and than adds them together
    rightDigit *= 100;
    middleDigit *= 10;
    int b = (firstDigit+middleDigit+rightDigit);
    
    //if the input is bigger than reversed number than subtracts it otherwise subtracts input from reversed number
    if (a>b){
        printf("\n\nI'll help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n\n");
        printf("%4d   (The original number)\n", a);
        printf("-%2d   (The reversed digit)\n",b);
        printf("=====\n");
        
        ans = a-b;
        printf("%4d\n\n", ans);
    }
    else{
        printf("\n\nI'll help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n\n");
        printf("%4d  (The reversed digits)\n", b);
        printf("-%2d  (The original number)\n", a);
        printf("=====\n");
        
        ans = b-a;
        printf("%4d\n\n", ans);
        
    }
    
    //prompts user for input in order to go to next step or exit.
    printf("Press 'Y' to continue or 'X' to exit...");
    scanf(" %c", &c);
    
    if (( c == 'y') || (c == 'Y'))
    {
        printf("Now lets again scramble the numbers by reversing them, and adding them this time:");
        
        //reverses the answer from the top and adds that number to the answer that we got on the top
        int v = ans;
        int rightDigit2 = (ans % 10);
        ans = (ans / 10);
        int middleDigit2 = (ans % 10);
        int firstDigit2 = (ans/10);
        
        rightDigit2 *= 100;
        middleDigit2 *= 10;
        
        int z = (firstDigit2+middleDigit2+rightDigit2);
        
        printf("\n\nI'll help you with the math. Lets randomize those digits by reversing them, and do a subtraction:\n\n");
        printf("%4d\n", v);
        printf("+%2d\n",z);
        printf("=====\n");
        printf(" ???\n");
        
        int g = v+z;
        printf("Before you continue, take a look at my number guess written down on paper.\n");
        printf("Press 'D' to display the answer or 'X' to exit... \n");
        
        // prompts user to press d to display the answer...
        scanf(" %c", &c);
        if ((c == 'd')||(c =='D'))
        {
            printf("Answer is %d.\n\n", g);
        }
        else
            return 0;
        
    }
    else
        return 0;
    
    //prompts user if they wanna see which numbers can be entered for this game
    printf("Press 'T' to test all possible combinations or 'X' to exit...");
    scanf(" %c", &c);
    {
    if ((c == 't')||(c =='T'))
    {
        // this for loops runs and compares all three digits and if there are any two or three same digits it prints it out
        int tot = 0;
        for (i = 0; i < 1000; ++i ){
            int p = i;
            
            //this separates three digits and stored them into diffrent variable
            int j = (p % 10);
            p     = (p / 10);
            int r = (p % 10);
            int k =   (p/10);
            
            //compares each digit to one and another
            if ((j==r)||(r==k)||(k==j))
            {
                printf("%d ",i);
                tot +=1;
            }
            
        }
        printf("\n\nThere are %d values that do not work.\n\nThanks for playing!\n\n", tot);
    }
    else
        return 0;
    }
    return 0;
}
