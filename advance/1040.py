a = input()
b = list(a)
b.reverse()
# print(a)
# print("".join(b))

maxl = 0
i = 0
while i < len(a):
    lasti = i
    count = 0
    j = 0
    while j < len(b):
        ccount = 0
        lastj = j
        while i < len(a) and j < len(b) and a[i] == b[j]:
            i += 1
            j += 1
            ccount += 1
        if ccount > count:
            count = ccount
        j += 1
        i = lasti
    if count > maxl:
        maxl = count
    i = lasti + 1
print(maxl)

