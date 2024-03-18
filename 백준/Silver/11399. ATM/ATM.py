N = int(input())
data = list(map(int, input().split()))
data.sort()
sum = 0
for i in data:
	sum+=i*N
	N-=1
print(sum)