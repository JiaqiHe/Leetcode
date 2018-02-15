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
    ListNode* add(ListNode* l1, ListNode* l2, int ahead) {
        ListNode* head = NULL;
        while(l1 != NULL) {
            int res = l1->val;
            l1 = l1->next;
            if(ahead <= 0) {
                res += l2->val;
                l2 = l2->next;
            }
            ahead--;
            ListNode* tmp = new ListNode(res);
            tmp->next = head;
            head = tmp;
        }
        ListNode* toReturn = NULL;
        int carry = 0;
        while(head != NULL) {
            int cur = head->val + carry;
            ListNode* tmp = new ListNode(cur%10);
            carry = cur/10;
            tmp->next = toReturn;
            toReturn = tmp;
            head = head->next;
        }
        if(carry) {
            ListNode* tmp = new ListNode(1);
            tmp->next = toReturn;
            toReturn = tmp;
        }
        return toReturn;
    } 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0;
        int len2 = 0;
        ListNode* iter = l1;
        while(iter != NULL) {
            len1++;
            iter = iter->next;
        }
        iter = l2;
        while(iter != NULL) {
            len2++;
            iter = iter->next;
        }
        if(len1 > len2) return add(l1, l2, len1 - len2);
        else return add(l2, l1, len2 - len1);
    }
};
