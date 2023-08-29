#include <iostream>
using namespace std;

class Car {
public:
    virtual void Start() { cout << "Car Start" << endl; }
};

class Sedan : public Car {
public:
    void Start() override final { cout << "Sedan Start" << endl; }
    // 이제부터 모든 Sedan은(자식 포함) 위의 Start 함수만 사용하도록 하고 싶음.
    // C++11, `final`
    //   : 멤버 함수에서 더이상 오버라이딩이 불가능
};

// final을 클래스에 지정한 경우, 더이상 상속이 불가능
class Avante final : public Sedan {
public:
    // void Start() override { cout << "Avante Start" << endl; } // => 컴파일 에러, 더이상 override할 수 없음.
};

// class Avante2 : public Avante {};

int main()
{
    Avante a;
    Car* p = &a;

    p->Start();
}