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
    
    void recurse(ListNode* l1, ListNode* l2, int carry){
        
              
        l1->val+=l2->val+carry;
        carry = (l1->val)/10;
        l1->val = carry==1?l1->val-10:l1->val;
        
        if(l1->next==NULL){
            if(carry==0){
                l1->next=l2->next;
                return;
            }
            else{
                l1->next = new ListNode();
            }
        }
        
        if(l2->next==NULL){
            if(carry==0){
                return;
            }
            else{
                l2->next = new ListNode();
            }
        }
        
        recurse(l1->next,l2->next,carry);
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy =l1;
        recurse(l1,l2,0);
        return dummy;

    }
};