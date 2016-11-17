/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
      ListNode *current = NULL;
      
      bool add1 = false;
      while (l1!=NULL&&l2!=NULL) {
        int sum = 0;
        if (l1!=NULL) {
          sum+=l1->val;
        }
        if (l2!=NULL) {
          sum+=l2->val;
        }
        if (add1==true) {
          sum+=1;
          add1=false;
        }
        
        if (sum>=10) {
          ListNode *newNode = new ListNode(sum-10);
          add1 = true;
          
          if (head==NULL) {
            head = newNode;
            current = newNode;
          }
          else {
            current->next = newNode;
            current=newNode;
          }
        }
        else {
          ListNode *newNode = new ListNode(sum);
          if (head==NULL) {
            head = newNode;
            current = newNode;
          }
          else {
            current->next = newNode;
            current=newNode;
          }
        }
        
        if (l1!=NULL) l1=l1->next;
        if (l2!=NULL) l2=l2->next;
      }
      
      // Handle extra +1;
      if (add1==true) {
        ListNode *newNode = new ListNode(1);
        current->next = newNode;
      }
      
      return head;
    }
};