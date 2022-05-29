#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("provide tw0 command line argument  \n");

        return 1;
    }

    int digit_count = 0;
    int strtoin;

    for(int i = 0; i<strlen(argv[1]); i++)
    {
        if(isdigit(argv[1][i]))
        {
            digit_count +=1;
        }
        else
        {
            printf("key must be digits");
        }
    }
    if(digit_count == strlen(argv[1]))
    {
        strtoin = atoi(argv[1]);

    }
    else
    {
        printf("not of equal couunt");
    }

    char text[256];
    printf("input plain text: ");

    fgets(text, 256, stdin);

    text[strcspn(text,"\n")] = '\0';


    for(int j=0; j<strlen(text); j++)
    {
        if(isalpha(text[j]) && islower(text[j]))
        {
            printf("%c",(((text[j] - 97)+ strtoin) % 26)+ 97);
        }
        else if (isalpha(text[j]) && isupper(text[j]))
        {
            printf("%c", (((text[j] - 65) + strtoin) % 26) + 65);
        }
        else
        {
            printf("%c", text[j]);
        }
        
    }
    printf("\n");

    return 0;
    
}