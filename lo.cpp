#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

void printMenu();
void getData(ifstream &infile, record validRecords[], record invalidRecords[]);
int main() {

    struct record{
        string id;
        string name;
        int quantity;
        double price;
    };
    const int MAX = 100;

    record validRecords[MAX];
    record invalidRecords[MAX];

    ifstream infile;
    infile.open("allRecords.txt");

    if(!infile){
    cout << "Error opening infile";
    exit(1);
    }

    ofstream outfile;
    printMenu();
    
    
    enum option{ printAll = 1,  printInvalid = 2 ,quit = 3};
    int num;
    cin >> num;
    
    
    switch(num) {
        case printAll:
        cout << "Option 1";
        getData(infile, validRecords, invalidRecords)
        break;
        case printInvalid:
        cout << "Option 2";
        break;
        case quit:
        cout << "Option 3";
        
    }
    
return 0;
} 

void printMenu(){
    cout<< "Invetory Organizer:\n\nEnter the number that correlates to an option\n\n1: Print all current items\n2: Print invalid Records\n3: Quit\n\nPlease enter an option: ";
}

void getData(ifstream &infile, record valRecords[], record invalRecords[]){
    int counter = 0;
    while (!infile.eof()){
        infile >> valRecords[counter].id;
        infile >> valRecords[counter].name;
        infile >> valRecords[counter].quantity;
        infile >> valRecords[counter].price;
        counter++;
    }

}


