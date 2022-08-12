# 문자열 세기
def strlen(a):
    cnt = 0
    while a[cnt] != '\0':
            cnt += 1
    return cnt

a = ['a','b','c','\0']
print(strlen(a))

# 문자열 뒤집기
def reverseStr(s):
    new = []
    for i in range(1,len(s)+1):
        new.append(s[-i])
    new = ''.join(new)
    return new

def reverseStr1(s):
    new = ''
    for i in range(1,len(s)+1):
        new += s[-i]
    return new

    # 리스트로 변환해서 값을 교환
def reverse_Sort(s):
    s_lst = list(s)
    for i in range(1, len(s_lst)//2+1):
        s_lst[i-1],s_lst[-i] = s_lst[-i], s_lst[i-1]
    s_lst = ''.join(s_lst)
    return s_lst

def reverseStr2(s):
    new = ''
    for i in s:
        new = i + new
    return new

s = 'Reverse this strings'
print(reverseStr(s))  # sgnirts siht esreveR
print(reverseStr1(s)) # sgnirts siht esreveR
print(reverse_Sort(s)) # sgnirts siht esreveR
print(''.join(reversed(s)))
print(reverseStr2(s))

# 문자열 비교하기
s1 = 'abc'
s2 = 'abc'
s3 = 'def'
s4 = s1
s5 = s1[:2] + 'c'
print(s1 == s2, s1 == s3, s1 == s4, s1 == s5) # 메모리 참조(id)가 같은지 확인
print(s1 is s2, s1 is s3, s1 is s4, s1 is s5) # object(객체) 자체가 같은지
print(id(s1), id(s5))

def isBig(str1,str2):
    # if len(str1) != len(str2):
    #     l = min(len(str1), len(str2))
    #     str1 = str1[:l]
    #     str2 = str2[:l]
    # print(str1, str2)
    # if str1 == str2:
    #     return 0
    # i = 0
    # while str1[i] == str2[i]:
    #     i += 1
    # print(i)
    # if str1[i] < str2[i]:
    #     return -1
    # elif str2[i] < str1[i]:
    #     return 1

    # 교수님 방법!
    if str1 == str2 :
        return 0
    else:
        if str1 > str2 :
            return -1
        if str1 < str2 :
            return 1
str1 = 'abc'
str2 = 'abcd'
print(isBig(str1,str2))

# 정수를 문자열 숫자로 반환하기
def itoa(i):
    s = []
    while i > 1 :
        s.append(chr(i%10 + ord('0')))
        i //= 10
    s = ''.join(reversed(s))
    return s
i = 232346321
ans = itoa(i)
print(ans, type(ans))

# 교수님 방법! 나는 0이랑 음수일 때를 고려하지 않았다 ㅠㅠ
def itoa1(i):
    if i == 0:
        return '0'
    if i < 0 :
        flag = False
        i = -i
    else:
        flag = True
    
    result = ''
    while i :
        i, remainder = i // 10, i % 10
        result = chr(ord('0') + remainder) + result
    if flag :
        return result
    else:
        return '-' + result
# 문자열 숫자를 정수로 변환하기
def atoi(s):
    i = 0
    for x in s:
        i = i*10 + ord(x)-ord('0')
    return i


# 패턴매칭
# 고지식한 알고리즘 brute_force
target = 'This is a book~!'
pattern = 'is'
def brute_force(pattern,target):
    N,M = len(target), len(pattern)
    t , p = 0,0 # target, pattern의 인덱스
    while p < M and t < N :

        # 틀렸을 경우
        if target[t] != pattern[p]:
            # 지금위치에서 -j + 1 하면 다음 위치가 됨
            # if문 아래에서 t += 1, p += 1 해줌을 기억할것!
            t -= p
            p = -1

        t += 1
        p += 1

    # 검색 성공했을 경우
    if p == M:
        return t - M
    # 검색 실패
    return -1
print(brute_force(pattern,target))


def KMP(target, pattern):
    N = len(target)
    M = len(pattern)
# 비교 시작
    t, p = 0,0
    position = -1
    while t < N :

        # 같으면 다음으로 이동
        if target[t] == pattern[p]:
            t += 1
            p += 1

        # 다르다면!
        else : 
            # 값은 다른데 p가 0이 아니라면, t 자리는 유지, p만 이동해서 비교 시작
            if p != 0 :
                p = next[p - 1]

            # 값은 다른데 j == 0, t 값 한칸 이동하고 처음부터 다시 진행
            else:
                t += 1
        if p == M :
            position = t - p
            break
    return position

def nextt(pattern):
    M = len(pattern)
    next = [0]*M
    j = 0
    for i in range(1,M):
        if pattern[j] == pattern[i]:
            j += 1
            next[i] = j
        else:
            j = 0
            if pattern[i] == pattern[j]:
                j += 1
                next[j] = j
    return next