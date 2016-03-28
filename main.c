#include <stdio.h>
#include <string.h>

#include "tea.h"

#define KEY	"4nu&f%0(*&<%!@*7"

int main()
{
	uint8_t buf[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	int n = tea_encrypt((uint8_t *)buf, 20, KEY);

	int i;
	for (i = 0; i < n; i++)
		printf("%d ", buf[i]);
	printf("\n");

	n = tea_decrypt((uint8_t *)buf, n, KEY);

	for (i = 0; i < n; i++)
		printf("%d", buf[i]);
	printf("\n");

	return 0;
}
