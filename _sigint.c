#include "main.h"

/**
* sigint_handler - assigns sig_num as exit status
* @sig_num: exit status generator
* Return: void
*/

void sigint_handler(int sig_num)
{
	UNUSED(sig_num);
	signal(SIGINT, sigint_handler);
	_exit(0);
}
