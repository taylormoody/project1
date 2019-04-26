#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Assignment 1 eng1003//

//The int main will simply be able to call each function I make//
//In order to space each function properly//



//read in with stdin give option for each function with printf//
//The rotation encryption function//
void rotationEncryption();
void rotationDecryption();
void substitutionEncryption();
void substitutionDecryption();

int main() {
    int menuChoice=0,rotationAmount=0, x=0;
    char text[1000]={0},substitutionKey[26]={0};
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
    else if (menuChoice ==2){
        rotationDecryption(text[x],rotationAmount);
    }
    else if (menuChoice ==3){
        substitutionEncryption(text[x],substitutionKey);
    }
    else if (menuChoice ==4){
        substitutionDecryption(text[x],substitutionKey);
    }

    
        //run = function

    return 0;
}
void rotationEncryption(){
    char text[1000]={0}, cipher[1000]={0};
    int rotationAmount, c;
    printf("Please input Rotation Amount: ");
    scanf("%d", &rotationAmount);
    getchar();
    //this getchar is here because it lets the code work and im not good enough to make a better fix
    //runs a loop from text start to the last character,stopping when it hits the end of the string//
    //this is why the loop starts at x=0 and uses ++x instead of x++//
    printf("Please input Text to be encrypted in Uppercase: ");
    while ((c=getchar()) !='\n'){
        static int x=0,i=0;
        //Each Option targets a specific part of the ascii definitions//
        if (c+rotationAmount>='A' && c+rotationAmount<='Z'){
            text[i++]=(char)c;
            cipher[x++]=(char)(c+rotationAmount);
        }
        //For Making lowercase letters into uppercase//
        else if (c+rotationAmount>='a' && c+rotationAmount<='z'){
            c = c-32;
            text[i++]=(char)c;
            cipher[x++]=(char)(c+rotationAmount);
        }
        //in case the rotation forces a letter like Z above the selected alphabet, this will//
        //make the ltter uppercase and wrap the letter back to the start of the alphabet//
        else if (c+rotationAmount>= 122){
            
            c=(c-(32+(26)));
            text[i++]=(char)(c+26);
            cipher[x++]=(char)(c+rotationAmount);
        }
        //deals with all punctuation below the upeprcase letters//
        else if (c<'A'){
            text[i++]=(char)c;
            cipher[x++]=(char)c;
        }
        
    }    
    printf("%s\n", text);
    printf("%s\n", cipher);

    
}
void rotationDecryption(){
    char text[1000]={0}, cipher[1000]={0};
    int rotationAmount, c;
    printf("Please input Rotation Amount: ");
    scanf("%d", &rotationAmount);
    getchar();
    //this getchar is here because it lets the code work and im not good enough to make a better fix
    //runs a loop from text start to the last character,stopping when it hits the end of the string//
    //this is why the loop starts at x=0 and uses ++x instead of x++//
    printf("Please input Text to be Decrypted in Uppercase: ");
    while ((c=getchar()) !='\n'){
        static int x=0,i=0;
        //Each Option targets a specific part of the ascii definitions//
        if (c-rotationAmount>='A' && c-rotationAmount<='Z'){
            text[i++]=(char)c;
            cipher[x++]=(char)(c-rotationAmount);
        }
        //For Making lowercase letters into uppercase//
        else if (c-rotationAmount>='a' && c-rotationAmount<='z'){
            c = c-32;
            text[i++]=(char)c;
            cipher[x++]=(char)(c-rotationAmount);
        }
        //deals with all punctuation below the uppercase letters//
        else if (c<'A'){
            text[i++]=(char)c;
            cipher[x++]=(char)c;
        }
        //this includes all punctuation between the uppercase and lowercase groups in ascii//
        else if (c>'Z' && c<'a'){
            text[i++]=(char)c;
            cipher[x++]=(char)c;
        }
        //in case the letter goes below the alphabet, this will help it wrap around to the//
        //end of the alphabet//
        else if (c-rotationAmount<'A'){
            
            c=c+26;
            text[i++]=(char)(c-26);
            cipher[x++]=(char)(c-rotationAmount);

        }
    }    
    printf("%s\n", text);
    printf("%s\n", cipher);

    
}
void substitutionEncryption(){
    char text[1000]={0}, substitutionKey[26]={0}, alphabetKey[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",encryptedMessage[1000]={0},c=0;
    int x=0,y=0;
    printf("Please Input substitution alphabet in Uppercase: ");
    scanf("%s", substitutionKey);
    //i cant find any function that works with spaces, since scanf doesnt read them and in fact cuts off reading entirely if//
    //it hits a space//
    printf("Please input text to be encrypted, spaces are not allowed so use underscores or no spaces: ");
    scanf("%s", text);

    for (x=0; x <strlen(text);x++){ 
        //SCANF DOES NOT ALLOW SPACES//
        //found from an article on finding a char in a str//
        //Each Option targets a specific part of the ascii definitions//
        if (text[x]>='A' && text[x]<='Z'){
            char *positionLetter = strchr(alphabetKey,text[x]);
            //got no idea what the NULL ? does but i dont want the seg fault to happen thx//
            int positionNumber= (positionLetter == NULL ? -1 : positionLetter - alphabetKey);
            encryptedMessage[y++] = substitutionKey[positionNumber];
        }
        //For Making lowercase letters into uppercase//
        else if (text[x]>='a' && text[x]<='z'){
            c = text[x];
            c =c-32;
            char *positionLetter = strchr(alphabetKey, c);
            //got no idea what the NULL ? does but i dont want the seg fault to happen thx//
            int positionNumber= (positionLetter == NULL ? -1 : positionLetter - alphabetKey);
            encryptedMessage[y++] = substitutionKey[positionNumber]; 
        }
        //these three all deal with punctuation//
        else if (text[x]<'A'){
            encryptedMessage[y++] = text[x];
        }
        else if (text[x]<'a'&& text[x]>'Z'){
            encryptedMessage[y++] = text[x];
        }
        else if (text[x]>'z'){
            encryptedMessage[y++] = text[x];
        }
    }
    
    printf("%s", encryptedMessage);
        
        
    
    
}
void substitutionDecryption(){
    char text[1000]={0}, substitutionKey[26]={0}, alphabetKey[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",decryptedMessage[1000]={0},c=0;
    int x=0,y=0;
    printf("Please Input substitution alphabet in Uppercase: ");
    scanf("%s", substitutionKey);
    //i cant find any function that works with spaces, since scanf doesnt read them and in fact cuts off reading entirely if//
    //it hits a space//
    printf("Please input text to be decrypted, spaces are not allowed so use underscores or no spaces: ");
    scanf("%s", text);

    for (x=0; x <strlen(text);x++){ 
        //SCANF DOES NOT ALLOW SPACES//
        //found from an article on finding a char in a str//
        //Each Option targets a specific part of the ascii definitions//
        if (text[x]>='A' && text[x]<='Z'){
            char *positionLetter = strchr(substitutionKey,text[x]);
            //got no idea what the NULL ? does but i dont want the seg fault to happen thx//
            int positionNumber= (positionLetter == NULL ? -1 : positionLetter - substitutionKey);
            decryptedMessage[y++] = alphabetKey[positionNumber];
        }
        //For Making lowercase letters into uppercase//
        else if (text[x]>='a' && text[x]<='z'){
            c = text[x];
            c =c-32;
            char *positionLetter = strchr(substitutionKey, c);
            //got no idea what the NULL ? does but i dont want the seg fault to happen thx//
            int positionNumber= (positionLetter == NULL ? -1 : positionLetter - substitutionKey);
            decryptedMessage[y++] = alphabetKey[positionNumber]; 
        }
        //these three all deal with punctuation
        else if (text[x]<'A'){
            decryptedMessage[y++] = text[x];
        }
        else if (text[x]<'a'&& text[x]>'Z'){
            decryptedMessage[y++] = text[x];
        }
        else if (text[x]>'z'){
            decryptedMessage[y++] = text[x];
        }
    }
    
    printf("%s", decryptedMessage);
        
}      
    
    
