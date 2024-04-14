// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanToInt;
        romanToInt.insert({
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        });

        int num = 0;
        int sLen = s.size();
        for (int i = 0; i < sLen; i++) {
            if (i + 1 < sLen && romanToInt[s[i]] < romanToInt[s[i + 1]]) {
                num -= romanToInt[s[i]];
            } else {
                num += romanToInt[s[i]];
            }
        }

        return num;
    }
};
