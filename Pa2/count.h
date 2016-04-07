#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node{
	long int convertedHex;
	int hashKey;
	struct Node *next;
	struct Node *front;
}Node;


//
//Inserts the hexNumber into the table
//Returns the number of unique addresses in the table
//
int insertInTable(char *hexNumber, int numUniqueAddresses);

//
//Hash function that assigns a key to the converted hex number
//
int hash(int convertedhexNumber);

//
//Creates the node where the incoming information will be stored
//Returns the newly created node
//
Node *createNode(int hashKey, long int convertedHex);

//
//Creates the table and initializes the fronts to NULL
//
Node *initializeTable(Node *thetable);

//
//Frees the memory used up by the hash table
//
void freeHashtable(Node *hashtable);

//
//Checks to see if the convertedHexNum is already in the hashtable
//Returns 1 if the number is in the table
//Returns 0 if the number is not in the table
//
int checkDups(long int convertedHexNum, int hashKey);