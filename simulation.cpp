#include <iostream>
using namespace std;

int able(int x) {
	if (x >= 1 && x <= 30) {
		x = 2;
	}
	else if (x >= 31 && x <= 58) {
		x = 3;
	}
	else if (x >= 59 && x <= 83) {
		x = 4;
	}
	else if (x >= 84 && x <= 99) {
		x = 5;
	}
	return x;
}

int baker(int x) {
	if (x >= 1 && x <= 35) {
		x = 3;
	}
	else if (x >= 36 && x <= 60) {
		x = 4;
	}
	else if (x >= 61 && x <= 80) {
		x = 5;
	}
	else if (x >= 81 && x <= 99) {
		x = 6;
	}
	return x;
}

int main()
{
	int id[30];
	int Rn_Arrival[30];
	int time_arrival[30];
	int clock[30];
	int Rn_service[30];
	int able_begin[30];
	int able_timeService[30];
	int able_end[30];
	int baker_begin[30];
	int baker_service[30];
	int baker_end[30];
	int Qtime[30];


	for (int i = 0; i < 26; i++) {
		id[i] = i;
	}

	cout << "please enter 25 random degits for arrival \n ";
	Rn_Arrival[0] = 0;
	for (int i = 1; i < 26; i++) {
		cin >> Rn_Arrival[i];
	}


	// arrival {1-25, 26-65, 66-85, 86-99}
	// able { 1-30, 31-58 , 59-83 , 84-99}
	// baker {1-35, 36-60 , 61-80, 81-99}

	time_arrival[0] = 0;
	for (int i = 1; i < 26; i++) {
		if (Rn_Arrival[i] >= 1 && Rn_Arrival[i] <= 25) {
			time_arrival[i] = 1;
		}
		else if (Rn_Arrival[i] >= 26 && Rn_Arrival[i] <= 65) {
			time_arrival[i] = 2;
		}
		else if (Rn_Arrival[i] >= 66 && Rn_Arrival[i] <= 85) {
			time_arrival[i] = 3;
		}
		else if (Rn_Arrival[i] >= 86 && Rn_Arrival[i] <= 99) {
			time_arrival[i] = 4;
		}
	}

	clock[0] = 0;
	for (int i = 1; i < 26; i++) {
		clock[i] = clock[i - 1] + time_arrival[i];
	}


	cout << "please enter 26 random degits for service \n ";
	for (int i = 0; i < 26; i++) {
		cin >> Rn_service[i];
	}




	baker_begin[0] = 0;
	baker_service[0] = baker(Rn_service[0]);
	baker_end[0] = baker_service[0] + baker_begin[0];
	able_begin[0] = 0;
	able_timeService[0] = 0;
	able_end[0] = 0;
	Qtime[0] = 0;



	int flagA = able_end[0], flagB = baker_end[0];
	int waitingA, waitingB;


	for (int i = 1; i < 26; i++) {
		if (flagB <= clock[i]) {
			baker_begin[i] = clock[i];
			baker_service[i] = baker(Rn_service[i]);
			baker_end[i] = baker_service[i] + baker_begin[i];
			flagB = baker_end[i];
			able_begin[i] = 0;
			able_timeService[i] = 0;
			able_end[i] = 0;
			Qtime[i] = clock[i] - baker_begin[i];
		}

		else if (flagB > clock[i] && flagA <= clock[i]) {
			able_begin[i] = clock[i];
			able_timeService[i] = able(Rn_service[i]);
			able_end[i] = able_begin[i] + able_timeService[i];
			flagA = able_end[i];
			baker_begin[i] = 0;
			baker_service[i] = 0;
			baker_end[i] = 0;
			Qtime[i] = clock[i] - able_begin[i];
		}
		else if (clock[i] < flagB && clock[i] < flagA) {
			waitingA = flagA - clock[i];
			waitingB = flagB - clock[i];
			if (waitingA >= waitingB) {
				baker_begin[i] = clock[i] + waitingB;
				baker_service[i] = baker(Rn_service[i]);
				baker_end[i] = baker_service[i] + baker_begin[i];
				flagB = baker_end[i];
				able_begin[i] = 0;
				able_timeService[i] = 0;
				able_end[i] = 0;
				Qtime[i] = waitingB;

			}
			else {
				able_begin[i] = clock[i] + waitingA;
				able_timeService[i] = able(Rn_service[i]);
				able_end[i] = able_begin[i] + able_timeService[i];
				flagA = able_end[i];
				baker_begin[i] = 0;
				baker_service[i] = 0;
				baker_end[i] = 0;
				Qtime[i] = waitingA;
			}

		}

	}






	cout << "customer  RDA  arrival  clock  RDS  AStart  AService  AEnd  BStart  BService  BEnd  Queue \n";
	for (int i = 0; i < 26; i++)
	{
		cout << id[i] + 1 << "\t" << Rn_Arrival[i] << "\t" << time_arrival[i] <<
			"\t" << clock[i] << "\t" << Rn_service[i] <<
			"\t" << able_begin[i] << "\t" << able_timeService[i] << "\t" <<
			able_end[i] << "\t" << baker_begin[i] << "\t" << baker_service[i] <<
			"\t" << baker_end[i] << "\t" << Qtime[i] << endl;
	}

}