#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int _value, Node* _left = nullptr, Node* _right = nullptr)
        : value(_value), left(_left), right(_right) {}
};

Node* insertValue(int value, Node* node, int& c) {
    if (node == nullptr) {
        node = new Node(value);
        return node;
    }

    if (value < node->value) {
        c++;
        node->left = insertValue(value, node->left, c);
    } else if (value > node->value) {
        c++;
        node->right = insertValue(value, node->right, c);
    }

    return node;
}

int main() {
    Node* root = nullptr;
    int m = 0;
    while (true) {
        int t;
        int cnt = 1;
        cin >> t;
        if (!t) break;
        root = insertValue(t, root, cnt);
        m = max(m, cnt);
    }

    cout << m << endl;
}
