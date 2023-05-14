#include <cassert>
#include <iostream>

bool IsPalindrome(const std::string& string) {
  int size = static_cast<int>(string.size());
  int middle = size / 2;

  for (int i = 0; i < middle; i++) {
    if (string[i] != string[size - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  assert(IsPalindrome("radar") == 1);
  assert(IsPalindrome("kick") == 0);

  return 0;
}