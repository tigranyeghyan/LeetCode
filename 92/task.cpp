// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head->next || left == right)
        {
            return head;
        }
        ListNode *leftNode = head;
        ListNode *rightNode = head;
        ListNode *it = head;
        bool t = left == 1 ? true : false;
        do
        {
            leftNode = it;
            left--;
            it = it->next;
        } while (!t && left - 1 != 0);

        it = head;
        do
        {
            rightNode = it;
            right--;
            it = it->next;
        } while (right != 0);
        it = rightNode->next;
        rightNode->next = nullptr;
        rightNode = it;
        if (t)
        {
            ListNode *tmp = head;
            head = reverseList(head);
            tmp->next = rightNode;
        }
        else
        {
            ListNode *tmp = leftNode->next;
            leftNode->next = reverseList(leftNode->next);
            tmp->next = rightNode;
        }
        return head;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *prev = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return prev;
    }
};