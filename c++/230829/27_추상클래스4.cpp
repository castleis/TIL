#include <iostream>
using namespace std;

/*
인터페이스의 문제점
- 인터페이스에 새로운 기능을 추가하기 어려움.
  인터페이스에 새로운 기능이 추가되면, 기존에 인터페이스를 구현하는 모든 클래스가 해당 기능을 제공해야 함.
  제공하지 않는다면, 추상 클래스가 되어 객체를 생성할 수 없음.

- 이를 해결하고자 인터페이스의 정의가 변경됨.
    => 현대적인 객체지향 설계에서는 인터페이스에 기본 구현을 제공하는 것이 가능
       따라서 인터페이스에 새로운 기능을 추가할 때, 기본 구현을 제공하는 것이 좋음.
            => Java 8 : defender method
*/

class MP3 {
public:
    virtual ~MP3() {}
    virtual void Play() = 0;
    virtual void Stop() = 0;
    
};