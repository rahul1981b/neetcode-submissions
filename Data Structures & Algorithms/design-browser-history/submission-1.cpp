class BrowserHistory {
public:
    struct Node {
        string url;
        Node *prev, *next;
        Node(string val = ""): url(val), prev(nullptr), next(nullptr) {}
    };
    Node *curNode;
    BrowserHistory(string homepage) {
        curNode = new Node(homepage);
    }
    
    void visit(string url) {
        //Delete All history;
        /*Node *old_list = curNode->next;
        while(old_list)
        {
            Node *temp = old_list->next;
            delete old_list;
            old_list = temp;
        }*/

        Node *new_node = new Node(url);
        curNode->next = new_node;
        new_node->prev = curNode;
        curNode = new_node;
    }
    
    string back(int steps) {
        while (steps > 0 && curNode->prev != nullptr)        
        {
            steps--;
            curNode = curNode->prev;
        }
        return curNode->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && curNode->next != nullptr)        
        {
            steps--;
            curNode = curNode->next;
        }
        return curNode->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */