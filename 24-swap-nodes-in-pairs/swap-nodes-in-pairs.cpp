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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;

        vector<int> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }

        for(int i=0; i + 1 < v.size(); i+=2){
            swap(v[i], v[i+1]);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for(int x : v){
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;

    }
};