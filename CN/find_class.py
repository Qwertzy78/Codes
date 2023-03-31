ip = input()
ip_l = ip.split(".")
flag = 0
try:
    for i in ip_l:
        if int(i)>=0 and int(i)<=255 and len(ip_l)==4:
            continue
        else:
            flag = 1
            break
    if flag == 0:
        print("Valid")
        bin = "{0:08b}".format(int(ip_l[0]))
        if int(bin[0], 2) == 0:
            print("A")
        elif int(bin[:2], 2) == 2:
            print("B")
        elif int(bin[:3], 2) == 6:
            print("c")
        elif int(bin[:4], 2) == 14:
            print("D")
    else:
        print("Invalid")
except:
    print("Invalid")
