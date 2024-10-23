class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> partialSum(n + 1);

        for(int i = 1; i <= n; ++i) partialSum[i] = partialSum[i-1] + arr[i-1];

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j){
                int len = j - i + 1;

                if(len & 1) {
                    ans += partialSum[j] - partialSum[i-1];
                }
            }
        }
        return ans;
    }
};