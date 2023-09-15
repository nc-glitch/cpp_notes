#include <iostream>
#include <future>

// must use mutex to avoid concurrent object modification
// allows objects to be locked and automatically unlocks on lock_guard destruction
// Conceptually should be static, but not truly necessary
static std::mutex s_TestMutex;
static int idx = 0;

static void Func()
{
    std::lock_guard<std::mutex> lock(s_TestMutex);
    idx++;
    std::cout << "hi " << idx << "x\n";
}

int main() {

    // Parallel processing is very useful, but must be thoughtfully implemented

    // can view in default CLion debugger
    // for VS: Debug -> Windows -> Parallel Stacks

    // useful with independent for each loops

    for(int i = 0; i < 10; i++)
        //async calls function asynchronously
        std::async(std::launch::async, Func);

}
