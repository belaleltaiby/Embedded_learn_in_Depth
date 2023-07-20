/*
 * main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Belal
 */

#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
#define Dprintf(...)  {fflush(stdout);\
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin); \
}

struct SStudent* gpFirstStudent=NULL;

struct SDATA{
	int id;
	char name[40];
	float height;
};

struct SStudent{
	struct SStudent* PNextStudent;
	struct SDATA StudentData;
};

void Fill_Student(struct SStudent* newStudent)
{
	char temp_text[40];
	Dprintf("Enter Your ID\n");
	gets(temp_text);
	newStudent->StudentData.id = atoi(temp_text);

	Dprintf("Enter Your Name\n");
	gets(temp_text);

	Dprintf("Enter Your Height\n");
	gets(temp_text);
	newStudent->StudentData.height = atof(temp_text);
}


void AddStudent()
{
	struct SStudent* pNewStudent=NULL;
	struct SStudent* pLastStudent=NULL;
	if(!gpFirstStudent)  //the list is empty
	{
		//create first node
		pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		gpFirstStudent = pNewStudent;

	}
	else   //the list is not empty ....already have students
	{
		pLastStudent = gpFirstStudent;
		//navigate till reach the last student
		while(pLastStudent->PNextStudent){
			pLastStudent = pLastStudent->PNextStudent ;
		}
		pNewStudent = (struct SStudent*) malloc(sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent ;
	}
	//fill_the_record(pNewStudent);
	//set the next record to null
	pNewStudent->PNextStudent = NULL ;
}

int  DeleteStudent()
{
	char temp[40];
	int  selected_id;
	printf("enter the id to be deleted\n");
	gets(temp);
	selected_id = atoi(temp);
	if(gpFirstStudent)  //if there are nodes
	{
		struct SStudent* pPrevStudent = NULL ;
		struct SStudent* pToBeDeleted_Student = gpFirstStudent ;
		while(pToBeDeleted_Student)
		{
			if(pToBeDeleted_Student->StudentData.id == selected_id)
			{
				if(pPrevStudent) //if the selected student is not the first one
				{
					pPrevStudent->PNextStudent = pToBeDeleted_Student->PNextStudent ;
				}
				else   //if the selected student is the first one
				{
					gpFirstStudent->PNextStudent = pToBeDeleted_Student->PNextStudent ;
				}
				free(pToBeDeleted_Student);
				return 1 ;
			}
			pPrevStudent = pToBeDeleted_Student ;
			pToBeDeleted_Student = pToBeDeleted_Student->PNextStudent ;

		}
	}
	Dprintf("the selected id is not found\n ");
	return 0; //can not find it
}

void ViewStudent()
{
	struct SStudent* pcurrentStudent= gpFirstStudent;
	int count=0;

	if(gpFirstStudent == NULL)
	{
		Dprintf("the list is empty\n");
	}
	while(pcurrentStudent)
	{
		Dprintf("The data of student number(%d):\n",count);
		Dprintf("The ID of student (%d)\n",pcurrentStudent->StudentData.id);
		Dprintf("The name of student : (%s)\n", pcurrentStudent->StudentData.name);
		Dprintf("The height of student is : (%f)\n", pcurrentStudent->StudentData.height);
		pcurrentStudent = pcurrentStudent->PNextStudent ;
		count++ ;
	}
}

void DeleteAll()
{
	struct SStudent* pcurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		Dprintf("the list is empty\n");
	}
	while(pcurrentStudent)
	{
		struct SStudent* pTempStudent = pcurrentStudent;
		pcurrentStudent = pcurrentStudent->PNextStudent ;
		free(pTempStudent);
	}
	pcurrentStudent = NULL ;

}

int main(){
	char tem_text[40];
	while(1)
	{
		Dprintf("\n\t choose one of the following options\n");
		Dprintf("1 : Add student\n");
		Dprintf("2 : delete Student\n");
		Dprintf("3 : view students\n");
		Dprintf("4 : Delete all students\n");
		Dprintf("Enter option number\n");

		gets(tem_text);
		switch(atoi(tem_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteAll();
			break;
		case 3:
			ViewStudent();
			break;
		case 4:
			DeleteAll();
			break;
		default:
			Dprintf("wrong option\n");
			break;
		}
	}
}
