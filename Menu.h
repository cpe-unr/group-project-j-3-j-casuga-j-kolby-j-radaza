#pragma once

#include <iostream>

template<typename T>
class Menu{

private:
	T wavFile;
		

public:
	Menu(T wavFile){
		std::cout << "Success" << std::endl;

		/**

		cout << "**AUDIO FILE MANAGEMENT SYSTEM**" << endl;
		cout << "1. Modify/Add Metadata" << endl;
		cout << "2. Process Files" << endl;
		cout << "3. Export Files" << endl;
		cout << "0. EXIT" << endl;
		cout << "What do you want to do? " << endl;
		cin >> userChoice;

	    //userChoice = getMenuChoice();
	    switch(userChoice){
		case 1:
		cout << "Creating Metadata..." << endl;
		//modifyMetadata function
			break;
		case 2:
			//processFiles function
			cout << "How do you want to process your files?" << endl;
			cout << "1. Normalization" << endl;
			cout << "2. Noise Gate" << endl;
			cout << "3. Echo" << endl;
			cout << "Pick one: " << endl;
			cin >> userChoice2;
		
			switch(userChoice2){
			    case 1:
				cout << "One normalization coming right up, if you want to process another way, enter 1 for yes and 2 for no " << endl;
				cin >> Yn;
				
					if(Yn == 1){
						cout << "How do you want to process your files?" << endl;
						cout << "1. Noise Gate" << endl;
						cout << "2. Echo" << endl;
						cout << "Pick one: " << endl;
						cin >> userChoice3;

						switch(userChoice3){
						case 1:
						    cout << "One normalization and one noise gate coming right up, do you want to echo your file as well? (enter 1 for yes and 2 for no) " << endl;
						    cin >> Yn2;
						if(Yn2 == 1){
							cout << "One normalization, one noise gate, and one echo coming right up!" << endl;
							//add all three and break
						}else if(Yn2 == 2){
							cout << "Alright, one normalization and one noise gate coming right up!" << endl;
							//add two and break;
						}
						case 2:
						    cout << "One normalization and one echo coming right up, do you want to noise gate your file as well? (enter 1 for yes and 2 for no) " << endl;
						    cin >> Yn3;
						if(Yn3 == 1){
							cout << "One normalization, one echo, and one noise gate coming right up!" << endl;
							//add all three and break;
						}else if(Yn3 == 2){
							cout << "Alright, one normalization and one echo coming right up!" << endl;
						}
					        }
					}else if(Yn == 2){
						cout << "Alright, just the normalization, coming right up!" << endl;
						//add normalization and break
						break;
					}
					
			    case 2:
				cout << "One noise gate coming right up, if you want to process another way, enter 1 for yes and 2 for no " << endl;
				cin >> Yn4;

					if(Yn4 == 1){
						cout << "How do you want to process your files?" << endl;
						cout << "1. Normalization" << endl;
						cout << "2. Echo" << endl;
						cout << "Pick one: " << endl;
						cin >> userChoice4;
						
						switch(userChoice4){
						case 1:
		                                    cout << "One noise gate and one normalization coming right up, do you want to echo your file as well? (enter 1 for yes and 2 for no) " << endl;
						    cin >> Yn5;
						if(Yn5 == 1){
							cout << "All three comin right up!" << endl;
							//add all three and break;
						}else if(Yn5 == 2){
							cout << "Alright, just noise gate and normalization." << endl;
							//add two and break;
						}
						case 2:
							cout << "One noise gate and one echo comin right up, do you want to normalize as well? (enter 1 for yes and 2 for no) " << endl;
							cin >> Yn6;
						if(Yn6 == 1){
							cout << "All three coming right up!" << endl;
						}else if(Yn6 == 2){
							cout << "Alright, just noise gate and echo." << endl;
							//add two and break;
						}
						}
					}else if(Yn4 == 2){
						cout << "Alright, just the noise gate, comin right up!" << endl;
					}
                            case 3:
				cout << "One echo coming right up, if you want to process another way, enter 1 for yes and 2 for no " << endl;
				cin >> Yn7;
			
					if(Yn7 == 1){
						cout << "How do you want to process your files?" << endl;
						cout << "1. Normalization" << endl;
						cout << "2. Noisegate" << endl;
						cout << "Pick one: " << endl;
						cin >> userChoice5;

						switch(userChoice5){
						case 1:
						    cout << "One echo and one normalization coming right up, do you want to noise gate your file as well? (enter 1 for yes and 2 for no) " << endl;
						    cin >> Yn8;
							if(Yn8 == 1){
								cout << "All three comin right up!" << endl;
								//add three and break;
							}else if(Yn8 == 2){
								cout << "Alright just echo and normalization." << endl;
							}
						case 2:
							cout << "One echo and one noise gate coming right up, do you want to normalize your file as well? (enter 1 for yes and 2 for no) " << endl;
							cin >> Yn9;
							    if(Yn9 == 1){
								cout << "All three comin right up!" << endl;
							    }else if(Yn9 == 2){
								cout << "Alright just echo and noise gate." << endl;
								//add two and break;
							    }
						}
					}
				
			}	

			cout << "Processing Files..." << endl;

			break;
		case 3:
			//exportFiles function
			cout << "Exporting Files..." << endl;

			break;
		case 0:

			break;

		default:
			cout << "Not a valid option." << endl;
			break;

		**/
		
	}
		
};
