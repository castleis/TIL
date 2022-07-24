# 3-1 거스름돈
#나의 코드
money = int(input())
changes = [0,0,0,0]

while money > 500 :
    money -= 500
    changes[0] += 1
while money > 100 :
    money -= 100
    changes[1] += 1
while money > 50 :
    money -= 50
    changes[2] += 1
while money > 0:
    money -= 10
    changes[3] += 1
print(f'총 500원 {changes[0]}개, 100원 {changes[1]}개, 50원 {changes[2]}개, 10원 {changes[3]}개 입니다.')

#답안 예시 코드
n = int(input())
count = 0
coin_types = [500,100,50,10]
for coin in coin_types:
    count += n//coin # 해당 화폐로 거슬러 줄 수 있는 동전의 개수를 count에 더해주기
    n %= coin 
print(count)

# 3-2 큰 수의 법칙