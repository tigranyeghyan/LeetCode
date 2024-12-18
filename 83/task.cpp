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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head || !(head -> next))
        {
            return head;
        }

        ListNode *it = head;
        while(it -> next)
        {
            if(it -> next -> val == it -> val)
            {
                ListNode *tmp = it -> next;
                it -> next = it -> next -> next;
                delete tmp;
            }
            else
            {
                it = it -> next; 
            }
        }    
        return head;
    }
};