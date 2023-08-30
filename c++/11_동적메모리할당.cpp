#include <iostream>
using namespace std;

/*
C++은 동적 메모리 할당의 기능을 함수(malloc)가 아닌 연산자를 통해서 제공
=> new, delete

new는 타입을 전달하면, 전달된 타입의 크기 만큼 할당되고, 해당 타입의 주소 타입이 반환됨.
=> 명시적인 캐스팅이 필요하지 않음.
<함수의 경우>
- malloc : void* malloc(size_t size); => 메모리의 크기를 인자로 받고, void*를 반환, 즉 C++에서 명시적 캐스팅이 필요
- free : void* free(void* ptr); => 할당받은 메모리의 주소를 전달받고 해지함. 인자로 NULL이 전달될 경우, 아무일도 수행하지 않음.

delete 연산자를 통해 new를 통해 할당된 메모리를 해지할 수 있음. NULL이 전달되었을 때, 아무일도 수행하지 않음.

new int[size]를 통해 연속된 메모리를 할당할 수 있음.
연속된 메모리를 해지할 때는 delete가 아닌 delete[] 연산자를 이용해야 함.
*/

#include <cstdlib>   // malloc, free

int main()
{
    int* p2 = new int[1000];
    p2[0] = 10;
    p2[999] = 1000;
    cout << p2[999] << endl;        // 1000

    delete[] p2;   // 연속된 메모리 해지!!

    int* p = static_cast<int*>(malloc(sizeof(int) * 1000));
    p[0] = 10;
    p[999] = 1000;
    cout << p[999] << endl;         // 1000
    free(p);
}