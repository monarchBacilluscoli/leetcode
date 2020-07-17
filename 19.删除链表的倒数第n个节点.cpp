/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next)
        {
            delete head;
            return NULL;
        }
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; ++i)
        {
            if (p2->next != NULL)
            {
                p2 = p2->next;
            }
            else // p2 == NULL
            {
                ListNode *delete_node = head;
                head = head->next;
                delete delete_node;
                return head;
            }
        }
        while (p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *delete_node = p1->next;
        p1->next = delete_node->next;
        delete delete_node;
        return head;
    }
};
// @lc code=end
