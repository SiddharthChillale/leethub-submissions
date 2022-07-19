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
    ListNode *detectCycle(ListNode *head) {
        ListNode* hare = head;
        ListNode* tor = head;
        if(head == nullptr )  return nullptr;
        if(head->next == nullptr) return nullptr;
        
        tor = tor->next;
        hare = tor->next;
        
        while(hare != tor ){
            if(hare == nullptr || hare->next == nullptr) return nullptr;
            
            hare = hare->next->next;
            tor = tor->next;
        }
        
        ListNode* itr = head;
        
        while( itr != hare){
            hare = hare->next;
            itr = itr->next;
        }
        
        return itr;
        
        
        
    }
};