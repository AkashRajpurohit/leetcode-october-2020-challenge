/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* iter = head, *prev, *iter2;
        int numNodes = 0;
        
        if(k == 0 || !head) return head;
        
        while(iter) {
            iter = iter->next;
            numNodes++;
        }
        
        k %= numNodes;
        
        if(numNodes == 1 || k == 0) return head;
        
        iter = head;
        
        while(numNodes - k > 0) {
            prev = iter;
            iter = iter->next;
            numNodes--;
        }
        
        prev->next = NULL;
        
        iter2 = iter;
        
        while(iter2->next) iter2 = iter2->next;
        
        iter2->next = head;
        head = iter;
        
        return head;
    }
};