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
        ListNode *current =  head;
        ListNode *back = nullptr;
        ListNode *forward = nullptr;

        while (current)
        {
            forward = current->next;
            current->next = back;
            back = current;
            current = forward;
        }
        return back;
    }
};
