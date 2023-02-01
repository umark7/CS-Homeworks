#include<stdbool.h>
#include"Queue.h"

struct node 
{
   int key;
   struct FileData Data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() 
{
   struct node *ptr = head;

   if(ptr->Data.Scheduling_Type == "FCFS")
   {
      //start from the beginning
      while(ptr != NULL) 
      {
         printf("\n\n\tList Element[%d]\n\n", ptr->Data.Process_ID);
         printf("Proccess ID: %d\n", ptr->Data.PCB.Process_ID);
         printf("Process State: %s\n", ptr->Data.PCB.Process_State);
         printf("Process File: %s\n", ptr->Data.PCB.Process_File);
         printf("Operation Name: %s\n", ptr->Data.PCB.Process_Name);    
         printf("Operation Input 1: %d\n", ptr->Data.PCB.Process_Input1);    
         printf("Operation Input 2: %d\n", ptr->Data.PCB.Process_Input2);    

         ptr = ptr->next;
      }
   }
   else if(ptr->Data.Scheduling_Type == "SJF")
   {
      while(ptr != NULL)
      {
         printf("\n\n\tList Element[%d]\n\n", ptr->Data.Process_ID);
         printf("Proccess ID: %d\n", ptr->Data.PCB.Process_ID);
         printf("Process State: %s\n", ptr->Data.PCB.Process_State);
         printf("Process File: %s\n", ptr->Data.PCB.Process_File);
         printf("Operation Name: %s\n", ptr->Data.PCB.Process_Name);    
         printf("CPU-Burst Time: %d seconds\n", ptr->Data.PCB.Process_CPU);    
         printf("Operation Input 1: %d\n", ptr->Data.PCB.Process_Input1);    
         printf("Operation Input 2: %d\n", ptr->Data.PCB.Process_Input2);   
         
         ptr = ptr->next;
      }
   }
   else if(ptr->Data.Scheduling_Type == "Priority")
   {
      while(ptr != NULL)
      {
         printf("\n\n\tList Element[%d]\n\n", ptr->Data.Process_ID);
         printf("Proccess ID: %d\n", ptr->Data.PCB.Process_ID);
         printf("Process State: %s\n", ptr->Data.PCB.Process_State);
         printf("Process File: %s\n", ptr->Data.PCB.Process_File);
         printf("Operation Name: %s\n", ptr->Data.PCB.Process_Name);    
         printf("Operation Priority NUM: %d\n", ptr->Data.PCB.Process_Priority);    
         printf("Operation Input 1: %d\n", ptr->Data.PCB.Process_Input1);    
         printf("Operation Input 2: %d\n", ptr->Data.PCB.Process_Input2);

         ptr = ptr->next;
      }    
   }   
}

//insert link at the first location
void insertFirst(int Process_ID, struct FileData Object)
{
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = Process_ID;
   link->Data = Object;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//delete first item
struct node* deleteFirst() 
{
   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

// returns maximum node key
int getMax()
{
   int MAX_Key = 0;
   struct node *ptr = head;

   if(ptr->Data.Scheduling_Type == "SJF")
   {
      int MAX_CPU = 0;

      //start from the beginning
      while(ptr != NULL) 
      {
         if(ptr->Data.CPU_Time > MAX_CPU)
         {
            MAX_CPU = ptr->Data.CPU_Time;
            MAX_Key = ptr->key;
         }

         ptr = ptr->next;
      }      
   }
   else if(ptr->Data.Scheduling_Type == "Priority")
   {
      int MAX_Priority = 0;
      
      //start from the beginning
      while(ptr != NULL) 
      {
         if(ptr->Data.Priority_NUM > MAX_Priority)
         {
            MAX_Priority = ptr->Data.Priority_NUM;
            MAX_Key = ptr->key;
         }

         ptr = ptr->next;
      }
   }   
}

//delete a link with given key
struct node* delete(int key) 
{
   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

void sort() 
{
   struct FileData tempData;
   int i, j, k, tempKey;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) 
      {
         if(current->Data.Scheduling_Type == "FCFS")
         {
            if (current->Data.Process_ID > next->Data.Process_ID )
            {
               tempData = current->Data;
               current->Data = next->Data;
               next->Data = tempData;

               tempKey = current->key;
               current->key = next->key;
               next->key = tempKey;
            }
            
            current = current->next;
            next = next->next;
         }
         else if(current->Data.Scheduling_Type== "SJF")
         {
            if (current->Data.CPU_Time > next->Data.CPU_Time )
            {
               tempData = current->Data;
               current->Data = next->Data;
               next->Data = tempData;

               tempKey = current->key;
               current->key = next->key;
               next->key = tempKey;
            }
            
            current = current->next;
            next = next->next;
         }
         else if(current->Data.Scheduling_Type == "Priority")
         {
            if (current->Data.Priority_NUM > next->Data.Priority_NUM )
            {
               tempData = current->Data;
               current->Data = next->Data;
               next->Data = tempData;

               tempKey = current->key;
               current->key = next->key;
               next->key = tempKey;
            }
            
            current = current->next;
            next = next->next;
         }             
      }
   }   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}