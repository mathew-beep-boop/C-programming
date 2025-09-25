#include<iostream>
#include<string>
using namespace std;
class Payment
{
	public:
		void payment_amount(int price)
		{
			cout<<"The amount for the movie is "<<price<<endl;
			cout<<"the Paymet has been sucessful"<<endl;
		}
		
};

class feedback
{
	public:
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
	
	
};

class movie:public Payment,public feedback
{
    string M_name;
    int Total_seats;
    int Available_seats;
    friend void checkAvailability(movie m, int require_seats);


public:
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
            
            int amount = seatsbook * 200; 
        	payment_amount(amount);
        } 
		else 
		{
            cout << "Invalid booking request. Please check seat availability." << endl;
        }
    }
    void cancellation() 
	{
        int seats_cancel;
        cout << "Enter the number of seats to cancel for " << M_name << ": ";
        cin >> seats_cancel;
        if (seats_cancel > 0 && Available_seats + seats_cancel <= Total_seats) {
            Available_seats += seats_cancel;
            cout << "Successfully cancelled " << seats_cancel << " seats." << endl;
            cout << "Available seats: " << Available_seats << endl;
        } else {
            cout << "Invalid something went wrong.\n Check again" << endl;
        }
    }
    
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
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                x.add_values("Avengers", 180, 160);
                checkAvailability(x, 100);
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
            	int seatsbook;
                x.payment_amount(seatsbook*160);
                break;

            default:
                cout << "Invalid choice. Try again :)" << endl;
        }

    } 
	while (choice != 7);

    return 0;
}
