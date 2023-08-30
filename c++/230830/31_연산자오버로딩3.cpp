#include <iostream>
using namespace std;

class Point {
    int x;
    int y;
public:
    Point(int a, int b)
        : x { a }
        , y { b }
    {

    }

    friend ostream& operator<<(ostream& os, const Point& pt);
};


ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;
}

int main()
{
    Point pt { 10, 20 };
    cout << pt;

    /*
    멤버 함수 : 클래스의 설계자만 제공할 수 있음.
    cout.operator<<(pt);
    cout.operator<<(const Point& pt);

    */
}