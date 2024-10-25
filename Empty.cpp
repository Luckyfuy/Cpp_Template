#include <iostream>
#include <limits>

int main() {
    std::ios::sync_with_stdio(false);

    

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}