#include <iostream>
using namespace std;

/*
# 현대적인 객체 지향 설계
=> "상속"의 목적은 "다형성"
다형성을 구현하는 방법은 "Upcasting"
*/
class Animal {};

class Dog : public Animal {};

// 부모 클래스와 자식 클래스는 is-a 관계가 성립함.
// =>   <자식 클래스> is a <부모 클래스>
// =>   Dog is a(n) Animal

int main()
{
	Animal a;
	Dog d;

	Animal* p1 = &a;
	Dog* p2 = &d;

	// 만약 Dog가 Animal의 자식 클래스가 아니라면, Animal* pa = &d; 와 같은 코드는 불가능.
	Animal* pa = &d;
	Animal& ra = d;
	// 자식 클래스의 주소, 참조 타입이 부모 클래스의 주소, 참조 타입으로의 암묵적인 변환이 허용됨.
	// => Upcasting
	//		: 부모 클래스의 포인터, 참조를 통해 자식 객체를 참조할 수 있음.
}