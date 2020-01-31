#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <ctime>
#include "functions.h"
using namespace std;
int id=0;

class student{
	private:
		int choice;
	public:
		void setChoice(int ch){
			choice=ch;
			ChoiceFunction(choice);
		}
		
		//Menu Display Function
		void Main_Display(){
			student st;
			int c;
			cout<<"Press 1: Register a Student\n";
			cout<<"Press 2: View Registation\n";
			cout<<"Press 3: Update Registation\n";
			cout<<"Press 4: Delete Registation\n";
			cout<<"Press 5: Add Courses\n";
			cout<<"Press 6: Author Information\n";
			cout<<"Press 7: Exit\n";
			cout<<"\nEnter your Choice: ";
			cin>>c;
			cout<<"-------------------------";
			system("cls");
			st.setChoice(c);
		}
		
		//Generating ID on Runtime
		void Generating_ID(){
			student st;
			int rule=0;
			
			//Zero File Generator
			string name;
			ofstream start;
			stringstream aa;
			aa<<rule;
			name="Student_Information/" + aa.str() + ".txt";
			start.open(name.c_str());
			start<<"-------WELCOME TO STUDENT RECORDS-------\n";
			
			//ID Generator
			setid : stringstream a;
			a<<id;
			string filename = "Student_Information/" + a.str() + ".txt";
			fstream file;
			file.open(filename.c_str());
				
			if(file.is_open()){
				file.close();
				id++;
				goto setid;
			}
			start<<"\nTotal Students added are: "<<id-1;
			start.close();
			
			st.Main_Display();
		}
};

class Registration : public student{
	private:
		string name,fname,surname,email,country,city,clock;
		int dd,mm,yyyy;
		char gender;
		int clas;
		long long phone_no;
	public:
		Registration(string nam,string fnam,string surnam,int cla,
		int d,int m,int yy,string city_name,long long phoneno,
		char gende,string emai,string country_name,string clk){
			name=nam;
			fname=fnam;
			surname=surnam;
			clas=cla;
			dd=d;
			mm=m;
			yyyy=yy;
			city=city_name;
			phone_no=phoneno;
			gender=gende;
			email=emai;
			country=country_name;
			clock=clk;
			
			//Creating File
			file_Handling();
		}
		
		void file_Handling(){
			string filename;
			ofstream file;
			stringstream a;
			a<<id;
			filename="Student_Information/" + a.str() + ".txt";
			file.open(filename.c_str());
	
			file<<
			"Registration Time: "<<clock<<endl<<
			"Student Name: "<<name<<endl<<
			"Father Name: "<<fname<<endl<<
			"Surname: "<<surname<<endl<<
			"Class: "<<clas<<endl<<
			"Gender(m/f): "<<gender<<endl<<
			"Date of Birth: "<<dd<<"/"<<mm<<"/"<<yyyy<<endl<<
			"Country: "<<country<<endl<<
			"City: "<<city<<endl<<
			"Phone No# "<<phone_no<<endl<<
			"E-mail: "<<email;
			cout<<"\n-------------------------\n";
			cout<<"**** Successfully Data Saved ****";
			cout<<"\n-------------------------\n";
			file.close();
			++id;
			
			Generating_ID();
		}
};

class DeleteRegistration : public student{
	private:
		int idn;
		int status;
	public:
		DeleteRegistration(int idnum){
			idn=idnum;
			status=1;
			string filename;
			stringstream a;
			a<<idn;
			filename = "Student_Information/"+a.str()+".txt";
			status=remove(filename.c_str());
			
			if(status==0){
				cout<<"\n-------------------------\n";
				cout<<"***File Deleted Successfully***";
				cout<<"\n-------------------------\n";
			}else{
				cout<<"\n-------------------------\n";
				cout<<"***Unable To Found File in Directory***";
				cout<<"\n-------------------------\n";
			}
			
			Main_Display();
		}
};

class View : public student{
	private:
		int idn;	
	public:
		View(int idnum){
			idn=idnum;
			string filename;
			stringstream a;
			a<<idn;
			filename = "Student_Information/"+a.str()+".txt";
			string line_;
			ifstream file_(filename.c_str());
			if(file_.is_open()){
				while(getline(file_,line_)){
					cout<<line_<<'\n';
				}
				file_.close();
				cout<<"\n-------------------------\n";
			}else{
				cout<<"***File not Found***";
				cout<<"\n-------------------------\n";
			}
			
			Main_Display();
		}
};

class Update : public student{
	private:
		int idn;
		string name,fname,surname,email,country,city,clock;
		int dd,mm,yyyy;
		char gender;
		int clas;
		long long phone_no;
	public:
		Update(int idnum,string nam,string fnam,string surnam,int cla,int d,int m,int yy,
		string city_name,long long phoneno,char gende,string emai,string country_name,
		string clk){
			idn=idnum;
			name=nam;
			fname=fnam;
			surname=surnam;
			clas=cla;
			dd=d;
			mm=m;
			yyyy=yy;
			city=city_name;
			phone_no=phoneno;
			gender=gende;
			email=emai;
			country=country_name;
			clock=clk;
			
			string filename;
			stringstream a;
			a<<idn;
			filename = "Student_Information/"+a.str()+".txt";
			ifstream file_(filename.c_str());
			if(file_.is_open()){
				file_.close();
				
				//Updating File
				file_Handling();
				cout<<"\n-------------------------\n";
			}else{
				cout<<"***File not Found***";
				cout<<"\n-------------------------\n";
			}
			
			Main_Display();
		}
		
		void file_Handling(){
			string filename;
			fstream file;
			stringstream a;
			a<<idn;
			filename="Student_Information/" + a.str() + ".txt";
			file.open(filename.c_str(), ios::app);
	
			file<<
			"\n\n---------------------------------"<<
			"\nUpdating Time: "<<clock<<endl<<
			"Student Name: "<<name<<endl<<
			"Father Name: "<<fname<<endl<<
			"Surname: "<<surname<<endl<<
			"Class: "<<clas<<endl<<
			"Gender(m/f): "<<gender<<endl<<
			"Date of Birth: "<<dd<<"/"<<mm<<"/"<<yyyy<<endl<<
			"Country: "<<country<<endl<<
			"City: "<<city<<endl<<
			"Phone No# "<<phone_no<<endl<<
			"E-mail: "<<email;
			cout<<"\n-------------------------\n";
			cout<<"**** Successfully Data Saved ****";
			cout<<"\n-------------------------\n";
			file.close();
		}
};

class Courses : public student{
	private:
		int idn, course_number,ps;
	public:
		Courses(int idnum,int number){
			idn=idnum;
			course_number=number;
			string courses[number];
			
			string filename;
			stringstream a;
			fstream file;
			a<<idn;
			filename = "Student_Information/"+a.str()+".txt";
			ifstream file_(filename.c_str());
			
			if(file_.is_open()){
				file_.close();
				
				cout<<"\n***Enter Courses Name or Code***\n";
				for(int i=0; i<number; i++){
					cout<<"Course "<<i+1<<": ";
					cin>>courses[i];
				}
				
				file.open(filename.c_str(), ios::app);
				file<<"\n\nCourse Added: "<<course_number;
				for(int i=0; i<number; i++){
					file<<"\nCourse "<<i+1<<": "<<courses[i];
				}
				
				uper:cout<<"\nEnter How many Courses you have Passed? ";
				cin>>ps;
				if(ps>=0 && ps<=number){
					int arr[ps];
					int a;
					a=number-ps;
					
					file<<"\n\nCourses Passed are: "<<ps;
					cout<<"\n***Enter Course Number which you passed***\n";
					for(int i=0;i<ps;i++){
						cout<<"Course ";
						cin>>arr[i];
						file<<"\nCourse "<<arr[i];
					}
				}else{
					cout<<"\n***Invalid Passed Courses***\n";
					goto uper;
				}
				
				file.close();
				cout<<"\n-------------------------\n";
			}
			else{
				cout<<"***File not Found***";
				cout<<"\n-------------------------\n";
			}
			
			Main_Display();
		}	
};



//////////////////////////////////////////////////////////////////////////////
							/*FUNCTIONS*/
//////////////////////////////////////////////////////////////////////////////


//Clock-------------------------------------------------------
string Clock(){
	//Setting up clock
	time_t tt;
	string clk;
	// Declaring variable to store return value of
	// localtime()
	struct tm * ti;				
	// Applying time()
	time(&tt);		
	// Using localtime()
	ti = localtime(&tt);		
	clk = asctime(ti);
	return clk;
}
//------------------------------------------------------------

//Taking Inputs-----------------------------------------------
//Input Name
string Input1(){
	string name;
	cout<<"*Enter Your Name: ";
	cin>>name;
	return name;
}
//Input Father Name
string Input2(){
	string fname;
	cout<<"*Enter Father Name: ";
	cin>>fname;
	return fname;
}
//Input Surname
string Input3(){
	string surname;
	cout<<"*Enter Surname: ";
	cin>>surname;
	return surname;
}
//Input Class
int Input4(){
	int clas,z;
	do{
		cout<<"*Enter Class: ";
		cin>>clas;
		if(clas>=1 && clas<=12){
			z=1;
		}else{
			cout<<"\n***Class should be from (1 to 12)***\n";
		}
	}while(z!=1);
	return clas;
}
//Input Gender
char Input5(){
	char gender;
	int gen;
	ggg:cout<<"*Enter your Gender(m/f): ";
	cin>>gender;
	if(gender=='M'||gender=='m'||gender=='F'||gender=='f'){
		gen=1;
	}else{
		cout<<"\n***Invalid Gender***\n";
		goto ggg;
	}
	return gender;
}
//Date of Birth for Date
int Input6(){
	int dd,x;
	
	date:cout<<"*Enter Date of Birth\n";
	cout<<"Date: ";
	cin>>dd;
	if(dd>=1 && dd<=31){
		x=1;
	}else{
		cout<<"\n***Invalid Date (i.e 1 to 31)***\n";
		goto date;
	}
	return dd;
}
//Date of Birth for Month
int Input7(int d){
	int mm,x,dd;
	dd=d;
	month:cout<<"Month: ";
	cin>>mm;
	if(mm==1||mm==3||mm==5||mm==7||mm==9||mm==11){
		if(dd>=1 && dd<=31){
			x=1;
		}else{
			cout<<"\n***Month should be in odd number***\n";
			goto end;
		}
	}
	else if(mm==2){
		if(dd>=1 && dd<=29){
			x=1;
		}else{
			cout<<"\n***Month should be February (i.e 2)***\n";
			goto end;
		}
	}
	else if(mm==4||mm==6||mm==8||mm==10||mm==12){
		if(dd>=1 && dd<=30){
			x=1;
		}
		else{
			cout<<"\n***Month should be in even number except 2***\n";
			goto end;
		}
	}
	else{
		cout<<"\n***Invalid Month (i.e 1 to 12)***\n";
		end:cout<<"";
		goto month;
	}
	return mm;
}
//Date of Birth for Year
int Input8(int d, int m){
	int yyyy,x,dd,mm;
	mm=m;
	dd=d;
	year:cout<<"Year: ";
	cin>>yyyy;
	//From 2000 to 2018
	if(yyyy>=2000 && yyyy<=2018){
		if((yyyy==2000||yyyy==2004||yyyy==2008||yyyy==2012||yyyy==2016) && mm==2 && dd==29){
			x=1;
		}
		else if((mm==2 && (dd>=1 && dd<=28)) || (mm!=2 && (dd>=1 && dd<=31))){
			x=2;
		}
		else{
			cout<<"\n***Be Aware of Leap Year Conditions***\n";
			goto el;
		}
	}
	else{
		cout<<"\n***Invalid Year (i.e 2000 to 2018)***\n";
		el:cout<<"";
		goto year;
	}
	return yyyy;
}
//Input Country
string Input9(){
	string country;
	cout<<"*Enter your Country Name: ";
	cin>>country;
	return country;
}
//Input City
string Input10(){
	string city;
	cout<<"*Enter your City Name: ";
	cin>>city;
	return city;
}
//Input Phone no
long long Input11(){
	long long phone_no;
	cout<<"*Enter your Phone no: ";
	cin>>phone_no;
	return phone_no;
}
//Input Email
string Input12(){
	string email;
	cout<<"*Enter your Email: ";
	cin>>email;
	return email;
}
//------------------------------------------------------------


//Function for Option 5
void CourseSelection(){
	int idnum,coursenum;
	cout<<"\n\nEnter Student ID Number: ";
	cin>>idnum;
	cout<<"\nHow many Course you want to add: ";
	cin>>coursenum;
	
	Courses cs(idnum,coursenum);
}

//Function for Option 3
void UpdateRegistration(){
	student st;
	string name,fname,surname,email,country,city;
	int dd,mm,yyyy,ddtemp,mmtemp;
	char gender;
	int clas;
	long long phone_no;
	string clk;
	int idnum;
	char sure;
	
	cout<<"\n\nEnter Student ID Number: ";
	cin>>idnum;
	upd:cout<<"\nAre you Sure to Update Student Data?";
	cout<<"\nThis may replace your Previous Data (y/n) : ";
	cin>>sure;
	if(sure=='y'||sure=='Y'){
		cout<<"\nUpdating a Student...\n\n";
		//Displaying ID Number
		cout<<"*** Your ID Number: "<<idnum<<" ***"<<endl;
		
		//Input Data
		name = Input1();
		fname = Input2();
		surname = Input3();
		clas = Input4();
		gender = Input5();
		dd = Input6();
		ddtemp=dd;
		mm = Input7(ddtemp);
		mmtemp=mm;
		yyyy = Input8(ddtemp,mmtemp);
		country = Input9();
		city = Input10();
		phone_no = Input11();
		email = Input12();
		
		//Clock
		clk = Clock();
		
		Update up(idnum,name,fname,surname,clas,dd,mm,yyyy,city,phone_no,gender,email,country,clk);
	}
	else if(sure=='n'||sure=='N'){
		cout<<"\n-------------------------\n";
		cout<<"***Back To Main***";
		cout<<"\n-------------------------\n";
		st.Main_Display();
	}
	else{
		cout<<"\n-------------------------\n";
		cout<<"***Invalid Type***";
		cout<<"\n-------------------------\n";
		goto upd;
	}
}

//Function for Option 2
void ViewRegistration(){
	int idnum;
	cout<<"\n\nEnter Student ID Number: ";
	cin>>idnum;
	cout<<endl;
	
	View v(idnum);
}

//Function for Option 4
void Deleting(){
	student st;
	int idnum;
	char sure;
	cout<<"\n\nEnter Student ID Number: ";
	cin>>idnum;
	del:cout<<"\nAre you Sure to Delete Student Data (y/n) ?";
	cin>>sure;
	if(sure=='y'||sure=='Y'){
		DeleteRegistration delreg(idnum);
	}else if(sure=='n'||sure=='N'){
		cout<<"\n-------------------------\n";
		cout<<"***Back To Main***";
		cout<<"\n-------------------------\n";
		st.Main_Display();
	}else{
		cout<<"\n-------------------------\n";
		cout<<"***Invalid Type***";
		cout<<"\n-------------------------\n";
		goto del;
	}
}

//Function for Option 1
void SignUp(){
	string name,fname,surname,email,country,city;
	int dd,mm,yyyy,ddtemp,mmtemp;
	char gender;
	int clas;
	long long phone_no;
	string clk;
	
	cout<<"\n\nRegister a Student...\n\n";
	//Displaying ID Number
	cout<<"*** Your ID Number: "<<id<<" ***"<<endl;
	
	//Input Data
	name = Input1();
	fname = Input2();
	surname = Input3();
	clas = Input4();
	gender = Input5();
	dd = Input6();
	ddtemp=dd;
	mm = Input7(ddtemp);
	mmtemp=mm;
	yyyy = Input8(ddtemp,mmtemp);
	country = Input9();
	city = Input10();
	phone_no = Input11();
	email = Input12();
	
	//Clock
	clk = Clock();
	
	Registration Reg(name,fname,surname,clas,dd,mm,yyyy,city,phone_no,gender,email,country,clk);
}

//Function for Option 6
void Author(){
	student st;
	cout<<"\n--------------------------------\n";
	cout<<"   *** CREATED BY ***\n";
	cout<<"Sameer Khowaja (K17-3613)\n";
	cout<<"\n--------------------------------\n";
	st.Main_Display();
}

//Main Display
void MainDisplay(){
	student st;
	st.Main_Display();
}
