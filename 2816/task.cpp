//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* doubleIt(ListNode* head) 
    {
        int val = recurs(head);
        if(val > 0)
        {
            head = new ListNode(val, head);
        }
        return head;
    }
    int recurs(ListNode *head)
    {
        if(!head)
        {
            return 0;
        }
        int val = (head -> val * 2 + recurs(head -> next));
        head -> val = val % 10;
        return val / 10;  
    }
};