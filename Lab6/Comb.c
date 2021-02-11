#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

int B_MPPs(List *list)
{
	if (Bomb_Move(list)) return 1;
	Player(list);
	if (Print(list)) return 1;
	sleep(1);
	return 0;
}

int BPPsB_MPPs(List* list)
{
	Bomb(list);
	Player(list);
	if (Print(list)) return 1;
	sleep(1);
	
	if (B_MPPs(list)) return 1;
	return 0;
}

int B_R_B(List *list)
{
	for (int i = 0; i < 12; i++)
	{
		if (BPPsB_MPPs(list)) return 1;
		Right(list);
		B_MPPs(list);
	}
	return 0;
}

int B_L_B(List *list)
{
	for (int i = 0; i < 24; i++)
	{
		if (BPPsB_MPPs(list)) return 1;
		Left(list);
		B_MPPs(list);
	}
	return 0;
}

int B_D_B(List *list)
{
	for (int i = 0; i < 3; i++)
	{
		if (BPPsB_MPPs(list)) return 1;
		Down(list);
		B_MPPs(list);
	}
	return 0;
}

int Comb(List* list)
{
	for (int i = 0; i < 3; i++)
	{
		if (B_R_B(list)) return 1;
		if (B_L_B(list)) return 1;
		if (B_R_B(list)) return 1;
		if (B_D_B(list)) return 1;
	}

	while (1)
	{
		if (B_R_B(list)) return 1;
		if (B_L_B(list)) return 1;
		if (B_R_B(list)) return 1;
	}
}
