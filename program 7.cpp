#include <iostream>
#include <string>
using namespace std;

class Movie 
{
    string M_name;
    int Total_seats;
    int Available_seats;

public:
   
    Movie(string name = "Default Movie", int total = 100, int available = 100) 
	{
        M_name = name;
        Total_seats = total;
        Available_seats = available;
    }

    
    void Display() 
	{
        cout << "\nMovie Name:: " << M_name << endl;
        cout << "Total number of seats : " << Total_seats << endl;
        cout << "Available seats : " << Available_seats << endl;
    }

   
    Movie operator++() 
	{
        if (Available_seats < Total_seats)
		 {
            ++Available_seats;
        } 
		else 
		{
            cout << "All seats are already available. Cannot increase further!\n";
        }
        return *this;
    }
};

int main() {
    Movie m1("Avengers", 10, 5); 
    

    cout << "Initial Details:";
    m1.Display();

    cout << "\nApplying ++ (one seat becomes available):";
    ++m1;
    m1.Display();


    return 0;
}
