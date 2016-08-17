#include <llvm/ADT/StringRef.h>
#include <iostream>

int main()
{
    llvm::StringRef s("Hello,World!");
    std::cout << s.data() << std::endl;
}
