#include <iostream>
#include <vector>
using namespace std;

/*
* 리팩토링(Refactoring), 마틴 파울러
정의 : 코드의 기능을 변경하지 않고, 구조를 개선하는 작업
    코드의 유지보수성을 떨어뜨리는 요소 => 냄새... 제거하자
* Replace type code with polymorphism
*/
class Shape {
public:
    // int type;
    virtual ~Shape() {}

    virtual Shape* Clone() const
    {
        return new Shape(*this);
    }

    virtual void Draw() const { cout << " Shape Draw " << endl; }
};
class Rect : public Shape {
public:
    // Rect() {type = 1;}
    Shape* Clone() const override
    {
        return new Rect(*this);
    }
    void Draw() const { cout << " Rect Draw " << endl; }
};

class Circle : public Shape {
public:
    // Circle() {type = 2;}
    Shape* Clone() const override
    {
        return new Circle(*this);
    }
    void Draw() const { cout << " Circle Draw " << endl; }
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
        } else if (cmd == 8){
            cout << "몇번째 도형?";
            int index;
            cin >> index;

            /*
            이 코드의 문제점 : 새로운 도형이 추가될 때마다, 아래 코드가 수정되어야 함.
            => OCP를 충족하지 않음.
            if (shapes[index]->type == 0) {  // Rect

            } else if (shapes[index]->type==1) {  // Circle

            }
            */
           // 대신 Clone()을 사용
           Shape* copy = shapes[index]->Clone();
           shapes.push_back(copy);
        } 
        else if (cmd == 9) {
            for (auto e : shapes) {
                e->Draw();
            }
        } else if (cmd == 0){
            break;
        }
    }
    for (auto e : shapes) {
        delete e;
    }
}