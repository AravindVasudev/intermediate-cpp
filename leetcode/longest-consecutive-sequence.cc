// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int longest{0};

        for (const int& num : numsSet) {
            if (!numsSet.contains(num - 1)) {
                int cur = num, streak = 1;
                while (numsSet.contains(++cur)) {
                    streak++;
                }

                longest = std::max(longest, streak);
            }
        }

        return longest;
    }
};
