// https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/reverse-a-linked-list

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* cur = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        while(cur != nullptr) { // 1, 2, 3, 4
            next = cur -> next; // 2
            cur -> next = prev; // null
            prev = cur; // 1
            cur = next; // 2
        }
        return prev;
    }
};


// Author: Ikramul Hasan Rakib