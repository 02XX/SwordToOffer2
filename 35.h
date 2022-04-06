#include<unordered_map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//时间复杂度O(n), 空间复杂度O(n)
class Solution {
    std::unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(m.find(head) == m.end())
        {
            Node* r = new Node(head->val);
            m[head] = r;
            r -> next = copyRandomList(head -> next);
            r -> random = copyRandomList(head -> random);
        }
        return m[head];
    }
};

//时间复杂度O(n), 空间复杂度O(n)
class Solution {
    std::unordered_map<Node*, Node*> m;
public:
    Node* copyRandomList(Node* head) {
        //构建新节点
        Node* p = head;
        while(p != nullptr)
        {
            Node* newNode = new Node(p -> val);
            m[p] = newNode;
            p = p -> next;
        }
        //链接新节点
        Node* pr = head;
        while(pr != nullptr)
        {
            m[pr] -> next = m[pr -> next];
            m[pr] -> random = m[pr -> random];
            pr = pr -> next;
        }
        return m[head];
    }
};

//最简单的.时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* p = head;
        //创建S'节点
        while(p != nullptr) 
        {
            Node* newNode = new Node(p -> val);
            newNode -> next = p -> next;
            p -> next = newNode;
            p = p -> next -> next;
        }
        //链接复制后的节点的random节点
        p = head;
        while(p != nullptr)
        {
            if(p -> random != nullptr)
            {
                p -> next -> random = p -> random -> next;
            }
            else
            {
                p -> next -> random = nullptr;
            }
            p = p -> next -> next;
        }
        p = head;
        Node* r = p -> next;
        Node* res = r;
        while(p != nullptr)
        {
            if(r != nullptr)
            {
                p -> next = r -> next;
                p = p -> next;
            }
            if(p != nullptr)
            {
                r -> next = p -> next;
                r = r -> next;
            }
            
        }
        return res;
    }
};