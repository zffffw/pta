# split 会导致速度慢很多，尽量不要用，直接处理字符串
NC = input().split()
total = []
for i in range(int(NC[0])):
    total.append(input())
# print(total)
def printtotal():
    for i in total:
        print(i)
if NC[1] == '1':
    total.sort(key=lambda x:x)
    printtotal()
elif NC[1] == '2':
    total.sort(key=lambda x:(x[7:-3], int(x[:6])))
    printtotal()
elif NC[1] == '3':
    total.sort(key=lambda x:(x[-2:], x[:6]))
    printtotal()