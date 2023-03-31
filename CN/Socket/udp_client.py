from socket import *
socketName = gethostname()
port = 12000
clientSocket = socket(AF_INET,SOCK_DGRAM)
message = input("enter lower sentence\n")
clientSocket.sendto(message.encode(),(socketName,port))
mes_rcv,address = clientSocket.recvfrom(2048)
print(address)
print(mes_rcv.decode())
clientSocket.close()