struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* tmp = node -> next;
        node -> val =  node -> next -> val; 
        node -> next = node -> next -> next;
        delete tmp; 
    }
}; 
