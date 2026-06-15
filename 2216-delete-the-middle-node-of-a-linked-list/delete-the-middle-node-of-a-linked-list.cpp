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
    ListNode* deleteMiddle(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }

        if(cnt == 1){
            return nullptr;
        }

        temp = head;
        int sz = cnt/2;
        while(sz-1 > 0){ // reach to the node b4 delete  that why did -1
            sz--;
            temp = temp->next;
        }

        ListNode* temp1 = temp->next;

        temp->next = temp->next->next;

        delete temp1;

        return head;

    }
};