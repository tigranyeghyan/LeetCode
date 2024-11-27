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
    void reorderList(ListNode* head) 
    { 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        recurs(head, slow, slow);
    }
    ListNode* recurs(ListNode *head, ListNode *mid, ListNode *prev)
    {
        if(!mid -> next)
        {
            ListNode *tmp = head -> next;
            head -> next = mid;
            head -> next -> next = tmp;
            prev -> next = nullptr;
            return tmp;
        }
        head = recurs(head, mid -> next, mid);
        ListNode *tmp = head -> next;
        head -> next = mid;
        head -> next -> next = tmp;
        prev -> next = nullptr;
        return tmp;
    }
};