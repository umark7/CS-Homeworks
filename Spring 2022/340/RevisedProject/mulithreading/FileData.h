#include "PCB.h"

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
