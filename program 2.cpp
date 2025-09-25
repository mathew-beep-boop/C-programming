#include<iostream>
#include<string>
using namespace std;
class movie
{
	string M_name;
	int Total_seats;
	int Available_seats;
	public:
		void add_values(string name="Default Movie",int total=0,int available=0)
		{
			M_name=name;
			Total_seats=total;
			Available_seats=available;
		}
		void Display()
		{
			cout<<"\nMovie Name:: "<<M_name<<endl;
			cout<<"Total number of seats :"<<Total_seats<<endl;
			cout<<"Available_seats :"<<Available_seats<<endl;
		}
		void Booking()
		{
			int seatsbook;
			cout<<"Enter the amount of seats booked for"<<M_name<<endl;
			cin>>seatsbook;
			if(seatsbook<=Available_seats)
			{
				Available_seats=Available_seats-seatsbook;
				cout<<"sucessfully booked "<<seatsbook<<endl;
				cout<<"Remaining seats are "<<Available_seats<<endl;
			}
			else
			{
				cout<<"Somthing went wrong"<<endl;
			}
		}
		void rate_our_site(float rate=5.0)
		{
			cout<<"Give your rating for this site (1.0 - 10.0) [Default is 5.0]: ";
			float userRate;
			string feedback;
			cin >> userRate;
			if (userRate>5.0 && userRate<=10)
			{
				cout<<"Thank you for your rating.\nHave a great day "<<endl;
			}
			
			else
			{
				cout<<"somthing went wrong in your output"<<endl;
			}
		}
		void cancellation()
		{
			int seats_cancel;
			cout<<"Enter the number of seats canncelled "<<M_name;
			cin>>seats_cancel;
			if(Available_seats + seats_cancel<=Total_seats)
			{
				Available_seats=Available_seats+seats_cancel;
				cout<<"Cancellation gone sucessfully "<<seats_cancel<<endl;
				cout<<"Available seats are "<<Available_seats<<endl;
			}
			else
			{
				cout<<"Something went wrong check again please "<<endl;
			}
		}
		friend void checkAvailability(movie m, int require_seats);
		
};
void checkAvailability(movie m, int require_seats) 
{
	cout << "\n[Checking Seat Availability]";
	if (require_seats <= m.Available_seats) {
		cout << "\nYes, " << require_seats << " seats are available for " << m.M_name << ".";
	} else {
		cout << "\nSorry, only " << m.Available_seats << " seats are available for " << m.M_name << ".";
	}
}
int main()
{
	movie x;
	int choice;
	do
	{
		cout<<"\n<========Mathews Movie Booking Site=========>";
		cout<<"\nM_Theater. Proceed for the process ";
		cout<<"\n2. Display the details ";
		cout<<"\n3. To book ";
		cout<<"\n4. wish to rate the site ";
		cout<<"\n5. do you want to cancel the seats ";
		cout<<"\n6 Check for the available seats";
		cout<<"\n7 Exit ";
		cout<<"\nEnter your choice ";
		cin>>choice;
		switch (choice)
		{
		
		case 1:
			x.add_values("Avengers",180,160);
			checkAvailability(x, 100);
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
			x.checkAvailability();
			break;

		case 7:
			cout<<"Thank you for using our site";
			break;
		default:
			cout<<"Invalid choice.\nTry again:)";
		}
		
	}
	while(choice!=7);
	return 0;
}
