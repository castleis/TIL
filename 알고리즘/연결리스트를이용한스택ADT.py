# 연결리스트를 이용한 스택의 ADT 구현

#연결리스트를 담을 Node 클래스
# 노드의 값은 item, 다음 노드를 가리키는 포인터는 next로 정의
class Node:
    def __init__(self, item, next):
        self.item = item
        self.next = next
    
# stack 은 각각 이전 값을 가리키는 연결 리스트로 구현되어 있으며 가장 마지막 값은 last 포인터가 가리킨다.
class Stack:
    def __init__(self):
        self.last = None
    
    # 연결리스트에 요소를 추가하면서 가장 마지막 값을 next로 지정하고 포인터인 last는 가장 마지막으로 이동시킨다
    def push(self,item):
        self.last = Node(item, self.last)
    
    # 가장 마지막 아이템을 끄집어내고 last 포인터를 한 칸 앞으로 전진시킨다. (이전에 추가된 값을 가리키게 함)
    def pop(self):
        item = self.last.item
        self.last = self.last.next
        return item

stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)
stack.push(5)

for _ in range(5):
    print(stack.pop())