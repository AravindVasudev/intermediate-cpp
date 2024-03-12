// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area{};
        int left{}, right{static_cast<int>(height.size()) - 1};

        while (left < right) {
            int minHeight = std::min(height[left], height[right]);
            area = std::max(area, minHeight * (right - left));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return area;
    }
};