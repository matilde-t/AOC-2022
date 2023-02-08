#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("../input");
  std::vector<std::vector<int>> map;
  std::string line;
  int visible = 0;
  while (std::getline(input, line)) {
    std::vector<int> row;
    for (auto el : line) {
      row.push_back((int)el - '0');
    }
    map.push_back(row);
  }
  visible += 2 * (map.size() + map[0].size() - 1) - 2;
  for (auto i = 1; i < map.size() - 1; i++) {
    for (auto j = 1; j < map[0].size() - 1; j++) {
      std::cout << map[i][j] << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}