#include <iostream>
using namespace std;

/*
함수 포인터
  : 함수를 가르키는 포인터 변수
함수의 타입은 [함수의 인자와 반환 타입](함수의 시그니처)에 의해서 결정됨.
=> 함수의 시그니처가 동일한 함수는 같은 타입

*/

int add(int a, int b)   // 함수 type : int(int,int)
{
    return a + b;
}
int sub(int a, int b)   // 함수 type : int(int,int)
{
    return a - b;
}
// 함수 포인터를 이용하여 함수의 주소를 담을 수 있구..
int main()
{
    // 함수 포인터 타입 만드는 방법
    int (*fp)(int, int) = nullptr;
    /*
    1) (*fp) : fp는 포인터 타입.
               포인터가 참조하는 타입은?
    2) (*fp)(int, int)
        : 포인터가 참조하는 타입은 (int, int)인자를 받는 함수
          함수의 반환 타입은?
    3) int (*fp)(int, int)
        : 함수의 반환 타입은 int
    함수 포인터 타입 : * --------------> int(int,int)
    */

    // C++에서 주로 사용하는 표현 방식
    fp = &add;
    int result = (*fp)(10,20);
    cout << result << endl;

    // C에서 주로 사용하는 표현 방식
    fp = sub;                // 그냥 대입 가능
    result = fp(100, 20);    // 그냥 대입 가능
    cout << result << endl;
}

/**/
// endl은 함수

namespace xstd{
class ostream{

};
ostream* endl(ostream& os)
{
    return os << '\n';
}

}