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
  std::string line;
  std::vector<char> intersection;
  int val, sum = 0;
  while (std::getline(input, line)) {
    std::set first_part(line.begin(), line.begin() + line.size() / 2);
    std::set second_part(line.begin() + line.size() / 2, line.end());
    std::set_intersection(first_part.begin(), first_part.end(),
                          second_part.begin(), second_part.end(),
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