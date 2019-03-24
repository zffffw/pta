import time
def takeSecond(elem):
    return elem[1]
def takeThird(elem):
    return elem[2]

K = int(input())
total = []
for i in range(K):
    templ = input().split()
    total.append(templ)

total.sort(key=takeSecond)
print(total[0][0], end=' ')
total.sort(key=takeThird)
print(total[-1][0])