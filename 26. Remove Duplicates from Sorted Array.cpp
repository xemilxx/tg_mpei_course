//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() == 0) { 
            return 0;
        }
        
        int l = 0;
        int r = 1;
        
        while(l < nums.size() && r < nums.size()) {
            if (nums[l] == nums[r]) r++;
            else swap(nums[++l], nums[r++]);
        }
        
        return l+1;
        
    }
};
