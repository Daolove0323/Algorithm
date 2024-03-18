N, K = map(int, input().split())
data = []
for _ in range(N):
	num = (int)(input())
	data.append(num)
data.reverse()
count = 0
for i in data:
	if (K >= i):
		count = count + (K//i)
		K = (K%i)
	if (K == 0):
		break
print(count)