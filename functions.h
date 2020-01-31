//Header File
void exit();
void SignUp();
void Deleting();
void Author();
void ViewRegistration();
void UpdateRegistration();
void CourseSelection();
void MainDisplay();

void ChoiceFunction(int choice){
	switch(choice){
		case 1:
			SignUp();
			break;
		case 2:
			ViewRegistration();
			break;
		case 3:
			UpdateRegistration();
			break;
		case 4:
			Deleting();
			break;
		case 5:
			CourseSelection();
			break;
		case 6:
			Author();
			break;
		case 7:
			exit();
			break;
		default:
			std::cout<<"\n\n***WRONG CHOICE...!***";
			std::cout<<"\n--------------------------------\n";
			MainDisplay();
	}
}
void exit(){
	std::cout<<"\n\n--------------Thank You For Visiting--------------\n";
}
