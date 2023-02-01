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