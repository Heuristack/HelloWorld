#include <system_error>
#include <ios>
#include <future>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    cout << std::is_error_code_enum<std::errc>::value << endl;

//  std::error_code ec(EAFNOSUPPORT, std::generic_category());

    std::error_code ec = std::make_error_code(std::errc::address_family_not_supported);
//  std::error_code ec = std::make_error_code(std::io_errc::stream);
//  std::error_code ec = std::make_error_code(std::future_errc::no_state);

    cout << "[" << ec.value() << ":" << ec.category().name() << ":\"" << ec.category().message(ec.value()) << "\":\"" << ec.message() << "\"]" << endl;
    if (ec == std::errc::address_family_not_supported) cout << "we can compare error code against errc enumerators" << endl;
}
