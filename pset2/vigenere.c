#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    string p; /*declaring variable p (user input)*/
    string k; /*declaring variable k (key)*/
    int j, ii; /*declaring variable j (index of key string)*/
    if (argc != 2)  /*checking if number of command-line argument is not equal to two*/
        {
            printf ("Usage: ./vigenere k\n"); /*generating error message*/
            return 1; /*return error message*/
        }
    int nn = strlen (argv[1]);
    k = (argv[1]); /*assign string to variable k*/
    for (ii = 0; ii < nn; ii++)
    {
        if (!isalpha(argv[1][ii]))
        {
            printf ("Usage: ./vigenere k\n"); /*generating error message*/
            return 1; /*return error message*/
        }
    }
    printf ("plaintext: "); /*invite user to input*/ 
    p = get_string(); /*getting input*/
    printf ("ciphertext: "); /*printing ciphertext*/
    int nonalpha = 0; /*create variable for counting non-alphabetical characters*/
    for (int i = 0, n = strlen (p); i < n; i++) /*checking each char of string p*/
    {
        if (i == 0) /*if current char is equal to zero*/
        {
            j = i % strlen (k); /*calculate j*/
        }
        else if (isalpha(p[i - 1]) && (i != 0)) /*if previous char is not alphabetical and not equal to zero*/
        {
            if (i > strlen (k)) /*if char is greater than stringlength of key*/
            {
                j = (i - nonalpha) % strlen (k); /*calculate j substracting amount of non-aplha chars*/
            }
            else
            {
               j = i % strlen (k); 
            }
        }
        else
        {
            nonalpha++; /*if current char is not letter, increase counter*/
            j = (i - nonalpha) % strlen (k);
        }
            if ((isupper(p[i])) && (isalpha(p[i])) && (isalpha(k[j])) && (isupper(k[j]))) 
            {
            printf ("%c", ((p[i] - 65 + k[j] - 65) % 26) + 65); 
            }
            else if ((isupper(p[i])) && (isalpha(p[i])) && (isalpha(k[j])) && (islower(k[j])))
            {
            printf ("%c", ((p[i] - 65 + k[j] - 97) % 26) + 65);
            }
            else if ((islower(p[i])) && (isalpha(p[i])) && (isalpha(k[j])) && (isupper(k[j])))
            {
            printf ("%c", ((p[i] - 97 + k[j] - 65) % 26) + 97);   
            }
            else if ((islower(p[i])) && (isalpha(p[i])) && (isalpha(k[j])) && (islower(k[j]))) 
            {
            printf ("%c", ((p[i] - 97 + k[j] - 97) % 26) + 97);  
            }
            else
            {
            printf ("%c", p[i]); /*don't shift chars*/
            }
       
    }
    printf ("\n");
    return 0;
}   
