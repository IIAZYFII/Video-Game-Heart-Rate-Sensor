#ifndef SERVER_H
#define SERVER_H

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
class Server
{
private:
    websocketpp::server<websocketpp::config::asio> endpoint;

public:
    Server();
    ~Server();
    void run();
    void serverOpen(websocketpp::connection_hdl hdl);
};
#endif