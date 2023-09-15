#include <iostream>
#include <bitset>

int main() {

    // << >>: bit shift left + right
    // & | : and + or
    // ^ ~: xor + not

    // can be overloaded: hence cout & cin

    int a = 5; // allocated 4 bytes and sets them as 00000101,00000000,00000000,00000000
    a<<=2;
    std::cout << "two right: " << a << std::endl;

    a = a>>4;
    // rounds down
    std::cout <<"two right: " << a << std::endl;

    /*
    USING OPERATORS (don't forget =)
    <<: shifts left by specified num: doubles each time
    >>: shifts right by specified num: halves each time
    &: subtract bits
    |: combine bits
    ^: useful for hashing
    ~: using for inverting bits
    */

    // Using the Rest

    // & IS NOT &&
    bool bAnd = 0 & 1;
    // ONLY 1 & 1 = 1, else 0

    // ex use: checking 5th bit:
    // compare 101100101 with 00010000
    // if result = 32, 5th bit = 1, else 0

    bAnd = 0 & 0;
    // ONLY 0 | 0 = 1, else 1

    uint8_t bit1 = 125;
    uint8_t compare = 31;
    uint8_t ans = bit1&compare;

    std::cout << (int)ans << std::endl;
    // ans = 32 since & is true for the 5th bit

    // combining with or
    int b1 = 0b0101;
    int b2 = 0b10110;
    b2<<=4;
    int c = b1 | b2;

    // bitset is needed to convert from dec to bin
    std::cout << std::bitset<9>(c) << std::endl;


    // XOR ^ : only true if the bits are opposites
    // useful with and


    // NOT ~
    int swap = 0b000100000;
    swap = ~swap;
    c = c&swap;

    // c's 4th bit is now 0
    std::cout << std::bitset<9>(c) << std::endl;

    b1 = 1101;
    b2 = b1 ^ b1;
    // b2 = 0 (funny thing, it's occasionally faster than actually setting to 0)

}
