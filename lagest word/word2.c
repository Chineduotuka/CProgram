#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* largest_word(char *word);

int main(void)
{
    char word[] = "this is a sentence a halliburton oil";
    // this is a ecnetnes a notrubillah oil

    char *word1 = largest_word(word);

    printf("%s \n", word1);

    free(word1);

    return 0;
}

char* largest_word(char *word)
{
    char buffer_word[256];

    char max_word[256];

    int count = 0;

    int len = strlen(word);

    int max = -1;

    char nonwords[] = " .,\n\t!";
    int i =0;
    char word2[100];

    while(i < len)
    {
        count = 0;
        while(i < len)
        {
            if(strchr(nonwords, word[i]) != NULL) 
                break;

            buffer_word[count] = word[i];
            i++;
            count++;
        }
        buffer_word[count] = '\0';
        
        if (count > max)
        {
            max = count;
            strcpy(max_word, buffer_word);
        }

        while(i < len)
        {
            if(strchr(nonwords, word[i]) == NULL)
                break;
            i++;
        }
    }
    // "this is a sentence a halliburton oil"
    char *word1 = malloc(sizeof(char)* (max + 1));
    strcpy(word1, max_word);
    return word1;
}