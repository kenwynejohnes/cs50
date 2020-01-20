#include <cs50.h>
#include <stdio.h>

int main(void)
{
        int minutes, bottles;
        printf ("Minutes: ");
        do
        {
            minutes = get_int ();
        }
        while (minutes < 0);
        bottles = minutes * 12;
        printf ("Bottles: %i\n", bottles);
}