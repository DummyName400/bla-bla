#include "file_IO.h"

void LoadFile(double* Con,Tower*&THead ,Queue &regHead,Queue &SFH)
{
	int Index, T, ArrivalTime, ReloadPeriod, TowerHit;
	double Health, FirePower, TowerHealth, TowerFireP; char R;
	Etype Type; REGION Region;

	ifstream input("simulation input.txt", ios::in);
	if (!input.is_open()) {
		cout << "Error : input file is not found " << endl;
		return;
	}

	input >> TowerHealth >> TowerHit >> TowerFireP;
	for (int i = 0; i < 4; i++) {
		if (!InsertTower(THead, TowerHealth, TowerHit, TowerFireP)) {
			cout << "Error while inserting a tower node, check insert tower function " << endl;
			return;
		}
	}

	for (int i = 0; i < 3; i++) {
		input >> Con[i];
	}

	input >> Index; 
	while (Index != -1) {

		input>>T >> ArrivalTime >> Health >> FirePower >> ReloadPeriod >> R;
		Type = static_cast<Etype>(T);
		Region = static_cast<REGION>(R);

		enemy* Data = new enemy;
		Data->ID=Index;
		Data->ArrivalTime = ArrivalTime;
		Data->Health = Health;
		Data->FirePower = FirePower;
		Data->ReloadPeriod = ReloadPeriod;
		Data->Type = Type;
		Data->Region = Region;

		//put all shield fighters in one list
		if (Type == SHLD_FITR) 
			Enqueue(SFH, Data);
			
		//put all other regular fighters in a single list
		else
			Enqueue(regHead, Data);
		
		input >> Index;
	}
	input.close();
}