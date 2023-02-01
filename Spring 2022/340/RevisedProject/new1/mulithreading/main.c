#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <pthread.h>

struct PCB
{
   int Process_ID;
   
   char Process_Name[10];
   char* Process_State;
   char* Process_File;

   int Process_CPU;
   int Process_Priority;

   int Process_Input1;
   int Process_Input2;
   int Process_Output;
};

struct FileData
{
	int Process_ID;

	char* Scheduling_Type;
	char Operation_Name[10];
	int CPU_Time;
	int Priority_NUM;
	int Input1;
	int Input2;

	int Output;

	struct PCB PCB;
};


# define SIZE 15
void FCFS_Enqueue(char* Type, int ID, char* Operation, int input1, int input2);  //FCFS
void SJF_Enqueue(char* Type, int ID, char* Operation, int CPU, int input1, int input2); //SJF
void Priority_Enqueue(char* Type, int ID, char* Operation, int Priority, int input1, int input2);    //Priority
void Dequeue();
void print_ReadyQueue_print();
struct FileData Ready_Queue[SIZE];
int Rear = - 1;
int Front = - 1;

void FCFS_Enqueue(char* Type, int ID, char* Operation, int input1, int input2)
{
    struct FileData Insert_Object;
    Insert_Object.Process_ID = ID;
    Insert_Object.Scheduling_Type = Type;
    //Insert_Object.Operation_Name = Operation;
    Insert_Object.Input1 = input1;
    Insert_Object.Input2 = input2;
    
    int i = 0;
    for(i=0; Operation[i] != '\0'; i++)
        Insert_Object.Operation_Name[i] = Operation[i];
        // printf("%c", Insert_Object.Operation_Name[i]);

        Insert_Object.Operation_Name[i] = '\0';

    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)       
            Front = 0;

        //printf("Element inserted in the Queue...\n");
        Rear = Rear + 1;
        Ready_Queue[Rear] = Insert_Object;
    }
} 

void SJF_Enqueue(char* Type, int ID, char* Operation, int CPU, int input1, int input2)
{
    struct FileData Insert_Object;
    Insert_Object.Process_ID = ID;
    Insert_Object.Scheduling_Type = Type;
    //Insert_Object.Operation_Name = Operation;
    Insert_Object.CPU_Time = CPU;
    Insert_Object.Input1 = input1;
    Insert_Object.Input2 = input2;
    
    int i = 0;
    for(i=0; Operation[i] != '\0'; i++)
        Insert_Object.Operation_Name[i] = Operation[i];
        // printf("%c", Insert_Object.Operation_Name[i]);

        Insert_Object.Operation_Name[i] = '\0';


    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)       
            Front = 0;

        //printf("Element inserted in the Queue...\n");
        Rear = Rear + 1;
        Ready_Queue[Rear] = Insert_Object;
    }
} 

void Priority_Enqueue(char* Type, int ID, char* Operation, int Priority, int input1, int input2)
{
    struct FileData Insert_Object;
    Insert_Object.Process_ID = ID;
    Insert_Object.Scheduling_Type = Type;
    //Insert_Object.Operation_Name = Operation;
    Insert_Object.Priority_NUM = Priority;    
    Insert_Object.Input1 = input1;
    Insert_Object.Input2 = input2;
    
    int i = 0;
    for(i=0; Operation[i] != '\0'; i++)
        Insert_Object.Operation_Name[i] = Operation[i];
        // printf("%c", Insert_Object.Operation_Name[i]);

        Insert_Object.Operation_Name[i] = '\0';


    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)       
            Front = 0;

        //printf("Element inserted in the Queue...\n");
        Rear = Rear + 1;
        Ready_Queue[Rear] = Insert_Object;
    }
} 

void Dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("First Element deleted from the Queue..\n");
        // struct FileData temp;
        // Ready_Queue[Front] = temp;
        Front = Front + 1;
    }
} 
  
void print_ReadyQueue_print()
{
     
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("\n\nDisplaying Elements stored in the Ready Queue..\n\n");


        if(Ready_Queue[0].Scheduling_Type == "FCFS")
        {
            printf("Scheduling Type: %s\n", Ready_Queue[0].Scheduling_Type);

            for (int i = Front; i <= Rear; i++)
            {
                printf("\n\n\tQueue Element[%d]\n\n", (i+1));

                printf("Process Number: %d\n", Ready_Queue[i].Process_ID);
                printf("Operation Name: %s\n", Ready_Queue[i].Operation_Name);
                printf("Input Parameter 1: %d\n", Ready_Queue[i].Input1);
                printf("Input Parameter 2: %d\n", Ready_Queue[i].Input2);
            }
            printf("\n");
        }
        else if(Ready_Queue[0].Scheduling_Type == "SJF")
        {
            printf("Scheduling Type: %s\n", Ready_Queue[0].Scheduling_Type);

            for (int i = Front; i <= Rear; i++)
            {
                printf("\n\n\tQueue Element[%d]\n\n", (i+1));

                printf("Process Number: %d\n", Ready_Queue[i].Process_ID);
                printf("Operation Name: %s\n", Ready_Queue[i].Operation_Name);
                printf("CPU Burst-Time: %d seconds\n", Ready_Queue[i].CPU_Time);
                printf("Input Parameter 1: %d\n", Ready_Queue[i].Input1);
                printf("Input Parameter 2: %d\n", Ready_Queue[i].Input2);
            }
            printf("\n");
        }
        else if(Ready_Queue[0].Scheduling_Type == "Priority")
        {
            printf("Scheduling Type: %s\n", Ready_Queue[0].Scheduling_Type);

            for (int i = Front; i <= Rear; i++)
            {
                printf("\n\n\tQueue Element[%d]\n\n", (i+1));

                printf("Process Number: %d\n", Ready_Queue[i].Process_ID);
                printf("Operation Name: %s\n", Ready_Queue[i].Operation_Name);
                printf("Priority Number: %d\n", Ready_Queue[i].Priority_NUM);
                printf("Input Parameter 1: %d\n", Ready_Queue[i].Input1);
                printf("Input Parameter 2: %d\n", Ready_Queue[i].Input2);
            }
            printf("\n");
        }
    }
} 

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

// Global Mutex Lock
pthread_mutex_t Mutex_Lock;

// Output filename
char* Output_FileName;

int SUMMATION_Function(int input1, int input2)
{
    // Locking the Critical Section 
    //pthread_mutex_lock(&Mutex_Lock);

    int SUM = 0;
 
    for(int num = input1; num <= input2; num++)
        SUM += num;

    //pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section

    //printf("\nSUM: %d\n", SUM);

    return SUM;    
}

int PRODUCT_Function(int input1, int input2)
{
    // Locking the Critical Section 
    //pthread_mutex_lock(&Mutex_Lock);

    int PRODUCT = 1;

    // for(int num = input1; num <= input2; num++)
        PRODUCT = input1 * input2;
    
    //pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section

    //printf("\nPRODUCT: %d\n", PRODUCT);

    return PRODUCT;
}

int POWER_Function(int input1, int input2)
{
    int POWER = 1;

    // Locking the Critical Section 
    //pthread_mutex_lock(&Mutex_Lock);
 
    if (input2 == 0)
        return 1;
    else if (input2%2 == 0)
        return POWER_Function(input1, input2/2)*POWER_Function(input1, input2/2);
    else
        return input1*POWER_Function(input1, input2/2)*POWER_Function(input1, input2/2);    
    //pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section 

}

int FIBONACCI_Function(int input1, int input)
{
    // Locking the Critical Section 
    //pthread_mutex_lock(&Mutex_Lock);
 
    if (input <= 1)
        return input;

    return FIBONACCI_Function(input1, input - 1) + FIBONACCI_Function(input1, input - 2);    
    //pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section

    //printf("\nFIBONACCI: %d\n", FIBONACCI);
}

int myAtoi(char* str)
{
    int sign = 1, base = 0, i = 0;
     
    // if whitespaces then ignore.
    while (str[i] == ' ')
        i++;
     
    // sign of number
    if (str[i] == '-' || str[i] == '+')
        sign = 1 - 2 * (str[i++] == '-');
   
    // checking for valid input
    while (str[i] >= '0' && str[i] <= '9')
    {
        // handling overflow test case
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

char* Concatenate(char* string, char* string2)
{
    int length = 0, j = 0;

    // store length of string in the length variable
    while (string[length] != '\0') 
        ++length;

    char * string1 = (char*)malloc (length * sizeof (char));
    for(int i=0; string[i] != '\0'; i++)
        string1[i] = string[i];


    // concatenate s2 to s1
    for (j = 0; string2[j] != '\0'; ++j, ++length)
        string1[length] = string2[j];

    // terminating the string1
    string1[length] = '\0';

    return string1;
}

void Scheduler_Dispatcher(long Process_NUM)
{
    struct node *ListPtr = head;

    // Locking the Critical Section 
    pthread_mutex_lock(&Mutex_Lock);

    if(ListPtr->Data.Scheduling_Type == "FCFS")
    {
        //printf("Scheduling Type: %s\n", ListPtr->Data.Scheduling_Type);

        // Accessing the next List Element
        int iterator = 1;
        while(iterator < Process_NUM)
        {
            ListPtr = ListPtr->next;
            iterator++;
        }

        int input1 = ListPtr->Data.Input1;
        int input2 = ListPtr->Data.Input2;

        if(!strcmp(ListPtr->Data.PCB.Process_Name, "sum\0"))
        {
            ListPtr->Data.Output = SUMMATION_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput SUM: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "product\0"))
        {
            ListPtr->Data.Output = PRODUCT_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput PRODUCT: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "power\0"))
        {
            ListPtr->Data.Output = POWER_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput POWER: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "fibonacci\0"))
        {
            ListPtr->Data.Output = FIBONACCI_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput FIBONACCI: %d\n", ListPtr->Data.PCB.Process_Output);
        }
    }
    else if(ListPtr->Data.Scheduling_Type == "SJF")
    {
        //printf("Scheduling Type: %s\n", ListPtr->Data.Scheduling_Type); 
        sort();

        // Accessing the next List Element
        int iterator = 1;
        while(iterator < Process_NUM)
        {
            ListPtr = ListPtr->next;
            iterator++;
        }

        int input1 = ListPtr->Data.Input1;
        int input2 = ListPtr->Data.Input2;

        if(!strcmp(ListPtr->Data.PCB.Process_Name, "sum\0"))
        {
            ListPtr->Data.Output = SUMMATION_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput SUM: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "product\0"))
        {
            ListPtr->Data.Output = PRODUCT_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput PRODUCT: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "power\0"))
        {
            ListPtr->Data.Output = POWER_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput POWER: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "fibonacci\0"))
        {
            ListPtr->Data.Output = FIBONACCI_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput FIBONACCI: %d\n", ListPtr->Data.PCB.Process_Output);
        }
    }
    else if(ListPtr->Data.Scheduling_Type == "Priority")
    {
        //printf("Scheduling Type: %s\n", ListPtr->Data.Scheduling_Type); 
        sort();

        // Accessing the next List Element
        int iterator = 1;
        while(iterator < Process_NUM)
        {
            ListPtr = ListPtr->next;
            iterator++;
        }

        int input1 = ListPtr->Data.Input1;
        int input2 = ListPtr->Data.Input2;

        if(!strcmp(ListPtr->Data.PCB.Process_Name, "sum\0"))
        {
            ListPtr->Data.Output = SUMMATION_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput SUM: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "product\0"))
        {
            ListPtr->Data.Output = PRODUCT_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput PRODUCT: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "power\0"))
        {
            ListPtr->Data.Output = POWER_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput POWER: %d\n", ListPtr->Data.PCB.Process_Output);
        }
        else if(!strcmp(ListPtr->Data.PCB.Process_Name, "fibonacci\0"))
        {
            ListPtr->Data.Output = FIBONACCI_Function(input1, input2);
            ListPtr->Data.PCB.Process_Output = ListPtr->Data.Output;
            //printf("\nOutput FIBONACCI: %d\n", ListPtr->Data.PCB.Process_Output);
        }
    }

    pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section
   
}

void Pthread_Logger()
{
    struct node *ptr = head;

   if(ptr->Data.Scheduling_Type == "FCFS")
   {
        FILE *fptr = fopen(Output_FileName,"w");
        if(fptr == NULL)
            printf("Error opening file\n");   

      //start from the beginning
      while(ptr != NULL) 
      {
         // printf("\n\n\tList Element[%d]\n\n", ptr->Data.Process_ID);
        //  printf("Operation Name: %s\n", ptr->Data.PCB.Process_Name);    
        //  printf("Operation Input 1: %d\n", ptr->Data.PCB.Process_Input1);    
        //  printf("Operation Input 2: %d\n", ptr->Data.PCB.Process_Input2);    
        //  printf("Operation Output: %d\n", ptr->Data.Output);
         fprintf(fptr, "%s,%d,%d,%d\n", ptr->Data.PCB.Process_Name, ptr->Data.PCB.Process_Input1, ptr->Data.PCB.Process_Input2, ptr->Data.Output);

         ptr = ptr->next;
         //printf("\n");

      }
      
         fclose(fptr);

   }
   else if(ptr->Data.Scheduling_Type == "SJF")
   {

        FILE *fptr = fopen(Output_FileName,"w");
        if(fptr == NULL)
            printf("Error opening file\n");   

      while(ptr != NULL)
      {
         // printf("\n\n\tList Element[%d]\n\n", ptr->Data.Process_ID);
        //  printf("Operation Name: %s\n", ptr->Data.PCB.Process_Name);    
        //  printf("CPU-Burst Time: %d seconds\n", ptr->Data.PCB.Process_CPU);    
        //  printf("Operation Input 1: %d\n", ptr->Data.PCB.Process_Input1);    
        //  printf("Operation Input 2: %d\n", ptr->Data.PCB.Process_Input2);   
        //  printf("Operation Output: %d\n", ptr->Data.Output);
         fprintf(fptr, "%s,%d,%d,%d\n", ptr->Data.PCB.Process_Name, ptr->Data.PCB.Process_Input1, ptr->Data.PCB.Process_Input2, ptr->Data.Output);

         ptr = ptr->next;
         //printf("\n");
      }

         fclose(fptr);

   }
   else if(ptr->Data.Scheduling_Type == "Priority")
   {
        FILE *fptr = fopen(Output_FileName,"w");
        if(fptr == NULL)
            printf("Error opening file\n");   

      while(ptr != NULL)
      {
         // printf("\n\n\tList Element[%d]\n\n", ptr->Data.Process_ID);
        //  printf("Operation Name: %s\n", ptr->Data.PCB.Process_Name);    
        //  printf("Operation Priority NUM: %d\n", ptr->Data.PCB.Process_Priority);    
        //  printf("Operation Input 1: %d\n", ptr->Data.PCB.Process_Input1);    
        //  printf("Operation Input 2: %d\n", ptr->Data.PCB.Process_Input2);
        //  printf("Operation Output: %d\n", ptr->Data.Output);
         fprintf(fptr, "%s,%d,%d,%d\n", ptr->Data.PCB.Process_Name, ptr->Data.PCB.Process_Input1, ptr->Data.PCB.Process_Input2, ptr->Data.Output);

         ptr = ptr->next;
         //printf("\n");
      }    

         fclose(fptr);

   }   
}

void Initialize_List(long Process_ID)
{
    char* File = Ready_Queue[Process_ID-1].Scheduling_Type;
    char* FileName = Concatenate(File, ".txt");

    // Locking the Critical Section 
    pthread_mutex_lock(&Mutex_Lock);

    if(Ready_Queue[Process_ID-1].Scheduling_Type == "FCFS")
    {
        struct FileData Obj;
        Obj.Process_ID = Process_ID;
        Obj.Input1 = Ready_Queue[Process_ID-1].Input1;        
        Obj.Input2 = Ready_Queue[Process_ID-1].Input2;        
        Obj.Scheduling_Type = Ready_Queue[Process_ID-1].Scheduling_Type;
        for(int i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            Obj.Operation_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        struct PCB obj;
        obj.Process_State = "Active";
        obj.Process_ID = Process_ID;
        obj.Process_Input1 = Ready_Queue[Process_ID-1].Input1;
        obj.Process_Input2 = Ready_Queue[Process_ID-1].Input2;
        obj.Process_File = FileName;//Ready_Queue[Process_ID-1].Scheduling_Type + "".txt";
        for(int i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            obj.Process_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        // Inserting PCB Address and FileData in the FIFO List
        Obj.PCB = obj; insertFirst((int)Process_ID, Obj);
    }
    else if(Ready_Queue[Process_ID-1].Scheduling_Type == "SJF")
    {
        struct FileData Obj;
        Obj.Process_ID = Process_ID;
        Obj.Input1 = Ready_Queue[Process_ID-1].Input1;        
        Obj.Input2 = Ready_Queue[Process_ID-1].Input2; 
        Obj.CPU_Time = Ready_Queue[Process_ID-1].CPU_Time;       
        Obj.Scheduling_Type = Ready_Queue[Process_ID-1].Scheduling_Type;
        for(int i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            Obj.Operation_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        struct PCB obj;
        obj.Process_State = "Active";
        obj.Process_ID = Process_ID;
        obj.Process_CPU = Ready_Queue[Process_ID-1].CPU_Time;
        obj.Process_Input1 = Ready_Queue[Process_ID-1].Input1;
        obj.Process_Input2 = Ready_Queue[Process_ID-1].Input2;
        obj.Process_File = FileName;//Ready_Queue[Process_ID-1].Scheduling_Type + "".txt";
        for(int i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            obj.Process_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        // Inserting PCB Address and FileData in the FIFO List
        Obj.PCB = obj; insertFirst(Process_ID, Obj);
    }
    else if(Ready_Queue[Process_ID-1].Scheduling_Type == "Priority")
    {
        struct FileData Obj;
        Obj.Process_ID = Process_ID;
        Obj.Input1 = Ready_Queue[Process_ID-1].Input1;        
        Obj.Input2 = Ready_Queue[Process_ID-1].Input2; 
        Obj.Priority_NUM = Ready_Queue[Process_ID-1].Priority_NUM;       
        Obj.Scheduling_Type = Ready_Queue[Process_ID-1].Scheduling_Type;
        for(int i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            Obj.Operation_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        struct PCB obj;
        obj.Process_State = "Active";
        obj.Process_ID = Process_ID;
        obj.Process_Input1 = Ready_Queue[Process_ID-1].Input1;
        obj.Process_Input2 = Ready_Queue[Process_ID-1].Input2;
        obj.Process_Priority = Ready_Queue[Process_ID-1].Priority_NUM;
        obj.Process_File = FileName;//Ready_Queue[Process_ID-1].Scheduling_Type + "".txt";
            for(int i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
        obj.Process_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];


        // Inserting PCB Address and FileData in the FIFO List
        Obj.PCB = obj; insertFirst(Process_ID, Obj);
    }   

    pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section
}

void Initialize_PCB(long Process_ID)
{
    char* File = Ready_Queue[Process_ID-1].Scheduling_Type;
    char* FileName = Concatenate(File, ".txt");

    // Locking the Critical Section 
    pthread_mutex_lock(&Mutex_Lock);

    if(Ready_Queue[Process_ID-1].Scheduling_Type == "FCFS")
    {
        struct PCB obj;
        obj.Process_State = "Active";
        obj.Process_ID = Process_ID;
        obj.Process_Input1 = Ready_Queue[Process_ID-1].Input1;
        obj.Process_Input2 = Ready_Queue[Process_ID-1].Input2;
        obj.Process_File = FileName;//Ready_Queue[Process_ID-1].Scheduling_Type + "".txt";
        
        int i=0;
        for(i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            obj.Process_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        obj.Process_Name[i] = '\0';    

        // Inserting PCB Address in the Ready-Queue
        Ready_Queue[Process_ID-1].PCB = obj;

        // printf("\n\n\tProcess Control Block - PCB: %ld\n\n", Process_ID);
        // printf("Proccess ID: %d\n", Ready_Queue[Process_ID-1].PCB.Process_ID);
        // printf("Process State: %s\n", Ready_Queue[Process_ID-1].PCB.Process_State);
        // printf("Process File: %s\n", Ready_Queue[Process_ID-1].PCB.Process_File);
        // printf("Operation Name: %s\n", Ready_Queue[Process_ID-1].PCB.Process_Name);    
        // printf("Operation Input 1: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Input1);    
        // printf("Operation Input 2: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Input2);    
    }
    else if(Ready_Queue[Process_ID-1].Scheduling_Type == "SJF")
    {
        struct PCB obj;
        obj.Process_State = "Active";
        obj.Process_ID = Process_ID;
        obj.Process_CPU = Ready_Queue[Process_ID-1].CPU_Time;
        obj.Process_Input1 = Ready_Queue[Process_ID-1].Input1;
        obj.Process_Input2 = Ready_Queue[Process_ID-1].Input2;
        obj.Process_File = FileName;//Ready_Queue[Process_ID-1].Scheduling_Type + "".txt";

        int i=0;
        for(i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            obj.Process_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        obj.Process_Name[i] = '\0';    

        // Inserting PCB Address in the Ready-Queue
        Ready_Queue[Process_ID-1].PCB = obj;

        // printf("\n\n\tProcess Control Block - PCB: %ld\n\n", Process_ID);
        // printf("Proccess ID: %d\n", Ready_Queue[Process_ID-1].PCB.Process_ID);
        // printf("Process State: %s\n", Ready_Queue[Process_ID-1].PCB.Process_State);
        // printf("Process File: %s\n", Ready_Queue[Process_ID-1].PCB.Process_File);
        // printf("Operation Name: %s\n", Ready_Queue[Process_ID-1].PCB.Process_Name);    
        // printf("CPU-Burst Time: %d seconds\n", Ready_Queue[Process_ID-1].PCB.Process_CPU);    
        // printf("Operation Input 1: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Input1);    
        // printf("Operation Input 2: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Input2);    
    }
    else if(Ready_Queue[Process_ID-1].Scheduling_Type == "Priority")
    {
        struct PCB obj;
        obj.Process_State = "Active";
        obj.Process_ID = Process_ID;
        obj.Process_Input1 = Ready_Queue[Process_ID-1].Input1;
        obj.Process_Input2 = Ready_Queue[Process_ID-1].Input2;
        obj.Process_Priority = Ready_Queue[Process_ID-1].Priority_NUM;
        obj.Process_File = FileName;//Ready_Queue[Process_ID-1].Scheduling_Type + "".txt";

        int i=0;
        for(i=0; Ready_Queue[Process_ID-1].Operation_Name[i] != '\0'; i++)           
            obj.Process_Name[i] = Ready_Queue[Process_ID-1].Operation_Name[i];

        obj.Process_Name[i] = '\0';    

        // Inserting PCB Address in the Ready-Queue
        Ready_Queue[Process_ID-1].PCB = obj;

        // printf("\n\n\tProcess Control Block - PCB: %ld\n\n", Process_ID);
        // printf("Proccess ID: %d\n", Ready_Queue[Process_ID-1].PCB.Process_ID);
        // printf("Process State: %s\n", Ready_Queue[Process_ID-1].PCB.Process_State);
        // printf("Process File: %s\n", Ready_Queue[Process_ID-1].PCB.Process_File);
        // printf("Operation Name: %s\n", Ready_Queue[Process_ID-1].PCB.Process_Name);    
        // printf("Operation Priority NUM: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Priority);    
        // printf("Operation Input 1: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Input1);    
        // printf("Operation Input 2: %d\n", Ready_Queue[Process_ID-1].PCB.Process_Input2);    
    }   

    pthread_mutex_unlock(&Mutex_Lock);
    // Unlocking the Critical Section
}

void FileReading_FCFS(char* fileName)
{
    FILE* fp = fopen(fileName, "r");
 
    if (!fp)
        printf("Can't open file\n");
    else {
        // The size of array 1024
        char buffer[1024];
 
        while (fgets(buffer, 1024, fp)) 
        {
           int column = 0;

           int Process_ID;

            int Input1;
            int Input2;
            char* Operation_Name;

 
            // Splitting the data
            char* value = strtok(buffer, ",");
 
            while (value) 
            {
                // Column 1
                if (column == 0)
                {
                    // printf("Serial Num: ");
                    Process_ID = myAtoi(value);
                    // printf("%d", Process_ID);
                }

                // Column 2
                if (column == 1)
                {
                    // printf("\t\tOperation Name: ");
                    Operation_Name = value;
                    // printf("%s", Operation_Name);
                }

                // Column 3
                if (column == 2)
                {
                    // printf("\t\tInput Parameter 1: ");
                    Input1 = myAtoi(value);
                    // printf("%d", Input1);
                }

                // Column 4
                if (column == 3)
                {
                    // printf("\t\tInput Parameter 2: ");
                    Input2 = myAtoi(value);
                    // printf("%d", Input2);
                }

                //printf("\n");
                value = strtok(NULL, ",");
                column++;
            }
 
            char* Scheduling_Type = "FCFS";
            FCFS_Enqueue(Scheduling_Type, Process_ID, Operation_Name, Input1, Input2);
            //printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
}

void FileReading_SJF(char* fileName)
{
    FILE* fp = fopen(fileName, "r");
 
    if (!fp)
        printf("Can't open file\n");
    else {
        // The size of array 1024
        char buffer[1024];
 
        while (fgets(buffer, 1024, fp)) 
        {
           int column = 0;

           int Process_ID;

            char* Operation_Name;
            int CPU_Time;
            int Input1;
            int Input2;

 
            // Splitting the data
            char* value = strtok(buffer, ",");
 
            while (value) 
            {
                // Column 1
                if (column == 0)
                {
                    //printf("Serial Num: ");
                    Process_ID = myAtoi(value);
                    //printf("%d", Process_ID);
                }

                // Column 2
                if (column == 1)
                {
                    //printf("\t\tCPU Burst-Time: ");
                    CPU_Time = myAtoi(value);
                    //printf("%d", CPU_Time);
                }

                // Column 3
                if (column == 2)
                {
                    //printf("\t\tOperation Name: ");
                    Operation_Name = value;
                    //printf("%s", Operation_Name);
                }

                // Column 4
                if (column == 3)
                {
                    //printf("\t\tInput Parameter 1: ");
                    Input1 = myAtoi(value);
                    // printf("%d", Input1);
                }

                // Column 5
                if (column == 4)
                {
                    // printf("\t\tInput Parameter 2: ");
                    Input2 = myAtoi(value);
                    // printf("%d", Input2);
                }

                //printf("\n");
                value = strtok(NULL, ",");
                column++;
            }
 
            char* Scheduling_Type = "SJF";
            SJF_Enqueue(Scheduling_Type, Process_ID, Operation_Name, CPU_Time, Input1, Input2);
            //printf("\n");
        }

 
        // Close the file
        fclose(fp);
    }
}

void FileReading_Priotity(char* fileName)
{
    FILE* fp = fopen(fileName, "r");
 
    if (!fp)
        printf("Can't open file\n");
    else {
        // The size of array 1024
        char buffer[1024];
 
        while (fgets(buffer, 1024, fp)) 
        {
           int column = 0;

           int Process_ID;

            char* Operation_Name;
            int Priority_NUM;
            int Input1;
            int Input2;

 
            // Splitting the data
            char* value = strtok(buffer, ",");
 
            while (value) 
            {
                // Column 1
                if (column == 0)
                {
                    // printf("Serial Num: ");
                    Process_ID = myAtoi(value);
                    // printf("%d", Process_ID);
                }

                // Column 2
                if (column == 1)
                {
                    // printf("\t\tPriority Number: ");
                    Priority_NUM = myAtoi(value);
                    // printf("%d", Priority_NUM);
                }

                // Column 3
                if (column == 2)
                {
                    // printf("\t\tOperation Name: ");
                    Operation_Name = value;
                    // printf("%s", Operation_Name);
                }

                // Column 4
                if (column == 3)
                {
                    // printf("\t\tInput Parameter 1: ");
                    Input1 = myAtoi(value);
                    // printf("%d", Input1);
                }

                // Column 5
                if (column == 4)
                {
                    // printf("\t\tInput Parameter 2: ");
                    Input2 = myAtoi(value);
                    // printf("%d", Input2);
                }

                //printf("\n");
                value = strtok(NULL, ",");
                column++;
            }

            char* Scheduling_Type = "Priority";
            Priority_Enqueue(Scheduling_Type, Process_ID, Operation_Name, Priority_NUM, Input1, Input2);
            //printf("\n");
        }
 
        // Close the file
        fclose(fp);
    }
}

void *Initializing_ThreadFunction(void *threadID)
{
    //printf("\nInitializing Thread num: %ld\n\n", (long)threadID);

    // Creating and Initialize PCB
    // Storing PCB addresses in Ready-Queue
    Initialize_PCB((long) threadID);

    // Creating and Initialize PCB
    // Storing PCB addresses in Ready-Queue
    Initialize_List((long) threadID);

    pthread_exit(NULL);
}

void *Scheduler_Dispatcher_ThreadFunction(void *threadID)
{
    //printf("\nScheduler_Dispatcher Thread num: %ld\n\n", (long)threadID);

    // Scheduling the Processes
    Scheduler_Dispatcher((long)threadID);

    pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
    char* FileInput;
    char* Input_FileName;
    
    for(int i=1; i<argc; i++)
    {
        if(i == 1)
            FileInput = argv[i];

        if(i == 2)
            Input_FileName = argv[i];

        if(i == 3)
            Output_FileName = argv[i];
    }

    // int fileInput = 0;
    // printf("\nSelect your File Reading Option..\n");
    // printf("1. First-come First Serve (FCFS)\n");
    // printf("2. Shortest Job-First (SJF)\n");
    // printf("3. Priority Scheduling\n");
    // scanf("%d", &fileInput);

    //printf("Printing File Data..\n\n");

    if(!strcmp(FileInput, "FCFS"))
    {
        char* fileName = "FCFS.txt";
        FileReading_FCFS(fileName);
    }
    else if(!strcmp(FileInput, "SJF"))
    {
        char* fileName = "SJF.txt";
        FileReading_SJF(fileName);
    }
    else if(!strcmp(FileInput, "Priority"))
    {
        char* fileName = "Priority.txt";
        FileReading_Priotity(fileName);    
    }

    // Printing FIFO Ready Queue Elements
    //print_ReadyQueue_print();

    // Initializing the Mutex_Lock
    if (pthread_mutex_init(&Mutex_Lock, NULL) != 0)
        printf("\nMutex initialization has failed\n");

    int NUM_Threads = 15;
    //printf("\n\n'%d' Number of threads created to Analyze and Intitialize the Data gathered\n", NUM_Threads);

    // Creating for the Initial-Processing Threads
    pthread_t Initialize_Threads[NUM_Threads];

    //printf("\nThreads Processing/Initializing..\n\n");

    for(int i=0; i<NUM_Threads; i++)
    {
        pthread_create(&Initialize_Threads[i], NULL, Initializing_ThreadFunction, (void* )i+1);
        pthread_join(Initialize_Threads[i], NULL);
    }


    // Printing FIFO List Elements
    //printf("\n\nPrinting Linked List Elements\n\n");
    reverse(&head); //printList(); 


    //printf("\nInitializing Threads finished..\n\n");

    // Creating threads for the Scheduling and Dispatching the Operations
    pthread_t Scheduler_Dispatcher_Threads[NUM_Threads];
    //printf("\nCreating 'Scheduler_Dispatcher' Threads..\n\n");

    for(int i=0; i<NUM_Threads; i++)
    {
        pthread_create(&Scheduler_Dispatcher_Threads[i], NULL, Scheduler_Dispatcher_ThreadFunction, (void* )i+1);
        pthread_join(Scheduler_Dispatcher_Threads[i], NULL);
    }

    //printf("\n\nPrinting the Output List..\n\n");
    Pthread_Logger();

    //printf("\n'Scheduler_Dispatcher' Threads finished..\n");

    // Destroying the Mutex_Lock
    pthread_mutex_destroy(&Mutex_Lock);  

    //printf("\nExiting the MAIN Thread..\n\n");
    pthread_exit(NULL); 
}