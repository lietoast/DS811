#include <stdlib.h>
#include "iopp.h"

/*
	从stdin中读取一行字符
*/
void get_stdin_line(char *buff, int buff_size)
{
	if (buff_size <= 0)
		return;
	
	int i;
	for (i = 0; i < buff_size; i ++)
	{
		buff[i] = (char)getchar();
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			break;
		}
	}
}


