// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<pair<int,int> > arrivals;

        for(int i = 0; i < n; ++i) {
            arrivals.push_back({times[i][0], i}); // {arrivalTime, friendId}
        }

        sort(arrivals.begin(), arrivals.end());

        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > occupiedChairs; // {leaving time, chair number}

        priority_queue<int, vector<int>, greater<int> > availableChairs;

        for(int i = 0; i < n; ++i) {
            availableChairs.push(i); // all are available intitially
        }

        // process each one
        for(auto &[arrivalTime, friendId] : arrivals) {
            int leavingTime = times[friendId][1];

            while(!occupiedChairs.empty() and occupiedChairs.top().first <= arrivalTime) { // chair becomes free
                int freedChair = occupiedChairs.top().second;
                occupiedChairs.pop();
                availableChairs.push(freedChair);
            }

            int assignedChair = availableChairs.top();
            availableChairs.pop();
            occupiedChairs.push({leavingTime, assignedChair});

            if(friendId == targetFriend) {
                return assignedChair;
            }
        }
        return -1;
    }
};