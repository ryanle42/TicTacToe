#include "ticktac.h"

int main()
{
    int option;
    int token;
    char input[100];

    token = 1;
    while (token)
    {
        input[0] = '.';
        option = menu();
        if (option == 1)
            pvp();
        if (option == 2)
            cpu_easy();
        if (option == 3)
            cpu_medium();
        if (option == 4)
            cpu_hard();
        token = 0;
        while (input[0] != 'y' && input[0] != 'n')
        {
            printf("\nPlay again? y/n\n");
            scanf("%s", input);
        }
        if (input[0] == 'y')
            token = 1;
    }
    return (1);
}