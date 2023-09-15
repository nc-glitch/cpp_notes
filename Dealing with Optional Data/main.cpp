#include <iostream>
#include <fstream>

#include <optional>

std::optional<std::string> ReadFileAsString(const std::string& filepath)
{
    std::ifstream stream(filepath);
    if(stream)
    {
        std::string result;
        // read file
        stream.close();
        return result;
    }

    return {};
}

int main() {

    //read in
    std::optional<std::string> data = ReadFileAsString("data.txt");

    std::string value = data.value_or("Not Present");

    //could do "if(data.has_value())" instead
    if(data)
    {
        std::cout << "File read successfully\n";
    }
    else
    {
        std::cout << "File could not be opened\n";
    }

}
