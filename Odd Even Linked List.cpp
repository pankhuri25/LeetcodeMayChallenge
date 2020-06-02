class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
        
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenH = even;
        
        while(odd!=NULL && odd->next!=NULL && odd->next->next!=NULL)
        {
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenH;
        return head;
    }
};
