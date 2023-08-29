#include <iostream>
using namespace std;

// 1) 부모 클래스의 멤버 함수가 가상 함수이면, 자식이 재정의한 멤버 함수도 가상함수
// 2) virtual 문제점
//   - 부모의 멤버 함수가 가상 함수가 아니면, 자식이 오버라이딩 하면 안됨.
//   - 오버라이딩을 수행할 때, 자식이 잘못된 이름을 사용할 경우(오타 등, Cry => Cryy로 잘못 작성한 경우), 오류가 발생하지 않음.
//      => C++11, `override`
//         1) 오버라이딩한 부모의 멤버 함수가 가상 함수가 아니면, 컴파일 오류가 발생
//         2) 부모가 제공하지 않는 멤버 함수를 오버라이딩 한 경우, 컴파일 오류가 발생
//       결론 : 자식이 재정의하는 멤버 함수에는 반드시 override를 지정해야 함.

class Animal {
public:
    virtual void Cry() const {cout<<"Animal Cry"<<endl;}
};

class Dog : public Animal {
public:
    void Cry() const override {cout<<"Dog Cry"<<endl;}             // 1
    // virtual void Cry() const override {cout<<"Dog Cry"<<endl;}  // 2
    // 1번으로 적는 것이 보편적 
    // => 부모 멤버 함수가 가상함수이기 때문 + override 키워드를 사용하는 것 자체가 가상 함수라는 의미
};

int main()
{
    Animal* p = new Dog;
    p->Cry();

    Dog d;
    Animal& r = d;
    r.Cry();
}