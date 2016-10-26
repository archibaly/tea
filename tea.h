#ifndef _TEA_H_
#define _TEA_H_

#include <stdint.h>

#define TEA_KEY	"l(9A#%2*!<6&@!9^"

uint8_t *tea_encrypt(const uint8_t *clear_text, int *text_len, const uint8_t *key);
uint8_t *tea_decrypt(const uint8_t *cipher_text, int *text_len, const uint8_t *key);

#endif /* _TEA_H_ */
