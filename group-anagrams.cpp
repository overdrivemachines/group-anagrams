#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> result;
  vector<string> sorted_strs;

  // sorting each string of the vector. Inserting the sorted string into a new vector.
  // ["eat","tea","tan","ate","nat","bat"] => ["aet", "aet", "ant", "aet", "ant", "abt" ]
  for (string str: strs) {
    sort(str.begin(), str.end());
    sorted_strs.push_back(str);
  }


  for (unsigned long int i = 0; i < sorted_strs.size(); i++) {
    vector<string> group;
    group.push_back(strs[i]);
    for (unsigned long int j = i + 1; j < strs.size(); j++) {
      if (sorted_strs[i] == sorted_strs[j]) {
        group.push_back(strs[j]);
        strs.erase(strs.begin() + j);
        sorted_strs.erase(sorted_strs.begin() + j);
        j--;
      }
    }

    result.push_back(group);
  }

  return result;
}

// Print vector of vectors of string
// e.g. [[eat, tea, ate], [tan, nat], [bat]]
void printv(vector<vector<string>> groupstrs) {
  // vector<string> strs;
  string output = "[";

  for (auto &strs : groupstrs) {
    output.append("[");
    for (auto str : strs) {
      output.append(str);
      output.append(", ");
    }
    output.erase(output.length() - 2);
    output.append("], ");
  }

  if (groupstrs.size() >= 1)
    output.erase(output.length() - 2);
  output.append("]");

  cout << output;
}

int main(int argc, char const *argv[]) {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // vector<string> strs = {"eat", "tea", "tan"};

  printv(groupAnagrams(strs));

  return 0;
}
