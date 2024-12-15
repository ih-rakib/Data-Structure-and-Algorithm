// https://leetcode.com/problems/maximum-average-pass-ratio/

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto marginal_gain = [](int pass, int total) { // marginal_gain: gain for adding one student
            return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
        };

        priority_queue<pair<double, pair<int,int>>> pq; // {gain, {passi, totali}}

        for(auto &cls : classes) {
            int pass = cls[0], total = cls[1];
            double gain = marginal_gain(pass, total);
            pq.push({gain, {pass, total}});
        }

        while(extraStudents--) {
            auto [g, p] = pq.top(); pq.pop();
            int pass = p.first + 1, total = p.second + 1; // adding an extra that's why + 1
            double newGain = marginal_gain(pass, total);
            pq.push({newGain, {pass, total}});
        }

        double totalRatio = 0.0;

        while(!pq.empty()) {
            auto [g, p] = pq.top(); pq.pop();
            totalRatio += (double)p.first / p.second;
        }
        return totalRatio / classes.size();
    }
};

// Author: Ikramul Hasan Rakib