// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (const int& num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        return heap.top();
    }
};
