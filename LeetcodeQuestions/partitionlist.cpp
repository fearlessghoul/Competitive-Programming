#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head | !head->next) return head;
        ListNode*one=nullptr,*two=nullptr,*three=head,*temp1=nullptr,*temp2=nullptr;
        while(three){
            if(three->val < x){
                if(one){
                    one->next=three;
                    one=one->next;
                }else{
                    one=three;
                    temp1=one;
                }
            }else{
                if(two){
                    two->next=three;
                    two=two->next;
                }else{
                    two=three;
                    temp2=two;
                }
            }
            three=three->next;
        }
        two->next=nullptr;
        if(!temp1){
            return temp2;
        }
        one->next=temp2;
        return temp1;
    }
};
int main(){
    Solution a;

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(2);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(2);
    ListNode *res = a.partition(head2,3);
    printList(res);
}