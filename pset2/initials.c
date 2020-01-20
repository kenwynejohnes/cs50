#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string();
    if (s[0] != ' ')
    {
        printf ("%c", toupper (s[0]));
    }
    for (int i = 0; i < strlen (s); i++ )
    {
        if ((s[i] == ' ') && (s[i + 1] != ' ') && (s[i + 1] != '\0'))
        {
            printf ("%c", toupper (s[i + 1]));
        }
    }
    printf ("\n");
}