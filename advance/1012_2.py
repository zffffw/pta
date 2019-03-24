
# 空间换时间，建立成绩映射表
NM = input().split()
# AL[i] 存放A科目成绩为i的学生ID，相当于直接排好序
AL = [[] for i in range(101)]
CL = [[] for i in range(101)]
ML = [[] for i in range(101)]
EL = [[] for i in range(101)]
nameL = []
def pList(L):
    for n,i in enumerate(L):
        if i:
            print(n, i)

def getRank(L, number):
    rank = 0
    for i in range(100, 0, -1):
        rank += 1
        if L[i] and number in L[i]:
            return rank
        else:
            rank -= 1
            rank += len(L[i])


for i in range(int(NM[0])):
    tmp = input().split(" ")
    Cgrad = int(tmp[1])
    Mgrad = int(tmp[2])
    Egrad = int(tmp[3])
    ID = tmp[0]
    nameL.append(ID)
    CL[Cgrad].append(ID)
    ML[Mgrad].append(ID)
    EL[Egrad].append(ID)
    average = round((Cgrad + Mgrad + Egrad)/3)
    AL[average].append(ID)
for i in range(int(NM[1])):
    ID = input()
    if ID in nameL:
        rankA = getRank(AL, ID)
        rankC = getRank(CL, ID)
        rankM = getRank(ML, ID)
        rankE = getRank(EL, ID)
        if rankA <= rankC and rankA <= rankE and rankA <= rankM:
            print(rankA, 'A')
        elif rankC <= rankE and rankC <= rankM:
            print(rankC, 'C')
        elif rankM <= rankE:
            print(rankM, 'M')
        else:
            print(rankE, 'E')
    else:
        print('N/A')

