class BrowserHistory {
public:
    struct Node {
        string url;
        Node *prev, *next;
        Node(string val = ""): url(val), prev(nullptr), next(nullptr) {}
    };
    Node *cur_node;
    BrowserHistory(string homepage) {
    cur_node = new Node(homepage);
    }
    
    void visit(string url) {
        //Delete All history;
        /*Node *old_list =cur_node->next;
        while(old_list)
        {
            Node *temp = old_list->next;
            delete old_list;
            old_list = temp;
        }*/

        Node *new_node = new Node(url);
    cur_node->next = new_node;
        new_node->prev =cur_node;
    cur_node = new_node;
    }
    
    string back(int steps) {
        while (steps > 0 &&cur_node->prev != nullptr)        
        {
            steps--;
        cur_node =cur_node->prev;
        }
        returncur_node->url;
    }
    
    string forward(int steps) {
        while (steps > 0 &&cur_node->next != nullptr)        
        {
            steps--;
        cur_node =cur_node->next;
        }
        returncur_node->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */