// Mahmoud Hamed

#include <iostream>
using namespace std;



int cummulative(int x) {
	if (x >= 1 && x <= 10) {
		x = 0;
	}
	else if (x >= 11 && x <= 35) {
		x = 1;
	}
	else if (x >= 36 && x <= 70) {
		x = 2;
	}
	else if (x >= 71 && x <= 91) {
		x = 3;
	}
	else if (x >= 92 && x <= 99) {
		x = 4;
	} 
	return x;
}

int main()
{
	
	int cycle[25], days[25], invB[25], rnD[25], demand[25], invE[25], Short[25], order[25], rnL[25], lead[25];
	int x = 0 ,sumorder = 0,sumEnd=0,day=25,u,M; // x for cummulative shortage , sum for identify order to invB ,u start , M capcity
	double avgEnd=0.0; // average 

	//cycle 
	for (int i = 0; i < 25; i++)
	{
		if (i < 5) {
			cycle[i] = 1;
		}
		else if (i >= 5 && i < 10) {
			cycle[i] = 2;
		}
		else if (i >= 10 && i < 15) {
			cycle[i] = 3;
		}
		else if (i >= 15 && i < 20) {
			cycle[i] = 4;
		}
		else if (i >= 20 && i < 25) {
			cycle[i] = 5;
		}
	}

	//days
	for (int i = 0; i < 25; i++) {
		days[i] = i + 1;
	}


	cout << "enter the Standard Inventory Level \n ";
	cin >> M;
	
	//random number
	cout << "plaese enter 25 random number \n";
	for (int i = 0; i < 25; i++) {
		cin >> rnD[i];
	}

	//	demand
	for (int i = 0; i < 25; i++) {
		demand[i] = cummulative(rnD[i]);
	}


	//random lead
	cout << "plaese enter 5 random number \n";
	for (int i = 0; i < 25; i++) {
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24)
		{
			cin >> rnL[i];
		}
		else
			rnL[i] = 0;

	}

	cout << "enter the Starting Quantity \n ";
	cin >> u;

	//lead
	for (int i = 0; i < 25; i++) {
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24)
		{
			if (rnL[i] >= 1 && rnL[i] <= 6) {
				lead[i] = 1;
			}
			else if (rnL[i] >= 7 && rnL[i] <= 9) {
				lead[i] = 2;
			}
			else if (rnL[i] == 0) {
				lead[i] = 3;
			}
		}
		else
			lead[i] = 0;
	}

	// to make countdown of lead
	for (int i = 0; i < 24; i++) {
		if (lead[i] != 0) {
			lead[i + 1] = lead[i] - 1;
		}
	}


	// first two days
	invB[0] = u;
	invE[0] = invB[0] - demand[0];
	lead[0] = 1;
	Short[0] = 0;
	order[0] = 8;

	invB[1] = invE[0] - x;
	invE[1] = invB[1] - demand[1];
	lead[1] = 0;
	Short[1] = 0;
	order[1] = 0;
	
	sumEnd = invE[0] + invE[1];

	for (int i = 2; i < 25; i++) {

		//inventory begin
		if (invE[i-1] >= demand[i]|| lead[i - 2] == 1) {
			if (lead[i - 2] == 1) {
				invB[i] = sumorder+invE[i-1]-x;
				x = 0;
				if (i == 2) {
					invB[i] = invE[i - 1] + 8; // 8 bec the Question said that at the 2nd day will come 8
				}
			}
			else if (lead[i - 2] != 1)
			{

				invB[i] = invE[i - 1] -x;
				x = 0;
			}
		}
		else if (invE[i-1] < demand[i]) {
			invB[i] = 0;
		}

		// end and short
		if (invB[i] >= demand[i]) {
			invE[i] = invB[i] - demand[i];
			Short[i] = 0;
		}
		else if (invB[i] < demand[i]) {
			invE[i] = 0;
			Short[i] = x+ demand[i];
			x = Short[i];
		}

		// order
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 24) {
			sumorder = 0;
			order[i] = M - invE[i];
			sumorder = order[i];
		}
		else {
			order[i] = 0;
		}

		sumEnd = sumEnd + invE[i];
	}

	avgEnd = (double)sumEnd / day;


	cout << endl;
	cout << "Cycle \t Days \t Inv.B \t RN D \t Demand\t Inv.E \t Short \t Order \t RN.L\tLead \n";
	cout << "----------------------------------------------------------------------------- \n";
	for (int i = 0; i < 25; i++) {
		cout << cycle[i] << " \t" << days[i] << "\t " << invB[i]
			<< "\t " << rnD[i] << " \t" << demand[i] << "\t " << invE[i]
			<< "\t " << Short[i] << "\t " << order[i] << " \t" << rnL[i] << " \t" << lead[i] << endl;
		cout << "----------------------------------------------------------------------------- \n";
	}
	cout << "Average End of Inventory = " <<avgEnd<< endl;



	/*
	random numbers 
	24
	35
	65
	81
	54
	03
	87
	27
	73
	70
	47
	45
	48
	17
	09
	42
	87
	26
	36
	40
	07
	63
	19
	88
	94


	random lead numbers 
	5
	0
	3
	4
	8

	*/

}

