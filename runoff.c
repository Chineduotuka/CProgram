#include<stdio.h>
#include<string.h>

void reverse(char *s);

int main(void)
{
    char s[256];
    printf("input text: ");
    fgets(s, 100, stdin);

    s[strcspn(s, "\n")] = '\0';

    reverse(s);

    printf("%s \n", s);
    

    return 0;
}

void reverse(char *s)
{
    int len = strlen(s);

    int i = 0, j = 0;

    char temp[100];

    for(i = 0; i<len; i++)
    {
        for(j = 0; i<len; j++, i++)
        {
            if(s[i] == ' '|| s[i] == ','|| s[i] == '.')
            {
                break;
            }
            temp[j] = s[i];
        }
        temp[j] = '\0';
        
         while(j >0 && strlen(temp) > 4)
        {
            j--;
            s[i - j - 1] = temp[j];
        }
        

    }
    
   
}
