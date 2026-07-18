class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small=INT_MAX;
        int big=INT_MIN;
        for(int i=0;i<nums.size();i++){
            small=min(small,nums[i]);
            big=max(big,nums[i]);
        }
            for(int i=small;i>=2;i--){
                if((big%i==0) && (small%i==0))return i;
            }
        return 1;
    }
};