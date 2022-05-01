//=======================================================================
// Author:		Theodore Brucker
// Date:  		4/31/2022
// Language:	C
// Example:		Stack functions using pointers
// File:   		homeworkFour.c
//=======================================================================

#include <stdio.h>

//Function declarations
void push(int **SP, int val);
int pop(int **SP);
int inStack(int *SP, int val);
int SizeOfStack(int *SP);
void PrintStack(int *SP);
void peek(int *SP);

int Stack[100]; //The "stack area"
int* SP = Stack; //The pointer to the stacks location
const int* initSP = Stack; //The initial value of SP (this does not change)

//Main function, handles the interactive portion of the program
int main()
{
    //Variables to hold user input
    int userFunc, userInt;

    //While input for function selection does not equal -1
    while(userFunc != -1)
    {
        //Prompt the user for desired function
        printf("-----------------------------------------------------------------------------------------------\nSelect a function [0]push, [1]pop, [2]InStack, [3]sizeOfStack, [4]printStack, [5]peek, [-1]quit\n-----------------------------------------------------------------------------------------------\n");
        //Read answer into userFunc
        scanf("%d", &userFunc);

        //If desired function requires a second input
        if(userFunc == 0 || userFunc == 2)
        {
            //Prompt user for second input to go with their function
            printf("User Int - ");
            //Read answer into userInt
            scanf("%d", &userInt);
        }

        if(userFunc == -1){ 
           
            //Exit main function
            break;
        }else if(userFunc == 0){ 
            
            //Call push with SP and userInt
            push(&SP, userInt);
        }else if(userFunc == 1){ 
            
            // Call pop with SP
            int popNum = pop(&SP);
        }else if(userFunc == 2){ 
            
            //Call inStack with SP and userInt
            int tempBool = inStack(SP, userInt);

            //Print the result of search
            printf("%d\n", tempBool);
        }else if(userFunc == 3){ 
            
            //Call SizeOfStack with SP
            int tempNum = SizeOfStack(SP);

            //Print out current stack size
            printf("Stack size is %d\n", tempNum);
        }else if(userFunc == 4){ 
            
            //Call PrintStack with SP
            PrintStack(SP);
        }else if(userFunc == 5){ 
            
            //Call peek with SP
            peek(SP);
        }else{
            printf("invalid input\n");
        }
    }
}

//Adds userInt at current pointer, then increments the pointer.
//INPUT: (pointer) current SP, (int) userInt
//RETURN: void
void push(int **SP, int val)  
{
    //check for overflow before push, break out if overflowing
    if(SizeOfStack(*SP) > 100){
        printf("Push failed due to overflow\n");
        return;
    }
    //current SP = userInt
    **SP = val;
    //increment SP to look at next address in array
    *SP = *SP + 1;
}

//Decrements SP, prints the 'top' of the array as SP looks one ahead
//INPUT: (pointer) currentSP
//RETURN: (int) value at SP post decrement
int pop(int **SP){
    //check for underflow before pop, break out if underflowing
    if(SizeOfStack(*SP) <= 0){
        printf("Pop failed due to underflow\n");
        return 0;
    }
    //Decrement the pointer to look at previous address in array
    *SP = *SP - 1;
    //Return the value held where the current SP is looking
    int temp = **SP;
    return temp;
}

//Checks if a value is in the stack
//INPUT: (pointer) current SP, (int) value to search for
//RETURN: (int) 1 if value is found, else 0
int inStack(int *SP, int val){
    int *tempSP = SP - 1;
    //Loop from 0 to the size of the stack
    for(int i = 0; i < SizeOfStack(SP); i++){
        //If value held at tempSP is equal to search value, return 1
        if(val == *tempSP){
            return 1;
        }
        //Else, decrement the tempSP
        tempSP = tempSP - 1;
    }
    //If the value is not found in the stack, return 0
    return 0;
}
//PURPOSE: Determines the size of the array using SP and initSP
//INPUT: (pointer) Current SP 
//RETURN: (int) size of array
int SizeOfStack(int *SP){
    //Address of SP - Address of initSP returns the number of integers that fit between these adresses (int takes 4 bits, compiler automatically does this math for you?)
    return (SP - initSP);
}

//PURPOSE Prints the stack from the bottom up
//INPUT: (pointer) Current SP
//RETURN: void
void PrintStack(int *SP){
    //Temporary SP so we can decrement without losing the top
    int *tempSP = SP;
    //Loop from size of array to 0
    for(int i = SizeOfStack(SP); i > 0; i--){
        //Decrement tempSP
        tempSP = tempSP - 1;
        //Print contents at tempSP
        printf("%d\n", *tempSP);
    }
}

//PURPOSE: Prints top value of stack pointer
//INPUT: (pointer) Current SP
//RETURN: void 
void peek(int *SP){
    //decrement
    SP = SP - 1;
    //print 'top' value
    printf("Peeked %d\n", *SP);
    //set pointer back above it
    SP = SP + 1;
}