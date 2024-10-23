// https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> res(n+m, 0);

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j) {
                int mul = (num1[i]-'0') * (num2[j]-'0');
                res[i+j] += mul;
                res[i+j+1] += (res[i+j] / 10);
                res[i+j] %= 10;
            }
        }

        while(res.back() == 0) {
            res.pop_back();
        }
        
        string product;
        for(int dig: res) {
            product += (dig + '0'); // to_string(dig)
        }
        reverse(product.begin(), product.end());

        return product;
    }
};


// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         int a = stoi(num1);
//         int b = stoi(num2);
//         long long c = a * b;
//         return to_string(c);
//     }
// };