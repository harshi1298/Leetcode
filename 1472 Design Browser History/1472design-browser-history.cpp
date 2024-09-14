class BrowserHistory {
public:
   class Node{
    public:
       string str;
       Node *next;
       Node *prev;
    };
    Node* head=NULL;
    Node* tail=NULL;
public:
    BrowserHistory(string homepage) {
         Node* newnode= new Node();
        newnode->str=homepage;
        head=newnode;
        tail=newnode;
        head->next=NULL;
        head->prev=NULL;
    }
    void visit(string url) {
        Node* newnode= new Node();
        newnode->str=url;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
    
    string back(int steps) {
        int i=0;
        while(tail->prev!=NULL && i<steps){
            tail=tail->prev;i++;
        }
        return tail->str;
    }
    
    string forward(int steps) {
         int i=0;
        while(tail->next!=NULL && i<steps){
            tail=tail->next;i++;
        }
        return tail->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */