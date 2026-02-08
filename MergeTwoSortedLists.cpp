// Merge Two Sorted Lists
// Easy
// Topics
// premium lock icon
// Companies
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.with best time complexity and space complexity

#include <iostream>
using namespace std;
struct ListNode {  // Definition for singly-linked list.
    int val;        // node value
    ListNode* next;     // pointer to the next node
    ListNode() : val(0), next(nullptr) {}  // default constructor
    ListNode(int x) : val(x), next(nullptr) {} // constructor with value
    ListNode(int x, ListNode* next) : val(x), next(next) {}  // constructor with value and next pointer
};  
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the start of the merged list
        ListNode dummy;
        ListNode* tail = &dummy;

        // Traverse both lists and append the smaller value to the merged list
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // If there are remaining nodes in either list, append them
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // Return the merged list, which starts from the next of dummy node
        return dummy.next;
    }
};

int main() {
    // Example usage:
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print merged list
    ListNode* current = mergedList;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Free allocated memory (not shown here for brevity)

    return 0;
}


