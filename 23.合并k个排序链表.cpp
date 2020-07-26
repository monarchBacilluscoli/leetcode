/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        std::multimap<int, ListNode *> sorted_map;
        ListNode *result = new ListNode(0), *p = result;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
            {
                sorted_map.insert({lists[i]->val, lists[i]});
            }
        }

        while (!sorted_map.empty())
        {
            //todo 出一个
            p->next = sorted_map.begin()->second;
            sorted_map.erase(sorted_map.begin());
            p = p->next;
            //todo 进一个
            if (p->next)
            {
                sorted_map.insert({p->next->val, p->next});
            }
        }
        return result->next;
    }
};
// @lc code=end
