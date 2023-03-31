n = int(input())
inp = []
for i in range(n):
    inp.append(input())

for i in range(n):
    li = inp[i].split(" ")
    m = int(li[0])        
    sow = 2**(m-1)          #size of window
    Sf = int(li[1])
    Sn = int(li[2])
    E1 = int(li[3])
    E2 = int(li[4])  
    E3 = int(li[5])
    if m <= 0 or Sf <= 0 or Sn <= 0:
        print(str(Sf) + " " + str(Sn))
        continue
    else:
        if E1==0:
            if E2!= 0:
                Sn += E2
                if Sn > Sf +sow:
                  Sn = Sf + sow
            elif E3!=0:
                Sf = abs(E3)
    print(str(Sf) + " " + str(Sn))