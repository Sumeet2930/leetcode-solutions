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
    ListNode* reverseList(ListNode* head) {
        ListNode* bef = nullptr;
        ListNode* curr = head;
        //Node* aft = head->next;

        while(curr != nullptr) {
            ListNode* aft = curr->next;
            curr->next = bef;
            bef = curr;
            curr = aft;
            //aft = curr->next;

        }

        return bef;
    }
};