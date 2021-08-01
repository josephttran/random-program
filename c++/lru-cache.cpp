#include <iostream>
#include <map>

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   std::map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache {
    public:
        LRUCache(int);
        void set(int, int);
        int get(int);
};

LRUCache::LRUCache(int c)
{
    cp = c;
}

void LRUCache::set(int key, int value)
{
    if (mp.size() == 0) {
        mp[key] = new Node(key, value);
        tail = mp[key];
        head = mp[key];
        return;
    }
    
    if (mp.count(key) > 0) {
        mp[key]->value = value;
        Node* cur_node = mp[key];
        
        if (cur_node != head) {
            if (cur_node == tail) {
                tail = tail->next;
                tail->prev = NULL;
            }
            else {
                Node* next_node = cur_node->next;
                Node* prev_node = cur_node->prev;
                
                prev_node->next = next_node;
                next_node->prev = prev_node;
            }
            
            cur_node->next = NULL;
            cur_node->prev = head;
            head->next = cur_node;
            head = cur_node;
        }
    } else {
       Node* newNode = new Node(head, NULL, key, value);
          
       if (mp.size() == cp) {
            Node* toDeleteNode = tail;
            tail = tail->next;
            tail->prev = NULL;
            mp.erase(toDeleteNode->key);
            delete toDeleteNode;
        } 
        
        mp[key] = newNode;
        head->next = newNode;
        head = newNode;
    }
}

int LRUCache::get(int key)
{
    if (mp.count(key) > 0) {
        return mp[key]->value;
    }

    return -1;
}
