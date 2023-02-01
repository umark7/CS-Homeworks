#include <stdio.h>
#include "FileData.h"
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
