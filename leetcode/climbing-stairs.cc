// https://leetcode.com/problems/climbing-stairs/
// Top Down
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        return climbStairs(n, memo);
    }

private:
    int climbStairs(int n, vector<int> &memo) {
        if (n <= 2) {
            return n;
        }

        if (memo[n] != 0) {
            return memo[n];
        } 

        memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
        return memo[n];
    }
};

// Bottom Up
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prev = 2, prevTwo = 1;
        int cur = 0;

        for (int i = 2; i < n; i++) {
            cur = prev + prevTwo;
            prevTwo = prev;
            prev = cur;
        }

        return cur;
    }
};
