#include <iostream>
#include <vector>
using namespace std;

// Stack을 만들어봅시당~
// vector를 이용해서 한쪽으로 데이터를 추가하고, 한쪽으로 데이터를 제거하면 스택처럼 사용할 수 있음!

/*
상속을 통해 기존 클래스를 재사용할 수 있음. -> vector를 이용하여 Stack 구현
=> 
Adapter Pattern
: 기존 클래스의 인터페이스를 변경해서 새로운 클래스처럼 사용하는 설계 방법
문제점
: 부모가 제공하는 모든 인터페이스를 물려받음. -> 내가 정의하지 않은 vector의 모든 기능에 접근 가능
해결 방법
: 상속을 public이 아닌 private로 상속받기.
  private 상속 의도
    : 부모의 구현은 내부적으로 재사용하지만, 인터페이스(부모의 public 기능)는 물려받지 않겠다.
*/
#if 0
template <typename TYPE>
class Stack: private vector<TYPE> {
public:
    void push(const TYPE& n)
    {
        vector<TYPE>::push_back(n);
    }

    T& top()
    {
        return vector<TYPE>::back();
    }

    void pop()
    {
        return vector<TYPE>::pop_back();
    }
};
#endif

#include <deque>
// template <typename TYPE>
template <typename TYPE, typename C = deque<TYPE>>
class Stack{ 
    // 이처럼 포함을 사용하는 것이 더 효율적
    // 실제 C++의 스택이 아래와 같이 구현되어 있음.
    // vector<TYPE> v;
    C v;
public:
    void push(const TYPE& n)
    {
        v.push_back(n);
    }

    T& top()
    {
        return v.back();
    }

    void pop()
    {
        return v.pop_back();
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}