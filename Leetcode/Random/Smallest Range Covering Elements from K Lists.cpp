// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

struct Element {
    int value;
    int valueIndex;
    int listIndex;
};

struct Compare {
    bool operator()(Element const &a, Element const &b) {
        return a.value > b.value; // For a min-heap based on the value
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();

        priority_queue<Element, vector<Element>, Compare> minRangeTracker; // {value, valueIndex, listIndex}

        int rangeStart = 0, rangeEnd = INT_MAX;
        int currentMax = INT_MIN;

        // Initialize the heap with the first number of each list
        for(int i = 0; i < n; ++i) {
            int value = nums[i][0];
            minRangeTracker.push({value, 0, i});
            currentMax = max(currentMax, value); // Track the current max value
        }

        // Process each element from the heap
        while (true) {
            Element minElement = minRangeTracker.top();
            minRangeTracker.pop();

            int currentMin = minElement.value;

            // Check if the current range is smaller
            if (currentMax - currentMin < rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }

            // Move to the next element from the list from which the currentMin was taken
            int indexOfNextElement = minElement.valueIndex + 1;
            int listIndex = minElement.listIndex;

            // Check if the next element exists in the current list
            if (indexOfNextElement < nums[listIndex].size()) {
                int nextValue = nums[listIndex][indexOfNextElement];
                minRangeTracker.push({nextValue, indexOfNextElement, listIndex});
                currentMax = max(currentMax, nextValue); // Update the current max value
            } else {
                // We reached the end of one list, so we stop
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};
