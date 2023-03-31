from socket import *
from _thread import *
import threading

print_lock = threading.Lock()

def threaded(c):
    while True:
        data = c.recv(1024).decode()
        if not data:
            print("bye")
            print_lock.release()
            break
        print(data)
        reply = input()
        c.send(reply.encode())
    c.close()

port = 12000
serversocket = socket(AF_INET,SOCK_STREAM)
serversocket.bind(("",port))
serversocket.listen(1)
print('Ready')
while True:
    c,addr = serversocket.accept()
    print_lock.acquire()
    start_new_thread(threaded,(c,))
serversocket.close()