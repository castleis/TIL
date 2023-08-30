#include <iostream>
using namespace std;

/*
1. C의 const와 C++의 const는 차이가 있음
    - C의 상수는 런타임 상수
    - C++의 상수는 컴파일 타임 상수 / 런타임 상수가 될 수 있음.

2. 상수 표현식
    - 컴파일러는 컴파일 시간에 미리 계산할 수 있는 것은 계산을 수행
    - C/C++에서 배열의 크기는 상수 표현식이 필요
*/

/*
C++11, constexpr
 : 상수 표현식에 저장할 수 있는 키워드
 const와의 차이점
 : const는 컴파일 시간 상수 뿐 아니라 실행시간에 변경된 변수로도 초기화할 수 있지만
   constexpr은 컴파일 시간 상수만 가능함.

컴파일 타임 상수 : 상수의 초기값이 컴파일 시간에 결정된다면, 컴파일 상수
               컴파일 타임 상수는 상수 표현식
               컴파일 타임 상수에 대한 접근은 메모리로부터 읽는 연산이 필요하지 않음.
런타임 상수 : 상수의 초기값이 컴파일 시간에 결정될 수 없다면, 변수이지만 실행 시간에 값을 변경할 수 없는 런타임 상수
           런타임 상수는 상수 표현식이 아니기 때문에, 상수 표현식이 필요한 배열의 크기를 지정하는 용도로 사용할 수 없음.
           런타임 상수에 대한 접근은 메모리로부터 값을 읽어야 함.
*/
int main()
{
    // 컴파일 상수 => 컴파일 시간에 해당 값들이 결정 됨. (각각 10으로)
    const int c1 = 10;
    constexpr int c2 = 10;

    int n = 0;
    cin >> n;

    const int c3 = n;
    // constexpr int c4 = n;   // Error. n이 컴파일 이후 입력받는 값이기 때문
}