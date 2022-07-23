## List comprehension

1. 표현식 + for 문
  `result = [표현식 for 변수 in 리스트]`
  
2. 표현식 + for문 + 조건문
  `result = [표현식 for 변수 in 리스트 조건문]`

3. 조건문 + for문
  `result = [조건문 for 변수 in 리스트]`
  
4. 중첩 for문
  `result = [조건문 for 변수1 in 리스트1 for 변수2 in 리스트2 ...]`

## join 함수
`'구분자'.join(리스트)` or `.join(리스트)`
이 함수를 이용하면 매개변수로 들어온 ['a','b','c']와 같은 리스트를 'abc'처럼 **문자열로 합쳐서 반환**해줌
example)
```python
word = input() #apple
reverse_word = []
for i in range(1,len(word)+1):
    reverse_word.append(word[-i])
#1
result = ""
for j in range(len(reverse_word)):
    result += reverse_word[j]
print(result) #elppa

#2 .join()함수 사용
result2 = "".join(reverse_word)
print(result2) #elppa
```

### replace()로 특정 문자 삭제하기
```python
word = 'banana'
word = word.replace('a', '') # .replace(삭제하고 싶은 문자, 빈칸(?))
print(word) #bnn
```


# 완전 검색 (Exhaustive Search)
문제의 해법으로 생각할 수 있는 모든 경우의 수를 나열해보고 확인하는 기법
- 브루트 포스 (Brute-force)라고도 함. 
- 모든 경우의 수를 테스트, 최종 해법 도출
- 일반적으로 경우의 수가 상대적으로 작을 때 유용
- 모든 경우의 수를 생성하고 테스트하기 때문에 수행속도는 느리지만 해답을 찾아내지 못할 확률이 작음
- 주어진 문제를 풀 때  우선 완전 검색으로 접근하여 해답을 도출한 후, 성능 개선을 위해 다른 알고리즘을 사용하고 해답을 확인하는 것이 바람직함

### 1. 순열 (Permutation)
- 서로 다른 n개 중 r개를 택하는 순열 : nPr
- nPr = n*(n-1)*(n-2)* ... *(n-r+1)
- {1,2,3}을 포함하는 모든 순열을 생성하는 함수
```python
#동일한 숫자가 포함되지 않았을 때, 각 자릿수별로 loop를 이용
for i1 in range(1,4):
  for i2 in range(1,4):
    if i2 != i1 : 
      for i3 in range(1,4):
        if i3 != i1 and i3 != i2:
          print(i1,i2,i3)
```

# Greedy Algorithm
탐욕 알고리즘 : 최적 해를 구하는데 사용되는 근시안적인 방법
- 여러 경우 중 하나를 걸정해야 할 때마다 그 순간에 최적이라고 생각되는 것을 선택해 나가는 방식으로 진행하여 최종적인 해답에 도달함.
- 수행과정
  1. 해 선택 : 현재 상태에서 부분 문제의 최적 해를 구한 뒤, 이를 부분 해 집합에 추가
  2. 실행 가능성 검사 : 새로운 부분 해 집합이 실행 가능한지 확인
   ( 문제의 제약 조건을 위반하지 않는지를 검사 )
  3. 해 검사 : 새로운 부분 해 집합이 문제의 해가 되는지를 확인.
      아직 전체 문제의 해가 완성되지 않았다면 해 선택부터 다시 시작
- 탐욕 알고리즘적인 접근은 해답을 찾아내지 못하는 경우도 있으므로 유의해야함.
