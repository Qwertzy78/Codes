from socket import *
serverName = gethostname()
serverPort = 12000
clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
while True:
    sentence = input("Lower case\n")
    if sentence == "over":
        break
    else:
        clientSocket.send(sentence.encode())
        modified = clientSocket.recv(1024)
        print(modified.decode())
clientSocket.close()