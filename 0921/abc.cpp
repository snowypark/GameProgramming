#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char word[30];              
    int length;                  
    bool isPalindrome = true; 

    printf("�Է�: ");
    scanf("%s", word);

    length = strlen(word);    
    
   
    for (int i = 0; i < length / 2; i++)
    {
        
        if (word[i] != word[length - 1 - i])
        {

            isPalindrome = false;
            break;
        }
    }

    printf("%d\n", isPalindrome);   

    return 0;
}
