#include <iostream>
using namespace std;

namespace xstd {

class istream{
public:
    istream& operator>>(int& r)
    {
        scanf("%d", &r);
        return *this;
    }
    istream& operator>>(double& r)
    {
        scanf("%lf", &r);
        return *this;
    }

};

istream cin;

}

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
    int n;
    //cin >> n;
    cin.operator>>(n);      // -> call by reference

    cout << n << endl;
}