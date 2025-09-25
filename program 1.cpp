#include<iostream>
#include<string>
using namespace std;
class movie
{
	string M_name;
	int Total_seats;
	int Available_seats;
	public:
		void add_values()
		{
			cout<<"\nEnter the movie to watch ";
			cin.ignore();
			getline(cin,M_name);
			cout<<"Enter the total number of seats for the film ";
			cin>>Total_seats;
			cout<<"Enter the number of available seats ";
			cin>>Available_seats;
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
		void rate_our_site()
		{
			float rate;
			cout<<"Give your rating for this site::";
			cin>>rate;
			if(rate>=1.0 && rate<=10)
			{
				cout<<"Thank you for your feedback.\nHave a great day "<<endl;
			}
			else
			{
				cout<<" SOMETHING WENT WRONG.\nPLEASE CHECK YOUR INPUT"<<endl;
			}
		}
		void cancelletion()
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
};
int main()
{
	movie x;
	int choice;
	do
	{
		cout<<"\n<========Mathews Movie Booking Site=========>";
		cout<<"\n1. what movie to watch ";
		cout<<"\n2. Display the details ";
		cout<<"\n3. To book ";
		cout<<"\n4. wish to rate the site ";
		cout<<"\n5. do you want to cancel the seats ";
		cout<<"\n6 Exit ";
		cout<<"\nEnter your choice ";
		cin>>choice;
		switch (choice)
		{
		
		case 1:
			x.add_values();
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
			x.cancelletion();
			break;
		case 6:
			cout<<"Thank you for using our site";
			break;
		}
	}
	while(choice!=6);
	return 0;
}
