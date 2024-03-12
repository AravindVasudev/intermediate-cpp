// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the vector.
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> result {};
        int N = nums.size();

        for (int i = 0; i < N && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, result);
            }
        }

        return result;
    }

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& result) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            if (total < 0) {
                left++;
            } else if (total > 0) {
                right--;
            } else {
                result.push_back({nums[i], nums[left++], nums[right--]});
                while (left < right && nums[left] == nums[left - 1]) left++;
            }
        }
    }
};