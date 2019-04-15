#include "header.h"
/* signals - function that handles signal
 */

void signals(int sign)
{
        (void)sign;
        signal(SIGINT, signals);
        fflush(stdout);
}
