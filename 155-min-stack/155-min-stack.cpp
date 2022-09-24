class MinStack {
public:
    
    typedef struct Node
    {
        int val;
        struct Node* prev;
        Node(int _v) : val(_v), prev(NULL) {};
    } Node;
    
    
    Node* stack;
    Node* min;
    
    MinStack() {
        stack = new Node(INT_MAX); 
        min = new Node(INT_MAX);
    }
    
    void push(int val) {
        if (val <= min->val)
        {
            Node* curr = min;
            min = new Node(val);
            min->prev = curr;
        }
        
        Node* curr = stack;
        stack = new Node(val);
        stack->prev = curr;
    }
    
    void pop() {        
        
        // delete the min
        if (getMin() == top())
        {
            Node* curr = min;
            min = min->prev;
            delete curr;
        }
        
        // delete the top
        Node* curr = stack;
        stack = stack->prev;
        delete curr;
    }
    
    int top() {
        return stack->val;
    }
    
    int getMin() {
        return min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */