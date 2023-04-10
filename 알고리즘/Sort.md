# Sort
2개 이상의 자료를 **특정 기준(key)**으로 정렬하기!

**시간복잡도**
특정한 크기의 입력에 대하여 알고리즘이 얼마나 오래걸리는지, 알고리즘을 위해 필요한 연산의 횟수

```python
#수행 시간 측정 소스코드
import time
start_time = time.time() #측정시작

end_time = time.time() #측정 종료
print("time :", end_time - start_time) #수행 시간 출력
```

1. 버블 정렬 (Bubble)
인접한 두 개의 원소를 비교하며 자리를 계속 교환하는 방식
- 첫 번째 원소부터 인접한 원소끼리 계속 자리를 교환하면서 맨 마지막 자리까지 이동
- 한 단계가 끝나면 가장 큰 원소 또는 가장 작은 원소가 마지막 자리로 정렬됨
- 교환하며 자리를 이동하는 모습이 물 위에 올라오는 거품모양 같아서 버블 정렬이라고 한다네용??
- 시간 복잡도 : O(n^2)
```python
def BubbleSort(a):
    for i in range(len(a)-1,0,-1): # 범위의 끝 위치
        for j in range(0,i):
            if a[j] > a[j+1]:
                a[j],a[j+1] = a[j+1],a[j]
```

2. 카운팅 정렬 (Counting sort)
항목들의 순서를 결정하기 위해 집합에 각 항목이 몇 개씩 있는지 세는 작업을 하여, 선형 시간에 정렬하는 효율적인 알고리즘
- 정수나 정수로 표현할 수 있는 자료에 대해서만 적용 가능
- 카운트를 위한 충분한 공간을 할당하려면 집합 내의 가장 큰 정수를 알아야 함
- 시간 복잡도 : O(n+k), n은 리스트의 개수, k는 정수의 최대값
```python
def CountingSort(A,B,k):
    # A : [1,,,n] -- 입력 리스트. 사용된 숫자는 1~k
    # B : [1,,,n] -- 정렬된 리스트.
    # C : [1,,,k] -- 카운트 리스트.
    C = [0]*k
    # 입력된 리스트 A의 각 원소의 개수를 카운팅해서 저장
    for i in range(0,len(B)):
        C[A[i]] += 1
    # 원소들을 정렬하기 위해 정렬 리스트의 인덱스를 저장
    for i in range(1,len(C)):
        C[i] += C[i-1]   
    # 정렬 리스트 B에 각 항목들을 정렬, 정렬될 때마다 C에 저장된 인덱스를 조정해준다.
    for i in range(len(B)-1,-1,-1):
        B[C[A[i]]] = A[i]
        C[A[i]] -= 1 
```
3. 선택 정렬 (Selection sort)
- 시간 복잡도 : O(n^2)
- 교환 횟수가 버블, 삽입정렬보다 작음.
```python
for i in range(len(array)):
    min_index = i  #가장 작은 원소의 인덱스
    for j in range(i+1, len(array)):
        if array[min_index] > array[j]: #인덱스 i 다음의 원소들과 비교해서 더 작은 값의 인덱스를 min_index로 지정
            min_index = j
    array[min_index], array[j] = array[j], array[min_index] #for문을 돌면서 확인한 가장 작은 값과 위치를 스와프
```
4. 퀵 정렬 (Quick sort)
- 시간 복잡도 : O(n log n)
- 분할정복으로 최악의 경우 시간복잡도가 O(n^2)이지만 평균적으로는 가장 빠름
```python
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    # pivot을 무엇으로 설정할지는 사용자에게 달려있음.
    pivot = arr[len(arr) // 2]
    lesser_arr, equal_arr, greater_arr = [],[],[]
    for num in arr:
        if num < pivot:
            lesser_arr.append(num)
        elif num > pivot:
            greater_arr.append(num)
        else:
            equal_arr.append(num)
    return quick_sort(lesser_arr) + equal_arr + quick_sort(greater_arr)
```
- 위의 구현은 간결하고 이해가 쉽지만 매번 재귀호출될 때마다 새로운 리스트를 생성하여 리턴하기 때문에 메모리 사용 측면에서 비효율적.
  - 큰 사이즈의 입력 데이터를 다뤄야할 때는 추가 메모리 사용이 적은 in-place 정렬이 선호됨.

5. 삽입 정렬 (Insertion sort)
- 시간 복잡도 : O(n^2)
  - 모두 정렬되어 있는 optimal한 경우 모든 원소가 한번씩만 비교되므로 O(n)
- 공간 복잡도 : 하나의 배열에서 정렬이 이루어지므로 O(n)
- n의 개수가 작을 때 효과적
- 첫번째 index는 비교할 대상이 없기 때문에 두번째 index부터 시작. 알고리즘이 동작하는 동안 계속해서 정렬이 진행되므로 반드시 맨 왼쪽 index까지 탐색하지 않아도 된다는 장점이 있음. 

```python
def insert_sort(array):
	for i in range(1,len(array)): # 두번째 원소부터 순회
		j = i
		while j > 0 and array[j-1] > array[j]:  # 현재 인덱스부터 거꾸로 탐색하면서 현재 값보다 큰 값이 있다면 자리를 바꿔주기
			array[j-1],array[j] = array[j],array[j-1]
			j -= 1
	return array
```

6. 병합 정렬 (Merge sort)
- 시간 복잡도 : O(n log n)
- 분할정복, 연결 리스트의 경우 가장 효율적인 방식
- 퀵 정렬과의 차이점은 퀵 정렬이 피봇 선택 이후 피봇을 기준으로 대소를 비교하는 반면, 병합 정렬은 배열의 원소가 하나만 남을 때까지 계속 분할한 다음, 대소를 비교하여 다시 재배열하며 원래 크기의 배열로 병합함. 
  - 즉, 퀵 정렬은 대소 비교를 분할하는 과정에서, 병합 정렬은 정복(합치는)하는 과정에서 진행.
- 대부분의 경우 퀵정렬보다 느리지만 일정한 실행 속도뿐 아니라 무엇보다도 안정 정렬이라는 점에서 여전히 상용 라이브러리에 많이 쓰이고 있다.
```python
def merge_sort(array):
	if len(array) <= 1:    # 배열의 길이가 1일 때 분할 중단
		return array
	
	mid = len(array)//2     # 배열의 중간을 기준으로 분할
	left = merge_sort(array[:mid])  # 각 과정에서 정렬된 리스트인 merged_array가 반환됨
	right = merge_sort(array[mid:])

	merged_array = []       # 원소들을 정렬하여 넣어줄 리스트
	l,r = 0,0               # l,r은 각각 left, right 배열의 인덱스

	while l < len(left) and r < len(right):  # 각각의 배열의 크기를 넘어가지 않는 동안
		if left[l] < right[h]:                 # 왼쪽 배열의 숫자가 더 작다면 merged_array에 먼저 추가
			merged_array.append(left[l])         # left 배열은 다음 원소를 가리킴
			l += 1
		else:                         
			merged_array.append(right[r])        # 오른쪽 배열의 숫자가 더 작다면 merged_array에 먼저 추가
			r += 1                               # right 배열은 다음 원소를 가리킴

	# while문은 적어도 하나의 배열이 merged_array에 모두 추가되었을 때 끝나므로 
	# 남아있는 원소가 있는 배열은 left, right 중 하나밖에 없음.
	merged_array += left[l:]                 # left 배열에 남아있는 원소를 추가
	merged_array += right[r:]                # right 배열에 남아있는 원소를 추가

	return merged_array
```

7. 힙 정렬 (Heap sort)
- 힙(Heap)이란?
  - **완전이진트리** 기반 자료구조
  - 여러 개의 값들 중, 가장 큰 값 or 가장 작은 값을 빠르게 찾아내도록 만들어진 자료구조임
  - `부모노드_Key >= 자식노드_Key`가 항상 성립
  - 노드 인덱스 구성
    1. 배열로 구현 시 0번째 인덱스가 아니라 1번째 인덱스부터 시작
    2. 왼쪽 자식의 인덱스 = (부모 인덱스) * 2
    3. 오른쪽 자식의 인덱스 = (부모 인덱스) * 2 + 1
    4. 부모 인덱스 = (자식 인덱스) // 2
- 시간복잡도 : O(nlogn)
- 불안정 정렬임.
- 최대 힙을 구성한 후, 루트를 힙의 마지막 원소와 교환 -> 마지막 원소를 제외하고 나머지 원소에 대해서 반복 -> 정렬된 원소를 제외하고 최대 힙에 원소가 1개 남으면 정렬을 종료

```python
def heapify(li,idx,n):
    left = idx * 2
    right = idx * 2 + 1
    s_idx = idx
    if l <= n and li[s_idx] > li[left]:
        s_idx = left
    if r <= n and li[s_idx] > li[right]:
        s_idx = right
    if s_idx != idx:
        li[idx], li[s_idx] = li[s_idx], li[idx]
        return heapify(li, s_idx, n)

def heap_sort(v):
    n = len(v)
    v = [0]+v

    # min_heap 생성
    for i in range(n, 0, -1):
        heapify(v, i, n)
    
    # min element extract & heap
    for i in range(n, 0, -1):
        v[i], v[1] = v[1], v[i]
        heapify(v, 1, i-1)
```