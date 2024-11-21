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
    ListNode* insertionSortList(ListNode* head) 
    {
        if(!head || !head -> next)
        {
            return head;
        }
        ListNode *sorted = head;
        head = head -> next;
        sorted -> next = nullptr;

        while(head != nullptr)
        {
            ListNode *it = head;
            ListNode *pos = sorted;
            while(pos -> next && it -> val > pos -> next -> val)
            {
                pos = pos -> next;
            }
            head = head -> next;
            if(pos == sorted && it -> val < sorted -> val)
            {
                it -> next = sorted;
                sorted = it;
            }
            else
            {
                it -> next = pos -> next;
                pos -> next = it;
            }
        }
        return sorted;
    }   
};