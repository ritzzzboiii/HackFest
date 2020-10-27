//Basic Understanding of linked List

#include <stdio.h>
#include<stdlib.h>

int choice = 0,n = 0 ;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *start = NULL,*newNode,*last = NULL;
void creation (), displayLL(), insertion(), deletion(), search(),middle();
void main(){
    while(choice!=7){
        printf("\n========================================\n");
        printf("\tChoose from the options");
        printf ("\n========================================\n");
        printf(" 1. Creation \n 2. Insertion \n 3. Deletion \n 4. Linear Search \n 5. Print \n 6. Middle Element \n 7. Exit \n");
        printf ("\n========================================\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1: creation();
            //Creation
            ;
            break;
            case 2:insertion();
            //Insertion
            ;
            break;
            case 3:deletion();
            //Deletion
             ; 
            break;
            case 4:search();
            //Linear Search
            ;
            break;
            case 5:displayLL();
            //Print Element
            ;
            break;

            case 6:middle();
            //Middle Element
            ;
            break;

            case 7:
            //Bye
            ;
            break;
            default: printf("Please enter a correct number\n");
        }
    }
}
void creation (){
    int data = 0;
    while(data!=-1){
    newNode = (Node*)malloc(sizeof(Node));
    printf ("Press -1 to End\n");
    printf("Enter the data: ");
    scanf("%d",&data);
    if(data == -1){break;}else{
    newNode->data = data;
    newNode->next = NULL;
    if(start == NULL){
        last = newNode;
        start = newNode;
    }else{
        last->next = newNode;
        last = newNode;
    }
    n++;}}
    printf("Linked List has been created");
};
void displayLL (){
    printf("The data stored is\n");
    last = start;
    while(last!= NULL){
        printf("%d ",last->data);
        last = last->next;
    }
}

void insertion (){
    int pos,data;
    last = start;
    printf("Enter the position where you want to enter new data: ");
    scanf("%d",&pos);
    if(pos>(n+1) || pos < 1)printf("Please enter the values under the range\n");
    else{
        printf ("Enter the data: ");
        scanf("%d",&data);
        newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        last = start;
        if(pos == 1){
            //If user wants to insert the data at first position
            newNode->next = start;
            start = newNode;
            
        }else if(pos == (n+1)){
            while(last->next!=0){
                last = last->next;
            }
            last->next = newNode;
            newNode->next =NULL;
        }else{
            for(int i = 0; i<pos-2;i++){
                last = last->next;
            }
            newNode->next = last->next;
            last->next = newNode; 
        }
        printf("Data has been added\n");
        n++;
        }
}

void deletion (){
    int pos;
    Node *prev;
    printf("Enter the position you want the element to be deleted from: ");
    scanf("%d",&pos);
    last = start;
    if(pos <= n && pos>0){
        if(pos == 1){
            last= start;
            start = start->next;
            free(last);
        }else if(pos==n){
            while(last->next != NULL){
                prev = last;
                last = last->next;
            }
            prev->next = NULL;
            free(last);
        }else{
            last = start;
            Node *current =NULL;
            for(int i = 0; i<pos-2; i++){
                last = last->next;
            }
            current = last->next;
            last->next = current->next;
            free(current);
        }
        printf("Node has been deleted\n");
        n--;
    }else{
        printf("Please enter the position under range");
    }
}
void search(){
    int data, i = 1,f=0;
    last = start;
    printf("Enter the data you want to search : ");
    scanf("%d",&data);
    while(last!=0){
        if(last->data==data){
            printf("%d is present at %d position\n",data,i);
            f=1;
            break;
        }else{
            i++;
        }
        last = last->next;
    }
    if(f==0){
            printf("%d is not present in the Linked List");
        }
}
void middle(){
    int pos = 0;
     last = start;
    if(n%2!=0){
        //odd number of elements
        pos = (n/2)+1;
        for(int i = 0; i<=pos-2;i++){
            last=last->next;
        }
        printf("Middle element is %d",last->data);
    }else{
        pos = n/2;
        for(int i = 0; i<=pos-2; i++){
            last = last->next;
        }
        printf("The middle elements are %d & ",last->data);
        last = last->next;
        printf("%d",last->data);
    }
}
