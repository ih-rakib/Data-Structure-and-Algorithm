// https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};

// The formula 1+(n−1)%9 is derived from the properties of numbers modulo 9 and is specifically adjusted to handle the case where 
// n is a multiple of 9. It ensures that we correctly compute the digital root without having to repeatedly sum digits.