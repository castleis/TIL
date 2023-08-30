#include <iostream>
using namespace std;

class Plus {
public:
    // 함수 호출 연산자를 재정의할 수 있습니다.
    // => 인자와 반환 타입을 자유롭게 만들 수 있음.
    int operator()(int a, int b) const      // ()를 재정의
    {
        return a + b;
    }
};

int main()
{
    Plus plus;

    // 함수 객체, Functor
    cout << plus(10, 20) << endl;
    // plus.operator()(10,20)
    // plus는 함수가 아닌 객체
}