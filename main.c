#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tea.h"

int main()
{
	uint8_t *buf = "some clear text";
	int len = strlen(buf);

	uint8_t *cipher_text = tea_encrypt(buf, &len, (uint8_t *)TEA_KEY);

	int i;
	for (i = 0; i < len; i++)
		printf("0x%02x ", cipher_text[i]);
	printf("\n");

	uint8_t *clear_text = tea_decrypt(cipher_text, &len, (uint8_t *)TEA_KEY);

	for (i = 0; i < len; i++)
		printf("%c", clear_text[i]);
	printf("\n");

	free(cipher_text);
	free(clear_text);

	return 0;
}
