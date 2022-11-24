#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode mylist_cpy;
    struct ListNode *mylist = l1;
    struct ListNode *prev = &mylist_cpy;
    
    mylist_cpy.next = mylist;
    
    while (l1 != NULL || l2 != NULL) {
        int sum = 0;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            if (mylist == NULL) {
                prev->next = l2;
                mylist = l2;
            }
            
            sum += l2->val;
            l2 = l2-> next;
        }
        
        sum += carry;
        carry = sum / 10;
        mylist->val = sum % 10;
        prev = mylist;
        mylist = mylist->next;
    }
    
    if (carry) {
        mylist = malloc(sizeof(*mylist));
        mylist->val = carry;
        mylist->next = NULL;
        prev->next = mylist;
    }
    
    return mylist_cpy.next;
}

int main() {
     struct ListNode l1;
     struct ListNode l2;
     struct ListNode *l3;
     
     l1.val = 2;
     l1.next = &l2;
     l2.val = 4;
     l2.next = NULL;
     
     l3 = addTwoNumbers(&l1, &l2);
     
     while (l3 != NULL) {
          printf("%d ", l3->val);
          l3 = l3->next;
     }
     
     return 0;
}