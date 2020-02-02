#include <stdio.h>
int i = 0;
char main()
{
	i += 1;
	printf("%d\n", i);
	main();
	return 0;
}