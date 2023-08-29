#include <iostream>
using namespace std;

// 정적바인딩, 동적바인딩 및 가상 함수 테이블을 이해하기

#if 0
class AAA {
public:
    void foo() { cout << "AAA foo" << endl; }
};
class BBB {
public:
    void goo() { cout << "BBB goo" << endl; }
};

int main()
{
    AAA aaa;
    BBB* p = reinterpret_cast<BBB*>(&aaa);
    p->goo();           // BBB goo가 호출됨. (정적 바인딩, p의 타입이 BBB이기 때문) => BBB::goo(p);
}
#endif

#if 1
class AAA {
public:
    virtual void foo() { cout << "AAA foo" << endl; }
};
class BBB {
public:
    virtual void goo() { cout << "BBB goo" << endl; }
};

int main()
{
    AAA aaa;
    BBB* p = reinterpret_cast<BBB*>(&aaa);
    p->goo();           // AAA 가상함수 테이블을 참조하고 있고, foo()가 해당 가상함수 테이블의 첫번째이기 때문에 AAA foo가 출력
}
#endif