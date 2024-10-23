// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        vector<vector<int> > dp(n+1, vector<int> (m+1, 0));

        // dp[i][j] = min # of operation needed to convert first i character of word1 to first j character of word2
        // word[0,1,2,....i-1] to word[0,1,2,...j-1]

        // base case 
        dp[0][0] = 0; // empty string to empty string;

        // if word1 is empty we need j insertion
        for(int j = 1; j <= m; ++j) {
            dp[0][j] = j; 
        }

        // if word2 is empty we need i deletion
        for(int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }

        // otherwise fill the dp 
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    int insertion = dp[i][j-1] + 1; 
                    int deletion = dp[i-1][j] + 1; 
                    int replacement = dp[i-1][j-1] + 1; 

                    dp[i][j] = min({insertion, deletion, replacement});
                }  
            }
        }
        return dp[n][m];
    }
};


/*

Insertion (dp[i][j-1] + 1):
    This represents converting the first i characters of word1 to the first j-1 characters of word2. Then, we insert a character into word1 to match word2[j-1], so we move to the state where both word1 and word2 are aligned up to j characters.


Deletion (dp[i-1][j] + 1):
    This represents converting the first i-1 characters of word1 to the first j characters of word2. Then, we delete the ith character of word1, bringing it down to i-1 characters.

Replacement (dp[i-1][j-1] + 1):
    This represents converting the first i-1 characters of word1 to the first j-1 characters of word2. Then, we replace the ith character of word1 with the jth character of word2, making both strings aligned at the ith and jth positions.

*/