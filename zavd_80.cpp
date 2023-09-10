// zavd_80.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "Node.h"
#include "StringNode.h"

void putNodeToTail(Node*& head, double value) {
    Node* n = new Node(value);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node* tmp = nullptr;
    tmp = head;

    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = n;
}

void display(Node* head) {
    Node* temp;
    temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}


void CheckQueue(Node* head) {
    if (head == nullptr) {
        cout << "The queue is empty!" << endl;
        return;
    }
    else {
        cout << "The queue isn't empty!" << endl;
        display(head);
    }
}

void add(Node*& head, double number) {
    Node* tmp = new Node(number);

    Node* temp = nullptr;
    temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = tmp;
}

void removeNodeFromHead(Node*& head) {
    double value = head->value;
    head = head->next;
    cout << "Removed first element is: " << value << endl;
}

bool pickElementsFromHead(Node*& head, double value) {
    while (head != nullptr) {
        if (head->value == value) {
            cout << "Found: " << head->value << endl;
            return true;
        }
        else {
            head = head->next;
        }
    }
    cout << "Not found" << endl;
    return false;
}

void clearQueue(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}




void putNodeToTailStr(StringNode*& headStr, string value) {
    StringNode* n = new StringNode(value);
    if (headStr == nullptr) {
        headStr = n;
        return;
    }
    StringNode* tmp = nullptr;
    tmp = headStr;

    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = n;
}
void display(StringNode* headStr) {
    StringNode* temp;
    temp = headStr;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void clearQueue(StringNode*& headStr) {
    while (headStr != nullptr) {
        StringNode* temp = headStr;
        headStr = headStr->next;
        delete temp;
    }
}

void createQueueFromStr(StringNode*& headStr, string str) {
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        string s(1, c);  // Convert char to string
        putNodeToTailStr(headStr, s);
    }
}

void splitQueue(StringNode* headStr, StringNode*& englishQueue, StringNode*& otherQueue) {
    while (headStr != nullptr) {
        if ((headStr->value[0] >= 'a' && headStr->value[0] <= 'z') || (headStr->value[0] >= 'A' && headStr->value[0] <= 'Z')) {
            putNodeToTailStr(englishQueue, headStr->value);
        }
        else {
            putNodeToTailStr(otherQueue, headStr->value);
        }
        headStr = headStr->next;
    }
}


int main()
{
    Node* head = nullptr;

    StringNode* headStr = nullptr;
    StringNode* englishQueue = nullptr;
    StringNode* otherQueue = nullptr;

    int size;
    double number = 0.0;
    cout << "Enter size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter number: ";
        cin >> number;
        putNodeToTail(head, number);
    }
    display(head);

    while (true) {
        int choice;
        cout << "Make your chice" << endl;
        cout << "1 - Check if the queue is empty, 2 - add an element to the end, 3 - remove Node From Head, 4 - pick Elements From Head, 5 - Create a queue of string characters,  6-Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            CheckQueue(head);
        }

        else if (choice == 2) {
            double num;
            cout << "Enter a number: ";
            cin >> num;

            add(head, num);
            display(head);
        }

        else if (choice == 3) {
            removeNodeFromHead(head);
            display(head);
        }

        else if (choice == 4) {
            double num;
            cout << "Enter element: ";
            cin >> num;

            pickElementsFromHead(head, num);
            display(head);
        }

        else if (choice == 5) {
            string str;
            cout << "Enter a string: ";
            cin >> str;

            createQueueFromStr(headStr, str);
            splitQueue(headStr, englishQueue, otherQueue);

            cout << "Original queue: ";
            display(headStr);

            cout << "English characters queue: ";
            display(englishQueue);

            cout << "Other characters queue: ";
            display(otherQueue);

            clearQueue(headStr);
        }

        else if (choice == 6) {
            cout << "Exiting..." << endl;
        }

        else {
            cout << "Wrong number" << endl;
        }
    }
    clearQueue(head);
    clearQueue(englishQueue);
    clearQueue(otherQueue);
}