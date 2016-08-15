#include <boost/asio.hpp>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
    boost::asio::io_service service;
    boost::asio::deadline_timer timer(service, boost::posix_time::seconds(5));
    timer.wait();
    std::cout << "time up!" << std::endl;

    return 0;
}
