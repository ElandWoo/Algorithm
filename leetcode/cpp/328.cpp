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
    
    /*
    Solution1
    */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* evenHead = new ListNode(0, even);

        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;
            // if (!odd || !odd->next) break;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead->next;
        return head;
    }
    
    /*
    Solution2
    */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pOdd = head;
        ListNode* p = head ->next;
        ListNode* pNext = nullptr;
        while (p && (pNext = p->next)) {
            p->next = pNext->next;
            pNext->next = pOdd->next;
            pOdd->next = pNext;

            p = p->next;
            pOdd = pOdd->next;
        }
        return head;
    }
};