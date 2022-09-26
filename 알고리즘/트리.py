# 포화 / 완전 이진 트리
'''
4
1 2 1 3 3 4 3 5
'''
def preorder(n):
    if n:
        print(n, end = ' ')
        preorder(ch1[n])
        preorder(ch2[n])

def inorder(n):
    if n:
        inorder(ch1[n])
        print(n, end = ' ')
        inorder(ch2[n])

def postorder(n):
    if n:
        postorder(ch1[n])
        postorder(ch2[n])
        print(n, end=' ')


# E = int(input())   # 정점의 개수
# arr = list(map(int,input().split()))    # 정점의 관계
# V = E+1 # 정점 개수, 마지막 정점 번호

# ch1 = [0]*(V+1)
# ch2 = [0]*(V+1)

# for i in range(0,V,2):
#     p,c = arr[i], arr[2*i]
#     if ch1[p] == 0:
#         ch1[p] = c
#     else:
#         ch2[p] = c
# print(ch1)
# print(ch2)

# preorder(1)



# 연습문제
'''
13
1 2 1 3 2 4 3 5 3 6 4 7 5 8 5 9 6 10 6 11 7 12 11 13
'''
V = int(input())
arr = list(map(int,input().split()))
E = V-1

ch1 = [0]*(V+1)
ch2 = [0]*(V+1)

for i in range(E):
    p,c = arr[2*i], arr[2*i+1]
    if ch1[p] == 0:
        ch1[p] = c
    else:
        ch2[p] = c
print(ch1)
print(ch2)
preorder(1)
print()
inorder(1)
print()
postorder(1)
print()

# 순회한 정점의 개수를 리턴하는 함수
def f(n):
    if n==0:    # 서브트리가 비어있으면 0을 리턴
        return 0

    else:
        # 왼쪽 자식노드의 서브트리 정점 개수
        L = f(ch1[n])
        # 오른쪽 자식노드의 서브트리 정점 개수
        R = f(ch2[n])
        # 왼쪽 + 오른쪽 + 자기자신
        return L+R+1