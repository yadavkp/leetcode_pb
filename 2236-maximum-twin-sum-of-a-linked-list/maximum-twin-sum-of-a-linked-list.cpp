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
    int pairSum(ListNode* head1) {
        
        ListNode* head2 = head1;

        ListNode* slow = head1;
        ListNode* fast = head1;

        while(fast && fast->next){  // finding the mid 
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = slow;

        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head1;
        ListNode* second = prev;
        int mx = 0;
        
        while(second != nullptr){
            mx = max(mx, first->val + second->val);
            first = first->next;
            second = second->next;
          
        }

        return mx;
    }
};