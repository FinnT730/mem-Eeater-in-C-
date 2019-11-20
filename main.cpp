#include <iostream>
#include <memory.h>

int main() {

    // simple usage
    char source[] = "this is here to be in ram, so if this is done, you might get something completely random after that. This is how ram works.", dest[9000];
    std::memcpy(dest, source, sizeof dest);
    for (char c : dest)
        std::cout << c << ' ';

    // reinterpreting
    double d = 10397;
  std::int64_t n = *reinterpret_cast<std::int64_t*>(&d); // aliasing violation
    //std::int64_t n;
    std::memcpy(&n, &d, sizeof d); // OK

    std::cout << std::hexfloat << d << " is " << std::hex << n
              << " as an std::int64_t\n";

    return 0;
}