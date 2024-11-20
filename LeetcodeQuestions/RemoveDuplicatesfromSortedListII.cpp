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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        bool duplicate=false;
        while(head && head->next && head->val == head->next->val){
            while(head->next && head->val == head->next->val){
                duplicate=true;
                head=head->next;
            }
            if(duplicate){
                head=head->next;
            }
            duplicate=false;
        }
        if(!head || !head->next) return head;
        ListNode* temp=head,*prev=head;
        while(temp && temp->next){
            while(temp && temp->next && temp->val == temp->next->val){
                duplicate=true;
                temp->next=temp->next->next;
            }
            if(duplicate){
                prev->next=temp->next;
                duplicate=false;
            }else{
                prev=temp;
            }
            temp=temp->next;
        }
        return head;
    }
};
int main(){
    Solution a;

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(2);
    // head2->next->next->next = new ListNode(3);
    // head2->next->next->next->next = new ListNode(4);
    // head2->next->next->next->next->next = new ListNode(4);
    // head2->next->next->next->next->next->next = new ListNode(5);
    ListNode *res = a.deleteDuplicates(head2);
    printList(res);
}