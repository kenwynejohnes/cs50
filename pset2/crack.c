#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

char *crypt (const char *key, const char *salt);
int main (int argc, string argv[])
{
    string k;
    int cmpreslt;
    if  (argc != 2)//checking if number of command-line argument is not equal to two
        
        {
            printf ("Usage: ./crack hash\n"); //generating error message
            return 1; //return error message
        }
    k = (argv[1]);
    const char* salt = "50"; //defining salt value
    const char* hashed = NULL;
    char password[6]; //declaring srting containing password consist of 6 characters (up to 5 characters long password and indicator string end "\0")
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //declaring alphabet string
    for (int i = 0; i < 52; i++) //checking all a-Z variations
    {
        password[0] = alphabet[i];
        hashed = crypt(password, salt);
        cmpreslt = strcmp (hashed, argv[1]); //comparing user input hash and computed hash
        if (cmpreslt == 0) 
        {
        printf ("password found: %s\n", password); //output cracking password if matched
        return 0;
        //printf ("%s\n", hashed);
        }
        
    }
    
    for (int i = 0; i < 52; i++) //checking all aa-ZZ variations
    {
        password[0] = alphabet[i];
        
            for (int j = 0; j < 52; j++)
            {
                password[1] = alphabet[j];
                hashed = crypt(password, salt);
                cmpreslt = strcmp (hashed, argv[1]); //comparing user input hash and computed hash
            if (cmpreslt == 0) 
            {
                printf ("%s\n", password); //output cracking password if matched
                return 0;
                //printf ("%s\n", password);
            }
            }
    }
    
    for (int i = 0; i < 52; i++) //checking all aaa-ZZZ variations
    {
        password[0] = alphabet[i];
        
        for (int j = 0; j < 52; j++)
            {
                password[1] = alphabet[j];
                
                for (int x = 0; x < 52; x++)
                {
                    password[2] = alphabet[x];
                    hashed = crypt(password, salt);
                    cmpreslt = strcmp (hashed, argv[1]); //comparing user input hash and computed hash
                    if (cmpreslt == 0) 
                     {
                        printf ("%s\n", password); //output cracking password if matched
                        return 0;
                        //printf ("%s\n", password);
                    }
            
                } 
            
            }
            
    }
    
    for (int i = 0; i < 52; i++) //checking all aaaa-ZZZZ variations
    {
        password[0] = alphabet[i];
        
        for (int j = 0; j < 52; j++)
            {
                password[1] = alphabet[j];
                
                for (int x = 0; x < 52; x++)
                {
                    password[2] = alphabet[x];
                    
                    for (int y = 0; y < 52; y++)
                    {
                        password[3] = alphabet[y];
                        hashed = crypt(password, salt);
                        cmpreslt = strcmp (hashed, argv[1]); //comparing user input hash and computed hash
                    if (cmpreslt == 0) 
                     {
                        printf ("%s\n", password); //output cracking password if matched
                        return 0;
                        //printf ("%s\n", password);
                    }
                    
                    }
                    
                }
                
            }
            
    }
    
    for (int i = 0; i < 52; i++) //checking all aaaaa-ZZZZZ variations
    {
        password[0] = alphabet[i];
        
        for (int j = 0; j < 52; j++)
            {
                password[1] = alphabet[j];
                
                for (int x = 0; x < 52; x++)
                {
                    password[2] = alphabet[x];
                    
                    for (int y = 0; y < 52; y++)
                    {
                        password[3] = alphabet[y];
                        
                        for (int z = 0; z < 52; z++)
                        {
                            password[4] = alphabet[z];
                            hashed = crypt(password, salt);
                            cmpreslt = strcmp (hashed, argv[1]); //comparing user input hash and computed hash
                        if (cmpreslt == 0) 
                            {
                                printf ("%s\n", password); //output cracking password if matched
                                return 0;
                                //printf ("%s\n", password);
                            }
                        }
                    }
                    
                }
                
            }
                
    }
}
