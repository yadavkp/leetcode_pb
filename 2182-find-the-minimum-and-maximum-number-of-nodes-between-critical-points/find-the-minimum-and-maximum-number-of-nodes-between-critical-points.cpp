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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int st = 1e7, end = 0, cnt = 0;
         int mn_ans = st, mx_ans = -1;

        int prev = head->val;

        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return {-1,-1};
        }

        head = head->next;
        cnt = 0;
        int idx = 2;
        int mid_idx = idx;
        while(head->next != nullptr){
          
            int cur = head->val;
            int new_next = head->next->val;

            if(prev < cur && cur > new_next || (prev > cur && cur < new_next)){

                cnt++;
                st = min(st,idx);
                end = max(end,idx);


                if(cnt >= 3 && st != -1){

                    mn_ans = min({mn_ans, abs(st - mid_idx),abs(mid_idx - end)});
                    mx_ans = max({mx_ans, abs(end - st)});
                }else if(cnt >= 2){
                    mn_ans = min({abs(st - end)});
                    mx_ans = mn_ans;
                }
                mid_idx = idx;
            }
            prev = cur;
            idx++;
            head = head->next;
        }

        if(mn_ans == 1e7) return {-1,-1};

        return {mn_ans, mx_ans};
        
    }
};