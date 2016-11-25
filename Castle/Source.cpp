#include "file_IO.h"

int main()
{
	cout<<"War Started"<<endl;
	int RegSize = 0, SHsize = 0, NumKilled = 0;
	Tower* TowerHead = NULL; 
	Queue in_regFigthersHead ; 
	in_regFigthersHead.bounds.front = in_regFigthersHead.bounds.rear = NULL;
	Queue in_SHFighterHead ;
	in_SHFighterHead.bounds.front = in_SHFighterHead.bounds.rear = NULL;
	enemy* ac_regFigthersHead = NULL;
	enemy* ac_SHFighterHead = NULL;
	enemy* DeadHead = NULL;
	enemy* K1=NULL;
	enemy* K2=NULL;
	enemy* K3=NULL;
	enemy* K4=NULL;
	double Constants[3];
	LoadFile(Constants,TowerHead, in_regFigthersHead, in_SHFighterHead);
	int timestep = 1;
	
	do 
	{
		cout<<"        __________________________"<<"Time Step "
			<<timestep<<"________________________________"<<endl;
		Activate(in_regFigthersHead, ac_regFigthersHead, timestep, RegSize);
		Activate(in_SHFighterHead, ac_SHFighterHead, timestep, SHsize);
		if(RegSize!=0){
			K1 = SearchEnemy(ac_regFigthersHead, rand() % RegSize + 1);
			K2 = SearchEnemy(ac_regFigthersHead, rand() % RegSize + 1);
		}
		if(SHsize!=0){
			K3 = SearchEnemy(ac_SHFighterHead, rand() % SHsize + 1);
			K4 = SearchEnemy(ac_SHFighterHead, rand() % SHsize + 1);
		}
		if (K1 != NULL) {
			Kill(K1, DeadHead);
			NumKilled++;
			RegSize--;
			K1=NULL;
		}
		if (K2 != NULL) {
			Kill(K2, DeadHead);
			NumKilled++;
			RegSize--;
			K2=NULL;
		}
		if (K3 != NULL) {
			Kill(K3, DeadHead);
			NumKilled++;
			SHsize--;
			K3=NULL;
		}
		if (K4 != NULL) {
			Kill(K4, DeadHead);
			NumKilled++;
			SHsize--;
			K4=NULL;
		}
		cout<<"Total Number of Active enemies : "<<SHsize+RegSize<<endl;
		cout<<"Total Number of Killed enemies : "<<NumKilled<<endl;
		printEnemyByRegion(ac_regFigthersHead, ac_SHFighterHead, DeadHead);
		
		timestep++;
		Sleep(1000);
	}while(!(ac_regFigthersHead==NULL&&ac_SHFighterHead==NULL
		&&in_regFigthersHead.bounds.front==NULL&&in_SHFighterHead.bounds.front==NULL));
	cout<<"\n ALL enemies died , Program terminated . \n"<<"War ended !";
	cin.get();
}
