N = (int)(input())
conference = []
for _ in range(N):
 time = list(map(int, input().split()))
 conference.append(time)
conference.sort()
conference.reverse()
start = conference[0][1]+1
count = 0
for i in range(len(conference)):
 if conference[i][1] <= start:
  start=conference[i][0]
  count+=1
print(count) 