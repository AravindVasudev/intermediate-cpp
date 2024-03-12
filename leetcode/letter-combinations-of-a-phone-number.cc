class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        string path;

        // I know, I know, this is a poor way of achieving recursive with lambdas.
        const auto dfs = [&digits, &letters, &output](auto &&dfs, int index, string &path) {
            // Found a combination.
            if (index == digits.size()) {
                output.push_back(path);
                return;
            }

            const int letterIndex = digits[index] - '0' - 2; // (to int) -> offset.
            const string &letterSet = letters[letterIndex];
            for (char letter : letterSet) {
                path.push_back(letter);
                dfs(dfs, index + 1, path);
                path.pop_back();
            }
        };

        // Navigate all combinations.
        dfs(dfs, 0, path);

        return output;
    }
};