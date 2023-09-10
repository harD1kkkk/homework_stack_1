#pragma once
#include <iostream>
using namespace std;

class StringNode {
public:
    string value;
    StringNode* next;

    StringNode();
    StringNode(string value);
};