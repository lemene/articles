/** 
 * @file constructor_exception.cpp
 * @brief 测试构造函数异常引起的行为
 * @copyright public domain
 */

/**
 * 类的构造函数抛出异常，不会调用该类的析构函数，在构造函数申请的资源需要在构造函数释放。
 + 解决方法：
   * 在构造函数中使用`try...catch`结构。
   * 使用类包装资源申请，如auto_ptr。
 */

#include <iostream>
#include <exception>
#include <memory>

class Base {
public:
	Base() { std::cout << "Base()" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};

class Member {
public:
	Member(int id):mId(id) { std::cout << "Member():" << mId << std::endl; }
	virtual ~Member() { std::cout << "~Member()" << mId << std::endl; }
protected:
	int mId;
};

class Except : public Base {
public:
	Except() : mMember1(1), mMember2(NULL) { 
		std::cout << "Except() enter" << std::endl; 
		mMember2 = new Member(2);
		mMember3.reset(new Member(3));
		throw std::exception();
		std::cout << "Except() leave" << std::endl; 
	}

	virtual ~Except() { 
		delete mMember2;
		std::cout << "~Except()" << std::endl; 
	}

protected:
	Member mMember1;
	Member *mMember2;
	std::auto_ptr<Member> mMember3;
};

int main() {
	try {
		Except e;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

