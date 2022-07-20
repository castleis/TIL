from re import L


num = 2
result = '홀수' if num%2 else '짝수'
print(result)

if num >= 0:
    value = num
else:
    value = 0
print(value)

#
cubic_dict = {}
cubic_dic = {}
for number in range(1,4):
    cubic_dict[number] = number**3
print(cubic_dict)

cubic_dic = {number : number**3 for number in range(1,4)}
print(cubic_dic)