
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include <string.h>

using namespace std;

#define MOV1 "Jab tak hai Jaan"
#define MOV2 "Rocket Man"
#define MOV3 "Scent of a Woman"
#define MOV4 "Little Women"
#define MOV5 "The Shawshank Redemption"

#define TIME1 "09:30 AM"
#define TIME2 "01:00 PM"
#define TIME3 "02:50 PM"
#define TIME4 "06:00 PM"
#define TIME5 "09:00 PM"
#define TIME6 "01:00 AM"

#define MAXSEAT 5

class person{
    public:
	string name;
	string phn;
};

class ticket:public person {
	public:
	string movie;
	string time;
	int seat;
	float amount;
};

class cardreg:public person{
    public:
	string address;
	string emailid;
};

ticket* available[MAXSEAT+1];
int i=0;
int cust_id=0;

void displayMovie(){
        system("CLS");
		cout<<"\n\n\t\t\t\tThe Shows are :";
        cout<<"\n\n\t\t\t\t 1. "<<MOV1;
        cout<<"\n\n\t\t\t\t 2. "<<MOV2;
        cout<<"\n\n\t\t\t\t 3. "<<MOV3;
        cout<<"\n\n\t\t\t\t 4. "<<MOV4;
        cout<<"\n\n\t\t\t\t 5. "<<MOV5;
        return;
}

void displayTime(){
        system("CLS");
		cout<<"\n\n\t\t\t\t The Timings for the selected show are:";
        cout<<"\n\n\t\t\t\t 1. "<<TIME1;
        cout<<"\n\n\t\t\t\t 2. "<<TIME2;
        cout<<"\n\n\t\t\t\t 3. "<<TIME3;
        cout<<"\n\n\t\t\t\t 4. "<<TIME4;
        cout<<"\n\n\t\t\t\t 5. "<<TIME5;
        cout<<"\n\n\t\t\t\t 6. "<<TIME6;
        return;
}

float pay(int x,int y){   //normal is 120 //gold is 190
    if(x==1)
    return(120*y+(120*y)*0.18);
    else
    return(190*y+(190*y)*0.18);
}

int createTicket(int c1,int c2){
    ticket* temp=new ticket;
    system("CLS");
    cout<<"\n\t\t\t\t Enter your name: ";
    cin>>temp->name;
    cout<<"\n\t\t\t\t Enter your contact number: ";
    cin>>temp->phn;
    cout<<"\n\t\t\t\t Enter the number of tickets you want to purchase: ";
    cin>>temp->seat;

    switch(c1){
            case 1:	temp->movie=MOV1;break;
			case 2:	temp->movie=MOV2;break;
			case 3:	temp->movie=MOV3;break;
			case 4:	temp->movie=MOV4;break;
			case 5:	temp->movie=MOV5;break;
			}

    switch(c2){
            case 1:	temp->time=TIME1;break;
			case 2:	temp->time=TIME2;break;
			case 3:	temp->time=TIME3;break;
			case 4:	temp->time=TIME4;break;
			case 5:	temp->time=TIME5;break;
			case 6:	temp->time=TIME6;break;
            }
    i=i+temp->seat;
    if(i<=MAXSEAT){
        int c3;
        cout<<"\n\n\t\t\t\tThank you for selecting the show.\n\t\t\t\tNow we request you to select your type of seating"<<endl;
        cout<<"\n\n\t\t\t\t\t 1.Normal Class \n\t\t\t\t\t OR \n\t\t\t\t\t 2. Gold Class "<<endl;
        cout<<"\n\n\t\t\t\tChoose:";
        cin>>c3;
        temp->amount=pay(c3,temp->seat);
        cout<<"\n\n\t\t\t\t Amount to be paid with 18% GST is Rs. "<<temp->amount<<endl;
        available[i]=temp;
        system("PAUSE");
        return(i);
        }
    else{
        cout<<"\n\n\t\t\t\tSorry there's only "<<(MAXSEAT-cust_id)<<" tickets left\n";
        i=i-temp->seat;
        return (0);
    }
}

void card()
{
    cardreg v;
	int cardid;
	cout<<"\t\t\t\tWelcome to register for card facility in our cinemas";
	cout<<" \n\n\t\t\t\tEnter your name: ";
	cin>>v.name;
	cout<<"\t\t\t\tEnter your mobile number: ";
	cin>>v.phn;
	cout<<"\t\t\t\tEnter the address: ";
	cin>>v.address;
	cout<<"\t\t\t\tEnter the mail id: ";
	cin>>v.emailid;
	system("CLS");
	int ID;
	srand (time(NULL));
	ID = rand() % 400000 + 4000000;
	if (ID<0)
	ID=(ID*-1);
	cout<<"\n\n\t\t\t\tYour new card number is :" <<"\t"<<ID;
	fstream fout;
	fout.open("card.dat", ios::out|ios::app);
	fout<<"\n Name :"<<v.name<<"\n"<<"\n Mobile No. :"<<v.phn<<"\n"<<"\n Address :"<<v.address<<"\n"<<"\n Mail ID :"<<v.emailid<<"\n"<<"\nCard Number:"<<ID;
	fout.close();
	cout<<"\n\t\t\t\tThank you for the registration for the card. \n";
}
void paymentMode(int id){
    	time_t t = time(NULL);							//time setup
        tm* timePtr = localtime(&t);
        system("CLS");
        cout<<"\n\n\t\t\t\t Do you have Registered movie card(y/n): ";
        char final;
		cin>>final;
		if(final=='y')
		{
		    while(1){
		    cout<<"\n\t\t\t\tEnter the card number[10 digits]: ";
		    string num;
		    cin>>num;
		    if(num.size()==10){
		    cout<<"\n\t\t\t\tYou get 10% discount";
		    available[id]->amount-=(available[id]->amount*0.1);
		    cout<<"\n\t\t\t\tAmount to be paid is Rs. "<<(available[id]->amount);
		    break;
		    }
		    else
                cout<<"\n\t\t\t\tEnter Valid 10 digit number";
		    }
		}
        cout<<"\n\t\t\t\tWant to pay by Card(y/n): ";
		char rep;
		cin>>rep;

		if (rep=='y'||rep=='Y')
		{
			cout<<"\n\t\t\t\tEnter the card number: ";
			string Card;
			cin>>Card;
			cout<<"\t\t\t\tExpiry(MM  YYYY)";
			int expirymm,expiryyy;
			cin>>expirymm;
			cin>>expiryyy;
			bool valid=true;
			while(valid){
				if(expiryyy<(timePtr->tm_year + 1900)){
					    cout<<"\t\t\t\tPlease enter a valid year: ";
                        cin>>expiryyy;
					}
                else if(expiryyy==(timePtr->tm_year + 1900)){
                    if(expirymm<timePtr->tm_mon){
                            cout<<"\t\t\t\tPlease enter valid month: ";
                            cin>>expirymm;
					    }
                else
                    valid=false;
                }
                else
                    valid=false;
			}

			string cvv;
			do{
			cout<<"\n\n\t\t\t\tEnter CVV: ";
			cin>>cvv;
			if(cvv.size()!=3)
                cout<<"\t\t\t\tInvalid CVV";

                }while(cvv.size()!=3);
		}
		else
            cout<<"\n\t\t\t\tPaying by cash.\n";

		cout<<"\n\t\t\t\t"<<"Paying Rs. "<<available[id]->amount<<endl;
		system("PAUSE");
		return;
		}

void displayTicket(int id){
    cout<<"\n\t\t\t\tHere is you ticket Sir/Madam "<<available[id]->name;
    cout<<"\n\n\n\n\t\t\t\t------------------------------------------";
    cout<<"\n\t\t\t\t|Movie : "<<available[id]->movie;
    cout<<"\n\t\t\t\t|Timings : "<<available[id]->time;
    cout<<"\n\t\t\t\t|Seats : "<<available[id]->seat;
    cout<<"\n\t\t\t\t------------------------------------------";
    cout<<"\n\n\n\t\t\t\tInvoice is sent to your phone number "<<available[id]->phn<<endl;;
    system("PAUSE");
}

int main(){
    system("CLS");
	int ent, choice1, choice2, N_seat, x, cardid;
	char ans;
{time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	cout << "SYSTEM TIME:";
  	cout << timePtr->tm_hour <<":" ;
    cout <<  timePtr->tm_min <<":" ;
    cout <<  timePtr->tm_sec <<endl;
	cout << "DD:MM:YY = " << timePtr->tm_mday <<":"<<timePtr->tm_mon<<":"<<timePtr->tm_year + 1900<< endl;
	cout << "SYSTEM STATUS : GOOD " << endl;
	system("pause");
	}

do{
		//Menu
		system("CLS");
		cout<<"\n\n\t\t\t ------------------------------------------------";
		cout<<"\n\n\t\t\t             CPP COURSE PROJECT ";
		cout<<"\n\n\t\t\t          Movie Ticket Booking System";
		cout<<"\n\n\t\t\t ------------------------------------------------";
		cout<<"\n\t\t\t\t Welcome Dear Customer!";	 																					//Menu for the user
		cout<<"\n\n\t\t\t\t <1> Movie Timings";
		cout<<"\n\t\t\t\t <2> Receiving Ticket";
		cout<<"\n\t\t\t\t <3> For Information";
		cout<<"\n\t\t\t\t <4> Movie Card Registration";
		cout<<"\n\t\t\t\t <5> Exit \n\n";
		cout<<"\t\t\t\t Enter Your Choice :"<<"\t";
		cin>>ent;
	switch(ent)
	{
			//Movie Titles
		case 1:
		    displayMovie();
            cout<<"\n\t\t\t\tEnter Your Choice :"<<"\t";
			cin>>choice1;

            displayTime();
            cout<<"\n\n\t\t\t\t Please select the timings: ";
            cin>>choice2;

            cust_id=createTicket(choice1,choice2);
            if(cust_id==0){
                cout<<"\n\t\t\t\tTry again";
                ans='y';
                system("PAUSE");
                break;
            }

            paymentMode(cust_id);
            system("CLS");
            displayTicket(cust_id);
            ans='y';

                break;
		case 2:	system("CLS");
				cout<<"\n\t\t\t\tThank you for booking the tickets online \n\t\t\t\tTo print out the tickets please enter your transaction ID in the portal";					//Finding about a prebooked ticket
				struct pre
				{
				int trsnid;
				char name[10];
				} p;
				cout<<"\n Enter your transaction id\n (Eg.last five digits of the transaction id) ";
				cin>>p.trsnid;
				cout <<"Enter your name";
				cin>>p.name;
				cout<<"Sorry to say, but you will need to get the print out of the booking because our database shows no booking by this name";
				cout<<"\n Do you want to choose another option(y/n)";
				cin>>ans;
				system("CLS");
				break;
		case 3: system("CLS");
				cout<<"For further information about movies or queries please email us at ece.proj.by.nie.stud@gmail.com or DIAL 1800-MOVIES";			//Finding out more about our cinemas
				cout<<"\n Do you want to choose another option(y/n)";
				cin>>ans;
				system("CLS");
				break;
		case 4: system("CLS");
				cout<<"\n\t\t\t\tGood Morning/Evening \n\n\t\t\t\tYou are about to start a new journey with our cinemas \n";																												//card membership
				card();
				cout<<"\n\n\t\t\t\tIt will take us a week for completing your registration for the card. \n\t\t\t\tPlease see the benefits of the card on the next page. -->";
				char f;
				cout<<"\n\t\t\t\tFor selecting the page to go to benefits say (y/n) :";
				cin>>f;
				if(f=='y')
				{
					cout<<"\n\n\t\t\t\tThank you for registration once again \n The privileges provided with this card are as follows:";
					cout<<"\n\n\t\t\t\t 1. For every purchase of a movie ticket you get 25 points(1point = 1Rs.) so after 16 movies you get a free movie ticket.";
                    cout<<"\n\t\t\t\t 2. You are provided with regular updates regarding the movie and the show timings.";
					cout<<"\n\t\t\t\t 3. Anytime pre book tickets for the upcoming movie and preffered seats will be provided.";
				}
				cout<<"\n\n\t\t\t\tDo you want to choose another option(y/n)";
				cin>>ans;
				break;
		case 5:
                ans='n';
				break;
	}
	}while(ans=='y');
	system("CLS");
		cout<<"\n\t\t\t\t developed by NIE-EC (B) as a fullfillment for course project\n\n\t\t\t\t";
		cout<<"\n\t\t\t\t     4NI14EC066\n\t\t\t\t";
		cout<<"\n\t\t\t\t     4NI16EC043\n\t\t\t\t";
		cout<<"\n\t\t\t\t     4NI17EC075\n\t\t\t\t";
		cout<<"\n\t\t\t\t     4NI17EC082\n\t\t\t\t";
return 0;
}
