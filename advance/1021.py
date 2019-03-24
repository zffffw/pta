import sys
sys.setrecursionlimit(100000)

def search(node, depth):
    global maxdepth
    global maxi
    global searched
    if node not in searched:
        if depth > maxdepth:
            maxi = node
            maxdepth = depth
        searched.append(node)
        for j in node_l[node]:
            search(j, depth + 1)
def search2(node, depth):
    global maxdepth
    global depthList
    global searched
    # print(node, searched)
    if node not in searched:
        depthList[node][1] = depth
        if depth > maxdepth:
            maxdepth = depth
        searched.append(node)
        for j in node_l[node]:
            search2(j, depth + 1)
        

if __name__ == "__main__":
    node_num = int(input())
    node_l = [[] for i in range(node_num)]
    # print(node_num)
    for i in range(node_num - 1):
        tmp = input().split(" ")
        # print(tmp)
        node_l[int(tmp[0]) - 1].append(int(tmp[1]) - 1)
        node_l[int(tmp[1]) - 1].append(int(tmp[0]) - 1)
    # print(node_l)
    
    compno = 0
    searched = []
    maxdepth = 0
    maxi = 0
    for i in range(node_num):
        if i not in searched:
            search(i, 1)
            compno += 1
    if compno > 1:
        print("Error: {} components".format(compno))
    else:
        # print("maxi", maxi)
        searched = []
        maxdepth = 0
        depthList = [[i, 0] for i in range(node_num)]
        tmp = maxi
        search2(maxi, 1)
        depthList[tmp][1] = maxdepth
        depthList.sort(key=lambda x:(-x[1], x[0]))
        # print(depthList)
        k = 0
        while depthList[k][1] == depthList[0][1]:
            print(depthList[k][0] + 1)
            k += 1

        