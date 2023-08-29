#include <iostream>
using namespace std;

#if 0
int square(int x) { return x * x; }
double square(double x) { return x * x; }
long long square(long long x) { return x * x; }
#endif

/*
위와 같이 함수의 인자/반환 타입만 다르고, 구현(알고리즘)이 동일할 때, 컴파일 시간에 코드를 생성할 수 있음.
=> Template
장점: 적은 코드로 모든 타입에서 동작하는 일반적인 함수를 정의할 수 있습니다.
단점:
  1) 타입에 따라서 코드를 생성하기 때문에,
     템플릿으로 인해 전체적인 코드 메모리 사용량이 증가할 수 있습니다.
  => 인라인 최적화가 가능하다면, 메모리 사용량을 최적화할 수 있습니다
  2) 템플릿은 다른 소스 파일로 분리가 불가능합니다.
     헤더를 통해서 모든 구현이 제공되어야 합니다
  3) 컴파일 시간에 코드를 생성하기 때문에,
     컴파일 시간이 증가될 수 있습니다.
*/

#if 0
// 함수 템플릿
template <typename TYPE>
inline TYPE square(TYPE x) { return x * x; }

int main()
{
    cout << square(10) << endl;             // TYPE -> int
    cout << square(3.14) << endl;           // TYPE -> double
    cout << square(100000000LL) << endl;    // TYPE -> long long
}
#endif

template <typename T1, typename T2>         // 타입 파라미터
void foo(T1 a, T2 b) {}                     // 값 파라미터

int main()
{
    // 템플릿은 명시적으로 타입을 전달할 수 있음
    foo<long, double>(10, 100);
    // T1 -> long, T2 -> double

    foo(10, 3.14);
    // == foo<ing, double>(10, 3.14)
    //       ------------  --------
    //          타입 인자      값 인자
    // T1 -> int, T2 -> double
}