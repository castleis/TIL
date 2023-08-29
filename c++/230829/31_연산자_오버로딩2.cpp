#include <iostream>
using namespace std;

namespace xstd {
class ostream {
public:
    // 연산자 재정의 및 오버라이딩
    ostream& operator<<(int n)
    {
        printf("%d\n", n);
        return *this;
    }
    ostream& operator<<(double d)
    {
        printf("%lf\n", d);
        return *this;
    }
};
ostream cout;
}

int main()
{
    int n = 42;
    double d = 3.14;

    cout << n << d;
    // cout.operator<<(n).operator<<(d)  => 체이닝
    // 체이닝을 위해서는 멤버 함수가 자기 자신을 참조하여 반환
    // => ostream& 을 참조, *this를 반환..
}

#if 0
int main()
{
    int n = 42;
    // cout << n;
    // == cout.operator<<(n);  멤버 함수의 연산자 (operator)를 이용하여 n의 값이 전달되고 있는 것
    // 즉, 연산자 재정의

    xstd::cout.operator<<(n);

    double d = 3.14;
    // cout << d;
    xstd::cout << d;
}
#endif