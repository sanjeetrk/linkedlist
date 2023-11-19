#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};


void display(struct node *head);
void addbeg(struct node **head,int data);
void addend(struct node **head, int data);
void addpos(struct node **head,int pos, int data);



int main(){


    struct node *head = NULL;

    while(1){

        int get,data,pos;
        printf("------------Singly linked list ---------\n");
        printf("1. add beginning\n");
        printf("2. add end\n");
        printf("3. add at position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Choose your option: ");
        scanf("%d",&get);

        switch(get){

            case 1: 
            
            printf("Enter the data: ");
            scanf("%d", &data);
            addbeg(&head,data);
            break;

            case 2: 
            
            printf("Enter the data: ");
            scanf("%d", &data);
            addend(&head,data);
            break;

            case 3: 
            
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("\nEnter the position: ");
            scanf("%d",&pos);
            addpos(&head,pos,data);
            break;

            case 4:
                display(head);
                break;

            case 5:
                return 0;



        }
    }

    // addbeg(&head,7);
    // addbeg(&head,6);
    // addend(&head,5);
    // addpos(&head,1,8);
    // display(head);
    return 0;

}

void addbeg(struct node **head,int data){
    
    struct node *temp=malloc(sizeof(struct node));
    if (temp==NULL){
        printf("Memory is  not available");
        return;
        }

    temp->data=data;
    temp->link=*head;
    *head=temp;
}

void display(struct node *head){

    struct node *temp=head;
    while(temp!=NULL){

        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("\n");

    
}

void addend(struct node **head, int data){
    struct node *temp;
    temp=malloc(sizeof(struct node));

    temp->data=data;
    temp->link=NULL;

    struct node *ptr=*head;

    while(ptr->link!=NULL){
        ptr=ptr->link;

    }
    ptr->link=temp;

}

void addpos(struct node **head, int pos, int data){
    struct node *newnode=malloc(sizeof(struct node));
    int i=1;
    if (newnode!=NULL){
        newnode->data=data;
        newnode->link=NULL;
    }

    
    if (pos<1){
        printf("Position is less than one");
        return;
    }
    if(pos==1){
        newnode->link=*head;
        *head=newnode;
        return;
    }
    struct node *temp=*head;
    while(i<pos-1 && temp!=NULL){
        temp=temp->link;
        i++;

    }
    newnode->link=temp->link;
    temp->link=newnode;


}
