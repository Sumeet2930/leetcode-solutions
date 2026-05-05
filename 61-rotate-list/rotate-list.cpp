class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // yes
        if (!head || !head->next || k == 0) return head;
        
        vector<int> nums;
        ListNode* temp = head;

        while(temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        temp = head;
        int i = 0;

        while (temp) {
            temp->val = nums[i++];
            temp = temp->next;
        }
        return head;
    }
};