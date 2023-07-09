from typing import List
from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) == 0:
            return []
        if len(strs) == 1:
            return [strs]

        # Defining a dict
        # When the list class is passed as the default_factory argument,
        # then a defaultdict is created with the values that are list
        result = defaultdict(list)

        for word in strs:
            result["".join(sorted(word))].append(word)

        return list(result.values())

    # Slow solution from: https://youtu.be/vzdNOK2oB2E
    def groupAnagrams2(self, strs: List[str]) -> List[List[str]]:
        result = defaultdict(list)

        for word in strs:
            count = [0] * 26
            for character in word:
                count[ord(character) - ord("a")] += 1
            result[tuple(count)].append(word)

        return list(result.values())


s = Solution()
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
anagrams = s.groupAnagrams(strs)
print(anagrams)
