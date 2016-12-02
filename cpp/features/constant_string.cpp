/**
 * @file constant_string.cpp
 * @brief 测试常量字符串
 * @copyright public domain
 */

/** 
+ 相同的字符串常量会合并，变量a，b指向的地址相同
+ 字符串常量禁止修改，(1) 处，编译器会报警告,运行程序会崩溃。
*/

#include <iostream>

int main() {
	    char* a = "string";
	    const char* b = "string";

    std::cout << "a == b is " << (a==b ? "true" : "false") << std::endl; // (0)

    a[1] = 'd'; // (1) 

    return 0;
}

