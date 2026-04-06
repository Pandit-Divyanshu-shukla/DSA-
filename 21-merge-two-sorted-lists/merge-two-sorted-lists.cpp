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
        if(list1 == nullptr){
            return list2;
        }
        if(list2==nullptr) return list1;
        ListNode* dummy = new ListNode(-1);

        ListNode* list = dummy;

        ListNode* head1 = list1;
        ListNode* head2 = list2;

        while(head1!= nullptr && head2!=nullptr){
            if(head1->val<head2->val){
                list->next = head1;
                head1 = head1->next;
                list = list->next;
            }else{
                list->next = head2;
                head2=head2->next;
                list = list->next;
            }
        }

        while(head1!= nullptr){
            list->next = head1;
            head1 = head1->next;
            list = list->next;
        }

        while(head2!= nullptr){
            list->next = head2;
            head2 = head2->next;
            list = list->next;
        }

        return dummy->next;
    }
};