// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x)
    {
    if(!head ||  !head -> next)
    {
        return head;
    }
    ListNode *greate{};
    ListNode *less{};
    ListNode *start {};
    ListNode *start_greate {};

    while (head)
    {
        ListNode *tmp = head;
        head = head-> next;
        tmp -> next = nullptr;
        if (tmp -> val >= x)
        {
            if (!start_greate)
            {
                start_greate = tmp;
                greate = tmp;
            }
            else
            {
                greate -> next = tmp;
                greate = greate -> next;
            }
        }
        else
        {
            if (!start)
            {
                start = tmp;
                less = tmp;
            }
            else
            {
                less -> next = tmp;
                less = less -> next;
            }
        }
    }
    if(!start)
    {
        return start_greate;
    }
    less -> next = start_greate;
    return start;
}

};