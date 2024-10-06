// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = ""; 

        while(i >= 0 or j >= 0 or carry) {
            int sum = carry;

            if(i >= 0) {
                sum += (a[i] - '0');
                i--;
            }
            if(j >= 0) {
                sum += (b[j] - '0');
                j--;
            }

            res += ((sum % 2) + '0'); // to_string(sum % 2)
            carry = sum / 2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};