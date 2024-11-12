// https://leetcode.com/problems/most-beautiful-item-for-each-query/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();

        sort(items.begin(), items.end());
        int maxBeauty = 0;

        for(auto &item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            item[1] = maxBeauty;
        }

        int m = queries.size();
        vector<pair<int, int> > queryIndex(m);

        for(int i = 0; i < m; ++i) {
            queryIndex[i] = {queries[i], i};
        }
        sort(queryIndex.begin(), queryIndex.end());

        vector<int> answer(m, 0);

        int k = 0;
        for(auto &[queryPrice, idx] : queryIndex) {
            while(k < items.size() && items[k][0] <= queryPrice) k++; // this loop will break when price > beauty
            if(k > 0) answer[idx] = items[k-1][1]; // that's why items[k-1]
        } 
        return answer;
    }
};

// Author: Ikramul Hasan Rakib