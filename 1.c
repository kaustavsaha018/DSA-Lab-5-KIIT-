#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int data;
	struct node *next;
};

int count=0;


void create();
void insert_begin();
void insert_end();
void insert_atPos();
void display();

struct node *head,*newnode,*temp;

void main(){
	
	create();
	int i;
	
	printf("\nCHOICES:\n1 for insert at begin\n2 for insert at end\n"
	"3 for insert at given position\n4 for displaying the list\n\n");
	
	int again=1;
	do{
		printf("\nEnter your choice: ");
		scanf("%d",&i);
		
		switch(i){
			case 1:
				insert_begin();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_atPos();
				break;
			case 4:
				display();
				break;
			default:
				printf("\nWrong Input!");
		}
	}while(again==1);	
		
}

void create(){
	char flag;
	printf("Enter the elements of the Linked List:\n\n");
	do{
		newnode = (struct node *)malloc(sizeof(struct node));
		if(count==0){
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			head=newnode;
			temp=newnode;
			temp->next=0;
			count++;
		}
		else{	
			printf("Enter data: ");	
			scanf("%d", &newnode->data);
			temp->next=newnode;
			temp=newnode;
			temp->next=0;
			count++;	
		}
		printf("Do you want to continue(y/n)? ");
		scanf(" %c",&flag);
		getchar();
		
	}while(flag='y' && flag!='n');
}

void display(){
	printf("\nThe List is Diplaying...\n");
	temp=head;
	while(temp!=0){
		printf(" %d ", temp->data);
		temp=temp->next;
	}	
}

void insert_begin(){
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	temp=head;
	printf("\n\nEnter new data (TO BE INSERTED AT BEGIN): ");
	scanf("%d",&newnode->data);
	newnode->next=temp;
	head=newnode;
}

void insert_end(){
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	temp=head;
	printf("\n\nEnter new data (TO BE INSERTED AT END): ");
	scanf("%d",&newnode->data);
	while(temp->next!=0){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=0;
}

void insert_atPos(){
	int pos,flag=1;
	
	while(flag==1){
		
		printf("\nEnter the position where you want to insert: ");
		scanf("%d",&pos);
		
		if(pos>count){
		printf("\nEnter a correct position");
		flag=1;
		}
		else{
	
		struct node *newnode;
		int count=1;
		temp=head;
		while(temp!=0){
			if(count==pos-1){
				break;
			}
			else{
				count++;
				temp=temp->next;	
			}
		
		}
	
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter the data to be inserted: ");
		scanf("%d", &newnode->data);
		newnode->next=temp->next;
		temp->next=newnode;
		flag=0;
		}
	}
	
}
