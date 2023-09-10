#include "Node.h"
Node::Node() {
    this->value = 0;
    next = nullptr;
}

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}