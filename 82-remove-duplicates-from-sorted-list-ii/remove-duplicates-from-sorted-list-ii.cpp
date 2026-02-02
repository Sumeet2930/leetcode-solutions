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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;

        while (temp) {
            v.push_back(temp->val);
            temp = temp -> next;
        }

        vector<int> clean;
        int n = v.size();

        for(int i=0; i<n; ){
            int j=i;
            while(j<n && v[j] ==v[i]){
                j++;
            }

            if (j - i == 1){
                clean.push_back(v[i]);
            }
            i = j;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (int x: clean){
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;
    }
};