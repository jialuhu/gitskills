/*************************************************************************
	> File Name: 两数相加.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  4/21 14:05:06 2019
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Result;
        Result = new ListNode(0);
        ListNode *head = Result;
        int flag = 0;
        int sum = 0;
        while(l1 || l2)
        {
            ListNode *stu = new ListNode(0);
            if(l1 && l2)
            {
                sum = l1->val + l2->val;
                stu -> val = (sum % 10 + flag) % 10;
                flag = (sum + flag) /10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == NULL)
            {
                sum = l2->val + 0;
                stu -> val = (sum % 10 + flag) % 10;
                flag = (sum + flag) / 10;
                l2 = l2->next;
            }
            else if(l2 == NULL)
            {
                sum = l1->val;
                stu -> val = (sum + flag)%10;
                flag = (sum+flag)/10;
                l1 = l1->next;
            }
            head->next = stu;
            head = stu;
        }
        if(flag != 0)
        {
            ListNode *stu = new ListNode(0);
            stu->val = flag;
            head -> next = stu;
            stu->next = NULL;
        }
        return Result->next;
    }
};
