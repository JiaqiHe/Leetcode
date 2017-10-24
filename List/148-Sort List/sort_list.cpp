/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //split the list in two halves
        if(head == NULL || head->next == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        //sort two parts
        ListNode* right = sortList(slow->next);
        slow->next = NULL;
        ListNode* left = sortList(head);
        //merge
        ListNode* res = new ListNode(0);
        ListNode* res_ptr = res;
        while(right != NULL && left != NULL){
            if(right->val < left->val){
                res->next = right;
                right = right->next;
                res = res->next;
            }
            else{
                res->next = left;
                left = left->next;
                res = res->next;
            }
        }
        if(right != NULL) res->next = right;
        if(left != NULL) res->next = left;
        return res_ptr->next;
    }
};
