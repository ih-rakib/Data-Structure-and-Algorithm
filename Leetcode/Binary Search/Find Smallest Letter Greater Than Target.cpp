// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int left = 0, right = n - 1;
        char ans = letters[0];

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(letters[mid] > target){
                ans = letters[mid];
                right = mid - 1; 
            }else {
                left = mid + 1;
            }
        }
        return ans;
    }
};