#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream input("../input");
  std::string line;
  std::vector<std::deque<char>> stacks;
  int quantity, from, to;
  std::getline(input, line);

  int N = (line.size() + 1) / 4;
  for (auto i = 0; i < N; i++) {
    stacks.push_back(std::deque<char>());
    if (isalpha(line[4 * i + 1])) {
      stacks[i].push_back(line[4 * i + 1]);
    }
  }
  while (std::getline(input, line) && !line.empty()) {
    for (auto i = 0; i < N; i++) {
      if (isalpha(line[4 * i + 1])) {
        stacks[i].push_back(line[4 * i + 1]);
      }
    }
  }
  while (std::getline(input, line)) {
    quantity = std::stoi(line.substr(5, line.find(" from ")));
    from = std::stoi(
               line.substr(line.find(" from ") + 6, line.find(" from ") + 7)) -
           1;
    to = line.back() - '0' - 1;
    for (auto i = 0; i < quantity; i++) {
      stacks[to].push_front(stacks[from].front());
      stacks[from].pop_front();
    }
  }
  for (auto el : stacks) {
    std::cout << el.front();
  }
  input.close();
  return 0;
}