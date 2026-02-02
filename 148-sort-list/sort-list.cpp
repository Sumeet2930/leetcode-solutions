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
    ListNode* sortList(ListNode* head) {
        if (!head) return head;

        list<int> ll;

        for (ListNode* cur = head; cur; cur = cur->next)
            ll.push_back(cur->val);

        ll.sort();

        ListNode* cur = head;
        for (int x : ll) {
            cur->val = x;
            cur = cur->next;
        }

        return head;
    }
};
