/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode* l1, *l2;
        for(l1 = head; l1 != NULL; l1 = l1->next) {
            RandomListNode* cur = new RandomListNode(l1->label);
            cur->next = l1->random;
            l1->random = cur;//use l1->random to save its corresponding copied node
        }
        RandomListNode* toReturn = head->random;
        //update random
        for(l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;
        }
        //update next
        for(l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : NULL;
        }
        return toReturn;
    }
};
