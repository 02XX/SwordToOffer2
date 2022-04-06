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
    vector<int> reversePrint(ListNode* head) {
        stack<int> S;
        vector<int> r;
        ListNode* p = head;
        while (p != nullptr)
        {
            S.push(p->val);
            p = p -> next;
        }
        while(!S.empty())
        {
            r.push_back(S.top());
            S.pop();
        }
        return r;
    }
};