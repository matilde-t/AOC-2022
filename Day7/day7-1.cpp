#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct file {
  int dim;
  std::string name;
};

struct directory {
  std::string name;
  std::vector<struct directory> subdirectories;
  std::vector<struct file> files;
};

int main() {
  std::ifstream input("../input");
  std::string line;
  struct directory root;
  while (std::getline(input, line)) {
    if (line.front() == '$') {
      std::string command = line.substr(2, 2);
      if (command == "cd") {
        root.name = line.substr(line.rfind(' ') + 1, line.size());
      } else if (command == "ls") {
        continue;
      } else {
        std::cout << "Unexpected command: " << command << std::endl;
      }
    } else {
      auto dim = line.substr(0, line.find(' '));
      auto name = line.substr(line.find(' ') + 1, line.size());
      if (dim == "dir") {
        struct directory dir;
        dir.name = name;
        root.subdirectories.push_back(dir);
      } else {
        struct file f;
        f.name = name;
        f.dim = std::stoi(dim);
        root.files.push_back(f);
      }
    }
  }
      return 0;
}