/** @file
 *  @brief Class to work with the server
 */
#ifndef LAB8_SERVER_H
#define LAB8_SERVER_H

#include <iostream>
#include <PlanetStorage.h>
#include <progbase-cpp/net.h>
#include <TextProcessing.h>

using namespace progbase::net;
using namespace std;

/**
 * @struct Request
 * @brief defines a HTTP client request
 */
typedef struct {
    string method;
    string path;
} Request;

/**
 * @class
 * @brief defines a server
 */
class Server {
    string title;
    string developer;
    TcpListener *listener;
    bool isActive = false;
    IpAddress *address;
    PlanetStorage *storage;
    TextProcessing *data;

private:
    /**
     * @brief Private server constructor
     * @param title - server name
     * @param developer - developer name
     * @param listener - listener
     * @param address - server ipAddress
     */
    Server(const string &title,
           const string &developer,
           TcpListener *listener,
           IpAddress *address);
public:
    /**
     * @brief Server destructor
     */
    ~Server();
    /**
     * @brief Server constructor
     * @param serverPort - server port
     * @param title - server name
     * @param developer - developer name
     * @return if success created server, else - false
     */
    static Server *create(int serverPort, const string & title, const string & developer);
    /**
     * @brief start executing server
     */
    void startServer();
private:
    /**
     * @brief listen client and his request
     * @param message
     * @return
     */
    Request *parse_request(const string & message);
    /**
     * @brief Get error code description
     * @param statusCode - error code
     * @return description
     */
    static string getStatusDescription(int statusCode);
    /**
     * @brief Send response
     * @param message - response
     */
    void sendResponse(NetMessage message);
    /**
     * @brief Determines the path that was requested
     * @param path - the path that was requested
     * @return same information or empty string, if path is wrong
     */
    string getPath(string path);
    /**
     * @brief Get the current time
     * @return string with start information in json format
     */
    string startInfo();
    /**
     * @brief Get the current time
     * @return current time
     */
    string getCurrTime();
};


#endif //LAB8_SERVER_H
