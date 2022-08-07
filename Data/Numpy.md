# Numpy
Python list에 비해 **빠른연산**을 지원, **메모리를 효율적**으로 사용

### 배열 만들기
```python
import numpy as np
np.array([1,2,3,4,5])  # array([1,2,3,4,5])
np.array([3, 1.4, 2, 3, 4]) #array[3. , 1.4, 2. , 3. , 4.], 실수가 들어가면 모든 데이터가 실수로 바뀜
np.array([[1,2],
          [3,4]]) # 2차원 배열 가능
```
- 배열 데이터 타입 : dtype
  - `àrr = np.array([1,2,3,4], dtype=float)` : array의 모든 데이터가 float 타입으로 바뀜
  - Python list와 다르게 array는 단일타입으로 구성
  - int, float, str, bool 이 있음.

- 다양한 배열 만들기
```python
np.zeros(10, dtype=int) # 0이 10개
np.ones((3,5), dtype=float) # 열:3, 행:5 인 1로 이루어진 배열 (데이터 타입 : float)
np.arange(0,20,2) # (start, end, step)
np.linspace(0,1,5) # 0부터 1까지 5번 나누어 배열 -> array([0. ,0.25 ,0.5 ,0.75 ,1. ])

np.random.random((2,2)) #2X2 배열로 난수 배열
np.random.normal(0,1,(2,2)) # (평균, 표준편차, 배열방식)
np.random.randint(0,10,(2,2)) # 0부터 10까지 사이의 숫자를 랜덤으로 2X2 형태로 출력
```
## 배열의 기초
`arr = np.random.randint(10, size=(3,4))`
- arr.ndim : 배열의 차원을 나타내줌. 위의 예시 답 # 2
- arr.shape : 배열의 모양
- arr.size : 배열 안에 원소가 몇개 있는지
- arr.dtype : 데이터 타입이 무엇인지

### Indexing
- 1차원 배열
  - 파이썬 리스트와 비슷
- 2차원 배열
  - arr[행 인덱싱, 열 인덱싱]

### Reshape
1. `.reshape()`
  - array의 shape를 변경
```python
x = np.arange(8)
x2 = x.reshape((2,4)) # x의 배열(1차원 배열)을 2X4의 2차원 배열로 변경
```

2. `np.concatenate()`
- array를 이어 붙임
```python
x = np.array([0,1,2])
y = np.array([3,4,5])
np.concatenate([x,y]) # array([0,1,2,3,4,5])
```
- 방향을 가지고 이어붙이기
  - `np.concatenate([], axis=0)` : axis 축을 기준으로 이어붙임. 세로 방향으로
  - `np.concatenate([], axis=1)` : 가로방향으로


3. `np.split()`
- axis 축을 기준으로 분할.
  - axis = 0 : 세로방향
  - axis = 1 : 가로방향
```python
matrix = np.arange(16).reshape(4,4)
upper, lower = np.split(matrix, [3], axis = 0) 
# .split(나눌 array, [나누는 기준이 될 인덱스], axis = 나눌 방향)
# matrix 배열을 3번째 행에서(세로 방향) 나눔 -> 위의 3줄은 upper, 밑의 1줄은 lower로 split
left, right = np.split(matrix, [3], axis = 1)
# matrix 배열을 3번째 열에서(가로 방향) 나눔 -> 왼쪽의 3줄은 left, 오른쪽의 1줄은 right로 split
```

## 연산
- array는 +,-,*,/ 에 대한 기본 연산을 지원
- array 내의 모든 원소에 대하여 일괄연산 가능
- 다차원 행렬에서도 적용 가능
- 행렬끼리 연산 가능

1. Broadcasting
- shape이 다른 array끼리 연산
- 3X3 배열의 matrix 
  - `matrix + 5` : 1X1인 5가 3X3으로 늘어나 matrix의 각각의 원소들에 5를 더해줌.
  - `matrix + np.array([1,2,3])` :1X3인 [1,2,3]이 [1,2,3]*3 이 되어서 matrix의 모든 원소에 1열에는 1, 2열에는 2, 3열에는 3을 더해줌.

2. 집계함수
- 데이터에 대한 요약 통계
- np.sum() 
  - sum(arr, axis = 0 or 1) : 가로 혹은 세로 방향으로 더해서 출력 (행은 행끼리, 열은 열끼리 )
- min(), max()
- np.mean() : 평균
- np.std() : 표준편차

3. 마스킹 연산
- True, False array를 통해서 특정 값들을 뽑아내는 방법
```python
x = np.arange(5)  # array([0,1,2,3,4])
x < 3  # array([True, True, True, False, False])
x > 5  # array([False, False, False, False, False])
x[x < 3]  #array([0,1,2]), True인 값들만 출력
```