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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        while(head){
            ListNode *next_node = head->next;
            head->next = prev;
            prev = head;
            head = next_node;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head){
        if(!head  || !head->next ) return head;
        head = reverseList(head);
        ListNode *curr = head;
        int max_so_far = curr->val;
        while( curr && curr->next){
            if(curr->next->val <max_so_far){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
                max_so_far = curr->val;
            }
        }
 return reverseList(head);
    }

};