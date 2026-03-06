#include <unordered_map>
#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int value;
    Node* pre;
    Node* next;
    Node() : key(0), value(0), pre(nullptr), next(nullptr) {}
    Node(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    int count;
    int _capacity;
    unordered_map<int, Node*> mp;

    // 移除节点（从链表中断开）
    void removeNode(Node* node) {
        if (node->pre) {
            node->pre->next = node->next;
        }
        if (node->next) {
            node->next->pre = node->pre;
        }
        
        // 更新 tail 指针
        if (node == tail) {
            tail = node->pre;
        }
    }
    
    // 在头部添加节点
    void addToHead(Node* node) {
        node->pre = head;
        node->next = head->next;
        
        if (head->next) {
            head->next->pre = node;
        }
        head->next = node;
        
        // 如果是第一个真实节点，更新 tail
        if (!tail) {
            tail = node;
        }
    }
    
    // 移动到头部
    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }
    
    // 移除尾节点
    void removeTail() {
        if (tail) {
            int key = tail->key;
            mp.erase(key);  // 从 map 中移除
            
            Node* prev = tail->pre;
            if (prev) {
                prev->next = nullptr;
            }
            
            delete tail;
            tail = prev;
            count--;
        }
    }

public:
    LRUCache(int capacity) {
        count = 0;
        _capacity = capacity;
        // 创建虚拟头节点
        head = new Node();
        tail = nullptr;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // 键已存在，更新值并移到头部
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            // 新键，创建新节点
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addToHead(newNode);
            count++;
            
            // 检查容量
            if (count > _capacity) {
                removeTail();
            }
        }
    }
    
    ~LRUCache() {
        // 清理所有节点
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};