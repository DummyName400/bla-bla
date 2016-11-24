#include <iostream>
#include "utility.h"
using namespace std;

void selectAndKill(enemy* &active1, enemy* &active2,enemy* &dead);
bool InsertTower(Tower* &towerH, double TH, int TKC , double FP);
bool InsertEnemy(enemy*& enemyH,int ID, Etype TYP,
				 int T, double H, double FP, int RP, REGION R);
void moveFromTo(enemy* &list1,enemy * &list2);

void Enqueue(Queue &queue, enemy* &data);

bool IsEmpty(Queue &queue);

void Kill(enemy* killed, enemy* &DeadH);

enemy* SearchEnemy(enemy* &ActiveHead, int index);

void Activate(Queue &inactiveH, enemy* &activeH, int timestep,int& counter);

void printEnemyByRegion(enemy* active1, enemy* active2, enemy* dead);

void printRegion(enemy * list, REGION region);
