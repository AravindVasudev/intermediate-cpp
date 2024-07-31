// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int longest{0};

        for (int start = 0, end = 0; end < s.size(); end++) {
            if (window.contains(s[end])) {
                start = std::max(window[s[end]], start);
            }

            window[s[end]] = end + 1;
            longest = std::max(longest, end - start + 1);
        }

        return longest;
    }
};
