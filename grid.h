

#include <iostream>
#include <fstream>

const int GridRows=2;  
const int GridCols=2;

const int SuperGridRows=2; 
const int SuperGridCols=2;

using namespace std;

class grid{

	int PowerGrid[GridRows][GridCols];

	friend ostream& operator <<(ostream&, const grid&);
    friend istream& operator >>(istream&, grid&);

public:
	grid(){
		for(int i=0; i<GridRows;i++)
			for(int j=0; j<GridCols;j++)
				PowerGrid[i][j] = 0;
	}
	int PowerOk(void);

	void WhereOff();

	void SwitchOFF(int row, int col);
	void SwitchON(int row, int col);

	void SwitchAllOFF();
	void SwitchAllON();



};


class supergrid
{
	grid SuperGrid[SuperGridRows][SuperGridCols];

	friend ostream& operator <<(ostream&, const supergrid&);
    friend istream& operator >>(istream&, supergrid&);

public:
	supergrid(){
		for(int i=0; i<SuperGridRows;i++)
			for(int j=0; j<SuperGridCols;j++)
				SuperGrid[i][j];
	}
	int PowerOk(void);

	void WhereOff();

	void SwitchPointOFF(int row, int col, int Point_row, int Point_col);
	void SwitchPointON(int row, int col, int Point_row, int Point_col);

	void SwitchAllOFF(int row, int col);
	void SwitchAllON(int row, int col);

	void SuperGridOFF();
	void SuperGridON();
};

void supergrid::SuperGridOFF(){

	for (int i=0; i<SuperGridRows ; i++)
	{
		for(int j=0; j<SuperGridCols ; j++){
			
			SuperGrid[i][j].SwitchAllOFF();
		}
	}
	cout<<"\n------ Super grid is turned OFF ------ "<<endl;
}

void supergrid::SuperGridON(){

	for (int i=0; i<SuperGridRows ; i++)
	{
		for(int j=0; j<SuperGridCols ; j++){
			
			SuperGrid[i][j].SwitchAllON();
		}
	}
	cout<<"\n------ Super grid is turned ON ------ "<<endl;
}




//------SuperGrid Functions---------------------------
ostream& operator <<(ostream&os, const supergrid& gr ){
	for (int i=0; i<SuperGridRows ; i++)
	{
		cout<<"\n|";
		for(int j=0; j<SuperGridCols ; j++){
			os<<" "<<gr.SuperGrid[i][j];
		}
		cout<<"|"<<endl;
	}
	return os;
}

istream& operator >>(istream &is, supergrid& gr){
	for (int i=0; i<SuperGridRows ; i++)
	{
	    for(int j=0; j<SuperGridCols ; j++){
			is>>gr.SuperGrid[i][j];
		}
		cout<<"\n----Next Supergrid Row-------"<<endl;
	}
	return is;
}

int supergrid::PowerOk(){
	int ok =1;

	for (int i=0; i<SuperGridRows ; i++)
		for(int j=0; j<SuperGridCols ; j++)
		   ok =	SuperGrid[i][j].PowerOk();
			
	return (ok);
}

void supergrid::WhereOff(){

	cout<<"\nPower is off in Supergrid cells: \n";

	for (int i=0; i<SuperGridRows ; i++)
	{
		for(int j=0; j<SuperGridCols ; j++){
			cout<<"\n------Search in Super grid row"<<i<< " colum"<<j<<"--------"<<endl;
			SuperGrid[i][j].WhereOff();
		}
	}
	cout<<"Scan of Supergird complete"<<endl;
}

void supergrid::SwitchAllON(int row, int col){
	for(int i=0; i<SuperGridRows ; i++)
	{
		for(int j=0; j<SuperGridCols ; j++)
			if(i==row && j == col)
		     {   
				 cout<<"\nGoing to Supergrid row "<<i<<" colum "<<j<<endl;//"  "<<PowerGrid[i][j]<<endl;
				 SuperGrid[i][j].SwitchAllON();

		     return;
		     }
	}
}

void supergrid::SwitchAllOFF(int row, int col){
	for(int i=0; i<SuperGridRows ; i++)
	{
		 for(int j=0; j<SuperGridCols ; j++)
			if(i==row && j == col)
		     {   cout<<"\nGoing to Supergrid row "<<i<<" colum "<<j<<endl;//"  "<<PowerGrid[i][j]<<endl;
				 SuperGrid[i][j].SwitchAllOFF();
		
		     return;
		     }
	}
}

void supergrid::SwitchPointOFF(int row, int col, int Point_row, int Point_col){
	for(int i=0; i<SuperGridRows ; i++)
	{
		 for(int j=0; j<SuperGridCols ; j++)
			if(i==row && j == col)
		     {   cout<<"\nGoing to Supergrid row "<<i<<" colum "<<j<<endl;
				 SuperGrid[i][j].SwitchOFF(Point_row,Point_col);
		     return;
		     }
	}
}

void supergrid::SwitchPointON(int row, int col, int Point_row, int Point_col){
	for(int i=0; i<SuperGridRows ; i++)
	{
		 for(int j=0; j<SuperGridCols ; j++)
			if(i==row && j == col)
		     {   cout<<"\nGoing to Supergrid row "<<i<<" colum "<<j<<endl;
				 SuperGrid[i][j].SwitchON(Point_row,Point_col);
				
		         return;
		     }
	}
}
//---------End of superGrid functions-----------------------
//---------Start of gird functions--------------------------
int grid::PowerOk(){
	int ok =1;

	for (int i=0; i<GridRows && ok; i++)
		for(int j=0; j<GridCols && ok; j++)
			ok =0;
	return (ok);
}

void grid::WhereOff(){
	for (int i=0; i<GridRows ; i++)
		for(int j=0; j<GridCols ; j++)
		{
			if (PowerGrid[i][j] != 1)
				cout<<"\nPower OFF in row"<<i<< " colum"<<j<<" "<<" is "<<PowerGrid[i][j]<<endl;
        }
}

void grid::SwitchAllON(){
		for(int i=0; i<GridRows;i++)
		{
			for(int j=0; j<GridCols;j++)
				PowerGrid[i][j] = 1;
		}
		cout<<"\nAll points in the grid have been set to '1' "<<endl; 
}

void grid::SwitchAllOFF(){
		for(int i=0; i<GridRows;i++)
		{
			for(int j=0; j<GridCols;j++)
				PowerGrid[i][j] = 0;  
		}
		cout<<"\nAll points in the grid have been set to '0' "<<endl; 
}

void grid::SwitchOFF(int row, int col){
	for(int i=0; i<GridRows ; i++)
	{
		 for(int j=0; j<GridCols ; j++)
			if(i==row && j == col)
		    { PowerGrid[i][j] = 0;
		 
		 cout<<"\nPower in row "<<i<<" colum "<<j<<" is now set to "<<PowerGrid[i][j]<<endl;
		 return;
		    }
	}
}

void grid::SwitchON(int row, int col){
	for(int i=0; i<GridRows ; i++)
	{
		 for(int j=0; j<GridCols ; j++)
			if(i==row && j == col)
		     { PowerGrid[i][j] = 1;
		 
		 cout<<"\nPower in row "<<i<<" colum "<<j<<" is now set to "<<PowerGrid[i][j]<<endl;
		 return;
		     }
	}
}

ostream& operator <<(ostream&os, const grid& gr ){
	for (int i=0; i<GridRows ; i++)
	{
		for(int j=0; j<GridCols ; j++)
		{
			os<<" "<<gr.PowerGrid[i][j];
		}
	}
	return os;
}

istream& operator >>(istream &is, grid& gr){
	for (int i=0; i<GridRows ; i++)
	{
		for(int j=0; j<GridCols ; j++)
		{
			cout<<"\nEnter the number for row"<<i<<" colum"<<j<< " => ";
			is>>gr.PowerGrid[i][j];
		}
	}
	return is;
}

void main(){
	grid ourgrid;
	supergrid oursupergrid;

	int userRow,userCol,SuperUserRow,SuperUserCol;
	char choice;

	cout<<"\nSuperGrid Data "<<oursupergrid<<endl;
	
	cout<<"Enter Supergrid "<<SuperGridRows<< "x" <<SuperGridCols<<" data:";
	cin>>oursupergrid;

	cout<<"\nNew SuperGrid Data "<<oursupergrid<<endl;

	if (oursupergrid.PowerOk() == 1 )
		cout<<"\nPower is ok throughout the grid "<<endl;
	else {oursupergrid.WhereOff(); }

	//----------------------asking to switch off/on a point in the supergrid---------
	cout<<"\nDo you want to switch off/on a point in the Supergrid [Y/N] => ";
	cin >> choice;
	choice = toupper(choice);

	if(choice == 'Y')
	{
			cout<<"\nEnter the Supergrid row => ";
			cin>>SuperUserRow;
			cout<<"\nEnter the Supergrid colum => ";
			cin>>SuperUserCol;
			cout<<"\nEnter the grid row => ";
			cin>>userRow;
			cout<<"\nEnter the grid colum => ";
			cin>>userCol;

			cout<<"\nDo you want to switch this OFF/ON "<<endl;
			cout<<"If you enter 'Y' it will be turned OFF "<<endl;
			cout<<"If you enter 'N' it will be turned ON "<<endl;
			cout<<"Enter [Y/N] here => ";
			cin>>choice;
			choice = toupper(choice);

			if(choice == 'Y')
			{
				oursupergrid.SwitchPointOFF(SuperUserRow,SuperUserCol,userRow,userCol);
			}
			if(choice == 'N')
			{
				oursupergrid.SwitchPointON(SuperUserRow,SuperUserCol,userRow,userCol);
			}
			else if(choice != 'N' && choice != 'Y')
			{cout<<"You did not enter 'Y' OR 'N' so no point will be turned off/on"<<endl;}
	}

			//------asking if user wants to switch off/on a grid object in supergrid--------
	       cout<<"\nDo you want to switch off/on any grid object in Supergrid [Y/N] => ";
	       cin >> choice;
	       choice = toupper(choice);

		   if(choice == 'Y')
		   {
					cout<<"\nEnter the Supergrid row => ";
					cin>>SuperUserRow;
					cout<<"\nEnter the Supergrid colum => ";
					cin>>SuperUserCol;

					cout<<"\nDo you want to switch this OFF/ON "<<endl;
					cout<<"If you enter 'Y' it will be turned OFF "<<endl;
					cout<<"If you enter 'N' it will be turned ON "<<endl;
					cout<<"Enter [Y/N] here => ";
					cin>>choice;
					choice = toupper(choice);

					if(choice == 'Y')
					{
						oursupergrid.SwitchAllOFF(SuperUserRow,SuperUserCol);
					}
					if(choice == 'N')
					{
						oursupergrid.SwitchAllON(SuperUserRow,SuperUserCol);
					}
					else if(choice != 'N' && choice != 'Y')
					{cout<<"You did not enter 'Y' OR 'N' so no grid object will be turned off/on"<<endl;}
		    }



		   cout<<"\nDo you want to switch OFF/ON The Supergrid [Y/N] => ";
	       cin >> choice;
	       choice = toupper(choice);
		   if(choice == 'Y')
		   {
			   cout<<"\nDo you want to switch OFF The Supergrid [Y/N] => ";
	           cin >> choice;
	           choice = toupper(choice);

			   if(choice == 'Y')
			   {
			   oursupergrid.SuperGridOFF();
		       }
		       if(choice == 'N')
		       {
			   oursupergrid.SuperGridON();
		       }
		   }




	cout<<oursupergrid;
}
