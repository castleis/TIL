#클래스와 인스턴스
class Person():
    blood_color = 'red' # 클래스 변수
    population = 100 # 클래스 변수

    def __init__(self, name):
        self.name = name # 인스턴스 변수

print(type(Person)) # <class 'type'>
person1 = Person('지민')
john = Person('john')
print(isinstance(person1,Person)) # True
print(type(person1)) # <class '__main__.Person'>
print(person1.name) # 지민

person1.blood_color = 'blue'
print(person1.blood_color) # blue
print(john.blood_color) # red

print(john.name) # john
john.name = 'John Kim'
print(john.name) # John Kim

# 메서드
class Food:

    def talk(self):
        print('안녕')
    
    def eat(self, food):
        print(f'{food}를 냠냠')
person2 = Food()
person2.talk() # 안녕
person2.eat('피자') # 피자를 냠냠


# 매직 메서드
class Circle:

    def __init__(self,r):
        self.r = r
    
    def area(self):
        return 3.14 * self.r * self.r

    def __str__(self):
        return f'[원] radius : {self.r}'
    
    def __gt__(self, other):
        return self.r > other.r
c1 = Circle(10)
c2 = Circle(1)
print(c1, c2) # [원] radius : 10 [원] radius : 1
print(c1 > c2, c1 < c2) # True False

# 데코레이터
# 데코레이터 없이 함수 꾸미기
def hello():
    print("hello")
def add_print(original): # 데코레이팅 함수, 파라미터로 함수를 받는다.
    def wrapper(): # 함수 내에서 새로운 함수 선언
        print("함수시작") # 부가기능 -> original 함수를 꾸민다
        original()
        print("함수 끝") # 부가기능 -> original 함수를 꾸민다.
    return wrapper # 함수를 return 한다.
add_print(hello)() # 함수시작
                   # hello
                   # 함수 끝
print_hello = add_print(hello)
print(print_hello) # <function add_print.<locals>.wrapper at 0x1005f0940>

# 데코레이터를 활용하면
@add_print #add_print를 사용해서 print_hello()함수를 꾸며주도록 하는 명령어!
def print_hello():
    print("hello")
print_hello() # 함수시작
              # hello
              # 함수 끝

print(int) # <class 'int'>
print(str) # <class 'str'>

