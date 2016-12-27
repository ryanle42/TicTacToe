#include "ticktac.h"

int menu()
{
    int option = 0;
    new_line();
    printf("Choose a mode:\n");
    printf("(1) PvP\n");
    printf("(2) CPU easy\n");
    printf("(3) CPU medium\n");
    printf("(4) CPU hard\n");
    scanf("%i", &option);
    while (!(option >= 1 && option <= 4))
    {
        printf("Invalid option:\n");
        scanf("%i", &option);
    }
    return (option);
}