// https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        int last[10] = {0};

        // find last occurence of each digit
        for(int i = 0; i < s.length(); ++i) {
            last[s[i] - '0'] = i;
        }

        for(int i = 0; i < s.length(); ++i) {
            // for each position check if we can find a digit which is greater than current one
            for(int digit = 9; digit > s[i]-'0'; --digit){ // s[i] - '0' = current digit
                if(last[digit] > i) { // there is a larger digit in right of i'th digit(i: current digit position)
                    swap(s[i], s[last[digit]]); // last[digit] -> it's a position, s[last[digit]] -> digit at that position
                    return stoi(s);
                }
            }
        }
        return num;
    }
};