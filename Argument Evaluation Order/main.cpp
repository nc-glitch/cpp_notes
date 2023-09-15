#include <iostream>

void PrintSum(int a, int b)
{
    std:: cout << a << " + " << b << " = " << (a + b) << std::endl;
}

int main() {

    int value = 0;

    // AVOID SUCH OPERATIONS

    // UNDEFINED BEHAVIOR until c++ 17
    // Varies from compiler to compiler and from system to system otherwise
    // Still undefined order of evaluation

    // C++17: this postfix-expression is sequenced before each expression in the expression-list
    // basically these expressions will not be evaluated at the same time anymore, but one at a time
    PrintSum(value++, value++); // either 1 + 0 or 0 + 1 now

    // Postfix expression
    PrintSum(++value, ++value);


}
