N = int(input())
length = list(map(int, input().split()))
price = list(map(int, input().split()))
priceSum = 0
nowPrice = price[0]

for idx, val in enumerate(price[:-1]):
    if val <= nowPrice:
        nowPrice=val
    priceSum += nowPrice*length[idx]

print(priceSum)