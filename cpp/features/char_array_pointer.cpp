
/**
 * @file char_array_pointer.cpp
 * @brief 测试字符数组和指针
 * @copyrigh public domain
 */

/**
+ 使用`char[]`和`char*`定义变量，并赋值字符串常量，这两者有较大区别。
  - 前者定义数组，并将字符串常量拷贝至该数组，变量表示这个新数组的首地址，拥有读写权限。
  - 后者定义指针，指向一个字符常量，只有读权限。

*/

#include <iostream>

const char* string0() {
	const char* str = "string";
	return str;
}

const char* string1() {
	return "string";
}

const char* string2() {
	static const char str[] = "string";
	return str;
}

const char* string3() {
    char str[] = "string";
    return str;
}

void function() {
    char a[] = "abc123456";
}

void test_string1() {
    const char* str = string1();
    std::cout << "test_string1: " << str << std::endl;
    function();
    std::cout << "test_string1: " << str << std::endl;
}

void test_string2() {
    const char* str = string2();
    std::cout << "test_string2: " << str << std::endl;
    function();
    std::cout << "test_string2: " << str << std::endl;
}

void test_string3() {
    const char* str = string3();
    std::cout << "test_string3: " << str << std::endl;
    function();
    std::cout << "test_string3: " << str << std::endl;
}

int main() {

	std::cout << "string0 == string1 is " << (string0() == string1() ? "true" : "false") << std::endl;

	std::cout << "string1 == string2 is " << (string1() == string2() ? "true" : "false") << std::endl;
    
    test_string1();
    test_string2();
    test_string3();
    
    return 0;
}


 