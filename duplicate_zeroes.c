#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{
    char str[200];
    int i, j, len;
    printf("Enter a String: ");
    gets(str);
    len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[0]==' ')
        {
            for(i=0; i<(len-1); i++)
                str[i] = str[i+1];
            str[i] = '\0';
            len--;
            i = -1;
            continue;
        }
        if(str[i]==' ' && str[i+1]==' ')
        {
            for(j=i; j<(len-1); j++)
            {
                str[j] = str[j+1];
            }
            str[j] = '\0';
            len--;
            i--;
        }
    }
    printf("\nNew String = %s", str);
    getch();
    return 0;
}
