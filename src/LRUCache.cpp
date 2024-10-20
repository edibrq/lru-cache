#include "LRUCache.h"

LRUCache::LRUCache(int capacity) : capacity(capacity) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
}

LRUCache::~LRUCache() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LRUCache::addNode(Node* newNode) {
    Node* temp = head->next;
    newNode->next = temp;
    newNode->prev = head;
    head->next = newNode;
    temp->prev = newNode;
}

void LRUCache::deleteNode(Node* delNode) {
    Node* prevNode = delNode->prev;
    Node* nextNode = delNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete delNode;
}

int LRUCache::get(int key) {
    if (cacheMap.find(key) != cacheMap.end()) {
        Node* resNode = cacheMap[key];
        int result = resNode->val;
        cacheMap.erase(key);
        deleteNode(resNode);
        addNode(new Node(key, result));
        cacheMap[key] = head->next;
        return result;
    }
    return -1;
}

void LRUCache::put(int key, int value) {
    if (cacheMap.find(key) != cacheMap.end()) {
        Node* existingNode = cacheMap[key];
        cacheMap.erase(key);
        deleteNode(existingNode);
    }

    if (cacheMap.size() == capacity) {
        cacheMap.erase(tail->prev->key);
        deleteNode(tail->prev);
    }

    addNode(new Node(key, value));
    cacheMap[key] = head->next;
}

