/**
 * @file variable_length_array.c
 * @brief 测试可变长度数组
 * @copyright public domain
 */

/** 可变长数组
+ C99标准支持可变长的数组，C90则要求数组在编译期间确定大小。
+ gcc支持该C99标准，但cl不支持
+ gcc 加参数-std=c90，只会警告，需要加 -pedantic，才会报告错误
+ alloca函数在栈上分配内存，并且在函数返回时释放，类似变长数组的效果。
*/

#include <stdio.h>

void func(int a) {
	int i = 0;
	int buf[a];
	for (i=0; i<a; ++i) buf[i] = i;
	for (i=0; i<a; ++i) printf("%d ", buf[i]);
	printf("\n");
}


int main(int argc, const char* argv[]) {
	func(argc);
	return 0;
}



