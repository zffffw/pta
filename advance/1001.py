a = input().split(' ')
num1 = int(a[0])
num2 = int(a[1])
res = list(str(num1 + num2))
count = 0
resl = len(res)
if res[0] == '-':
    resl -= 1
for i in range(len(res) - 1, 0, -1):
    count += 1
    if count % 3 == 0 and count < resl:
        res.insert(i, ',')
for i in res:
    print(i, end='')
print()