#include "../include/tree.hpp"

Tree::Tree()
{
    this->node = new Node;
    this->node->left = nullptr;
    this->node->right = nullptr;
    this->node->value = 0;
}

Tree::~Tree()
{
    freeTree(this->node);
}

void Tree::freeTree(Node* head)
{
    if (!head)
        return;

    freeTree(head->left);
    freeTree(head->right);
    delete(head);
}

Node* Tree::getNode(void)
{
    return (Node*)node;
}

void Tree::addFirstNode(int v)
{
    if (!this->node->left && !this->node->right) {
        this->node->value = v;
    }

    this->size++;
}

Node* Tree::initialisationRight(Node* right, int v)
{
    right->right = new Node;
    right->right->left = nullptr;
    right->right->right = nullptr;
    right->right->value = v;
    this->size++;

    return right;
}

Node* Tree::initialisationLeft(Node* left, int v)
{
    left->left = new Node;
    left->left->left = nullptr;
    left->left->right = nullptr;
    left->left->value = v;
    this->size++;

    return left;
}

void Tree::addNode(int v)
{
    Node *head = this->node;
    
    if (this->size == 0) {
        addFirstNode(v);
        return;
    }

    while (head && this->size > 0) {
        if (head->value <= v) {
            if (head->right) {
                head = head->right;
            } else {
                head = initialisationRight(head, v);
                return;
            }
        } else if (head->value > v) {
            if (head->left) {
                head = head->left;
            } else {
                head = initialisationLeft(head, v);
                return;
            }
        }
    }
}

void Tree::preOrder(Node* head)
{ 
    if (!head)
        return;

    std::cout << head->value << std::endl;

    preOrder(head->left);
    preOrder(head->right);
}

void Tree::inOrder(Node* head)
{ 
    if (!head)
        return;

    inOrder(head->left);
    std::cout << head->value << std::endl;
    inOrder(head->right);
}

void Tree::postOrder(Node* head)
{
    if (!head)
        return;

    postOrder(head->left);
    postOrder(head->right);
    std::cout << head->value << std::endl;
}

Node* Tree::search(int key) {
    Node *loop = this->node;

    while(loop) {
        if (key == loop->value)
            return loop;
        if (key >= loop->value)
            loop = loop->right;
        else
            loop = loop->left;
    }

    return nullptr;
}

int Tree::getSize(void) {
    return this->size;
}

Node* Tree::remove(Node* head, int key) {
    if (!head)
        return nullptr;

    if (key < head->value) {
        head->left = remove(head->left, key);
    }
    else if (key > head->value) {
        head->right = remove(head->right, key);
    }
    else {
        if (!head->left && !head->right) {
            this->size--;
            delete head;
            return nullptr;
        }
        if (!head->left) {
            Node* tmp = head->right;
            this->size--;
            delete head;
            return tmp;
        }
        if (!head->right) {
            Node* tmp = head->left;
            this->size--;
            delete head;
            return tmp;
        }

        Node* succ = head->right;
        while (succ->left)
            succ = succ->left;

        head->value = succ->value;
        head->right = remove(head->right, succ->value);
    }

    return head;
}