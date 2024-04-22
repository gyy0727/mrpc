#if 0
#include <iostream>
#include <map>
#include <vector>
int main() {
  uint32_t b = 79779799;
  uint32_t d=0;
  std::string a((char*)&b, 4);
  std::cout << a.size() << std::endl;
  a.copy((char*)&d,4,0);
  std::cout << b << std::endl;
  std::cout << a.substr(0, 4) << std::endl;

  return 0;
}
#endif