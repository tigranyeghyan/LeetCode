//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {} 
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <stack>

// solution1
//space comp O(n)
//time comp O(n) 

class Solution1 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!(head -> next))
        {
            return true;
        }
        std::stack<int> st;
        ListNode *it = head;
        while(it != nullptr)
        {   
            st.push(it -> val);
            it = it -> next;
        }
        it = head;
        while(it != nullptr)
        {
            if(st.top() == it -> val)
            {
                st.pop();
            }
            else
            {
                return false;
            }
            it = it-> next;
        }
        return true;
    }
};

//solution 2
//space comp O(1)
//time comp O(n)

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head -> next == nullptr || recurs(head, head))
        {
            return true;
        }
        return false;
    }
    
    ListNode* recurs(ListNode *head, ListNode *it)
    {
        if(it -> next == nullptr)
        {
            return (head -> val == it -> val) ? head -> next : nullptr;
        }
        head = recurs(head, it -> next);
        if(head != nullptr && head -> val == it -> val)
        {
            return head -> next == nullptr ? head : head-> next;
        }
        else
        {
            return nullptr;
        }
    } 
};