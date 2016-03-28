#include <stdio.h>
#include <string.h>

#include "tea.h"

int main()
{
	uint8_t buf[128] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	uint8_t key[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	int n = tea_encrypt((uint8_t *)buf, 23, key);

	int i;
	for (i = 0; i < n; i++)
		printf("%d", buf[i]);
	printf("\n");

	n = tea_decrypt((uint8_t *)buf, n, key);

	for (i = 0; i < n; i++)
		printf("%d", buf[i]);
	printf("\n");

	return 0;
}
