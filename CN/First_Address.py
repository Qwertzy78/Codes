inp = input().split('/')
n = 32-int(inp[1])

ip = inp[0].split('.')
for i in range(4):
    x = "{0:08b}".format(int(ip[i]))
    ip[i] = x
bin = "".join([str(item) for item in ip])
bin = list(bin)
add = []
for i in range(n):
    bin[32-i-1] = '0'

for i in range(4):
    tmp = 0
    for j in range(8):
        tmp = tmp*2 + int(bin[i*8 + j])
    add.append(tmp)

print(*add,sep=".")

add.clear()
for i in range(n):
    bin[32-i-1] = '1'

for i in range(4):
    tmp = 0
    for j in range(8):
        tmp = tmp*2 + int(bin[i*8 + j])
    add.append(tmp)

print(*add,sep=".")
print(2**n)