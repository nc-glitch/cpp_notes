#include <iostream>
#include <cstring>

struct Vect2
{
    float x, y;
};

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }

    //String(const String& other) = delete; PREVENTS COPIES
    //by default the only method of the shallow copy would be: memcpy(this, &other, sizeof(String));
    String(const String& other)
        : m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String(){ delete[] m_Buffer; }

    char& operator[](unsigned int index){ return m_Buffer[index];}

    //"friend" allows the method to access private data
    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main() {
    Vect2 a = { 2, 3};

    //actually using the copy constructor here (Java would use references here instead)
    Vect2 b = a;
    b.x = 5;

    // "2 3" + "5 3"
    std::cout << a.x << " " << a.y << std::endl << b.x << " " << b.y << std::endl;

    String string = "Cherno";
    String string2 = string;
    std::cout << string << std::endl;

    std::cout << string2 << std::endl;
    // originally caused a crash because the single cloned pointer of the strings cannot be deleted twice
}
