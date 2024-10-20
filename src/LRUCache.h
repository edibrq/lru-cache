#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity);
    ~LRUCache();

    int get(int key);
    void put(int key, int value);

private:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
    };

    void addNode(Node* newNode);
    void deleteNode(Node* delNode);

    Node* head;
    Node* tail;
    int capacity;
    std::unordered_map<int, Node*> cacheMap;
};

#endif // LRU_CACHE_H

