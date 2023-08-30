#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() const { cout << "Draw Image" << endl; }
};

// Image*의 역할을 수행하는 클래스 => "스마트 포인터"
template <typename T>   // Image 클래스만의 스마트 포인터가 아닌, 템플릿을 이용하여 범용성을 높여주기.
class Ptr {
    T* obj;
public:
    // 성능적인 측면에서 조금 더 느릴 수 있지만, inline화 하면 성능 차이도 없다.
    inline Ptr(T* p = nullptr)
        : obj { p }
    {

    }
    inline ~Ptr() { delete obj; }   // 소멸자가 호출될 때, 자동으로 메모리 해지가 될 수 있도록
                             // => 메모리 누수에 대한 문제점에서부터 조금 더 안전하다.
    inline Image& operator*() { return *obj; }     // 이 클래스가 포인터 참조연산을 할 수 있도록
    inline Image* operator->() { return obj; }
};

#if 0
// 2. 스마트 포인터를 사용할 때
int main()
{
    Ptr p { new Image };    // Ptr<Image> p { new Image }; 라고 하지 않아도
                            // 클래스 템플릿도 생성자의 인자를 통해 타입을 추론할 수 있음. (C++17)

    // 1. 포인터의 참조 연산
    (*p).Draw();
    // => (p.operator*()).Draw()
    // 결과는 Image의 reference가 나와야 한다.

    // 2.
    p->Draw();
    // => p.operator->()Draw(); => ?? 모양이 이상하다.
    // -> 컴파일러가 처리하는 형태: p.oprator->()->Draw();
}
#endif

#if 0
// 1. 스마트 포인터를 사용하지 않았을 때
int main()
{
    Image* p = new Image;

    (*p).Draw();
    p->Draw();

    delete p;  // !!반드시 메모리 해제를 진행해야 한다!!
}
#endif

/*
스마트 포인터를 직접적으로 만든다면, 멤버에 포인터를 사용해야 하는데
이는 얕은 복사 문제를 야기함. -> 복사 정책을 제공해야 함!

C++ 표준에서 이미 잘 만들어진 스마트 포인터를 제공함.
    : 자원의 소유권(Ownership)
1) shared_ptr
    : 참조 개수 기반

2) unique_ptr
    : 복사 금지 -> 독점
*/
#include <memory>
int main()
{
    shared_ptr<Image> p { new Image };
    p->Draw();
    (*p).Draw();

    shared_ptr other = p;

    unique_ptr<Image> p2 { new Image };
    p2->Draw();
    (*p2).Draw();

    cout << p2 << endl;
    // unique_ptr<Image> other2 = p2;  // Error, 복사가 금지되어 있음.
    // =>
    unique_ptr<Image> other2 = std::move(p2);  // 소유권 이전을 통해 해결
    cout << other2 << endl;
    cout << p2 << endl;
}