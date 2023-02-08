#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream input("../input");
  std::string line, first, second;
  int lb1, ub1, lb2, ub2, count = 0;
  while (std::getline(input, line)) {
    first = line.substr(0, line.find(','));
    second = line.substr(line.find(',') + 1, line.size());
    lb1 = std::stoi(first.substr(0, first.find('-')));
    ub1 = std::stoi(first.substr(first.find('-') + 1, first.size()));
    lb2 = std::stoi(second.substr(0, second.find('-')));
    ub2 = std::stoi(second.substr(second.find('-') + 1, second.size()));
    if ((lb1 <= lb2 && ub2 <= ub1) || (lb2 <= lb1 && ub1 <= ub2)) {
      count++;
    }
  }
  input.close();
  std::cout << "The number of fully contained ranges is: " << count
            << std::endl;
  return 0;
}
