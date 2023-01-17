#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> result;
  string s1, s2;

  for (unsigned long int i = 0; i < strs.size(); i++) {
    vector<string> group;
    group.push_back(strs[i]);
    s1 = strs[i];
    sort(s1.begin(), s1.end());
    for (unsigned long int j = i + 1; j < strs.size(); j++) {
      s2 = strs[j];
      sort(s2.begin(), s2.end());

      if (s1 == s2) {
        group.push_back(strs[j]);
        strs.erase(strs.begin() + (j));
        j--;
      }
    }

    result.push_back(group);
  }

  return result;
}

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
