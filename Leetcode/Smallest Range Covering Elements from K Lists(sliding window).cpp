class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, pair<int,int>>> elements; // {value, {listIndex, elementIndex}}

        // Step 1: Flatten the 2D nums array into a single list of elements.
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < nums[i].size(); ++j){
                elements.push_back({nums[i][j], {i, j}}); // Store value and its position
            }
        }

        // Step 2: Sort all the elements based on the value.
        sort(elements.begin(), elements.end()); // Sort by value to help with sliding window.

        // Initialize sliding window pointers and variables to track the range.
        int left = 0, right = 0; // Two pointers for sliding window
        int rangeStart = -1, rangeEnd = -1; // Store the result range
        int validLists = 0; // Count of valid lists in the current window
        unordered_map<int, int> freq; // Frequency map to track the lists in the window

        // Step 3: Sliding window approach.
        while (right < elements.size()) {
            // Add the element on the right of the window to the frequency map
            auto [value, indexes] = elements[right]; // Get the value and its position
            int listIndex = indexes.first; // Extract the list index

            // If this is the first time we are adding a value from this list, increment validLists
            if (++freq[listIndex] == 1) {
                validLists++; // We now have a new list included in the window
            }

            // Step 4: Try to shrink the window from the left if it covers all lists.
            while (validLists == nums.size()) { // When the window contains at least one element from every list
                int currentRangeStart = elements[left].first; // The smallest value in the window
                int currentRangeEnd = elements[right].first; // The largest value in the window

                // Update the result range if the current range is smaller
                if (rangeStart == -1 || currentRangeEnd - currentRangeStart < rangeEnd - rangeStart) {
                    rangeStart = currentRangeStart; // Update range start
                    rangeEnd = currentRangeEnd;     // Update range end
                }

                // Remove the element on the left from the window
                auto [leftValue, leftIndexes] = elements[left];
                freq[leftIndexes.first]--; // Decrease the frequency of the list that the left element belonged to

                // If the list no longer has any elements in the window, reduce validLists count
                if (freq[leftIndexes.first] == 0) {
                    validLists--; // No valid list from this list in the window anymore
                }

                left++; // Shrink the window from the left
            }

            right++; // Expand the window from the right
        }

        // Step 5: Return the smallest range
        return {rangeStart, rangeEnd};
    }
};



/*



# Using Priority Queue


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



*/