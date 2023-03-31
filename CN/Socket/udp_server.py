from socket import *
port = 12000
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind(("",port))
print("Ready\n")
while 1:
    message,add = serverSocket.recvfrom(2048)
    serverSocket.sendto(message.decode().upper().encode(),add)
