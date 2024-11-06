Node* detectCycle(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        
        while(slow != nullptr && fast != nullptr)
        {
            slow = slow -> next;
            fast = fast -> next;
            if(fast) fast = fast -> next;
            
            if(slow == fast) return slow;
        }
        
        return nullptr;
        
    }
    
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        Node* slow = detectCycle(head);
        Node* fast = head;
        
        
        if(slow == nullptr || fast == nullptr) return ;
        
        while(fast != slow)
        {
            fast = fast -> next; 
            slow = slow -> next; 
        }
        
        while(slow -> next != fast) slow = slow -> next;
        
        
        slow -> next = nullptr;
    }