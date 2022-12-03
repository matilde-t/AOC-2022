#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

int main() {
  std::ifstream input("input");
  std::string line1, line2, line3;
  std::vector<char> intersection;
  int val, sum = 0;
  while (std::getline(input, line1) && std::getline(input, line2) &&
         std::getline(input, line3)) {
    std::vector<char> temp_intersec;
    std::set elf1(line1.begin(), line1.end());
    std::set elf2(line2.begin(), line2.end());
    std::set elf3(line3.begin(), line3.end());
    std::set_intersection(elf1.begin(), elf1.end(),
                          elf2.begin(), elf2.end(),
                          std::back_inserter(temp_intersec));
    std::set_intersection(temp_intersec.begin(), temp_intersec.end(),
                          elf3.begin(), elf3.end(),
                          std::back_inserter(intersection));
  }
  for (auto el : intersection) {
    if (std::isupper(el)) {
      val = el - 'A' + 27;
    } else {
      val = el - 'a' + 1;
    }
    std::cout << el << " : " << val << std::endl;
    sum += val;
  }
  std::cout << "The sum is: " << sum << std::endl;
  input.close();
  return 0;
}