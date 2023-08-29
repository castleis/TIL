#include <iostream>
using namespace std;

/*
1. 원인
Car -------------- <> Camera
    : Car 클래스와 Camera 클래스는 강한 결합이 형성되었음.
     "Car 클래스가 Camera 구체적인 타입에 의존"

2. 해결방법
    : 약한 결합 / 느슨한 결합
    DIP(Dependency Inversion Principle, 의존 관계 역전의 원칙)
        : 구체적인 타입에 의존하는 것이 아니라 추상 클래스나 인터페이스에 의존해야 한다.
        => "교체가능한 유연한 설계"

    1) 카메라의 제작자와 자동차의 제작자는 사용방법(멤버 함수)을 약속
        => 인터페이스 / 프로토콜
        C++에서 인터페이스는 순수 가상함수만을 가지는 부모 클래스를 의미
    
*/
class BlackBox {
public:
    virtual ~BlackBox() {}

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

/*
    2) 자동차의 제작자는 인터페이스를 이용하는 형태로 코드를 작성
*/
class Car {
    BlackBox* camera;
public:
    Car(BlackBox* p)
        : camera { p }
    {

    }
    void Go()
    {
        camera->StartRecording();
        cout << "Car go" << endl;
        camera->StopRecording();
    }
};

/*
    3) 모든 카메라의 제작자는 BlackBox의 인터페이스를 구현
        : "인터페이스를 상속한다." 라고 하지 않고, "인터페이스를 구현한다." 라고 함.
    - Java
        class Car extends BlackBox {} - 상속
        class Car implements BlackBox {} - 구현
*/
class Camera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "Start Recording" << endl;
    }
    void StopRecording() override
    {
        cout << "Stop Recording" << endl;
    }
};
class FHDCamera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "[FHDCamera]Start Recording" << endl;
    }
    void StopRecording() override
    {
        cout << "[FHDCamera]Stop Recording" << endl;
    }
};

int main()
{
    Camera camera;
    Car car { &camera };

    // 새로운 형태의 카메라가 등장해도 기존 코드를 수정할 필요가 없음.
    FHDCamera camera2;
    Car car { &camera2 };

    car.Go();
}