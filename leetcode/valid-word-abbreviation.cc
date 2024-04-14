// https://leetcode.com/problems/valid-word-abbreviation/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int w = 0, a = 0;
        int wLength = word.size(), aLength = abbr.size();

        while (w < wLength && a < aLength) {
            if (word[w] == abbr[a]) {
                w++;
                a++;
            } else if (isdigit(abbr[a]) && abbr[a] != '0') {
                int num = 0;
                while (a < aLength && isdigit(abbr[a])) {
                    num = num * 10 + (abbr[a++] - '0');
                }

                w += num;
            } else {
                return false;
            }
        }

        return w == wLength && a == aLength;
    }
};
