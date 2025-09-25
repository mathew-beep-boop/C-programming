#include <iostream>
#include <string>
using namespace std;


class Theater 
{
protected:
    string theaterName;
    string location;

public:
    void setTheater(string name, string loc) 
	{
        theaterName = name;
        location = loc;
    }

    void showTheater()    
	{
        cout << "\n===== Theater Details =====";
        cout << "\nTheater Name : " << theaterName;
        cout << "\nLocation     : " << location << endl;
    }
};


class Movie : public Theater 
{
protected:
    string movieName;
    int totalSeats;
    int availableSeats;

public:
    void setMovie(string name, int total, int available) 
	{
        movieName = name;
        totalSeats = total;
        availableSeats = available;
    }

    void showMovie() 
	{
        cout << "\n===== Movie Details =====";
        cout << "\nMovie Name       : " << movieName;
        cout << "\nTotal Seats      : " << totalSeats;
        cout << "\nAvailable Seats  : " << availableSeats << endl;
    }
};


class Booking : public Movie 
{
public:
    void bookSeats(int n) 
	{
        if (n <= availableSeats) 
		{
            availableSeats -= n;
            cout << "\nSuccessfully booked " << n << " seats for " << movieName << ".";
            cout << "\nRemaining Seats: " << availableSeats << endl;
        } 
		else 
		{
            cout << "\nBooking Failed! Only " << availableSeats << " seats left.\n";
        }
    }

    void cancelSeats(int n) 
	{
        if (availableSeats + n <= totalSeats) 
		{
            availableSeats += n;
            cout << "\nSuccessfully cancelled " << n << " seats.";
            cout << "\nAvailable Seats: " << availableSeats << endl;
        } 
		else 
		{
            cout << "\nCancellation failed! Check again.\n";
        }
    }

    void rateSite(float rate = 5.0) 
	{
        cout << "\nYou rated our site: " << rate << " stars. Thank you!\n";
    }
};


int main() 
{
    Booking b;
    int choice;

    
    b.setTheater("Mathew's Multiplex", "Kochi");
    b.setMovie("Avengers", 180, 150);

    do 
	{
        cout << "\n<===== Movie Booking System =====>";
        cout << "\n1. Show Theater Details";
        cout << "\n2. Show Movie Details";
        cout << "\n3. Book Seats";
        cout << "\n4. Cancel Seats";
        cout << "\n5. Rate Site";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
        case 1:
            b.showTheater();
            break;
        case 2:
            b.showMovie();
            break;
        case 3: 
		{
            int seats;
            cout << "\nEnter number of seats to book: ";
            cin >> seats;
            b.bookSeats(seats);
            break;
        }
        case 4:
		{
            int seats;
            cout << "\nEnter number of seats to cancel: ";
            cin >> seats;
            b.cancelSeats(seats);
            break;
        }
        case 5: 
		{
            float rate;
            cout << "\nEnter your rating (1.0 - 10.0): ";
            cin >> rate;
            b.rateSite(rate);
            break;
        }
        case 6:
            cout << "\nThank you for using our booking system.\n";
            break;
        default:
            cout << "\nInvalid choice. Try again!\n";
        }
    } while (choice != 6);

    return 0;
}
