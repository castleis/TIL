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
