
#include <iostream>
using namespace std;

int main()
{
    int step[20], random_n[20], x[20], y[20];
    char direction[20]{};
    
    // steps 
    for (int i = 0; i < 20; i++) {
        step[i] = i + 1;
    }


    //random numbers 
    cout << " please enter 20 random numbers \n";

    for (int i = 0; i < 20; i++) {
        cin >> random_n[i] ;
    }

    // direction 
    for (int i = 0; i < 20; i++) {
        if (random_n[i] == 0 || random_n[i] == 1 || random_n[i] == 2 || random_n[i] == 3 || random_n[i] == 4) 
        {
            direction[i] = 'F'; 
        }
        else if (random_n[i] == 5 || random_n[i] == 6 || random_n[i] == 7)
        {
            direction[i] = 'L';
        }
        else if (random_n[i] == 8 || random_n[i] == 9)
        {

            direction[i] = 'R';
        }
    }


    // intialize first step 
    if (direction[0] == 'L') {
        x[0] = - 1;
        y[0] =0;
    }
    else if (direction[0] == 'R') {
        x[0] = 1;
        y[0] = 0;
    }
    else if (direction[0] == 'F') {
        x[0] = 0;
        y[0] = 1;
    }




    for (int i = 1; i < 20; i++) {
        if (direction[i] == 'L') {
            x[i]=x[i-1]-1;
            y[i] = y[i - 1];
        }
        else if (direction[i] == 'R') {
            x[i]=x[i-1]+1;
            y[i] = y[i - 1];
        }
        else if (direction[i] == 'F') {
            y[i]=y[i-1]+1;
            x[i] = x[i - 1];
            
        }
    }
    cout << " step   Random N   Direction   X coordinate   Y coordinate \n";
    for (int i = 0; i < 20; i++) {
        cout << step[i] << " \t " << random_n[i] << "\t\t" << direction[i] << "\t\t"
            << x[i] << "\t\t " << y[i] << endl; 
    }
}
