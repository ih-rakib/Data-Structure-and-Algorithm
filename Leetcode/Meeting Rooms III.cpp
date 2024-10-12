// https://leetcode.com/problems/meeting-rooms-iii/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int> > availableRooms; 
        priority_queue<pair<long long,int>, vector<pair<long long,int> > , greater<pair<long long, int> > > occupiedRooms; // {endTime, roomNumber}

        for(int i = 0; i < n; ++i) {
            availableRooms.push(i); // all rooms are available initially
        }

        vector<long long> count(n, 0); // to store how many times each room is used

        // process meetings
        for(auto &meeting : meetings) {
            long long start = meeting[0], end = meeting[1], duration = end - start;

            // find free rooms available before current meeting starts
            while(!occupiedRooms.empty() and occupiedRooms.top().first <= start) { // occupiedRooms.top().first = endTime
                int freedRoom = occupiedRooms.top().second; // occupiedRooms.top().second = roomNumber | roomNumber becomes available
                availableRooms.push(freedRoom);
                occupiedRooms.pop();
            }

            // check if there is an available room for current meeting
            if(!availableRooms.empty()) {
                int roomNumber = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({end, roomNumber}); // push current meetings ending time and roomNumber
                count[roomNumber]++; // increment count of meeting held in this roomNumber
            }else {
                // no rooms are available, so delay the meeting
                auto earliestFreeRoom = occupiedRooms.top(); // earliestFreeRoom: earliest room that will be free
                long long currentEnd = earliestFreeRoom.first;
                int currentRoomNumber = earliestFreeRoom.second;
                occupiedRooms.pop();
                long long newEnd = currentEnd + duration;
                occupiedRooms.push({newEnd, currentRoomNumber});
                count[currentRoomNumber]++;
            }
        }

        return max_element(count.begin(), count.end())- count.begin();
    }
};

/*

step 1: Sort the meetings by start time
step 2: Initialize priority queues
            availbleRooms: for storing availableRooms in sorted order
            occupiedRooms: for storing current meeting {endTime, roomNumber}
step 3: Start processing meetings one by one
step 4: Free the occupied room if possible(occupiedRooms endTime <= current start) and push it to available rooms
step 5: Now 2 case possible 
            case 1: There are rooms available for conducting current meeting
            case 2: No rooms available
step 6: (solving for case 1) : (rooms available)
       - conduct a meeting in this available roomNumber
       - remove it from availableRooms(since it is not available now) 
       - store it into occupiedRooms({endTime, roomNumber})
       - increament the count of roomNumber

       (solving case 2) : (no rooms available)
       - from the occupiedRooms, find earliest possible room that will be free (earliestFreeRoom)
       - update the occupiedRooms by storing newEnd and currentRoomNumber (occupiedRooms.push({newEnd, currentRoomNumber});)
       - increament the count of  currentRoomNumber
step 7: find maximum number stored in count(maximum number of meeting held in a room)


*/