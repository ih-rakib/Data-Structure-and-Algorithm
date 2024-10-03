// https://leetcode.com/problems/jump-game-iii/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int current = q.front();
            q.pop();

            if(arr[current] == 0) {
                return true;
            }

            int forward = current + arr[current];
            int backward = current - arr[current];

            if(forward < n and !visited[forward]){
                q.push(forward);
                visited[forward] = true;
            }

            if(backward >= 0 and !visited[backward]){
                q.push(backward);
                visited[backward] = true;
            }
        }
        return false;
    }
};