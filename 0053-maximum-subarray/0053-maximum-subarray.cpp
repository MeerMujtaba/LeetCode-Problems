class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0; int maxSum = INT_MIN;

        for(int i : nums){
            currSum += i;
            maxSum = max(currSum, maxSum);

            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};