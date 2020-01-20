#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define maxlengh 16

int main(void)
{
    long long card_number;
    printf ("Number: ");
    card_number = get_long_long ();
    char s[maxlengh];
    sprintf (s, "%lld", card_number);
    int len = strlen (s);
    if (len < 13 || len > 16 || len == 14)
    {
        printf("INVALID\n");
        return 0;
    }
    int number[len];
    for (int i = 0; i < len; i++)
    
        number[i] = s[i] - '0';

    int sum = 0, sum2 = 0, sum3 = 0, j = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (j % 2 == 0)
        {
            sum += (number[i]*2)%10 + (number[i]*2)/10;
            
        }
        else
        {
            sum2 += number[i];
        }
        j++;
        sum3 = sum + sum2;
    printf("%i\n", sum3);    
    }
    if (number[0] == 4 && (len == 13 || len == 16) && sum3 % 10 == 0)
        printf ("VISA\n"); 
    else if (number[0] == 3 && (number[1] == 4 || number[1] == 7) && len == 15 && sum3 % 10 == 0)
        printf ("AMEX\n");
    else if (number[0] == 5 && (number[1] == 1 || number[1] == 2 || number[1] == 3 || number[1] == 4 || number[1] == 5) && len == 16 && sum3 % 10 == 0)
        printf ("MASTERCARD\n");
    else
        printf ("INVALID\n");
        return 0;
 }
