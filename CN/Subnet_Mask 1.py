import math

ip = input().split('/')
subnets = int(input())
bits_subnet = len(format(subnets,'b'))
n = 32 - (bits_subnet + int(ip[1]))

mask = []
mask_bin = []

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

print(2**n)