#include "Instrumentor.h"

// HELPFUL MACROS
#define PROFILING true
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__) // __FUNCSIG__ provides entire function signatures
#else
#define PROFILE_SCOPE(name)
#endif

void func1()
{
    //PROFILE_SCOPE("FUNC_NAME") works as well, but must use for all
    PROFILE_FUNCTION();
    for(int i = 0; i < 1000; i++)
        std::cout << "Hello World #" << i << std::endl;
}

void func2()
{
    PROFILE_FUNCTION();
    for(int i = 0; i < 1000; i++)
        std::cout << "Hello World #" << sqrt(i) << std::endl;
}

void RunBenchmarks()
{
    PROFILE_FUNCTION();
    func1();
    func2();
}

int main() {

    // use chrome://tracing

    // the header is devoted to transforming the file into a JSON output and implementing a timing class
    Instrumentor::Get().BeginSession("Profile");
    RunBenchmarks();
    Instrumentor::Get().EndSession();

    //JSON save under the CMAKE folder for the project

    //Drag and drop json in Chrome Tracing

}
