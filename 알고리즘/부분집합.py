# 바이너리 카운팅을 통한 사전적 순서로 만든 부분집합
'''
원소 수에 해당하는 n개의 비트열을 이용
-> n번째 비트값이 1이면 n번째 원소가 포함되었음을 의미!
'''
arr = [3,6,7]
n = len(arr)
# for i in range(1, 1 << n):        # 1<<n : 부분집합의 개수, 1부터 시작하면 공집합 제외!
#     for j in range(n):          # 
#         if i & (1 << j):            # i의 j번째 비트가 1이면 arr[j]가 부분집합의 원소
#             print(arr[j], end=' ')
#     print()

# ==============================
bit = [0]*n         # bit[i] : arr[i]가 부분집합의 원소인지 아닌지
def f(i,k):
    if i == k:
        for j in range(k):
            if bit[j]:
                print(arr[j], end=' ')
        print()
    else:
        bit[i] = 0
        f(i+1, k)
        bit[i] = 1
        f(i+1,k)
f(0,n)