#include <iostream>
#include <vector>
using namespace std;

/*
1. 각 도형의 클래스를 설계
2. 부모 클래스 => 동종을 보관하는 컨테이너
3. 자식 클래스의 공통의 기능을 부모 클래스의 포인터/참조를 통해서 이용하기 위해서는 해당 특징이 부모로부터 비롯되어야 함.
     => 그래야 해당 기능을 부모의 포인터(참조)를 통해서 이용할 수 있음.
     => LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
         -> 자식 클래스는 부모 클래스도 대체할 수 있어야 한다.
         "자식의 공통 기능이 부모로부터 비롯되어야 한다."
4. 자식이 재정의하는 모든 멤버 함수는 반드시 가상 함수여야 함.
5. 반드시 부모의 소멸자는 가상이어야 함.
6. 다형성은 OCP를 만족
    : OCP (Open Close Principle, 개방 폐쇄 원칙)
      확장에는 열려있고, 수정에는 닫혀 있어야 한다.
      "새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다."
*/

class Shape {
public:
    virtual ~Shape() {}
    virtual void Draw() const { cout << " Shape Draw " << endl; }
};
class Rect : public Shape {
public:
    void Draw() const { cout << " Rect Draw " << endl; }
};

class Circle : public Shape {
    void Draw() const { cout << " Circle Draw " << endl; }
};
class Triagle : public Shape {
    void Draw() const { cout << " Triagle Draw " << endl; }
};

int main()
{
    vector<Shape*> shapes;

    while ( 1 ) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2){
            shapes.push_back(new Circle);
        } else if (cmd == 3){
            shapes.push_back(new Triagle);
        } else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
                /*
                            Rect --> Rect::Draw();
                 Draw() --> Circle --> Circle::Draw();
                            Triagle --> Triagle::Draw();
                 => 다형성(Polymorphism)
                */
            }
        } else if (cmd == 0){
            break;
        }
    }
    for (auto e : shapes) {
        delete e;
    }
}

/*
UNIX / Linux : 모든 것은 파일
    : VFS(Virtual File System)
Write() --> 일반 파일 -> 파일에 저장
            디바이스 파일 -> 디바이스 제어
            네트워크 파일 -> 패킷 전송
            ...
*/