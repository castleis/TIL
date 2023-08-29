#include <iostream>
using namespace std;

/*
C는 함수의 인자 타입이 다른 경우에도 동일한 이름의 함수를 여러개 만들 수 없음. 여러개의 다른 이름을 만듦.
C++은 동일한 이름의 함수를 여러개 만들 수 있음.
=> 함수의 이름은 동일하지만, 함수의 인자 정보(타입, 개수)가 다른 경우만 허용됨.
    "함수 오버로딩(Overloading)"
    : Name Mangling
    => 컴파일 시 함수 심볼의 이름이 함수의 식별자와 인자정보에 의해 결정됨.
    => extern "C"를 통해서 C++에서 C 컴파일러로 빌드된 함수를 호출하거나, C++ 컴파일러로 빌드된 함수를 C 프로그램에서 호출할 수 있음
*/
int square(int x) { return x*x; }
double square(double x) { return x*x; }
long long square(long long x) { return x*x; }

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
    cout << square(10000000000LL) << endl;
}
/*
1. 함수의 인자 정보가 동일하고, 반환 타입만 다른 경우 함수의 오버로딩은 허용되지 않음.
ex)
```cpp
int foo() {}
void foo() {}
```

2. 파라미터의 기본값을 지정하는 경우, 모호성 오류가 발생할 가능성이 있음.
=> 오버로딩과 파라미터 기본값의 문법은 같이 사용하지 않는 것이 좋음.
*/
void foo(int n = 100) { cout << "foo(int)" << endl; }
void foo() { cout << "foo()" << endl; }

int main()
{
    foo();   // 모호성 오류!
}