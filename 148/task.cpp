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
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head -> next)
        {
            return head;
        }    
        ListNode *mid = devide(head);
        ListNode *l = sortList(head);
        ListNode *r = sortList(mid);
        return mergeTwoLists(l, r);
    }

    ListNode* devide(ListNode* head) 
    {
        if(!head || !head -> next)
        {
            return head;
        }
        ListNode* it1 = head;
        ListNode* it2 = head -> next;
        while(it2 && it2 -> next)
        {
            it1 = it1 -> next;
            it2 = it2 -> next -> next;
        }
        ListNode * ptr = it1 -> next;
        it1 -> next = nullptr;
        return ptr;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1)
        {
            return list2;
        }
        if(!list2)
        {
            return list1;
        }
        if(list1 -> val < list2 -> val)
        {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
        else
        {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
    }
};