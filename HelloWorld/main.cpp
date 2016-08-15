#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>

void timer_handler(const boost::system::error_code &, boost::asio::deadline_timer * timer, int * count)
{
    if (*count < 5) {
        std::cout << *count << std::endl;
        (*count)++;
        timer->expires_at(timer->expires_at() + boost::posix_time::seconds(1));
        timer->async_wait(boost::bind(timer_handler, boost::asio::placeholders::error, timer, count));
    }
}

int main()
{
    boost::asio::io_service service;
    boost::asio::deadline_timer timer(service, boost::posix_time::seconds(5));
    int count = 0;
    std::cout << "3 2 1 ... " << std::endl;

    timer.async_wait(boost::bind(timer_handler, boost::asio::placeholders::error, &timer, &count));
    service.run();

    std::cout << count << std::endl;
    return 0;
}
