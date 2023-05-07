#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <sstream>
#include <vector>

double CalcMedian(std::vector<double>& vector) {
  std::sort(vector.begin(), vector.end());

  size_t size = vector.size();

  if (size % 2 == 0) {
    return (vector[size / 2 - 1] + vector[size / 2]) / 2.0;
  } else {
    return vector[size / 2];
  }
}

double Average(const std::vector<int>& vector) {
  int sum = std::accumulate(vector.begin(), vector.end(), 0);

  if (sum <= 0) return 0;

  return static_cast<double>(sum) / vector.size();
}

std::string AddStopWords(const std::string& query, const std::set<std::string>& stopWords) {
  return query + std::accumulate(
                     stopWords.begin(),
                     stopWords.end(),
                     std::string(),
                     [](const std::string& acc, const std::string& current) { return acc + " -" + current; }
                 );
}

void SortWords(std::string& words) {
  // create an istringstream to split the string into words
  std::istringstream iss(words);

  // vector to store the words
  std::vector<std::string> subStrings(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

  // sort the words lexicographically, ignoring case
  std::sort(subStrings.begin(), subStrings.end(), [](const std::string& a, const std::string& b) {
    std::string lowerA;
    std::string lowerB;
    std::transform(a.begin(), a.end(), std::back_inserter(lowerA), [](const char& c) { return std::tolower(c); });
    std::transform(b.begin(), b.end(), std::back_inserter(lowerB), [](const char& c) { return std::tolower(c); });
    return lowerA < lowerB;
  });

  // rebuild the input string from the sorted words
  words.clear();
  for (const auto& word : subStrings) {
    words += word + " ";
  }
  words.erase(words.end() - 1);  // remove the trailing space
}

int main() {
  std::string string = "quantity AMOUNT Selection Search";

  SortWords(string);

  std::cout << string << '\n';
  return 0;
}
