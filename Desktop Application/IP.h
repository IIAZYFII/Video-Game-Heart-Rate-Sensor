#ifndef IP_H
#define IP_H
class IP
{
private:
    int hostname;
    struct hostent *host_entry;
    char *ip_address;
    void checkHostName();
    void checkHostEntry();
    void initHostName();
    void initHostEntry();

public:
    IP();
    ~IP();
    void initIPAddress();
   char * getIPAddress();

    
};

#endif