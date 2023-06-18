
#ifndef SERVER_H
#define SERVER_H

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <functional>

class Server
{
private:
    websocketpp::server<websocketpp::config::asio> endpoint;
    bool isNumber(std::string check_string);

public:
    Server();
    ~Server();
    void run(int &bpm, int &s_port);
    void stop();
    bool isOpen();
};
#endif