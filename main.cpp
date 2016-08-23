#include <iostream>
#include <cmath>

int main()
{
    double not_a_number = NAN;
    double double_precision_floating_point_number = INFINITY;

    std::cout << std::isnan(not_a_number) << std::endl;
    std::cout << std::isinf(double_precision_floating_point_number) << std::endl;
    std::cout << std::isfinite(double_precision_floating_point_number) << std::endl;

    std::cout << std::numeric_limits<int>::infinity() << std::endl;
    std::cout << std::numeric_limits<double>::infinity() << std::endl;
}
