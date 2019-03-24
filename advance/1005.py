
di = {'1':'one', '2':'two', '3':'three', '4':'four', '5':'five', '6':'six', '7':'seven', '8':'eight', '9':'nine', '0':'zero'}
res = list(str(sum([int(i)  for i in list(input())])))
print(di[res[0]], end='')
for i in res[1:]:
    print(' ' + di[i], end='')