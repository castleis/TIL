#include <iostream>
using namespace std;

/*
Default Parameter (기본 파라미터)
- 정의 : 파라미터의 기본값을 지정할 수 있음.
        함수에 전달된 인자가 없는 경우, 파라미터의 기본값으로 컴파일러가 자동으로 처리함.
- 주의사항
1) 반드시 뒤에서부터 기본값을 지정해야 함.
2) 선언과 구현(정의)를 분리해서 작성하는 경우, 반드시 기본 파라미터는 선언부에 작성되어야 함.
*/
int add(int a, int b, int c = 0, int d = 0); // 선언

int main()
{
    cout << add(10, 20, 30, 40) << endl;
    cout << add(10, 20, 30) << endl;
    //      add(10, 20, 30, 0)

    cout << add(10, 20) << endl;
    //      add(10, 20, 0, 0)
}

// 주석을 통해서 기본 파라미터가 지정되어 있는 경우를 표현하는 경우가 많음.
int add(int a, int b, int c /* =0 */, int d /* =0 */) // 정의
{
    return a + b + c + d;
}

#if 0
int add(int a, int b, int c, int d)
{
    return a + b + c + d;
}

int main()
{
    cout << add(10, 20, 30, 40) << endl;
    cout << add(10, 20, 30, 0) << endl;
    cout << add(10, 20, 0, 0) << endl;
}
#endif