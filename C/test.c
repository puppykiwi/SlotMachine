#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char analyze (char* result){
    int length = strlen(result);

    for (int i=0; i<length; i = i + 2){
        if (result[i] == result[i+1] && result[i+1] == result[i+2]){
            printf("%c - %c - %c\n",result[i],result[i+1],result[i+2]);
            return result[i];
        }
        else{return '0';}
        
    }


}

int main (void){
    int i;
    i = analyze("@@@$$$@*#");
    printf("%c",i);
}