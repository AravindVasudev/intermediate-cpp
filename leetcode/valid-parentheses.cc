// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(') {
                stack.push(c);
                continue;
            }

            if (stack.empty() ||
                (c == ')' && stack.top() != '(') ||
                (c == ']' && stack.top() != '[') ||
                (c == '}' && stack.top() != '{')) {
                    return false;
            }

            stack.pop();
        }

        return stack.empty();
    }
};
