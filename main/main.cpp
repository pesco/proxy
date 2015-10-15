
#include <proxy/ProxyAPI.h>

#include <iostream>

using namespace proxy;


int main (int argc, char *argv[])
{
    std::error_code ec;

	ProxyConfig config;
	config.client.port = 8080;

    if(!config.client.SetAddress("127.0.0.1", ec))
    {
        std::cerr << "Config error: " << ec.message() << std::endl;
        return -1;
    }

	proxy::Run(config, ec);
	
	if(ec)
	{
	  std::cerr << "Proxy error: " << ec.message() << std::endl;
	  return -1;
	}
	
	return 0;
}
