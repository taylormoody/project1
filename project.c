#include <stdio.h>
#include <ctype.h>
//Assignment 1 eng1003//

//The int main will simply be able to call each function I make//
//In order to space each function properly//



//read in with stdin give option for each function with printf//
//The rotation encryption function//
void rotationEncryption();

int main() {
    int menuChoice=0,rotationAmount=0, x=0;
    char text[1000]={0};
    printf("Please choose a cipher function\n");
    printf("Press 1 for rotation encryption\n");
    printf("Press 2 for rotation decryption\n");
    printf("Press 3 for substitution encryption\n");
    printf("Press 4 for substitution decryption\n");
    //For the two cipher only text decryptions//
    printf("Press 5 for advanced rotation decryption\n");
    printf("Press 6 for advanced substitution decryption\n");
    scanf("%d", &menuChoice);
    
    if (menuChoice ==1){
        rotationEncryption(text[x],rotationAmount);

    }
        //run = function

    return 0;
}
void rotationEncryption(){
    char text[1000]={0}, cipher[1000]={0};
    int rotationAmount, c;
    printf("Please input Rotation Amount\n");
    scanf("%d", &rotationAmount);
    //runs a loop from text start to the last character,stopping when it hits the end of the string//
    //this is why the loop starts at x=0 and uses ++x instead of x++//
    printf("Please input Text to be encrypted in Uppercase\n");
    while ((c=getchar()) !='\n'){
        static int x=0,i=0;
        
        text[x++]=(char)c;
        cipher[i++]=(char)(c+rotationAmount);
        
    }    
    printf("%s\n", cipher);
    printf("%s\n", text);
    
}
