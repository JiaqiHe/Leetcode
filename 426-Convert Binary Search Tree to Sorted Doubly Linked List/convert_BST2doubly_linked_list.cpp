/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    void inorder(Node* root, Node* &head, Node* tail, Node* last) {
        if(root == NULL) return;
        stack<Node*> stk;
        while(root != NULL || !stk.empty()) {
            while(root != NULL) {
                stk.push(root);
                root = root->left;
            }
            Node* curNode = stk.top();
            stk.pop();
            if(head == NULL) {
                // cout<<"found head: "<<curNode->val<<endl;
                head = curNode;
                last = head;
            }
            else {
                // cout<<last->val << "->" << curNode->val<<endl;
                last->right = curNode;
                curNode->left = last;
                last = curNode;
            }
            if(curNode->right == NULL) tail = curNode;
            root = curNode->right;
        }
        // cout<<tail->val<<"->"<<head->val<<endl;
        tail->right = head;
        head->left = tail;
    }
    Node* treeToDoublyList(Node* root) {
        Node* head = NULL, *tail = NULL, *last = NULL;
        inorder(root, head, tail, last);
        return head;
    }
};
