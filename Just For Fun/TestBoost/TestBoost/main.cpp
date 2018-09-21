#include <boost/asio.hpp>
#include <iostream>
using namespace boost;

int main()
{
    std::string host = "samplehost.com";
    std::string port_num = "3333";
    
    asio::io_service ios;
    
    asio::ip::tcp::resolver::query resolver_query(host, port_num, asio::ip::tcp::resolver::query::numeric_service);
    
    asio::ip::tcp::resolver resoler(ios);
    
    boost::system::error_code ec;
    
    asio::ip::tcp::resolver::iterator it = resoler.resolve(resolver_query, ec);
    
    return 0;
}
