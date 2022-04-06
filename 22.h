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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre = head;
        ListNode* p = head;
        int count = 1;
        while(p -> next != nullptr)
        {
            if(count < k)
            {
                p = p -> next;
                count++;
                continue;
            }
            p = p -> next;
            pre = pre -> next;
        }
        return pre;
    }
};