//need to report to errorfile
//need to make search function


//Lab 1 Hernandez, Angel T TH
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
struct record{
        string id;
        string name;
        int quantity;
        double price;
    };

void getData(record validRecords[], int & recCount);
void printValidRecords(record validRecords[], int recCount);
bool errorChecker(string id, string name, int quantity, double price);
void printMenu();

int main() {
    const int size = 10;
    record validRecords[size];
    int menuOption;
    int recCount;
    enum option{ printAll = 1,  printInvalid = 2 ,quit = 3};
    getData(validRecords, recCount);

    while(menuOption != quit){
        printMenu();
        cin >> menuOption;
        switch(menuOption) {
            case printAll:
            cout << "Option 1" << endl;
            printValidRecords(validRecords,recCount);
            break;
            case printInvalid:
            cout << "Option 2";
            break;
            case quit:
            cout << "Option 3";
            
        }
    }
    
    system("pause");
    return 0;
    } 

void printMenu(){
    cout<< "Invetory Organizer:\n\n"
             "Enter the number that correlates to an option\n\n"
             "1: Print all current items\n"
             "2: Print invalid Records\n"
             "3: Quit\n\nPlease enter an option: ";
}


//This function takes an the array of structs for the valid records and a counter to keep count of the amount of valid records
//It reads the records file calls
void getData( record valRecords[], int &valCounter){
    valCounter = 0;

    ifstream infile;
    infile.open("allRecords.txt");

    if(!infile){
    cout << "Error opening infile";
    exit(1);
    }

    ofstream errorfile;
    errorfile.open("invalidRecords.txt");
    if(!errorfile){
        cout << "Error opening errorfile";
        exit(1);
    }

    record temp;
    while (!infile.eof()){
        infile >> temp.id>> temp.name>> temp.quantity >> temp.price;

        if(errorChecker(temp.id, temp.name, temp.quantity, temp.price)){
            valRecords[valCounter].id = temp.id;
            valRecords[valCounter].name = temp.name;
            valRecords[valCounter].quantity = temp.quantity;
            valRecords[valCounter].price = temp.price;
            valCounter++;
        }else{
            cout << "\n\nError on line " << valCounter << endl;
            
        }
    }

    infile.close();
    errorfile.close();
}

void printValidRecords(record valRecords[], int valCounter){
    for(int i= 0; i < valCounter; i++){
        cout << valRecords[i].id << " ";
        cout << valRecords[i].name << " ";
        cout << valRecords[i].quantity << " ";
        cout << valRecords[i].price << endl;
    }
    cout << "---------------------------------------------------" << endl;
}


bool errorChecker(string id, string name, int quantity, double price){

    int i =0, idLength = id.length(), nameLength = name.length();

    if(idLength > 5){
        return false;
    }else if(quantity < 0){
        return false;
    }else if(price < 0){
        return false;
    }

    while(i < idLength){
        if(!isalnum(id[i])){
            return false;
        }
        i++;
    }

    i=0;
    while(i < nameLength){
        if(!isalpha(name[i])){
            return false;
        }
        //can maybe get rid of if
        i++;
    }

    return true;
}
