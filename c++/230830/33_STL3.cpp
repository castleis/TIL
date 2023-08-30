#include <iostream>
using namespace std;

#include <vector>

#include <algorithm>
// => STL에서 컨테이너를 대상으로 검색/정렬 등의 연산을 수행하는 일반 함수 집합 => 알고리즘

#if 0
int main()
{
    vector<int> x = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Past the end => 검색에서 "실패의 의미"로 사용됨.
    auto p = find(begin(x), end(x), 5);   // x에서 5를 찾기
    if (p != end(x)) {
        cout << *p << endl;
    } else {
        cout << "찾지 못함 ㅠㅠ" << endl;
    }
}
#endif

#if 0
// C++ 알고리즘에서 정책을 전달하기 위해서는 함수의 인자로 함수 포인터를 전달해야 함.
// 하지만, 인라인 함수라고 하더라도 함수 포인터를 통해 호출하면 인라인 최적화가 불가능 ㅜㅜ
// => 함수 객체(Functor)를 통해 해결!
bool cmp1(int a, int b) { return a > b; }  // 내림차순 정렬을 위한 정책
bool cmp2(int a, int b) { return a < b; }  // 오름차순 정렬을 위한 정책

int main()
{
    vector<int> x = { 1, 3, 5, 7, 9 ,2, 4, 6, 8, 10 };

    // 내림차순 정렬
    sort(begin(x), end(x), cmp1);
    for (auto e : x) {
        cout << e << endl;
    }
    // 오름차순 정렬
    sort(begin(x), end(x), cmp2);
    for (auto e : x) {
        cout << e << endl;
    }
    // 하지만... cmp 함수들이 너무 많이 호출되고 있음;;
}
#endif

bool cmp1(int a, int b) { return a > b; }  // 내림차순 정렬을 위한 정책
bool cmp2(int a, int b) { return a < b; }  // 오름차순 정렬을 위한 정책

class Cmp1 {
public:
    inline bool operator()(int a, int b) const
    {
        return a > b;
    }
};

int main()
{
    vector<int> x = { 1, 3, 5, 7, 9 ,2, 4, 6, 8, 10 };

    Cmp1 cmp;
    sort(begin(x), end(x), cmp);
    //                    Cmp cmp
    // 함수 포인터를 정책으로 전달하면 인라인 최적화가 불가능
    // 하지만 함수 객체를 정책으로 전달하면 인라인 최적화가 가능


    // C++11, 함수 객체를 만드는 새로운 문법이 도입됨
    //  : Lambda Expression (람다 표현식)
    //  => 실행 가능한 코드 조각을 참조하는 기술
    //  => C++11, 익명의 함수 객체를 생성하는 문법
    sort(begin(x), end(x), [](int a, int b) -> bool {
        return a > b;
    });
    // 또한, 반환 타입을 생략할 수 있음.
    sort(begin(x), end(x), [](int a, int b) {
        return a > b;
    });

    for (auto e : x) {
        cout << e << endl;
    }

}
/*
위의 람다 표현식을 컴파일러가 클래스를 직접 만들고 객체를 생성해서 전달해줌.
class __Lambda {
public:
    bool operator()(int a, int b) const
    { return a > b; }
};
sort(begin(x), end(x), __Lambda());
*/