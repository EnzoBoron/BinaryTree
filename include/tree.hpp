#pragma once

    #include <iostream>
    #include <vector>
    #include <string>
    #include "node.hpp"
    
    class Tree
    {
    private:
        Node *node;
        int size = 0;
        void addFirstNode(int v);
        Node* initialisationLeft(Node* loop, int v);
        Node* initialisationRight(Node* loop, int v);
        void freeTree(Node* loop);
        Node* searchParent(int key);
    public:
        Tree();
        ~Tree();
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        void addNode(int);
        Node* getNode(void);
        Node* remove(Node* root, int key);
        Node* search(int);
        int getSize(void);
    };
    