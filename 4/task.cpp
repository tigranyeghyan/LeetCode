#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        int n1_i = 0;
        int n2_i = 0;
        std::vector<int> c;
        for (int i = 0; i < nums1.size() + nums2.size(); ++i)
        {
            if(n1_i >= nums1.size())
            {
                c.push_back(nums2[n2_i]);
                n2_i++;
                continue;
            }
            if(n2_i >= nums2.size())
            {
                c.push_back(nums1[n1_i]);
                n1_i++;
                continue;
            }
            c.push_back(nums1[n1_i] < nums2[n2_i] ? nums1[n1_i++] : nums2[n2_i++]);
        }
        return c.size()% 2 != 0 ? (double)c[c.size()/2] : (double)(c[c.size()/2 - 1] + c[c.size() / 2])/2;
    }
};