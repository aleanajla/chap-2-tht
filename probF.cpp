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

void swap( Num *a, Num *b){ 
    int temp = a->number; 
    a->number = b->number; 
    b->number = temp; 
} 

void sort(){
    int swapp,i; 
    struct Num *a; 
    struct Num *ptr = NULL; 
  
    if (head == NULL) {
        return; 
    }
    do{ 
        swapp = 0; 
        a = head; 
  
        while (a->next != ptr){ 

            if (a->number < a->next->number){  
                swap(a, a->next); 
                swapp = 1; 
            } 
            a = a->next; 
        } 
        ptr = a; 
    } 
    while (swapp); 
} 
  

int main(){

    // 20 -> 50 -> 100 -> 120 -> 140 ->NULL

    pushHead(50);
    pushHead(20);
    pushTail(100);
    pushTail(120);
    pushTail(140);

    printList();
    printf("After Sorting (descending)\n");
    sort();
    printList();

    
    return 0;
}