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
    int calculateLength(ListNode *head) {
        if(!head) return 0;
        return 1 + calculateLength(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> ans(k);
        int len = calculateLength(head);
       
        int width = len / k, rem = len % k;
        for(int i = 0; i < k; i++, rem--) {
            ListNode *temp = head;
            for(int j = 0; j < width + (rem > 0) - 1; j++) {
                if(head) head = head->next;
            }
            if(head) {
                ListNode *temp2 = head;
                head = head->next;
                temp2->next = NULL;
            }
            ans[i] = temp;
        }
        
        return ans;
        
    }
};