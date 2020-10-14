#include<bits/stdc++.h>
using namespace std;
/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Sum the numbers of L1 and L2, keep single digit, store the tens digit to the next digit.
Continuing update the answer node until no tens digit left.
O(n)
*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* res=nullptr, *nxt=nullptr;
    int add=0;
    while(l1!=nullptr||l2!=nullptr||add){
        if(l1!=nullptr){
            add+=l1->val;
            l1=l1->next;
        }
        if(l2!=nullptr){
            add+=l2->val;
            l2=l2->next;
        }
        ListNode* tmp=new ListNode(add%10);
        if(nxt==nullptr){ //at the beginning
            nxt=res=tmp;
        }else{
            nxt->next=tmp;
            nxt=nxt->next;
        }
        add/=10;
    }
    return res;
}

int main(){
    ListNode a1(9);
    ListNode a2(9);
    ListNode a3(9);
    ListNode a4(9);

    ListNode b1(9);
    ListNode b2(9);
    ListNode b3(9);
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;

    b1.next=&b2;
    b2.next=&b3;

    ListNode* x=&a1;
    //printf("%d %d %d",x->val,x->next->val,x->next->next->val);
    //printf("%d %d %d",a1.val,(*a1.next).val,(*(*a1.next).next).val);
    ListNode* y=addTwoNumbers(&a1,&b1);
    int cal=0;
    int bit=1;
    while(y){
        printf("%d",y->val);
        cal+=(y->val)*bit;
        bit*=10;
        y=y->next;
    }
    printf("\n%d",cal);
    return 0;
}
