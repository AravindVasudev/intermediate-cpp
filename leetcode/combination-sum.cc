// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        const int size = candidates.size();

        const auto combinations = [&](auto &&combinations, int index, const int target) {
            // Found a combination.
            if (target == 0) {
                result.push_back(path);
                return;
            }

            // Stop recursion.
            if (target < 0) {
                return;
            }

            // Walk all combination branches.
            for (; index < size; index++) {
                path.push_back(candidates[index]);
                combinations(combinations, index, target - candidates[index]);
                path.pop_back();
            }
        };

        combinations(combinations, 0, target);
        return result;
    }
};