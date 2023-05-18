#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "mwendwa.h"

#define size 100
char symbols[4] = {'#','@','$','%'};
int symbolsValue[] = {2,4,6,8};
char* slotResult;



// deposit money
int getDeposit(){
    int amount = 0;
    while (1){
        printf("Please enter your deposit amount: ");
        if (scanf("%d",&amount) != 1 ||amount < 1 ){
            printf("Please enter a valid deposit amount.\n");
            while (getchar() != '\n') continue;
        }
        else{break;}
    }
    return amount;
}

// determine lines
int getLines(){
    int lines = 0;
    while (1){
        printf("Please enter the number of lines to bet on (1-3): ");
        if (scanf("%d",&lines) != 1 ||lines < 1 || lines > 3 ){
            printf("Please enter a valid number of lines.\n");
            while (getchar() != '\n') continue;
        }
        else{break;}
    }
    return lines;
}

// collect bet amount
int getBet(int amount,int lines){
    int bet = 0;
    int maxBet = amount/lines;
    while (1){
        printf("Please enter the amount to bet per line: ");
        if (scanf("%d",&bet) != 1 || bet < 1 ){
            printf("Please enter a valid deposit bet.\n");
            while (getchar() != '\n') continue;
        }
        else if (bet > (maxBet)){
            printf("Your bet amount cannot be greater than %d.\n", maxBet);
            continue;
        }
        else{break;}
    }
    return bet;
}

// play the game
char* slot(char symbols[], char* slotResult){
    srand(time(NULL));
    slotResult = malloc(size * sizeof(char));
    
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            int index = rand() % 4;
            append(slotResult, '|');
            append(slotResult, ' ');
            append(slotResult, symbols[index]);
            //I could make the header file do these lines but a good programmer is a lazy programmer :)
            append(slotResult, ' ');
            append(slotResult, '|');
            append(slotResult, ' ');
        }
        append(slotResult, '\n');
    }
return (slotResult);
}

// check for wins
// return output and/or winning
// check if repeatable and ask for new gameplay

int main(void)
{
    //int amount = getDeposit();
    //int lines = getLines();
    //int bet = getBet(amount, lines);

    printf("%s",slot(symbols, slotResult));
    //printf("%d - %d - %d\n",amount, lines, bet);

}