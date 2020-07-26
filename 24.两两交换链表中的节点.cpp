/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return head;
        }
        vector<ListNode *> v1;
        vector<ListNode *> v2;
        ListNode *p = head;
        for (int i = 0; p != NULL; ++i)
        {
            if (i % 2)
            {
                v2.push_back(p);
                p = p->next;
            }
            else
            {
                v1.push_back(p);
                p = p->next;
            }
        }
        for (int i = 0; i < v2.size(); ++i)
        {
            v2[i]->next = v1[i];
            if (i + 1 < v2.size())
                v1[i]->next = v2[i + 1];
            else
                v1[i]->next = NULL;
        }
        if (v1.size() > v2.size())
        {
            (*(v1.end() - 2))->next = *(v1.end() - 1);
            *(v1.end() - 1) = NULL;
        }
        return v2[0];
    }
};
// @lc code=end
