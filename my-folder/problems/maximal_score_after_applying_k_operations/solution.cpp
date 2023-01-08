class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> heap;
        for (auto num : nums) {
            heap.push(num);
        }
        long long score = 0;
        for (int i = 0; i < k; i++) {
            long long maxElement = heap.top();
            score += maxElement;
            heap.pop();
            heap.push(ceil(maxElement*1.0 / 3*1.0));
        }
        return score;
    }
};