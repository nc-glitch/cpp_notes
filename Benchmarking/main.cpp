#include <iostream>

#include <chrono>

class Timer{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
public:
    Timer()
    {
        m_StartTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        Stop();
    }
    void Stop()
    {
        auto EndTimePoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();

        long long duration = end - start;
        double ms = duration * .001;

        std::cout << "Runtime: " << ms << std::endl;
    }
};

int main() {

    //BENCHMARKING VARIES AND IS APPLICATION SPECIFIC (ex: fps in game or run-time for rendering)
    //Using an auto-destructing Timer class
    //can be integrated within structs to process lifetime

    int value = 0;
    {
        Timer t;
        for (long i = 0; i < 100000000; i++)
            value += 2;
    }

    std::cout << value << std::endl;

}
