/*
 * TEA(Tiny Encryption Algorithm)是一种简单高效的加密算法，以加密解密速度快，
 * 实现简单著称。
 * 算法很简单，TEA算法每一次可以操作64-bit(8-byte)，采用128-bit(16-byte)作为key，
 * 算法采用迭代的形式，
 * 推荐的迭代轮数是64轮，最少32轮。
 */
#include "tea.h"

/*
 * tea加密
 * 参数:v:要加密的数据,长度为8字节
 *      k:加密用的key,长度为16字节
 */
static void tea_encrypt(uint32_t *v, uint32_t *k)
{
	uint32_t y = v[0], z = v[1], sum = 0, i;
	uint32_t delta = 0x9e3779b9;
	uint32_t a = k[0], b = k[1], c = k[2], d = k[3];

	for (i = 0; i < 32; i++) {
		sum += delta;
		y += ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
		z += ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
	}

	v[0] = y;
	v[1] = z;
}

/*
 * tea解密
 * 参数:v:要解密的数据,长度为8字节
 *      k:解密用的key,长度为16字节
 */
static void tea_decrypt(uint32_t *v, uint32_t *k) 
{
	uint32_t y = v[0], z = v[1], sum = 0xC6EF3720,i; 
	uint32_t delta = 0x9e3779b9;            
	uint32_t a = k[0], b = k[1], c = k[2], d = k[3];    

	for (i = 0; i < 32; i++) {
		z -= ((y << 4) + c) ^ (y + sum) ^ ((y >> 5) + d);
		y -= ((z << 4) + a) ^ (z + sum) ^ ((z >> 5) + b);
		sum -= delta;
	}

	v[0] = y;
	v[1] = z;
}

/*
 * 加密算法
 * 参数:src:源数据,所占空间必须为8字节的倍数.加密完成后密文也存放在这
 *      size_src:源数据大小,单位字节
 *      key:密钥,16字节
 * 返回:密文的字节数
 */
int encrypt(uint8_t *src, int size_src, uint8_t *key)
{
	int a = 0;
	int i = 0;
	int num = 0;
	
	// 将明文补足为8字节的倍数
	a = size_src % 8;
	if (a != 0)
		for (i = 0; i < 8 - a; i++)
			src[size_src++] = 0;

	// 加密
	num = size_src / 8;
	for (i = 0; i < num; i++)
		tea_encrypt((uint32_t *)(src + i * 8), (uint32_t *)key);
	
	return size_src;
}

/*
 * 解密算法
 * 参数:src:源数据,所占空间必须为8字节的倍数.解密完成后明文也存放在这
 *      size_src:源数据大小,单位字节
 *      key:密钥,16字节
 * 返回:明文的字节数,如果失败,返回0
 */
int decrypt(uint8_t *src, int size_src, uint8_t *key)
{
	int i = 0;
	int num = 0;
	
	// 判断长度是否为8的倍数
	if (size_src % 8 != 0)
		return 0;
	
	// 解密
	num = size_src / 8;
	for (i = 0; i < num; i++)
		tea_decrypt((uint32_t *)(src + i * 8), (uint32_t *)key);
	
	return size_src;
}
