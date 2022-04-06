/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head -> val == val) return head -> next;
        ListNode* p = head -> next;
        ListNode* pre = head;
        while(p != nullptr && p -> val != val)
        {
            p = p -> next;
            pre = pre -> next;
        }
        if(p != nullptr)
        {
            pre -> next = p -> next;
        }
        return head;
    }
};