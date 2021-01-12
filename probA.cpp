#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Num{
    int number;
    Num *next;
}*head,*tail,*head1,*tail1;

Num*createNum(int number){
    Num *newNum = (Num*)malloc(sizeof(Num));
    newNum->number = number;
    newNum->next = NULL;
    return newNum;
}


void pushHead(int number){

    Num *temp = createNum(number);
    if(!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

//2
void pushHead1(int number){

    Num *temp = createNum(number);
    if(!head1){
        head1 = tail1 = temp;
    }
    else{
        temp->next = head1;
        head1 = temp;
    }
}

void pushTail(int number){
    Num *temp = createNum(number);
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

// 2
void pushTail1(int number){
    Num *temp = createNum(number);
    if(!head1){
        head1 = tail1 = temp;
    }
    else{
        tail1->next = temp;
        tail1 = temp;
    }
}


void popHead(){
    if(!head){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Num *temp = head->next;
        head->next = NULL;
        free(head);
        head = NULL;
    }
}

//2
void popHead1(){
    if(!head1){
        return;
    }
    else if(head1 == tail1){
        free(head1);
        head1 = tail1 = NULL;
    }
    else{
        Num *temp = head1->next;
        head1->next = NULL;
        free(head1);
        head1 = NULL;
    }
}

void popTail(){
    if(!head){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Num *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail= temp;
    }
}

//2
void popTail1(){
    if(!head1){
        return;
    }
    else if(head1 == tail1){
        free(head1);
        head1 = tail1 = NULL;
    }
    else{
        Num *temp = head1;
        while(temp->next != tail1){
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail1);
        tail1= temp;
    }
}

void printList(){
    
    Num *curr = head;

    while(curr){
      printf(" %d ->",curr->number);
      curr =  curr->next;
    }
    puts("NULL");
}

void printList1(){
    
    Num *curr = head1;

    while(curr){
      printf(" %d ->",curr->number);
      curr =  curr->next;
    }
    puts("NULL");
}

int main(){

    pushHead(50);
    pushHead(30);
    pushTail(80);
    pushTail(90);
    pushTail(110);
    printf("Linked 1\n");
    printList();

    pushHead1(20);
    pushHead1(10);
    pushTail1(110);
    pushTail1(120);
    pushTail1(140);
    printf("Linked 2\n");
    printList1();

    printf("Merge Linked\n");
    pushHead(20);
    pushHead(10);
    pushTail(120);
    pushTail(130);
    pushTail(140);
    printList();

    return 0;
}