#include <boost/compute.hpp>
#include <iostream>

int main()
{
    boost::compute::device d = boost::compute::system::default_device();

    std::cout << d.name() << ": " << "Hello,Wrold!" << std::endl;

    return 0;
}
