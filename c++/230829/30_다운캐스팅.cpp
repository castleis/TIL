#include <iostream>
using namespace std;

class Animal{
public:
    virtual ~Animal() {}
};

class Dog : public Animal {
    int color = 42;
public:
    int GetColor() const { return color; }
};

int main()
{
    Animal a;
    // Upcasting
    Dog d;
    Animal* p = &d;

    // p가 Dog라면, GetColor()로 color를 출력하고 싶으면 다운캐스팅을 수행해야 함.
    // : 부모의 포인터(참조) 타입을 자식의 포인터(참조) 타입으로의 암묵적인 변환이 허용되지 않음.
    // => 명시적인 캐스팅이 필요함.
    //      - static_cast을 사용.
    //         : 하지만 잘못된 타입이 지정되어도 캐스팅이 수행됨.
    // 1) 따라서 p가 Dog 타입인지 조사해야 함.
    // => RTTI (Run Time Type Information) --> 개념적으로만 알아두기... 쓰지 말라... @.@...(타입에 의존하면 확장성이 구림, 쓰는 사람은 시말서 각)
    // typeid 연산자를 통해 타입의 정보를 담은 구조체를 얻을 수 있음.
    //      : type_info
    //          => 가상함수 테이블에 저장됨.
    //      1) typeid(클래스)
    //      2) typeid(객체)   가 같은지 확인함으로서 알 수 있음.

#if 0
    if (typeid(Dog) == typeid(*p)) {
        Dog* pDog = static_cast<Dog*>(p);
        cout << pDog->GetColor() << endl;
    } else {
        cout << "It's not Dog type" << endl;
    }
#endif
    Dog* pDog = dynamic_cast<Dog*>(p);
    /*
    **dynamic_cast**
    -> 실행 시간에 타입을 조사함.
       잘못된 타입인 경우, nullptr을 반환함.
       => 다운 캐스팅
    */
    if (pDog) {
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }
}
/*
C++ 다운 캐스팅 정리
1) static_cast
    : 컴파일 타임에 캐스팅을 수행 -> 오버헤드가 없음
      But 잘못된 타입을 감지할 수 없음.
      따라서 타입이 확정되어 있는, "실패 가능성이 없는 다운 캐스팅에서 이용"
2) dynamic_cast
    : 실행시간에 캐스팅을 수행
      잘못된 타입의 경우 nullptr을 반환함.
      또한 가상함수 테이블에 존재하는 타입 정보를 이용함.
        -> 가상함수 테이블이 없는 경우, 컴파일 오류가 발생
      즉, 실패 가능성이 존재하는 다운 캐스팅에서 이용
*/

/*
C++ 캐스팅 연산자 4가지
1) static_cast
2) reinterpret_cast
3) const_cast
4) dynamic_cast
*/