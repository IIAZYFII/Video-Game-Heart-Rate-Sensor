#include "server.h"

Server::Server()
{
    endpoint.set_error_channels(websocketpp::log::elevel::all);
    endpoint.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
    endpoint.init_asio();
}

Server::~Server() {}

void Server::run()
{
    endpoint.listen(9002);
    endpoint.start_accept();
    endpoint.run();
}