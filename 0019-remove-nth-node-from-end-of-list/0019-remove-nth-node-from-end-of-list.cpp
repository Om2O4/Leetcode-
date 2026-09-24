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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next=head;
        ListNode* f=temp;
        ListNode* s=temp;

        for(int i = 0;i<=n;++i){
            f=f->next;
        }

        while(f!=nullptr){
            f=f->next;
            s=s->next;
        }

        ListNode* dummy = s->next;
        s->next=s->next->next;
        delete dummy;

        return temp->next;
    }
};