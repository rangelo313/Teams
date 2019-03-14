/* Name: Robert Cimarelli	
Date: 12.06.17
Section: 6
Assignment: (Assignment#7)
Due Date: (12.06.17)
About this project: takes in a file with teams and their information and prints out their data and manipulates the data
Assumptions: assumes user enters a correct file with the number of teamnames taken in at the beginning.

All work below was performed by Robert Cimarelli */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
struct teamInfo 
{
	char teamname[40]; //0
	int wins; // 1
	int losses; // 2
	int playoffs; //3 
	int differential;//4

}; 
void OptionOne(teamInfo *ptr, int size); 
int main()
{
	
	char filename[40];
	ifstream in;	// a file input stream
	do {
		in.clear();
		cout << "Please enter the name of the input file." << endl; 
		cout << "Filename: " << endl;
		cin.getline(filename, 40); //gets filename
		in.open(filename); //open file 
		if (!in)
		{
			cout << "That is not a valid file.  Try again!" << endl; //if file is invalid
		}
	} while (!in);
	int size, howmany; 
	in >> size;  //size is dynamically taken in
	 teamInfo *ptr = new teamInfo[size]; //dynamic size in action

		 in.ignore();
		 for (int i = 0; i < size; i++) //loop to read in the file 
		 {
			 in.getline(ptr[i].teamname, 40, ',');
			 //cout << ptr[i].teamname << endl;  #comments here are for testing
			 in >> ptr[i].wins;
			 //cout << ptr[i].wins << endl;
			 in.ignore();
			 in >> ptr[i].losses;
			// cout << ptr[i].losses << endl;
			 in.ignore();
			 in >> ptr[i].playoffs;
			// cout << ptr[i].playoffs << endl;
			 in.ignore();
		 }
	 in.close();

	// ptr[4].differential = ptr[1].wins - ptr[2].losses;
	 int entry;
	 do {
		 cout << "\nSelect one of the following choices " << endl;

		 cout << "1 - View team Win/Loss records" << endl;
		 cout << "2 - Show teams with at least x wins" << endl;
		 cout << "3 - List teams that made the playoffs" << endl;
		 cout << "4 - Print teams and their Win Loss Differentials" << endl;
		 cout << "5 - Sort teams by their Win Loss Differentials" << endl;
		 cout << "0 - Exit program" << endl;
		 cout << "------------------------------------------" << endl;

		 cout << "Choice:";
		 cin >> entry; //user choice from the switch statement 
		 cout << "" << endl;
		 switch (entry)
		 {
		 case 0:
			 break;
		 case 1:
			 OptionOne(ptr, size); //calls function, passes in the structure as a pointer

			 break;
		 case 2:
			 cout << "Show teams with at least how many wins? --> ";
			 cin >> howmany; //user entry for how many wins
			 for (int i = 0; i < size; i++) //loops through to list teams by user entry
			 {
				 if (ptr[i].wins >= howmany) //meets condition 
					 cout << ptr[i].teamname << endl;
			 }
			 break;
		 case 3: // find a way to delete last comma
			 cout << "Playoff Teams: ";
			 {
				 int firstTeam = 0; //acts as a boolean
				
				 for (int i = 0; i < size; i++)
				 {
					 if (ptr[i].playoffs > 0) //condition for making the playoffs
					//{
						 if (firstTeam == 0) //handles the comma
						 {
							 cout << ptr[i].teamname;
							 firstTeam = 1;
						 }
						 else
							 cout << "," << " " << ptr[i].teamname; 
				 }
			 }
			 cout << "" << endl;
			 break;
		 case 4:
			 
			 for (int i = 0; i < size; i++)
			 {
				 ptr[i].differential = ptr[i].wins - ptr[i].losses; ///calculates differential
				 if (ptr[i].differential >= 0)
					 cout << ptr[i].teamname << " " << "+" << ptr[i].differential << endl; // handles positive values 
				 else
					 cout << ptr[i].teamname << " " << ptr[i].differential << endl; // negatives
			 }
			// cout << "" << endl;
 			 break;
		 case 5:
	//Bubble Sort
			 for (int x = 0; x < size; x++)
			 {
				 for (int y = 0; y < size - 1; y++)
				 {
					 if (ptr[y].differential < ptr[y + 1].differential)
					 {
						 teamInfo temp; //temporary variable 
						 temp = ptr[y + 1]; //stores so value isnt lost
						 ptr[y + 1] = ptr[y]; // swaps
						 ptr[y] = temp; // stores new place by order
					 }
				 } 
			 }
				 break;
		 default:
			 cout << "Invalid Choice " << endl; //accounts for other entry
			 }
		 } while (entry != 0); // to quit program and keep looping
		 if (entry == 0)
			 cout << "Goodbye" << endl; // prints message while quitting program
		 delete[] ptr;  //cleans up extra space
		 ptr = NULL; //precaution 

		 return 0;
	 }
void OptionOne(teamInfo *ptr,int size) //prints the team records, passes in entire structure teaminfo
{
	cout << "Team W-l: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i].teamname << " " << ptr[i].wins << "-" << ptr[i].losses << endl; //team records are printed 
	}
}