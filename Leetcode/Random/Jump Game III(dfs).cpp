// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);

        return dfs(arr, start, visited);
    }

    private:
        bool dfs(vector<int> &arr, int index, vector<bool> &visited) {
            // base
            if(index < 0 or index >= arr.size() or visited[index]){
                return false;
            }

            if(arr[index] == 0) {
                return true;
            }

            visited[index] = true;

            bool forwardJump = dfs(arr, index + arr[index], visited);
            bool backwardJump = dfs(arr, index - arr[index], visited);

            return forwardJump || backwardJump;
        }
};