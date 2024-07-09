#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class SportsEquipment {
private:
    list<int> sportsEquipmentId;
    list<string> equipmentName;
    list<string> brand;
    list<string> production;
    list<int> numberOfCopies;

public:
	SportsEquipment(){
	}
    void addEquipment() {
        int id = sportsEquipmentId.size() + 1; 
        cout<<"ID: "<<id<<endl;
		sportsEquipmentId.push_back(id);
		cin.ignore();
		string ename;
        cout << "Equipment Name: ";
        cin.ignore();
        getline(cin, ename);
        equipmentName.push_back(ename);
        cout << "Brand: ";
        string b;
        getline(cin, b);
        brand.push_back(b);
        string p;
        cout << "Production: ";
        getline(cin, p);
        production.push_back(p);
        int copies;
        cout << "Number of Copies: ";
        cin >> copies;
        numberOfCopies.push_back(copies);
        cout << endl;
        saveToFile();
    }

    void saveToFile() {
        ofstream file("equipment.txt", ios::app); 
        if (file.is_open()) {
            int index = sportsEquipmentId.size() - 1; 
            file << sportsEquipmentId[index] << "," 
                 << equipmentName[index] << "," 
                 << brand[index] << "," 
                 << production[index] << "," 
                 << numberOfCopies[index] << endl;
            file.close();
        } else {
            cout << "Can't open file'." << endl;
        }
    }

    void displayAllEquipment() {
        ifstream file("equipment.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }

    void menu() {
        cout << "[1] Insert a new sports equipment\n";
        cout << "[2] Rent a sports equipment\n";
        cout << "[3] Return a sports equipment\n";
        cout << "[4] Show the details of a particular sports equipment\n";
        cout << "[5] Display all sports equipment in the store\n";
        cout << "[6] Check whether a particular sports equipment is in the store\n";
        cout << "[7] Customer Maintenance\n";
        cout << "[8] Exit Program\n";
        cout << "Enter your choice: ";
    }
    
    

};
class Customer_Parent{
	protected: 
	list<int> CustomerID;
	list<string> Name;
	list<string> Address;
	
	public:
		Customer_Parent(){
			
		}
	
	void add_customer() {
    int c_id = CustomerID.size() +1;
    cout << "Customer ID: " << c_id << endl;
    CustomerID.push_back(c_id);
    
    string cname;
    cout << "Name: ";
    cin.ignore();  // to clear the newline left by previous cin
    getline(cin, cname);
    Name.push_back(cname);
    
    string address;
    cout << "Address: ";
    getline(cin, address);
    Address.push_back(address);
    
    ofstream file("Customer.txt", ios::app);
    if (file.is_open()) {
        int index = CustomerID.size() - 1;
        file << CustomerID[index] << ","
             << Name[index] << ","
             << Address[index] << endl;
        file.close();
    } else {
        cout << "Can't open file." << endl;
    }
}
    void customer_details(){
    	int search_customer;
    	cout<<"ID: ";
    	cin>>search_customer;
    	ifstream file("Customer.txt");
        if (file.is_open()) {
            string line;
            bool found = false;
            while (getline(file,line)){
            size_t pos = line.find(",");
            int id = stoi(line.substr(0, pos));
            if (id == search_customer) {
                cout << CustomerID[index]<< endl;
                cout << Name[index];
                
                found = true;
                break;
                }
            else{
            cout<<"Customer ID "<<search_customer<<" is not found";
			}
			}
        
            file.close();
        } else {
            cout << "Unable to open file." << endl;
        }
	}
	void customer_menu(){
		cout<<"Add Customer\n";
		cout<<"Show Customer Details\n";
		cout<<"Print of all Customers\n";
		cout<<"Enter choice: ";
	}

		
		
		
};

int main() {
    SportsEquipment equipment;
    Customer_Parent customer;
    int choice =0 ;
    while (choice != 8) {
        equipment.menu();
        cin >> choice;
        switch (choice) {
            case 1:
                equipment.addEquipment();
                break;
            case 5:
                equipment.displayAllEquipment();
                break;
            case 7:
            	int customer_choice;
            	customer.customer_menu();
            	cin>>customer_choice;
            	switch(customer_choice){
            		case 1:
            			customer.add_customer();
            		break;
            		case 2:
            			customer.customer_details();
				}
            	
            	
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
                break;
        }
    }

    return 0;
}

