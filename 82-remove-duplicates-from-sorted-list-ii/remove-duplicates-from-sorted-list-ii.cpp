/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Dummy node to handle head deletions
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            // Check for duplicates
            if (curr->next != NULL && curr->val == curr->next->val) {
                int val = curr->val;
                // Skip all nodes with this value
                while (curr != NULL && curr->val == val) {
                    curr = curr->next;
                }
                prev->next = curr; // Link past duplicates
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
