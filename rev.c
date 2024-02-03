#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void reverse(char	**res, int fd)
{
	int i = 0;
	int j = 31;

	while (i < 33)
	{
		j = 31;
		while (j >= 0)
		{
			write(fd, &res[j][i], 1);
			j--;
		}
		write(fd, "\n", 1);
		i++;
	}
}

int main()
{
	static char *result[] = {
"XXXXXXXXXXXXXX    XXXXXXXXXXXXXX",
"XXXXXXXXXX    ....    XXXXXXXXXX",
"XXXXXXXX  ............  XXXXXXXX",
"XXXXXXX ................ XXXXXXX",
"XXXXX  ..................  XXXXX",
"XXXX ...................... XXXX",
"XXXX ...................... XXXX",
"XXX ........................ XXX",
"XX .......................... XX",
"XX .......................... XX",
"X ............................ X",
"X ............................ X",
"X ............................ X",
" .............................. ",
" .............................. ",
" .............................. ",
" ..............                 ",
" .............................. ",
" .............................. ",
"X ............................ X",
"X ............................ X",
"X ............................ X",
"XX .......................... XX",
"XX .......................... XX",
"XXX ........................ XXX",
"XXXX ...................... XXXX",
"XXXX ...................... XXXX",
"XXXXX  ..................  XXXXX",
"XXXXXXX ................ XXXXXXX",
"XXXXXXXX  ............  XXXXXXXX",
"XXXXXXXXXX    ....    XXXXXXXXXX",
"XXXXXXXXXXXXXX    XXXXXXXXXXXXXX"
};
	int fd = open("xpm24", O_RDWR | O_CREAT, 777);
	reverse(result, fd);
}