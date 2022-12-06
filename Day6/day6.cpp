#include <fstream>
#include <iostream>
#include <set>
#include <string>
#define N 4

int main() {
  std::ifstream input("input");
  std::string line;
  std::getline(input, line);
  for (auto begin = line.begin(); begin < line.end() - N; begin++) {
    std::set token(begin, begin + N);
    if (token.size() == N) {
      std::cout << begin + N - line.begin() << std::endl;
      return 0;
    }
  }
  return 0;
}