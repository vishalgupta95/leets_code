
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); int n=nums.size()-1;
        return max(nums[0]*nums[1]*nums[n], nums[n-2]*nums[n-1]*nums[n]);
    }