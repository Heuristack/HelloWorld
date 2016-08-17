#include <boost/compute.hpp>
#include <iostream>
#include <vector>

int main()
{
    boost::compute::device device = boost::compute::system::default_device();
    boost::compute::context context(device);
    boost::compute::command_queue queue(context, device);

    int host_data[] = {1,3,5,7,9};
    boost::compute::vector<int> device_vector(5, context);
    boost::compute::copy(host_data, host_data + 5, device_vector.begin(), queue);

    std::vector<int> host_vector(5);
    boost::compute::copy(device_vector.begin(), device_vector.end(), host_vector.begin(), queue);

    std::cout << device.name() << std::endl;
    for (const int x : host_vector) std::cout << x << std::endl;

    return 0;
}
