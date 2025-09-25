#include <iostream>
#include <string>
using namespace std;

class movie 
{
    string M_name;
    int Total_seats;
    int Available_seats;

   

public:
    
    movie(string name = "Default Movie", int total = 0, int available = 0) 
	{
        M_name = name;
        Total_seats = total;
        Available_seats = available;
    }

    void add_values(string name = "Default Movie", int total = 0, int available = 0) 
	{
        M_name = name;
        Total_seats = total;
        Available_seats = available;
    }

    void Display() 
	{
        cout << "\nMovie Name: " << M_name << endl;
        cout << "Total number of seats: " << Total_seats << endl;
        cout << "Available seats: " << Available_seats << endl;
    }

    void Booking() 
	{
        int seatsbook;
        cout << "Enter the number of seats to book for " << M_name << ": ";
        cin >> seatsbook;
        if (seatsbook > 0 && seatsbook <= Available_seats) 
		{
            Available_seats -= seatsbook;
            cout << "Successfully booked " << seatsbook << " seats." << endl;
            cout << "Remaining seats: " << Available_seats << endl;
        } 
		else 
		{
            cout << "Invalid booking request. Please check seat availability." << endl;
        }
    }

    void rate_our_site(float rate = 5.0) 
	{
        float userRate;
        cout << "Give your rating for this site (1.0 - 10.0) [Default is 5.0]: ";
        cin >> userRate;
        if (userRate >= 1.0 && userRate <= 10.0) 
		{
            cout << "Thank you for your rating.\nHave a great day!" << endl;
        } 
		else 
		{
            cout << "Invalid rating. Please enter a value between 1.0 and 10.0." << endl;
        }
    }

    void cancellation() 
	{
        int seats_cancel;
        cout << "Enter the number of seats to cancel for " << M_name << ": ";
        cin >> seats_cancel;
        if (seats_cancel > 0 && Available_seats + seats_cancel <= Total_seats) 
		{
            Available_seats += seats_cancel;
            cout << "Successfully cancelled " << seats_cancel << " seats." << endl;
            cout << "Available seats: " << Available_seats << endl;
        } 
		else 
		{
            cout << "Invalid something went wrong.\n Check again" << endl;
        }
    }

    
    
    movie operator+(movie &m) 
	{
        movie temp;
        temp.M_name = this->M_name + " & " + m.M_name;
        temp.Total_seats = this->Total_seats + m.Total_seats;
        temp.Available_seats = this->Available_seats + m.Available_seats;
        return temp;
    }


   
   
    int operator-(movie &m) 
	{
        return this->Available_seats - m.Available_seats;
    }

   
    friend void checkAvailability(movie m, int require_seats);
};


void checkAvailability(movie m, int require_seats) 
{
    cout << "\n[Checking Seat Availability]";
    if (require_seats <= m.Available_seats) 
	{
        cout << "\nYes, " << require_seats << " seats are available for " << m.M_name << "." << endl;
    } 
	else 
	{
        cout << "\nSorry, only " << m.Available_seats << " seats are available for " << m.M_name << "." << endl;
    }
}

int main() 
{
    movie x("Avengers", 180, 160);
    movie y("Iron Man", 120, 100);
    movie combined;
    int choice;

    do 
	{
        cout << "\n<======== Mathews Movie Booking Site =========>";
        cout << "\n1. Display the details";
        cout << "\n2. Book seats";
        cout << "\n3. Rate the site";
        cout << "\n4. Cancel seats";
        cout << "\n5. Check seat availability";
        cout << "\n6. Combine two movies (+ operator)";
        cout << "\n7. Compare seats (- operator)";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                x.Display();
                y.Display();
                break;

            case 2:
                x.Booking();
                break;

            case 3:
                x.rate_our_site();
                break;

            case 4:
                x.cancellation();
                break;

            case 5: 
			{
                int req;
                cout << "Enter number of seats to check availability: ";
                cin >> req;
                checkAvailability(x, req);
                break;
            }

            case 6:
                combined = x + y; 
                cout << "\n[After Combining Movies]";
                combined.Display();
                break;

            case 7: 
			{
                int diff = x - y;
                cout << "\nDifference in available seats (Avengers - Iron Man): " << diff << endl;
                break;
            }

            case 8:
                cout << "Thank you for using our site!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again :)" << endl;
        }

    } while (choice != 8);

    return 0;
}
