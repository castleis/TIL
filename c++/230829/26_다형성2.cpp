#include <iostream>
using namespace std;

class Animal {
    public:
        int GetAge() const {return 10;}
};

class Dog : public Animal {

};


class Cat : public Animal {

};

// Upcasting
// 1. 동종을 처리하는 함수를 만들 수 있음.
void PrintAge(const Animal& a)
{
    cout<<a.GetAge()<<endl;
};

int main()
{
	Dog d;
    PrintAge(d);

    Cat c;
    PrintAge(c);
}