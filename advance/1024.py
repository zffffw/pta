l = input().split()

num = l[0]
k = 0
for i in range(int(l[1])):
    num_rev = num
    temp = list(num)
    temp.reverse()
    num_rev = "".join(temp)
    if num == num_rev:
        break
    num = str(int(num) + int(num_rev))
    k += 1
print(num)
print(k)