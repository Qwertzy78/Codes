Client code:
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Error creating socket." << endl;
        return EXIT_FAILURE;
    }
    
    cout << "Enter plaintext: ";
    string plaintext;
    getline(cin, plaintext);

    cout << "Enter keyword: ";
    string keyword;
    getline(cin, keyword);

    // Combine plaintext and keyword, separated by a comma
    string dataToSend = plaintext + "," + keyword;


    // Connect to the server
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    serverAddress.sin_port = htons(8080);

    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        cerr << "Error connecting to server." << endl;
        close(clientSocket);
        return EXIT_FAILURE;
    }

    cout << "Connected to server." << endl;

    // Send data to the server
    if (send(clientSocket, dataToSend.c_str(), dataToSend.size(), 0) == -1) {
        cerr << "Error sending data." << endl;
        close(clientSocket);
        return EXIT_FAILURE;
    }

    // Receive encrypted text from the server
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        cerr << "Error receiving data." << endl;
    } else {
        buffer[bytesRead] = '\0'; // Null-terminate the received data
        cout << "Received encrypted text from server: " << buffer << endl;
    }

    // Close the socket
    close(clientSocket);

    return EXIT_SUCCESS;
}