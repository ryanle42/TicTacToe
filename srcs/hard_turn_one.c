#include "ticktac.h"

int     turn_one(int pos)
{
    if (pos == 0)
        return (5);
    if (pos == 2)
        return (5);
    if (pos == 8)
        return (5);
    if (pos == 10)
        return (5);
    if (pos == 5)
        return (20);
    return (20);
}