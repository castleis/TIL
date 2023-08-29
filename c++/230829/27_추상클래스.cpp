#include <iostream>
#include <vector>
using namespace std;

/*
도입 : [26_다형성9.cpp]에서 Shape는 추상 클래스로서만 사용 되었음.
    - 부모의 입장에서 Clone / Draw 함수는 구현을 제공할 필요가 없음.
    - 하지만 자식 클래스는 반드시 Clone / Draw 함수를 오버라이딩해서 구현을 제공해야 함.
=> 순수 가상 함수(Pure virtual function)
    : 구현을 하지 않고 이름만(?) 생성해두는 것
      순수 가상 함수를 1개 이상 가지는 클래스는 객체를 생성할 수 없음.
      => 즉, 추상 클래스(abstract class)가 됨.
*/

class Shape {
public:
    virtual ~Shape() {}

    // virtual Shape* Clone() const
    // {
    //     return new Shape(*this);
    // }
    // virtual void Draw() const { cout << " Shape Draw " << endl; }

    // 순수 가상 함수
    virtual Shape* Clone() const = 0;
    virtual void Draw() const = 0;
};

// 자식 클래스가 부모가 제공하는 순수 가상 함수를 구현하지 않으면(overriding 하지 않으면)
// 자식 클래스도 추상 클래스가 됨.
class Rect : public Shape {
public:
    Shape* Clone() const override { return new Rect(*this); }
    void Draw() const override { cout << "Rect Draw" << endl; }
};

int main()
{
    // Shape s;
    // => 순수 가상 함수는 객체 생성이 불가능 
}