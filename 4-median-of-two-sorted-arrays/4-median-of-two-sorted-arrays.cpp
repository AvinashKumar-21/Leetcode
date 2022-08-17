class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int t=nums1.size()+nums2.size();
        int l=0,h=nums1.size();
        while(h>=l)
        {
            int cut1=l+(h-l)/2;
            int cut2=(t+1)/2-cut1;
            
            int l1,l2,r1,r2;
            l1=cut1==0?INT_MIN:nums1[cut1-1];
            l2=cut2==0?INT_MIN:nums2[cut2-1];
            
            r1=cut1==nums1.size()?INT_MAX:nums1[cut1];
            r2=cut2==nums2.size()?INT_MAX:nums2[cut2];
            if(l1<=r2 && l2<=r1)
            {
                if(t%2==0)
                return (max(l1,l2)+min(r1,r2))/2.0;
                else
                return max(l1,l2);
            }
            else if(l1>r2)
                h=cut1-1;
            else
                l=cut1+1;
        }
        return 0.0;
    }
};