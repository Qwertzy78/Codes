#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <cctype>
#include <algorithm>


using namespace std;


void handleclient(int clientSocket){
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        cerr << "Error receiving data." << endl;
    }
    buffer[bytesRead] = '\0'; // Null-terminate the received data
    cout << "Received plaintext from client: " << buffer << endl;
    
    
    string receivedData(buffer);
   size_t separatorPos = receivedData.find(',');
    if (separatorPos == string::npos) {
        cerr << "Invalid data format from client." << endl;
        close(clientSocket);
        return;
    }

    string plaintext = receivedData.substr(0, separatorPos);
    string keyword = receivedData.substr(separatorPos + 1);
    
        string encryptedText = playfairEncrypt(plaintext, key);

    // Send encrypted text back to the client
    if (send(clientSocket, encryptedText.c_str(), encryptedText.size(), 0) == -1) {
        cerr << "Error sending data." << endl;
    } else {
        cout << "Encrypted text sent to client: " << encryptedText << endl;
    }

}





int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating socket." << endl;
        return EXIT_FAILURE;
    }

    // Bind the socket to an address and port
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Error binding socket." << endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        cerr << "Error listening for connections." << endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    cout << "Server listening on port 8080..." << endl;

    // Accept a connection from a client
    sockaddr_in clientAddress;
    socklen_t clientAddrSize = sizeof(clientAddress);
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddrSize);

    if (clientSocket == -1) {
        cerr << "Error accepting connection." << endl;
        close(serverSocket);
        return EXIT_FAILURE;
    }

    cout << "Connection accepted from " << inet_ntoa(clientAddress.sin_addr) << endl;

    // Receive data from the client
    handleclient(clientSocket);

    // Close sockets
    close(clientSocket);
    close(serverSocket);

    return EXIT_SUCCESS;
}