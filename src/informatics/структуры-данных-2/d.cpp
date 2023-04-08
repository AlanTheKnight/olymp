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

void inOrderTraversal(Node* node) {
    if (node == nullptr) return;
    inOrderTraversal(node->left);
    cout << node->value << endl;
    inOrderTraversal(node->right);
}

int main() {
    Node* root = nullptr;
    while (true) {
        int t;
        cin >> t;
        if (!t) break;
        root = insertValue(t, root);
    }

    // Task: print all values in ascending order
    // Idea: use in-order traversal
    inOrderTraversal(root);
}
