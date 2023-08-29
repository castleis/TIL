#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int a, int b)
        : x {a}
        , y {b}
    {
    }

    void Print() const
    {
        cout << "(" << x << "," << y << ")" << endl;
    }

    // 멤버함수 Add
    // Point Add(const Point& rhs) const   // 불필요한 복사 생성을 막기 위해 const reference로
    /*
    Point operator+(const Point& rhs) const
    {
        Point result { x + rhs.x, y + rhs.y };
        // Point result { this->x + rhs.x, this->y + rhs.y };
        return result;
    }

    // 멤버함수 Subplus
    Point operator-(const Point& rhs) const
    {
        Point result { x - rhs.x, y - rhs.y };
        return result;
    }
    */

    // 일반함수는 내부의 private에 접근할 수 없기 때문에 friend를 사용하여 private에 접근할 수 있도록 해줌.
    // friend Point Add(const Point& lhs, const Point& rhs);
    friend Point operator+(const Point& lhs, const Point& rhs);
    friend Point operator-(const Point& lhs, const Point& rhs);
};

// 일반 함수 Add
// Point Add(const Point& lhs, const Point& rhs)
Point operator+(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x + rhs.x, lhs.y + rhs.y };
    return result;
}

// 일반 함수 Subplus
Point operator-(const Point& lhs, const Point& rhs)
{
    Point result { lhs.x - rhs.x, lhs.y - rhs.y };
    return result;
}

/*
연산자 오버로딩
정의 : 객체를 대상으로 연산자를 사용하였을 경우, 약속된 이름의 멤버 함수 또는 약속된 이름의 일반 함수가 호출되는 문법

a + b
=> 멤버 함수) a.operator+(b)
=> 일반 함수) operator+(a, b)

a - b
=> 멤버 함수) a.operator-(b)
=> 일반 함수) operator-(a, b)
*/

int main()
{
    Point pt1 {10, 20};
    Point pt2 {100, 200};

    // pt1 + pt2 를 만들고 싶음.
    // 1) 멤버 함수 Add
    // Point result1 = pt1.Add(pt2);   // pt1은 this로 주소가 암묵적으로 전달됨, pt2는 인자로 전달
    // result1.Print();

    // 2) 일반 함수
    // Point result2 = Add(pt1, pt2);
    // result2.Print();

    // 더 간단히 표현할 수 없을까?
    Point result = pt1 + pt2;
    Point result2 = pt1 - pt2;
    result.Print();
    result2.Print();
    /*
    1) 먼저 멤버 함수에서 찾음
        => Point result = pt1.operator+(pt2);
    2) 없으면, 일반 함수에서 찾음.
        => Point result = oprator+(pt1, pt2);
    */

}