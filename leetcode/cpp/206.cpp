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
    Solution1：双指针
    */
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = nullptr; 
        while (fast->next != nullptr) {
            ListNode* tmp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = tmp;
        }
        fast->next = slow;
        return fast;
    }
    
    /*
    Solution2： 递归
    */
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head ;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    
    /*
	Solution3: 迭代
    */
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while(head != NULL) {
            ListNode* nextHead = head->next;
            head->next = last;
            last = head;
            head = nextHead;
        }
        return last;
    }
};