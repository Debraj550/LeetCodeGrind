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
        int n = len / k, r = len % k; 
        
        ListNode* node = head, *prev = nullptr;
        
        for (int i = 0; node && i < k; i++, r--) {
            ans[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return ans;
        
    }
};