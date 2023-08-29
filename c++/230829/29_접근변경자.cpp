#include <iostream>
#include <string>
using namespace std;

class Base {
private:
    string name;
    int age;
public:
    string GetName() const { return name; }
    int GetAge() const { return age; }
};

// class User : public Base {
//          --------
//         접근 변경자
/*
          public 상속
<부모 영역>          <자식 영역>
 protected --------> protected
  public   -------->  public
         protected 상속
<부모 영역>          <자식 영역>
 protected --------> protected
  public   --------> protected
          private 상속
<부모 영역>          <자식 영역>
 protected -------->  private
  public   -------->  private

* protected, private 상속은 부모와 자식간의 is-a 관계가 성립되지 않음.
    => Upcasting이 불가능
       다형성, 추상 클래스 등이 적용되지 않음.
*/
class User : protected Base {

};

int main()
{
    User user;
    // user.GetName();
    // user.GetAge();
}