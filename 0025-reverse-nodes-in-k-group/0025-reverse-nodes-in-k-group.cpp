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

    // Reverse exactly k nodes
    ListNode* reverseKNodes(ListNode* head, int k) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {

            ListNode* front = curr->next;

            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Original head becomes the tail
        // Connect it with the remaining list
        head->next = curr;

        return prev;
    }

    // Find length of the linked list
    int findLength(ListNode* head) {

        int cnt = 0;
        ListNode* temp = head;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int len = findLength(head);

        ListNode* curr = head;
        ListNode* prevGroupTail = nullptr;

        while (len >= k) {

            // First node of current group
            // becomes the tail after reversal
            ListNode* groupHead = curr;

            // Reverse current group
            ListNode* newHead = reverseKNodes(curr, k);

            // Connect previous group with current group
            if (prevGroupTail == nullptr) {
                // First group
                head = newHead;
            }
            else {
                prevGroupTail->next = newHead;
            }

            // Current group's tail
            prevGroupTail = groupHead;

            // Move to next group
            curr = groupHead->next;

            len -= k;
        }

        return head;
    }
};