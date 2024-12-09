struct Node
{
    int val;
    Node *next;
    Node() : val{}, next{nullptr} {}
    Node(int x) : val{x}, next{nullptr} {}
    Node(int x, Node *nx) : val{x}, next{nx} {}
};

class MyLinkedList 
{
private:
    Node *head;
    int size;

public:
    MyLinkedList() : head{new Node()}, size{0} {}

    int get(int index) 
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        Node *ptr = head->next;
        while (index-- > 0)
        {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val) 
    {
        head->next = new Node(val, head->next);
        ++size;
    }

    void addAtTail(int val) 
    {
        Node *ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node(val);
        ++size;
    }

    void addAtIndex(int index, int val) 
    {
        if (index < 0 || index > size)
        {
            return;
        }
        Node *ptr = head;
        while (index > 0)
        {
            index--;
            ptr = ptr->next;
        }
        ptr->next = new Node(val, ptr->next);
        ++size;
    }

    void deleteAtIndex(int index) 
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        Node *ptr = head;
        while (index > 0)
        {
            index--;
            ptr = ptr->next;
        }
        Node *tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
        --size;
    }

    ~MyLinkedList()
    {
        Node *ptr = head;
        while (ptr)
        {
            Node *tmp = ptr;
            ptr = ptr->next;
            delete tmp;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
