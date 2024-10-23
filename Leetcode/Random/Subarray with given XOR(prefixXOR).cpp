class Solution {
public:
    int subarraysWithXOR(vector<int>& A, int B) {
        unordered_map<int, int> prefXORcount;

        int curXOR = 0, ans = 0, n = A.size();

        prefXORcount[0] = 1;

        for(int i = 0; i < n; ++i) {
            curXOR ^= A[i];

            int target = curXOR ^ B;

            if(prefXORcount[target] != prefXORcount.end()){
                ans += prefXORcount[target];
            }

            prefXORcount[curXOR]++;
        }
        return ans;
    }
};
