
//Accepted	256 ms	cpp
class Solution {
public:
    ListNode *mergeList(ListNode *head1,ListNode *head2)
    {
        ListNode* tmp;
        if(!head1) return head2;
        if(!head2) return head1;
        if(head1->val < head2->val)
        {
            tmp = head1;
            head1 = head1->next;
        }
        else
        {
            tmp = head2;
            head2 = head2->next;
        }
        tmp->next = mergeList(head1,head2);
        return tmp;
    }
    ListNode *sortList(ListNode *head)
    {
        if(!head) return NULL;
        ListNode *quick,*low,*ans;
        ans = quick = low = head;
        while(quick->next && quick->next->next)
        {
            quick = quick->next->next;
            low = low->next;
        }
        if(low->next == NULL) return ans;
        quick = low->next;
        low->next = NULL;
        low = head;
        ListNode* l = sortList(low);
        ListNode* q = sortList(quick);
        ans = mergeList(l,q);
        return ans;
    }
};

