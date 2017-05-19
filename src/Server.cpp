#include <cassert>
#include <Server.h>
#include <ctime>


Server::Server(const string &title,
               const string &developer,
               TcpListener *listener,
               IpAddress *address) {
    this->title = title;
    this->developer = developer;
    this->listener = listener;
    this->isActive = false;
    this->address = address;
    this->storage = new PlanetStorage("../data/Planets.json");
    this->data = new TextProcessing("../data/data.txt");
}

Server *Server::create(int serverPort, const string & title, const string & developer) {

    TcpListener *listener = new TcpListener();
    IpAddress *address = new IpAddress("127.0.0.1",serverPort);
    try{
        listener->bind(*address);
    }catch(NetException const & exc){
        delete listener;
        delete address;
        return NULL;
    }
    return new Server(title, developer, listener, address);
}

void Server::startServer(){
    isActive = true;
    NetMessage message(10000);
    try {
        listener->start();
        while (isActive) {
            cout << ">> Waiting for clients at " << this->address->address()<<":"<<this->address->port() << "..." << endl;
            sendResponse(message);
        }
    }catch(NetException const & exc){
        cerr << exc.what() << endl;
    }
    isActive=false;
}

void Server::sendResponse(NetMessage message) {
    TcpClient *client = listener->accept();
    client->receive(message);
    cout << ">> Received: " << endl << message.dataAsString() << endl;
    if(message.dataAsString().find("GET") == 0){
        Request *request = parse_request(message.dataAsString());
        string str = getPath(request->path);
        if(str == "") {
            message.setDataString("HTTP/1.1 " + to_string(404) + " " + getStatusDescription(404)+"\r\n"+"Content-type: text"+"\r\n\r\n"+to_string(404) + " " + getStatusDescription(404));
        }else{
            message.setDataString("HTTP/1.1 " + to_string(200) + " " + getStatusDescription(200)+"\r\n"+"Content-type: text/json"+"\r\n\r\n"+str);
        }
    }else{
        message.setDataString("HTTP/1.1 " + to_string(405) + " " + getStatusDescription(405)+"\r\n"+"Content-type: text"+"\r\n\r\n"+to_string(405) + " " + getStatusDescription(405));
    }
    client->send(message);
    cout << ">> Response sent."<<endl << message.dataAsString()<<endl;
    delete client;
}

Request *Server::parse_request(const string &message){
    Request *request = new Request;
    request->method = "GET";
    int shift = message.find(" HTTP");
    request->path = message.substr(message.find_first_of("/"), shift - message.find_first_of("/"));
    return request;
}

string Server::getStatusDescription(int statusCode){
    switch (statusCode){
        case 200:
            return "OK";
        case 404:
            return "Not Found";
        case 405:
            return "Method Not Allowed";
        default:
            return "Not Found";
    }
}

string Server::getPath(string path){
    if(path.compare("/") == 0) return startInfo();
    if(path.compare("/favorites") == 0) return storage->getAllPlanets();
    if(path.find("/favorites?rp") == 0) return storage->findPlanetsRotationPeriod(path.substr(path.find("=")+1));
    if(path.find("/favorites/") == 0) return storage->findPlanet(path.substr(path.find_last_of("/")+1));
    if(path.compare("/file") == 0) return data->fileInfo();
    if(path.find("/file/") == 0) return data->fileDataInfo();
    return "";
}

string Server::startInfo(){
    json_t *info = json_object();
    json_object_set_new(info, "title", json_string(this->title.c_str()));
    json_object_set_new(info, "developer", json_string(this->developer.c_str()));
    json_object_set_new(info, "time", json_string(getCurrTime().c_str()));
    string jsonString = json_dumps(info, JSON_INDENT(2));
    json_decref(info);
    return jsonString;
}

string Server::getCurrTime(){
    char buf[1000];
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    strftime(buf, sizeof buf, "%a, %d %b %Y %H:%M:%S %Z", &tm);
    return buf;
}
