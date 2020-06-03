#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define MAX_SIZE 20

struct People {
	char name[MAX_SIZE];
	int ezita;
	int wins;
};

void inputpeople(struct People** ptr, int* noOfRecords);
int Coinflip();
void Sort(int noOfRecords, struct People* ptr);
void Swap(struct People* a, struct People* b);
void Printwinner(int noOfRecords, struct People** ptr);
void SetEzita(struct People* ptr, int noOfRecords);

int main()
{
	struct People* ptr = NULL;
	int noOfRecords = 0;

	srand(time(NULL));
	inputpeople(&ptr, &noOfRecords);
	SetEzita(ptr, noOfRecords);
	Sort(noOfRecords, ptr);
	Printwinner(noOfRecords, &ptr);

	while (1)
	{
		printf("Do you want to play again?: ");
		char cont = 0;
		((getchar()) != '\n');
		scanf("%c", &cont);

		if (cont == 'Y')
		{
			SetEzita(ptr, noOfRecords);

			Sort(noOfRecords, ptr);
			Printwinner(noOfRecords, &ptr);
		}
		else
		{
			exit(1);
		}
	}

	return EXIT_SUCCESS;
}

void SetEzita(struct People* ptr, int noOfRecords)
{
	int i;
	for (i = 0; i < noOfRecords; ++i)
	{
		(ptr + i)->ezita = Coinflip();
	}
}

void inputpeople(struct People** ptr, int* noOfRecords)
{
	printf("Enter the number of people: ");
	scanf("%d", noOfRecords);

	*ptr = (struct People*)malloc((*noOfRecords) * sizeof(struct People));
	int i;
	for (i = 0; i < *noOfRecords; ++i)
	{
		printf("Enter the name: ");
		scanf("%s", (*ptr + i)->name);
		(*ptr + i)->wins = 0;
	}
}

void Sort(int noOfRecords, struct People* ptr)
{
	int j, t, count;
	count = 0;
	for (t = 0; t < noOfRecords; ++t)
	{
		for (j = 0; j < (noOfRecords - 1 - t); j++)
		{
			Swap((ptr + j), (ptr + j + 1));
		}
	}
	int n, v;
	for (n = 1; n < noOfRecords; ++n)
	{
		if (ptr->ezita == (ptr + n)->ezita)
		{
			count++;
		}
		else { break; }
	}
	if (count != 0)
	{
		for (v = 0; v < count; v++)
		{

			(ptr + v)->ezita += Coinflip();

		}
		Sort(noOfRecords, ptr);
	}
}

void Printwinner(int noOfRecords, struct People** ptr)
{
	(*ptr)->wins++;
	int r = 0;
	for (r = 0; r < noOfRecords; r++)
	{
		printf("Player:%s\t Ezita: %d\t Wins = %d\n", (*ptr + r)->name, (*ptr + r)->ezita, (*ptr + r)->wins);
	}
}

void Swap(struct People* a, struct People* b)
{
	struct People temp = { 0 };
	if (a->ezita < b->ezita)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

int Coinflip()
{
	int i;
	int ezi = 0;
	for (i = 0; i < 1; i++) {
		int moneta = (rand() % 2);
		if (moneta == 0) {
			return ezi;
			break;
		}

		else {
			ezi = ezi + 1;
		}
	}
}