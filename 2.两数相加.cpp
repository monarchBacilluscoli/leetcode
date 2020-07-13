/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int carry = 0;
        while (l1 || l2 || carry != 0)
        {
            // 创建下一个节点
            p->next = new ListNode(0);
            p = p->next;
            // 计算两个数的和
            int a1, a2;
            if (l1)
            {
                a1 = l1->val;
                l1 = l1->next;
            }
            else
            {
                a1 = 0;
            }
            if (l2)
            {
                a2 = l2->val;
                l2 = l2->next;
            }
            else
            {
                a2 = 0;
            }
            p->val = (a1 + a2 + carry) % 10;
            carry = (a1 + a2 + carry) / 10;
            // 注意两个指针的有效性，最后的l1、l2移位放在条件里w
        }
        return head->next;
    }
};
// @lc code=end
