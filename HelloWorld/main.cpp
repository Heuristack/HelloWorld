#include <tbb/tbb.h>
#include <iostream>

int main()
{
    class T : public tbb::task {
        public:
        tbb::task * execute(){
            std::cout << "Hello, World!" << std::endl;
            return nullptr;
        }
    };

    tbb::task_scheduler_init init(tbb::task_scheduler_init::automatic);
    T & t = *new(tbb::task::allocate_root())T();
    tbb::task::spawn_root_and_wait(t);
}
