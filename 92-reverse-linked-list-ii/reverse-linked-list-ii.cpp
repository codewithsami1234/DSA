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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        // Create a dummy node to simplify edge cases (e.g. left == 1)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // Step 1: Move `prev` to the node just before the `left` position
        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        // Step 2: Reverse the sublist from `left` to `right`
        ListNode* current = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* next = current->next;
            current->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
};
