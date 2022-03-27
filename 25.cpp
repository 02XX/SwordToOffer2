// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode(int x) : val(x), next(NULL) {}
//   };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* r = new ListNode(0);
        ListNode* p = r;
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        while(p1 != nullptr && p2 != nullptr)
        {
            if(p1 -> val <= p2 -> val)
            {
                p -> next = new ListNode(p1 -> val);
                p1 = p1 -> next;
            }
            else
            {
                p -> next = new ListNode(p2 -> val);
                p2 = p2 -> next;
            }
            p = p -> next;
        }
        while(p1 != nullptr)
        {
            p -> next = new ListNode(p1 -> val);
            p = p -> next;
            p1 = p1 -> next;
        }
        while(p2 != nullptr)
        {
            p -> next = new ListNode(p2 -> val);
            p = p -> next;
            p2 = p2 -> next;
        }
        return r -> next;

    }
};