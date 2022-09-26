# nCr = n-1Cr-1 + n-1Cr   -> 재귀적 표현

# N개 중 3개 고르기
# N = 5
# for i in range(N-2):
#     for j in range(i+1,N-1):
#         for k in range(j+1,N):
#             print(i,j,k)
        
# n개에서 r개를 고르는 조합 (재귀)
def nCr(n,r,s):
    if r == 0:
        print(*comb)
    else:
        for i in range(s, n-r+1):
            comb[r-1] = A[i]
            nCr(n,r-1,i+1)
            
A = [1,2,3,4,5]
n = len(A)
r = 3
comb = [0]*r
nCr(n,r,0)