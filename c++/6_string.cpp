/*
C++은 문자열 타입이 제공됨.
std::string
1) 연산자를 통해서 문자열의 비교/복사/연결 등의 작업을 직관적으로 수행할 수 있음.
2) 메모리 관리를 자동으로 수행
    => 미정의 동작 위험성이 적음
    => 짧은 문자열의 경우 내부적으로 메모리를 할당하지 않고 스택 메모리를 사용하기 때문에 성능도 최적화 되어있음.(SSO)
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string s1 = {"hello"};
    std::string s2 {"hello"};

    if (s1 == s2){
        cout << "Same" << endl;
    } else {
        cout << "Not same" << endl;
    }

    std::string other { s1 };
    cout << other << endl;

    other += " world!";
    cout << other << endl;
}