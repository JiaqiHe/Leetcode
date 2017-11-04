/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* helper = slow;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            helper = slow;
            slow = slow->next;
        }
        if(fast == slow){
            //only at most 2 elements
            if(slow->next){
                TreeNode *root = new TreeNode(slow->next->val);
                root->left = new TreeNode(slow->val);
                return root;
            }
            else{
                TreeNode *root = new TreeNode(slow->val);
                return root;
            } 
        }
        else{
            if(fast->next){
                //even numbers
                TreeNode *root = new TreeNode(slow->next->val);
                root->right = sortedListToBST(slow->next->next);
                slow->next = NULL;
                root->left = sortedListToBST(head);
                return root;
            }
            else{
                TreeNode *root = new TreeNode(slow->val);
                root->right = sortedListToBST(slow->next);
                helper->next = NULL;
                root->left = sortedListToBST(head);
                return root;
            }
        }
    }
};
