#include <stdio.h>
//Assignment 1 eng1003//

//The int main will simply be able to call each function I make//
//In order to space each function properly//



//read in with stdin give option for each function with printf//
//The rotation encryption function//
char rotationEncryption();

int main() {
    int menuChoice,rotationAmount;
    char encryption;
    char text[1000];
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
        //requests the text to be encrpted and uses the rotationEncryption function//
        printf("Please input the text to be encrypted in Uppercase\n");
        scanf("%s", text);
        printf("Please input Rotation Amount\n");
        scanf("%d", &rotationAmount);
        
        encryption=rotationEncryption(text,rotationAmount);
        printf("%s", &encryption);
    }
        //run = function

    return 0;
}
char rotationEncryption(){
    char text[1000],character;
    int x=0, rotationAmount;
    //runs a loop from text start to the last character,stopping when it hits the end of the string//
    //this is why the loop starts at x=0 and uses ++x instead of x++//
    for (x=0 ; text[x] != '\0'; ++x){
        //so that the text can be encrypted without things getting weird, baiscally copying it from one//
        //string to another and then saying the second string is equal to the first//
        character= (text[x]+rotationAmount);
        text[x]=character;
    
      

            
                
            
    }
    
}
