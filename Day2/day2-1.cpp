#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("input");
    std::string line;
    double sum = 0;
    int myaction, youraction;
    while (std::getline(input, line)) {
        youraction = line[0] - 'A' + 1;
        myaction = line[2] - 'X' + 1;
        if (myaction == youraction) {
            sum+=3;
        } else if ((myaction+1)%3 == youraction%3) {
            sum+=0;
        } else {
            sum+=6;
        }
    sum+=myaction;
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}