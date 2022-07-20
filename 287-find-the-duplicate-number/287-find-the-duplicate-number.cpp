class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int ele=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])]<0)
            {
                ele=abs(nums[i]);
                break;
            }
            nums[abs(nums[i])]=-1*nums[abs(nums[i])];
        }
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]*-1;
        return ele;
    }
};