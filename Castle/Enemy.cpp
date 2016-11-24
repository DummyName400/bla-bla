#include "EnemyAndTower.h"

bool InsertEnemy(enemy*& enemyH,int ID, Etype TYP, 
				 int T, double H, double FP, int RP, REGION R)
{

	enemy* Enemy = new enemy;
	Enemy->ID = ID;
	Enemy->Type = TYP;
	Enemy->ArrivalTime = T;
	Enemy->Health = H;
	Enemy->FirePower = FP;
	Enemy->ReloadPeriod = RP;
	Enemy->Region = R;
	Enemy->next = NULL;

	if (enemyH == NULL) {
		enemyH = Enemy;
		return true;
	}
	else {
		enemy* iterator = enemyH;

		while (iterator->next != NULL) {
			iterator = iterator->next;
		}

		iterator->next = Enemy;
		return true;
	}
	return false;
}


//moves the first element from the first list to the end of the other
void moveFromTo(enemy* &list1,enemy * &list2){
	enemy* temp =list1;
	list1=temp->next;
	if(list2==NULL){
		list2=temp;
		temp->next=NULL;
		return;
	}
	enemy * iterator=list2;
	while(iterator->next!=NULL){ iterator=iterator->next;}
	iterator->next=temp;
	temp->next=NULL;
}
/*
For each region, print
			1. Total number of active enemies and information of each one of them.
			2. Total number of killed enemies and information of each one of them.
			The killed enemies have to be printed ordered by enemy health.
*/
void printEnemyByRegion(enemy* active1,enemy* active2 ,enemy* dead){
	cout<<"\nListing Regular Fighters\n";
	for(int i=65;i<65+4;i++){
		char region= 'A'-i+65;
		cout<<"\nRegion "<<(char)('A'+i-65)<<"\n";
		printRegion(active1,i);
	}
	cout<<"\nListing shielded Fighters\n";
	for(int i=65;i<65+4;i++){
		cout<<"\nRegion "<<(char)('A'+i-65)<<"\n";
		printRegion(active1,i);
	}
	cout<<"\nListing dead Fighters\n";
	for(int i=65;i<65+4;i++){
		cout<<"\nRegion "<<(char)('A'+i-65)<<"\n";
		printRegion(dead,i);
	}

}

void printRegion(enemy * list,int region)
{
	while(list!=NULL){
		if(list->Region==region){
			cout << list->ID << " ";
			cout << list->Type << " ";
			cout << list->ArrivalTime << " ";
			cout << list->Health << " ";
			cout << list->FirePower << " ";
			cout << list->ReloadPeriod<< " ";
			cout << list->Region << " ";
			cout<<endl;
		}
		list=list->next;
	}
}


void Kill(enemy* killed, enemy* &DeadH)
{
	if (DeadH == NULL) {
		DeadH = killed;
		return;
	}
	else {
		enemy* prev = NULL; enemy* current = DeadH;
		int count = 0;
		while (current != NULL) {
			if (current->Health < killed->Health) {
				prev = current; 
				current = current->next;
				count++;
			}
			else {
				if (count == 0) {
					killed->next = DeadH;
					DeadH = killed;
					return;
				}
				else {
					prev->next = killed;
					killed->next = current;
					return;
				}
			}
		}
		prev->next = killed;
		killed->next =NULL;
		return;
	}
}

enemy* SearchEnemy(enemy* &ActiveHead, int index)
{
	int i = 1; 
	if (ActiveHead == NULL)
		return NULL;
	if(index==1){
		enemy* temp=ActiveHead;
		ActiveHead=ActiveHead->next;
		return temp;
	}
	i++;
	enemy* iterator = ActiveHead->next;
	enemy* prev= ActiveHead;
	while (iterator != NULL) {
		if (i == index){
			prev=iterator->next;
			return iterator;
		}
		prev=iterator;
		iterator = iterator->next;
		i++;
		}
	return NULL;
}

void PrintEnemy(enemy*head) {
	cout << "Enemy list is : " << endl;
	while (head != NULL) {
		cout << head->ID << " ";
		cout << head->Type << " ";
		cout << head->ArrivalTime << " ";
		cout << head->Health << " ";
		cout << head->FirePower << " ";
		cout << head->ReloadPeriod << " ";
		cout << head->Region << " ";
		cout << endl;
		head = head->next;
	}
	cout << endl;
}

void MoveFromTo(enemy* &origin, enemy* &destination)
{
	origin->next = NULL;          //detaching the node form its original list 
    //inserting the node at the end of the desetination list
	if (destination == NULL) {
		destination = origin;
		return ;
	}
	else {
		enemy* iterator = destination;
		while (iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = origin;
	}
}

void Activate(Queue &inactiveH, enemy* &activeH, int timestep,int&counter)
{
	enemy* current = inactiveH.bounds.front;
	enemy* prev = inactiveH.bounds.front; int count = 0;
	while (current != NULL) {//infinite Loop termination
		if(current->ArrivalTime > timestep)
			break;
		if (current->ArrivalTime != timestep) {
			prev = current;
			current = current->next;
			count++;
		}
		else {
			prev->next = current->next;
			if (count == 0){
				inactiveH.bounds.front = current->next;
				if (current == inactiveH.bounds.rear) {
					inactiveH.bounds.rear = NULL;
				}
			}
			MoveFromTo(current, activeH);
			current=prev->next;
			counter++;
		}	
	}
}

