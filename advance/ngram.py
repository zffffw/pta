n = int(input())
st = input()
total_dic = {}
for i in range(len(st) - n + 1):
    if st[i:i + n] not in total_dic:
        total_dic[st[i:i + n]] = [i, 1]
    else:
        total_dic[st[i:i + n]][1] += 1

total = list(total_dic.items())
# print(total)
# print(total[0][1][0])
total.sort(key=lambda x:(-x[1][1], x[1][0]))
# print(total)
if total[0][1][1] <= 1:
    print("NO")
else:
    count = 0
    for i in total:
        if i[1][1] == total[0][1][1]:
            count += 1
    print(total[0][1][1])
    for i in range(count):
        print(total[i][0])
