#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("input");
    std::string line;
    double sum = 0;
    int myresult, youraction, myaction;
    while (std::getline(input, line)) {
        youraction = line[0] - 'A' + 1;
        myresult = line[2] - 'X';
        myresult*=3;
        if (myresult == 3) {
            myaction = youraction; 
        } else if (myresult == 0) {
            myaction = (youraction-2+3)%3+1;            
        } else {
            myaction = youraction%3+1;
        }
    sum+=myresult;
    sum+=myaction;
    std::cout << ' ' << myresult << ' ' << myaction << ' ' << sum << std::endl;
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}