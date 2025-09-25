#include<iostream>
#include<string>
using namespace std;

class movie {
    string M_name;
    int Total_seats;
    int Available_seats;
    friend void checkAvailability(movie m, int require_seats);

public:
        movie() 
		{
        M_name = "Unknown";
        Total_seats = 0;
        Available_seats = 0;
        cout << "Default constructor called.\n";
    	}

    
	    movie(string name, int total, int available) 
		{
        M_name = name;
        Total_seats = total;
        Available_seats = available;
        cout << "Parameterized constructor called.\n";
    	}

    
	    movie(const movie &m) 
		{
        M_name = m.M_name;
        Total_seats = m.Total_seats;
        Available_seats = m.Available_seats;
        cout << "Copy constructor called.\n";
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
            cout << "Invalid cancellation request. Check again." << endl;
        }
    }
};


void checkAvailability(movie m, int require_seats) 
{
    cout << "\nChecking Seat Availability";
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
    movie x;
	int choice;

    do 
	{
        cout << "\n<======== Mathews Movie Booking Site =========>";
        cout << "\n1. Add movie details";
        cout << "\n2. Display the details";
        cout << "\n3. Book seats";
        cout << "\n4. Rate the site";
        cout << "\n5. Cancel seats";
        cout << "\n6. Check seat availability";
        cout << "\n7. Use copy constructor";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                x = movie("Avengers", 180, 160); 
                cout << "Movie details added successfully.\n";
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
			{
                int req;
                cout << "Enter number of seats to check availability: ";
                cin >> req;
                checkAvailability(x, req);
                break;
            }

            case 7: 
			{
                movie y = x;
                cout << "Copied movie details:\n";
                y.Display();
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