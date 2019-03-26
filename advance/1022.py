from collections import OrderedDict
n = int(input())
books = OrderedDict()
for i in range(n):
    id = input()
    books[id] = {}
    books[id]['1:'] = input()
    books[id]['2:'] = input()
    books[id]['3:'] = input()
    books[id]['4:'] = input()
    books[id]['5:'] = input()
# books = collections.OrderedDict(books)
m = int(input())
for i in range(m):
    tmp = input()
    idx = tmp.split()[0]
    other = " ".join(tmp.split()[1:])
    print(idx, other)
    # find = 0
    reslist = []
    if idx == '3:':
        for k in books:
            if other in books[k][idx]:
                # print(idx, other)
                # print(k)
                reslist.append(k)
                # find = 1


    else:
        for k in books:
            if other == books[k][idx]:
                # print(idx, other)
                # print(k)
                reslist.append(k)
                # find = 1
    if not reslist:
        print('Not Found')
    else:
        reslist.sort()
        # print(reslist)
        for k in reslist:
            print(k)


# print(books)