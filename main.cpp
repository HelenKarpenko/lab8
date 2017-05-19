#include <iostream>
#include <Server.h>
using namespace std;
int main() {
    Server * server=NULL;
    int port = 4003;
    while(server == NULL){
        server = Server::create(port++,"Helen's server","Helen jopa");
    }
    port--;
    cout<<port<<endl;
    server->startServer();
    return 0;
}