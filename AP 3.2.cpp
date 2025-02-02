#include <iostream> 
#include <unordered_map> 
class Node { 
public: 
int key; 
int value; 
Node* prev; 
Node* next; 
Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {} 
}; 
class LRUCache { 
private: 
int capacity; 
Node* head; 
Node* tail; 
std::unordered_map<int, Node*> cache; 
void moveToHead(Node* node) { 
  
        // Remove node from its current position 
        removeNode(node); 
        // Add it to the head 
        addNodeToHead(node); 
    } 
 
    void removeNode(Node* node) { 
        if (node->prev) { 
            node->prev->next = node->next; 
        } 
        if (node->next) { 
            node->next->prev = node->prev; 
        } 
        if (node == tail) { 
            tail = tail->prev; 
        } 
        if (node == head) { 
            head = head->next; 
        } 
    } 
 
    void addNodeToHead(Node* node) { 
        node->next = head; 
        node->prev = nullptr; 
        if (head) { 
            head->prev = node; 
        } 
        head = node; 
        if (!tail) { 
            tail = node; // If the list was empty, tail is also this node 
        } 
    } 
 
    void evict() { 
        if (!tail) return; // Nothing to evict 
        cache.erase(tail->key); // Remove from cache 
        removeNode(tail); // Remove from linked list 
    } 
 
public: 
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {} 
 
    int get(int key) { 
        if (cache.find(key) == cache.end()) { 
            return -1; // Key not found 

} 
Node* node = cache[key]; 
moveToHead(node); // Move accessed node to head 
return node->value; 
} 
void put(int key, int value) { 
if (cache.find(key) != cache.end()) { 
// Key exists, update the value and move to head 
Node* node = cache[key]; 
node->value = value; 
moveToHead(node); 
} else { 
// Key does not exist, create a new node 
Node* newNode = new Node(key, value); 
if (cache.size() >= capacity) { 
evict(); // Evict the least recently used item 
} 
addNodeToHead(newNode); // Add new node to head 
cache[key] = newNode; // Add to cache 
} 
} 
}; 
// Example usage 
int main() { 
LRUCache lruCache(2); 
lruCache.put(1, 1); 
lruCache.put(2, 2); 
std::cout << lruCache.get(1) << std::endl; // returns 1 
lruCache.put(3, 3); // evicts key 2 
std::cout << lruCache.get(2) << std::endl; // returns -1 (not found) 
lruCache.put(4, 4); // evicts key 1 
std::cout << lruCache.get(1) << std::endl; // returns -1 (not found) 
std::cout << lruCache.get(3) << std::endl; // returns 3 
std::cout << lruCache.get(4) << std::endl; // returns 4 
return 0; 
}