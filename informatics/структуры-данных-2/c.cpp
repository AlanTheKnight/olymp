#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int _value, Node* _left = nullptr, Node* _right = nullptr)
        : value(_value), left(_left), right(_right) {}
};

Node* insertValue(int value, Node* node) {
    if (node == nullptr) {
        node = new Node(value);
        return node;
    }

    if (value < node->value) {
        node->left = insertValue(value, node->left);
    } else if (value > node->value) {
        node->right = insertValue(value, node->right);
    }

    return node;
}

void secondLargest(Node* node, int& c) {
    if (node == nullptr || c >= 2) return;
    secondLargest(node->right, c);
    c++;
    if (c == 2) {
        cout << node->value << endl;
        return;
    }
    secondLargest(node->left, c);
}

int main() {
    Node* root = nullptr;
    while (true) {
        int t;
        cin >> t;
        if (!t) break;
        root = insertValue(t, root);
    }

    // Task: find the second largest value in binary search tree
    // Idea: use reverse in-order traversal

    int c = 0;
    secondLargest(root, c);
}
