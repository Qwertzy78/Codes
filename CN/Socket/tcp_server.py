from socket import *
port = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(("",port))
serverSocket.listen(1)
print("Ready")
while 1:
    connection,add = serverSocket.accept()
    sentence = connection.recv(1024)
    capital = sentence.decode().upper()
    connection.send(capital.encode())
    connection.close()