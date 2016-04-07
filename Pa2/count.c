//
//Anthony Castronuovo
//Programming Assignment 2 - Hash Table with Linked List chaining
//

#include "count.h"

Node *hashtable;
Node *front;

int main(int argc, char const *argv[])
{
	FILE *file;

	hashtable = initializeTable(hashtable);

	char inFile[128];
	char *hexSixFour;
	char *token;
	
	long int converted;
	int numUniqueAddresses = 0;
	int count = 0;
	int l = 0;

	file = fopen(argv[1], "r");
	if(argc <= 1)
	{
		printf("error\n");
		return 0;
	}

	if(file != NULL)
	{
		while(!feof(file))
		{
			char getterDun = fgetc(file);
			if(getterDun == EOF)
			{
				continue;
			}
			ungetc(getterDun, file);

			fgets(inFile, 128, file);
			token = strtok(inFile, "\n");
			if(token == NULL)
			{
				continue;
			}
			hexSixFour = token;
			numUniqueAddresses = insertInTable(hexSixFour, numUniqueAddresses);

			
		}
	}

	printf("%d\n", numUniqueAddresses);
	freeHashtable(hashtable);

	return 0;
}

int hash(int convertedhexnumber)
{
	return (convertedhexnumber * 997) % 1000;
}

int insertInTable(char *hexNumber, int numUniqueAddresses)
{
	long int decimalForm = strtol(hexNumber, '\0', 16);
	int hashKey = hash(decimalForm);	

	Node *newNode = createNode(hashKey, decimalForm);

	if(hashtable[hashKey].front == NULL)
	{
		numUniqueAddresses++;
		hashtable[hashKey].front = newNode;
		return numUniqueAddresses;
	}
	else
	{
		if (checkDups(decimalForm, hashKey) == 1)
		{
			newNode->next = hashtable[hashKey].front;
			hashtable[hashKey].front = newNode;
			return numUniqueAddresses;
		}
		else
		{
			numUniqueAddresses++;
			newNode->next = hashtable[hashKey].front;
			hashtable[hashKey].front = newNode;
			return numUniqueAddresses;
		}
		
	}
}

Node *createNode(int hashKey, long int convertedhexnumber)
{
	Node *createThis = (Node*)malloc(sizeof(Node));
	createThis->hashKey = hashKey;
	createThis->convertedHex = convertedhexnumber;
	createThis->next = NULL;

	return createThis;
}

Node *initializeTable(Node *thetable)
{
	Node *hasher = thetable;
	hasher = (Node*)malloc(sizeof(Node) * 2000);
	int i;
	for(i = 0; i < 1000; i++)
	{
		hasher[i].front = NULL;
	}

}

int checkDups(long int convertedHexNum, int hashKey)
{
	int count = 0;
	Node *ptr = NULL;
	for (ptr = hashtable[hashKey].front; ptr!= NULL; ptr = ptr->next)
	{
		if(ptr->convertedHex == convertedHexNum)
		{
			return 1;
		}
	}

	return 0;
}


void freeHashtable(Node *hashtable)
{
	int i;
	for (i = 0; i < 1000; i++)
	{
		free(hashtable[i].front);
	}
}
