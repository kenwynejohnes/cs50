#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    string p; /*declaring variable p*/
    if (argc != 2) /*checking if number of command-line argument is not equal to two*/
    {
    printf ("Usage: ./caesar k\n"); /*generating error message*/
    return 1;
    }
    else
        {
        printf ("plaintext: ");
        p = get_string();
        printf ("ciphertext: ");
        }
    int k = atoi (argv[1]); /*converting string to integer*/
    for (int i = 0, n = strlen (p); i < n; i++) /*checking each char of string*/
    {
            if ((isalpha(p[i])) && (isupper(p[i])))  /*checking if char is uppercase*/
            {
            printf ("%c", ((p[i] - 65 + k) % 26) + 65); /*shift uppercase chars*/
            }
            else if ((isalpha(p[i])) && (islower(p[i]))) /*checking if char is lowercase*/
            {
            printf ("%c", ((p[i] - 97 + k) % 26) + 97); /*shift lowercase chars*/   
            }
            else
            {
            printf ("%c", p[i]); /*don't shift chars*/
            }
    }
    printf ("\n");
}