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
    // function to split list in two halves
    ListNode *getMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // disconnect first half from second
        if(prev) prev->next = nullptr;
        return slow;
    }
    // function to merge two sorted list
    ListNode* merge(ListNode *l1 ,ListNode *l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        // attach the remaining element
        tail->next = l1 ? l1 :l2;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        return head; // base case
        /// split list into halves
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge( left , right);
    }
};