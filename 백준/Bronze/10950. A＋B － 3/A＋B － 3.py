N = int(input())
data = [[] for _ in range(N)]
for i in range(N):
    A, B = map(int, input().split())
    data[i].extend([A, B])
for i in range(N):
    print(sum(data[i]))