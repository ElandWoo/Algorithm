/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //设置保护结点
        ListNode* head = new ListNode(0,nullptr);
        ListNode* work = head;
        while (list1 != NULL&&list2 != NULL) {
            if (list1->val <= list2->val) {
                work->next = list1;
                work = work->next;
                list1 = list1->next;
            } else {
                work->next = list2;
                work = work->next;
                list2 = list2->next;
            }
        }
        if (list1 != NULL) {
            work->next = list1;
        } else {
            work->next = list2;
        }
        return head->next;
    }
};
