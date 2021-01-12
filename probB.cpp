#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Num{
    int number;
    Num *next;
}*head,*tail;

int max=0;
int min=1000;

Num*createNum(int number){
    Num *newNum = (Num*)malloc(sizeof(Num));
    newNum->number = number;
    newNum->next = NULL;
    if(max<number){
        max=number;
    }
    else{
        min=number;
    }

    return newNum;
}


// int maxNum(){
//     int max=0;
//     while(head != NULL){
//         if(max < head->number){
//             max = head->number;
//         }
//         head = head->next;
//     }
//     return max;
// }

// int minNum(){

//     int min=1000;
//     while(head != NULL){
//         if(min > head->number){
//             min = head->number;
//         }
//         head = head->next;
//     }
//     return min;
// }


//push head,push tail

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

    pushHead(50);
    pushHead(20);
    pushTail(100);
    pushTail(120);
    pushTail(140);

    printList();
    printf("Max element: %d\n",max);
    // printf("%d\n",maxNum());

    printf("Min element: %d\n",min);
    // printf("%d\n",minNum());
    printf("Range: %d\n",max-min);
    

    return 0;
}