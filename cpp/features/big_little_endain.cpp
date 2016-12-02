/**
 * @file little_big_endian.cpp
 * @brief 测试大小端字节序
 * @copyright public domain
 */

/**
big endian和little endian表示如何存放多字节数据。

big endian：
    ul = (uc[0]<< 24) + (uc[1]<<16) + (uc[2]<<8) + uc[3];
little endian:
    ul = (uc[3]<<24) + (uc[2]<<16) + (uc[1]<<8) + uc[0];
**/

#include <iostream>

static bool is_little_endian() {
	union {
		long l;
		char cs[4];
	} t;

	t.l = 1;

	return t.cs[0] == 1;
}

int main() {
	unsigned long ul = 0x12345678;
	unsigned char* uc = (unsigned char*)&ul;
	
	if (is_little_endian()) {
		bool r = (uc[0] + (uc[1]<<8) + (uc[2]<<16) + (uc[3]<<24)) == ul;
		std::cout << "little: (uc[0] + (uc[1]<<8) + (uc[2]<<16) + (uc[3]<<24)) == ul is " << (r ? "true" : "false") << std::endl;
	} else {
		bool r = (uc[3] + (uc[2]<<8) + (uc[1]<<16) + (uc[0]<<24)) == ul;
		std::cout << "little: (uc[3] + (uc[2]<<8) + (uc[1]<<16) + (uc[0]<<24)) == ul is " << (r ? "true" : "false") << std::endl;
	}

	return 0;
}
