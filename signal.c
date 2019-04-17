#include "header.h"
/**
 * signals - function that handles signals
 * @sign: int
 */
void signals(int sign)
{
	(void)sign;
	signal(SIGINT, signals);
	fflush(stdout);
}
