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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* it1 = headA;
        ListNode* it2 = headB;
        while(it1 != it2)
        {
            it1 = !it1 ? headB : it1 -> next;
            it2 = !it2 ? headA : it2 -> next;
        }
        return it1;
    }
};