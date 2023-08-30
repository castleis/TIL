#include <iostream>
using namespace std;

int main()
{
    int* p1 = static_cast<int*>(malloc(sizeof(int)));
    // malloc로 할당된 메모리에 쓰레기값을 가짐.
    free(p1);

    int* p2 = new int;
    // 마찬가지로 쓰레기값을 가짐.
    delete p2;

    // new는 Direct Initialization을 통해서 초기화할 수 있음.
    int* p3 = new int(10);
    cout << *p3 << endl;
    delete p3;

    int* p4 = new int { 10 };
    cout << *p4 << endl;
    delete p4;

    int* p5 = new int[3] { 10, 20, 30 };
    cout << p5[0] << ", " << p5[2] << endl;
    delete[] p5;
}