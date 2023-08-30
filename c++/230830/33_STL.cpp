#include <iostream>
using namespace std;

/*
STL(Standard Template Library)
- 1998 : C++ 1차 표준안, STL 탄생

STL 구성요소 3가지
1) 컨테이너 : 데이터를 보관하기 위한 자료구조
    vector : 연속된 메모리의 동적 배열 / 선형 자료 구조
      list : 노드 기반의 선형 자료 구조
     deque : vector와 list 중간 형태의 선형 자료 구조
    이 외에도 map, set, unordered_map, unordered_set, stack, queue ...

2) 알고리즘 : 컨테이너의 요소를 검색/정렬/이진 탐색 연산 등을 제공하는 "일반 함수"

3) 반복자(Iterator) : 컨테이너의 요소를 참조하는 타입
*/

// 컨테이너
/*
1) 템플릿 기반 
    - 타입에 상관없이 다양한 자료구조를 사용할 수 있음.
2) 멤버 함수의 이름이 유사함. -> 직관적
    => 자료구조의 전환을 쉽게 수행할 수 있음.
    삽입 : push_front     push_back
    제거 : pop_front      pop_back
    참조 :   front          back
3) 데이터를 참조하는 연산과 제거하는 연산이 분리되어 있음.
    => 값이 아니라 요소의 참조를 반환할 수 있음.
*/
#include <vector>
#include <list>
#include <deque>

int main()
{
    vector<int> v = {10, 20, 30};
    list<int> l;
    deque<int> d;
}