#include "StringNode.h"
StringNode::StringNode() {
    this->value = "";
    next = nullptr;
}

StringNode::StringNode(string value) {
    this->value = value;
    this->next = nullptr;
}