# 단순한 순열
def perm(n,r):
    for i in range(1,4):
        for j in range(1,4):
            if i != j:
                for k in range(1,4):
                    if k != i and k != j:
                        print(i,j,k)
# perm(1,4)

# =========================================
# 재귀를 이용한 순열 1
p = [1,2,3,4,5]
def perm1(n,k):
    # n번 인덱스가 원소의 개수와 같으면
    if n == k:
        print(p)
    
    else:
        for i in range(n,k):
            p[n],p[i] = p[i], p[n]
            perm1(n+1,k)
            p[i],p[n] = p[n], p[i]
# perm1(0,5)

# =========================================
# 재귀를 이용한 순열 2
N = 5
R = 3
a = [i for i in range(1,N+1)]
used = [0]*N
p = [0]*R
def perm2(i,k,r):
    if i == r:
        print(p)
    else:
        for j in range(k):
            if used[j] == 0:         # a[j]가 아직 사용되지 않았으면
                used[j] = 1          # a[j] 사용됨으로 표시
                p[i] = a[j]          # p[i]는 a[j]로 결정
                perm2(i+1,k,r)       # p[i+1] 값을 결정하러 이동
                used[j] = 0          # a[j]를 다른 자리에서 쓸 수 있도록 비사용으로 되돌려놓기
# perm2(0,N,R)

# 앞자리가 항상 1로 고정된 순열 구하기
N = 5
R = 5
a = [i for i in range(1,N+1)]
used = [0]*N
p = [0]*R
used[0] = 1
p[0] = 1
def perm3(i,k,r):
    if i == r:
        print(p)
    else:
        for j in range(k):
            if used[j] == 0:         # a[j]가 아직 사용되지 않았으면
                used[j] = 1          # a[j] 사용됨으로 표시
                p[i] = a[j]          # p[i]는 a[j]로 결정
                perm3(i+1,k,r)       # p[i+1] 값을 결정하러 이동
                used[j] = 0          # a[j]를 다른 자리에서 쓸 수 있도록 비사용으로 되돌려놓기
perm3(0,N,R)