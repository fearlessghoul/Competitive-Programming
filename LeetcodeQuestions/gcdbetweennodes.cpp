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
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* first=head,*second=head->next,*temp;
        while(second){
            temp = new ListNode(gcd(first->val,second->val),first->next);
            first->next= temp;
            first= temp->next;
            second=second->next;
        }
        return head;
    }
};
int main(){
    Solution a;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    ListNode *res = a.insertGreatestCommonDivisors(head1);
    printList(res);
}