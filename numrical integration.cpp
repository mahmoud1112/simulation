
#include <iostream>
#include <cmath>
using namespace std; 


int main()
{
	int sum = 0 ,range , height;
	int RnX[20], RnY[20], M[20], N[20];
	double Xcoor[20], Ycoor[20],xpower[20];
	double x , area; 


	//step
	for (int i = 0; i < 20; i++) {
		N[i] = i + 1;
	}

	//random number x
	cout << "plaese enter 20 random number for X between 20 to 50 \n";
	for (int i = 0; i < 20; i++) {
		cin >> RnX[i];
	}


	//random number y
	cout << "plaese enter 20 random number for Y between 0 to 100 \n";
	for (int i = 0; i < 20; i++) {
		cin >> RnY[i];
	}

	// range and hight 
	cout << "plaese enter the range of x \n";
	cin >> range;
	cout << "plaese enter the height of y \n";
	cin >> height;

	// x coordinate 
	for (int i = 0; i < 20; i++)
	{
		Xcoor[i] = (double)RnX[i] / 10;
	}

	// y coordinate
	for (int i = 0; i < 20; i++)
	{
		Ycoor[i] = ((double)RnY[i] / 100)*height;
	}

	cout << "plaese enter the power of x  \n";
	cin >> x; 
	// xpower 3 
	for (int i = 0; i < 20; i++) {
		xpower[i] = pow(Xcoor[i],x);
	}


	// M counter 
	for (int i = 0; i < 20; i++) {
		if (Ycoor[i] <= xpower[i]) {
			M[i] = 1;
			sum += 1;
		}
		else {
			M[i] = 0;
		}
	}
	
	cout << "Step\tRnx\txcoor \tRnY\tYcoor\tX^3\tM\n";
	cout << "----------------------------------------------------------------------------- \n";
	for (int i = 0; i < 20; i++) {
		cout << N[i] << "\t" << RnX[i] <<"\t"<< Xcoor[i]
			<< "\t" << RnY[i] << "\t" << Ycoor[i] <<"\t" << xpower[i]
			<< "\t" << M[i] << endl;
		cout << "----------------------------------------------------------------------------- \n";
	}

	area = (double)(sum / 20.0) * range * height;
	cout << "The value of integral is (M/N)*A = " << area << endl;


	/*
		random x
		22
		25
		45
		25
		27
		48
		43
		40
		47
		38
		33
		24
		47
		42
		25
		33
		50
		34
		21
		18

		random y
		57
		18
		90
		5
		77
		66
		10
		76
		42
		78
		88
		3
		9
		77
		61
		27
		60
		29
		40
		0
		*/ 

	
}
