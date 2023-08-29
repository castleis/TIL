#include <iostream>
#include <vector> // 컨테이너
using namespace std;

// Upcasting
// 2) 동종을 보관하는 컨테이너
class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
    vector<Animal*> animals;

    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
    animals.push_back(new Cat);
    animals.push_back(new Dog);
    animals.push_back(new Cat);
}