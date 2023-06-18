#include "server.h"
#include <string.h>

Server::Server()
{
    endpoint.set_error_channels(websocketpp::log::elevel::all);
    endpoint.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
    endpoint.init_asio();
}

Server::~Server() {}

bool Server::isOpen()
{
    return endpoint.is_listening();
}

void Server::run(int &bpm, int &s_port)
{

    websocketpp::server<websocketpp::config::asio> *endpointref = &endpoint;
    endpoint.set_open_handler([&endpointref](websocketpp::connection_hdl hdl)
                              {
                                  websocketpp::server<websocketpp::config::asio>::connection_ptr conn = endpointref->get_con_from_hdl(hdl);
                                  std::cout << "New Connection Established" << conn->get_remote_endpoint() << "\n";

                                  endpointref->send(hdl, "WebSocket Connection Established", websocketpp::frame::opcode::text); });

    endpoint.set_message_handler([&endpointref, &bpm, this](websocketpp::connection_hdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr msg)
                                 {
    std::string message = msg->get_payload();

     websocketpp::server<websocketpp::config::asio>::connection_ptr connection = endpointref->get_con_from_hdl(hdl);
   
     if(this->isNumber(message) == true) 
     {
        bpm = std::stoi(message);
     } 
        
  
    std::cout << "Received message from " << connection->get_remote_endpoint() << ": " << message << std::endl;

  

    endpointref->send(hdl, message, msg->get_opcode()); });

    endpoint.listen(s_port);
    endpoint.start_accept();
    endpoint.run();
}

void Server::stop()
{
    endpoint.stop_listening();
    endpoint.stop();
}

bool Server::isNumber(std::string check_string)
{
    for (int i = 0; i < check_string.length(); i++)
    {
        if (isdigit(check_string[i]) == false)
        {
            return false;
        }
    }
    return true;
}
