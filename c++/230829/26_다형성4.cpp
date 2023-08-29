#include <iostream>
using namespace std;


class Animal {
public:
    // void Cry() const {cout<<"Animal Cry"<<endl;}
    virtual void Cry() const {cout<<"Animal Cry"<<endl;}
};

// 1. 부모가 제공하는 멤버 함수를 자식 클래스가 재정의할 수 있음
//      => 함수 오버라이딩(Overriding)
class Dog : public Animal {
public:
    // void Cry() const {cout<<"Dog Cry"<<endl;}
    virtual void Cry() const {cout<<"Dog Cry"<<endl;}
};

// 2. C++의 함수 바인딩 : 어떤 함수를 호출할지 결정하는 것
//      Animal* p = &d;
//      p->Cry();
//      1) 정적(static) 바인딩
//          : 컴파일 타임에 컴파일러가 결정
//          -> 컴파일 시, p의 타입을 보고 어떤 클래스의 멤버 함수를 호출할지 결정
//          -> p가 Animal 타입이기 때문에 Animal의 Cry() 멤버 함수를 호출
//      2) 동적(dynamic) 바인딩
//          : 실행 시간에 어떤 함수가 호출될지 결정
//          -> 실행 시간에 p의 타입을 조사해서, 어떤 클래스의 멤버 함수를 호출할지 결정
//          -> p가 Dog의 타입을 가지고 있기 때문에 Dog의 Cry() 멤버 함수를 호출
//          -> 우리가 원하는 방법인데, C++은 기본적으로 정적 바인딩
//      => 멤버 함수를 virtual 함수로 만들면, 기본적인 정적 바인딩이 아닌 동적 바인딩을 수행함.
//  * 정적 바인딩이 기본인 이유
//  : 컴파일 타임에 컴파일러가 결정하기 때문에 "인라인 최적화"가 가능 => 오버헤드를 줄일 수 있다.
//    반대로, 동적 바인딩은 실행 시간에 결정하기 때문에 일반적인 호출밖에 하지 못함. 즉, 인라인 최적화를 하지 못함.
///
int main()
{
    Animal a;
    Dog d;
    a.Cry();
    d.Cry();

    Animal* p = &a;
    p->Cry();    // Animal Cry

    p = &d;
    p->Cry( );    // 가상 함수가 아닐 때 : Animal Cry => 정적 바인딩
                  // 가상 함수일 때 : Dog Cry => 동적 바인딩
}