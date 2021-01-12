#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Num{
    int number;
    Num *next;
}*head,*tail;

int count=0;

Num*createNum(int number){
    Num *newNum = (Num*)malloc(sizeof(Num));
    newNum->number = number;
    newNum->next = NULL;
    count++;
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

int main(){

    //20 -> 50 -> 100 -> 120 -> 140 ->NULL
    pushHead(50);
    pushHead(20);
    pushTail(100);
    pushTail(120);
    pushTail(140);

    printList();

    int counter = 0;
    int search = 20;
    Num *curr=head;
    while(curr->number != search){
        counter++;
        // printf("counter: %d\n",counter);
        curr = curr->next;
    }
    printf("%dth node from the end on index %d\n",search,count-counter);

    return 0;
}