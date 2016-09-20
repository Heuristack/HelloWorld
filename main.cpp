#include <iostream>
#include <string>
#include <system_error>
#include <cerrno>
#include <unistd.h>
#include <boost/filesystem.hpp>
#include <readline/history.h>
#include <readline/readline.h>

using namespace std;

int main()
{
    cout << "Current Working Directory: " << boost::filesystem::current_path() << endl;
    int return_code = 0;

    HISTORY_STATE * state = history_get_history_state();
    cout << "history list length = " << state->length << endl;

    return_code = read_history(NULL);
    cout << "read history return code = " << return_code << " : " << strerror(return_code) << endl;

    return_code = add_history("Hello,World!");
    cout << "add history entry return code = " << return_code << " : " << strerror(return_code) << endl;

    HIST_ENTRY * entry = current_history();
    cout << "current history line: " << entry->line << "; data: " << entry->data << endl;
    cout << "current history offset: " << where_history() << endl;
    cout << "history total bytes: " << history_total_bytes() << endl;
}
