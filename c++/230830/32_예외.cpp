#include <iostream>
using namespace std;

// 1. 반환값을 통해서 함수의 성공/ 실패를 전달하는 경우가 많음.
// 2. 반환 값을 통한 오류 처리의 문제점
//    1) 연산의 결과가 오류인지, 결과인지 구분하기 모호할 수 있음.
//      ex) atoi (#include <cstdlib>)
//          원인 : 결과를 전달할 때도 return
//                 오류를 전달할 때도 return
//    2) 실패 가능한 함수는 반드시 오류 체크를 해야함.
//          => 하지만 오류 처리를 강제할 수 없음.
// 3. 예외
//    결과는 return, 오류를 전달할 때는 return이 아닌 "throw"
//    함수를 수행했을 때, throw한 오류를 처리(catch)하지 않으면 실행시간에 비정상 종료됨.
//    하지만, 현대에는 코드 흐름을 분석하기에 깔끔하지 않고, 유지보수가 어려워짐에 따라 예외를 사용하는 것을 지양.

int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        throw -1;
        // 오류를 throw
    }

    return 0;
}

int main()
{
    // int result = OpenFile("a.txt");
    try {
        int result = OpenFile(nullptr);
        cout << result << endl;
    } catch (int& r) {
        cout << r << endl;
    }
}