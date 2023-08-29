#include <iostream>
using namespace std;


/*
1. 가상함수를 사용하면, 가상함수가 존재하는 클래스의 객체 크기가 포인터 크기만큼 늘어남.
    => 가상함수 테이블을 참조하는 포인터
2. 가상함수 테이블의 크기는 가상 함수의 개수만큼 유지됨.
*/
class Shape {
    int x;
    int y;
public:
    virtual void Draw() const {}
    virtual Shape* Clone() {}
};

class Rect : public Shape {
    int width;
public:
    void Draw() const override {}
};

int main()
{
    Shape s;
    Rect r;

    Shape* p = &s;
    p->Draw();
    // => (p->vfptr)[0]();
    // => 가상함수 테이블의 첫번째를 호출

    p = &r;
    p->Draw();
    // (p->vfptr[0])();
    p->Clone();
    // (p->vfptr[1])();

}

#if 0
int main()
{
    Shape s;
    cout << sizeof(s) << endl;   // -> virtual : 8 -> 16

    Rect r;
    cout << sizeof(r) << endl;   // -> virtual : 12 -> 24

}
#endif