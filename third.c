/*
	Anthony Castronuovo
	Programming Assignment 1 - Linked list
*/

#include "third.h"

Node *front;

int main(int argc, char const *argv[])
{
	FILE *file;
	front = NULL;
	//Take in file name
	char whichFile[10];
	//Read file
	char fileIn[128];
	char *token;
	int converted;
	//printf("file name:\n");
	fgets(whichFile, 10, stdin);
	if(strcmp(whichFile, " ") == 0 || strcmp(whichFile, "  ") == 0)
	{
		printf("error\n");
	}

	file = fopen(whichFile, "r");
	
	if(file != NULL)
	{
		while(!feof(file))
		{
			fgets(fileIn, 128, file);
			//printf("%s\n", fileIn);
			char *token = strtok(fileIn, "\t");
			//printf("%s\n", token);
			if(*token == 'i')
			{
				token = strtok(NULL, "\n");
				//printf("%s\n", token);
				converted = atoi(token);
				//printf("%d\n", converted);
				insertInorder(converted);
				//front->data = converted;
				//front->next = NULL;
			}
			if(*token == 'd')
			{
				token = strtok(NULL, "\n");
				//printf("%s\n", token);
				converted = atoi(token);
				//printf("%d\n", converted);
				delete(converted);
				//printlist();
				//front->data = converted;
				//front->next = NULL;
			}
		}
		fclose(file);
		printlist();

	}
	else
	{
		printf("error\n");
	}

	return 0;
}

void printlist()
{
	Node *temp = front;
	//printf("list:\n");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void delete(int tobeDeleted)
{
	Node *temp;
	for(temp = front; temp->next != NULL; temp=temp->next)
	{
		if(temp->next->data == tobeDeleted)
		{
			temp->next = temp->next->next;
		}
	}
}

void insertInorder(int newdata)
{	
	if(front == NULL)
	{
		front = (Node*)malloc(sizeof(Node));
		front->data = newdata;
		front->next = NULL; 
	}
	else
	{
		Node *temp;
		temp = (Node*)malloc(sizeof(Node));
		temp->data = newdata;
		temp->next = NULL;
		if(temp->data < front->data)
		{
			temp->next = front;
		}	

		Node *ptr = NULL;
		ptr = front;

		while(ptr->next != NULL && ptr->data < temp->data)
		{
			ptr = ptr->next;
		}
		temp->next = ptr->next;
		ptr->next = temp;
	}
}
