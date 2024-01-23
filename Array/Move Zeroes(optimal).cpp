// https://leetcode.com/problems/move-zeroes/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), k = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                k = i;
                break;
            }
        }

        if (k != -1)
        {
            for (int i = k + 1; i < n; ++i)
            {
                if (nums[i] != 0)
                {
                    swap(nums[i], nums[k]);
                    k++;
                }
            }
        }
    }
};

// Author: Ikramul Hasan Rakib