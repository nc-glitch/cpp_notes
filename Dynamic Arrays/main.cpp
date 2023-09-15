#include <iostream>
#include <vector>

struct Vertex
{
    float x, y, z;
    Vertex(float x, float y, float z)
    :x(x), y(y), z(z) {}

    Vertex(const Vertex& vertex)
    : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

int main() {
    std::vector<Vertex> vertices; //only has an original size of 2
    vertices.reserve(3); //allocates enough memory for the 3 vectors to be added
    //first created in the main function's stack, and then copied into the vector
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    //emplace constructs the object in place using its constructor parameters
    vertices.emplace_back(7, 8, 9);
}
