#include <stdio.h>
#include <stdlib.h>


typedef struct coisa
{
	int idade;
	struct coisa* next;

	
}COISA;

void ColocarFIFO(COISA** lel, int idade)
{
	COISA* tmp;
	if(*lel == NULL)
	{
		tmp = (COISA*)malloc(sizeof(COISA));
		if(tmp == NULL) return;
		tmp->idade = idade;
		tmp->next = NULL;
		*lel = tmp;
	}
	else
	{
		ColocarFIFO(&(**lel).next, idade);
	}

}

void ColocarLIFO(COISA** lel,int idade)
{
	COISA* tmp;
	

	if(*lel == NULL)/*First Time running*/
	{
		tmp = (COISA *)malloc(sizeof(COISA));
		if(tmp == NULL) return;
		tmp->idade = idade;
		tmp->next = NULL;
		*lel = tmp;

	}
	else
	{
		tmp = (COISA *)malloc(sizeof(COISA));
		if(tmp == NULL) return;
		tmp->idade = idade;
		tmp->next = *lel;
		*lel = tmp;
	}
		



}
void Mostrar(COISA** lel)/*Shows the list*/
{
	if(*lel == NULL)
	{
		printf("ACABOU\n");
		return;
	}
	printf("IDADE: %d\n", (*lel)->idade);
	Mostrar(&(**lel).next);
}

void MostrarR(COISA** lel)/*Shows the list and removes*/
{
	if(*lel == NULL)
		return;
	printf("IDADE: %d\n", (*lel)->idade);
	*lel = (**lel).next;
	Mostrar(lel);
}
int main(void)
{
	COISA* fila = NULL;
	ColocarLIFO(&fila, 5);
	ColocarLIFO(&fila, 6);
	ColocarLIFO(&fila, 7);
	ColocarLIFO(&fila, 8);
	MostrarR(&fila);



	return 0;
}

