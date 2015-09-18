#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

void insert(int newdata);
void printlist();
void delete(int tobeDeleted);
void insertInorder(int newdata);