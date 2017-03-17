#include <yadisk/client.hpp>

void main()
{
   `yadisk::Client Client { "token" };
  
    // Download example.dat 
    auto response = Client.download("example.dat", "example.dat"); 

    // Download example.dat in "/usr/local/tmp/"
    response = Client.download("disk:/example.dat", "/usr/local/tmp/example.dat"); 

    // Download example.dat, responce join list key "name", "_embedded.items.path"
    response = Client.download("example.dat", "example.dat", new std::list<std::string>{"name","_embedded.items.path"});     
}
