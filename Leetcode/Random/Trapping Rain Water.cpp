// https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(left < right) { 
            if(height[left] < height[right]){
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
                left++;
            }else {
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};

/*

- water trapped above each bar is determined by the bars towards its left and right
- specifically smallest of two boundary(right and left) - water level is limited by this shorter boundary
- if(height[left] < height[right]) that means left boundary is shorter - so process left
- otherwise process right


*/