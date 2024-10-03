// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;

        bool isNegative = (dividend < 0) ^ (divisor < 0); // if 1 then negative sign(divisor and dividend have different sign)

        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);
        long long quotient = 0;

        while(absDividend >= absDivisor) {
            long long temp = absDivisor, multiple = 1;

            while(absDividend >= (temp << 1)){
                temp <<= 1; // temp = temp * 2
                multiple <<= 1; // multiple = multiple * 2
            }
            absDividend -= temp;
            quotient += multiple;
        }
    
        return (isNegative ? -quotient : quotient);
    }
};