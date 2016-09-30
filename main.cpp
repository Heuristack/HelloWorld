#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;

int main()
{
    try { cout << std::stoi("NaN") << endl; }
    catch (std::logic_error & e) { cout << "logic error: " << e.what() << endl; }
    catch (std::runtime_error & e) { cout << "runtime error: " << e.what() << endl; }
    catch (std::exception & e) { cout << "exception: " << e.what() << endl; }
}
