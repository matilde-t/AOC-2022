#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <queue>

int main(void) {
std::ifstream input("input");
std::string line;
std::priority_queue<int, std::vector<int>, std::greater<int>> max;
int count = 0;
while (getline (input, line)) {

  if (line.empty()) {
    if (max.size()<3) {
        max.push(count);
    } else {
        if (count > max.top())  {
            max.pop();
            max.push(count);
        }
        
    }
    count = 0;
  } else {
        count += std::stoi(line);
    }
    
}
int sum = 0;
while (max.size()) {
    sum+=max.top();
    max.pop();
}
std::cout << "The sum is " << sum << std::endl;
input.close();
return 0;
}