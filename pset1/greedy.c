#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change_float;
    int change_int, quarters, q_remains, dimes, d_remains, nickels, n_remains, pennies, coins;
    do
    {
        printf ("O hai! How much change is owed?\n");
        change_float = get_float ();
    }
    while (change_float < 0);
    change_int = (int) round(change_float * 100);
    quarters = change_int / 25;
    printf ("%i\n", quarters);
    q_remains = change_int % 25;
    dimes = q_remains / 10;
    printf ("%i\n", dimes);
    d_remains = q_remains % 10;
    nickels = d_remains / 5;
    printf ("%i\n", nickels);
    n_remains = d_remains % 5;
    pennies = n_remains / 1;
    printf ("%i\n", pennies);
    coins = quarters + dimes + nickels + pennies;
    printf ("%i\n", coins);
}