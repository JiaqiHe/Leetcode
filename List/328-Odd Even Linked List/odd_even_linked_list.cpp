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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        int len = 0;
        ListNode* ptr = head;
        ListNode* firstOdd = head;
        ListNode* firstEven = head->next;
        ListNode* lastOdd = NULL;
        ListNode* lastEven = NULL;
        
        while(head != NULL){
            len++;
            if(len%2 == 0) lastEven = head;
            else lastOdd = head;
            head = head->next;
        }
        
        //first, last odd points to first even
        lastOdd->next = firstEven;
        
        //starting from the first element, change the next element
        while(ptr->next != lastOdd){
            ListNode* temp = ptr->next;
            ptr->next = temp->next;
            ptr = temp;
        }
        
        //ptr->next == lastOdd, meaning ptr is pointing to the last two even number if len is even
        ptr->next = len%2==0 ? lastEven : NULL;
        return firstOdd;
    }
};
