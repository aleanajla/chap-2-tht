#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Num{
    int number;
    Num *next;
}*head,*tail;

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

void printList(){
    
    Num *curr = head;

    while(curr){
      printf(" %d ->",curr->number);
      curr =  curr->next;
    }
    puts("NULL");
}

void printMiddle(Num *head){
    Num *a= head;
    Num *b = head;
    if(head != NULL){
        while(a != NULL && a->next != NULL){
            a = a->next->next;
            b = b->next;
        }
        printf("Middle elements: %d\n",b->number);
    }
}
int main(){
    

    pushHead(50);
    pushHead(20);
    pushTail(100);
    pushTail(120);
    pushTail(140);

    printList();
    printMiddle(head);


    return 0;
}