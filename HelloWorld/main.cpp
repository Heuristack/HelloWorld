#include <boost/asio.hpp>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>

void timer_handler(boost::system::error_code)
{
    std::cout << "time up!" << std::endl;
}

int main()
{
    boost::asio::io_service service;
    boost::asio::deadline_timer timer(service, boost::posix_time::seconds(5));
    std::cout << "3 2 1 ... " << std::endl;
    timer.async_wait(timer_handler);
    service.run();
    return 0;
}
