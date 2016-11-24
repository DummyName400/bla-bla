
#include "EnemyAndTower.h"

bool InsertTower(Tower* &towerH, double TH, int TKC , double FP)
{

	Tower* tower = new Tower;
	tower->Health = TH;
	tower->TowerKillingCapacity = TKC;
	tower->TowerFirePower = FP;
	tower->UnpavedArea = 30;
	tower->next = NULL;

	if (towerH == NULL) {
		towerH = tower;
		return true;
	}
	else {

		Tower* iterator = towerH;

		while (iterator->next != NULL) {
			iterator = iterator->next;
		}

		iterator->next = tower;
		return true;
	}

	return false;
}
/*
pick the first (2 or less) elements from  list1 and list2 
		call moveFromTo() to move selected enemies from list1/2 to list3
		should be in the Tower.cpp 
*/
void selectAndKill(enemy* &active1, enemy* &active2,enemy* &dead){
	for(int i=0;i<2&&active1!=NULL;i++)
		moveFromTo(active1,dead);
	for(int i=0;i<2&&active2!=NULL;i++)
		moveFromTo(active2,dead);
}
		