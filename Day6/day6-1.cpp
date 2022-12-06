#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main () {
    std::ifstream input("input");
    std::string line;
    std::getline(input, line);
    int N = line.size();
    auto begin = line.begin();
    for (auto i=0; i<N-4; i++) {
        std::set token(begin, begin+4);
        if (token.size()==4) {
            std::cout << begin + 4 - line.begin() << std::endl;
            return 0;
        }
        begin++;
    }
    return 0;
}