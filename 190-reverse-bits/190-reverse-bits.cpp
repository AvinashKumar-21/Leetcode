class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        int num=0;
        for(int i=0;i<32;i++)
        {
            num=num<<1;
            int temp=n&1;
            n=n>>1;
            num=num|temp;
        }
        return num;
    }
};