class MyLinkedList {
public:
    struct Node
    {
        int val;
        Node *next, *prev;
        Node(int v = 0) : val(v), prev(nullptr), next(nullptr) { }
    };
    Node *head;
    Node *tail;
    int len;
    
    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        len = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= len) return -1;
        Node *cur = head->next;

        while(cur && index > 0)
        {
            cur = cur->next;
            index--;
        }
        
        if (cur && cur != tail && index == 0)
            return cur->val;
        return -1;
    }
    
    void addAtHead(int val) {
        Node *new_node = new Node(val);
        new_node->next = head->next;
        new_node->next->prev = new_node;
        head->next = new_node;
        new_node->prev = head;
        len++;
    }
    
    void addAtTail(int val) {
        Node *new_node = new Node(val);
        new_node->prev = tail->prev;
        new_node->next = tail;
        new_node->prev->next = new_node;
        tail->prev = new_node;
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > len || index < 0) return;

        //index == 0
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        //index == len
        if (index == len) 
        {
            addAtTail(val);
            return;
        }

        Node *new_node = new Node(val);
        Node *cur = head->next;
        while(index > 0)
        {
            index--;
            cur = cur->next;
        }

        cur->prev->next = new_node;
        new_node->prev = cur->prev;
        new_node->next = cur;
        cur->prev = new_node;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (len == 0 || index >= len || index < 0 || head->next == tail) return;

        Node *cur = head->next;
        while(index > 0)
        {
            index--;
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        len--;
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