import math

ip = input().split('/')
dev = int(input())
n = int(math.log(dev,2))
mask_bin = []
mask = []
for i in range(32-n):
    mask_bin.append(1)
for i in range(n):
    mask_bin.append(0)
for i in range(4):
    tmp = 0
    for j in range(8):
        tmp = tmp*2 + int(mask_bin[i*8 + j])
    mask.append(tmp)
print(*mask,sep=".")