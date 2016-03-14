#include <stdio.h>
#include "tea.h"

int main()
{
	char buf[] = "123456789012345678901234";
	uint8_t key[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	encrypt((uint8_t *)buf, sizeof(buf) - 1, key);

	buf[sizeof(buf) - 1] = 0;
	printf("%s\n", buf);

	decrypt((uint8_t *)buf, sizeof(buf) - 1, key);

	buf[sizeof(buf) - 1] = 0;
	printf("%s\n", buf);

	return 0;
}
