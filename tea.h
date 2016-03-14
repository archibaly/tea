#ifndef _TEA_H_
#define _TEA_H_

#include <stdint.h>

int encrypt(uint8_t *src, int size_src, uint8_t *key);
int decrypt(uint8_t *src, int size_src, uint8_t *key);

#endif /* _TEA_H_ */
