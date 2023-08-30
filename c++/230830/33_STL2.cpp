#include <iostream>
using namespace std;

/*
반복자 : 배열에서 포인터의 개념과 유사

C++에서 선형 자료구조의 구간은
    [begin, end)  => "반개 구간"
    begin : 시작 위치
    end : 끝 다음 위치 (Past the end)
*/

#if 0
void PrintArray(int* begin, int* end) {
    while (begin != end) {
        cout << *begin << endl;
        ++begin;
    }
}

int main()
{
    //          p1             p2
    //           |             |
    int x[5] = { 1, 2, 3, 4, 5 };
    PrintArray(x, x+5);

    int* p1 = x;        // &x[0]
    int* p2 = x + 5;    // Past the end
}
#endif

#include <vector>
#include <list>
#include <deque>

#if 0
int main()
{
    vector<int> v = { 10, 20, 30 };
    // list<int> v = { 10, 20, 30 };
    // deque<int> v = { 10, 20, 30 };

    auto p1 = v.begin();  // p1 : 시작 위치를 가리키는 반복자
    auto p2 = v.end();    // p2 : 끝 다음 위치(past the end)를 가리키는 반복자

    while (p1 != p2) {
        cout << *p1 << endl;
        ++ p1;
    }
}
#endif

// 컨테이너(vector, list, deque)가 제공하는 멤버 함수(.begin(), .end())를 통해 반복자를 꺼내는것 보다
// 일반 함수 begin/end를 사용하는 것이 더 좋음.
// => 일반 배열도 반복자의 개념으로 사용할 수 있음.
#if 0
int main()
{
    int v[] = { 10, 20, 30 };

    auto p1 = begin(v);  // begin, end : 일반 함수
    auto p2 = end(v);    // 즉, 일반적인 배열 타입에도 사용할 수 있다.

    while (p1 != p2) {
        cout << *p1 << endl;
        ++ p1;
    }
}
#endif

// C++은 반복자를 통해서, 모든 컨테이너를 대상으로 동작하는 일반적인 함수를 제공할 수 있음.
// => "알고리즘"의 개념
// [컨테이너] ------>  [반복자] -------> [알고리즘(일반함수)]
template <typename T>               // 템플릿을 이용함으로
void PrintArray(T begin, T end)     // 일반 배열과 컨테이너들이 모두 사용할 수 있는 함수
{
    while (begin != end)
    {
        cout << *begin << endl;
        ++begin;
    }
}

int main()
{
    // int x[3] = { 10, 20, 30 };    // 일반 배열
    vector<int> x = { 10, 20, 30 };
    vector<int>::iterator p = begin(x);   // 
                                 
    PrintArray(begin(x), end(x));
}