#include<iostream>
#include<string>
using namespace std;

class movie 
{
    string M_name;
    int Total_seats;
    int Available_seats;

public:
    
    void add_values(string name, int total, int available) 
	{
        M_name = name;
        Total_seats = total;
        Available_seats = available;
    }
    void add_values(string name, int total) 
	{   
        M_name = name;
        Total_seats = total;
        Available_seats = total;   
    }
    void add_values(string name) 
	{  
        M_name = name;
        Total_seats = 100;         
        Available_seats = 100;
    }

    void Display() 
	{
        cout << "\nMovie Name:: " << M_name << endl;
        cout << "Total number of seats : " << Total_seats << endl;
        cout << "Available seats : " << Available_seats << endl;
    }

    
    void Booking(int seatsbook) 
	{
        if (seatsbook <= Available_seats) 
		{
            Available_seats -= seatsbook;
            cout << "Successfully booked " << seatsbook << endl;
            cout << "Remaining seats are " << Available_seats << endl;
        } 
		else 
		{
            cout << "Not enough seats available!\n";
        }
    }
    void Booking() 
	{  
        int seatsbook;
        cout << "Enter the number of seats to book: ";
        cin >> seatsbook;
        Booking(seatsbook); 
    }

    void rate_our_site(float rate) 
	{  
        cout << "You rated this site: " << rate << " / 10" << endl;
    }
    void rate_our_site() 
	{   
        float userRate;
        cout << "Give your rating for this site (1.0 - 10.0): ";
        cin >> userRate;
        rate_our_site(userRate); 
    }

    void cancellation(int seats_cancel) 
	{
        if (Available_seats + seats_cancel <= Total_seats) 
		{
            Available_seats += seats_cancel;
            cout << "Successfully cancelled " << seats_cancel << endl;
            cout << "Available seats are " << Available_seats << endl;
        } 
		else 
		{
            cout << "Invalid cancellation request.\n";
        }
    }
    void cancellation() 
	{  
        int seats_cancel;
        cout << "Enter the number of seats cancelled: ";
        cin >> seats_cancel;
        cancellation(seats_cancel);
    }

    friend void checkAvailability(movie m, int require_seats);
};

void checkAvailability(movie m, int require_seats) 
{
    cout << "\n[Checking Seat Availability]";
    if (require_seats <= m.Available_seats) 
	{
        cout << "\nYes, " << require_seats << " seats are available for " << m.M_name << ".";
    } 
	else 
	{
        cout << "\nSorry, only " << m.Available_seats << " seats are available for " << m.M_name << ".";
    }
}

int main() 
{
    movie x;
    int choice;
    do 
	{
        cout << "\n<======== Mathew's Movie Booking Site =========>";
        cout << "\n1. Add Movie Details";
        cout << "\n2. Display the details";
        cout << "\n3. Book Tickets";
        cout << "\n4. Rate the Site";
        cout << "\n5. Cancel Tickets";
        cout << "\n6. Check Availability";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            x.add_values("Avengers", 180, 160);  
            break;
        case 2:
            x.Display();
            break;
        case 3:
            x.Booking(); 
            break;
        case 4:
            x.rate_our_site();  
            break;
        case 5:
            x.cancellation();  
            break;
        case 6:
            checkAvailability(x, 50);
            break;
        case 7:
            cout << "Thank you for using our site!";
            break;
        default:
            cout << "Invalid choice.\nTry again :)";
        }
    } while (choice != 7);
    return 0;
}
