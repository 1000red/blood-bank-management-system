#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class User {
protected:
    struct UserData {
        int id = 0;
        string name = "";
        string email = "";
        string password = "";
        int age = 0;
        string gender = "";
        string bloodType = "";
    };
};

class Donor : public User {
private:
    struct DonorData : public UserData {
        bool bloodPressureDisorder = false;
        bool thyroidDisease = false;
        bool diabetes = false;
        bool cancer = false;
        bool heartDisorder = false;
        bool hepatitis = false;
        string otherDiseaseOrMedicine = "";
        string lastDonationDate = "";
    };

    struct Node {
        DonorData data;
        Node* next;
        Node* prev;
    };
    Node* first = nullptr;
    Node* last = nullptr;
    int length = 0;

public:
    void insert_donors() {
        Node* newNode = new Node;

        cout << "Enter ID: ";
        cin >> newNode->data.id;
        cout << "Enter Name: ";
        cin >> newNode->data.name;
        cout << "Enter Email: ";
        cin >> newNode->data.email;
        cout << "Enter Password: ";
        cin >> newNode->data.password;
        cout << "Enter Age: ";
        cin >> newNode->data.age;
        cout << "Enter Gender (male/female): ";
        cin >> newNode->data.gender;
        while (newNode->data.gender != "male" && newNode->data.gender != "female" &&
            newNode->data.gender != "Male" && newNode->data.gender != "Female") {
            cout << "Invalid gender. Please enter 'male' or 'female': ";
            cin >> newNode->data.gender;
        }
        cout << "Enter Blood Type: ";
        cin >> newNode->data.bloodType;
        cout << "Do you have blood pressure disorder (1 for Yes, 0 for No)?: ";
        cin >> newNode->data.bloodPressureDisorder;
        cout << "Do you have thyroid disease (1 for Yes, 0 for No)?: ";
        cin >> newNode->data.thyroidDisease;
        cout << "Do you have diabetes (1 for Yes, 0 for No)?: ";
        cin >> newNode->data.diabetes;
        cout << "Do you have cancer (1 for Yes, 0 for No)?: ";
        cin >> newNode->data.cancer;
        cout << "Do you have a heart disorder (1 for Yes, 0 for No)?: ";
        cin >> newNode->data.heartDisorder;
        cout << "Do you have hepatitis (1 for Yes, 0 for No)?: ";
        cin >> newNode->data.hepatitis;
        cout << "Enter any other disease or medicine: ";
        cin >> newNode->data.otherDiseaseOrMedicine;
        cout << "Enter the date of your latest donation: ";
        cin >> newNode->data.lastDonationDate;

        newNode->next = newNode->prev = NULL;
        if (length == 0) {
            first = last = newNode;
        }
        else {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        length++;

        File("donors");
        cout << "Donor inserted successfully!" << endl;
    }

    void login_donors(const string& email, const string& password, int& loggedInUserId) {
        if (email.empty() || password.empty()) {
            cout << "Login failed. Email or password cannot be empty." << endl;
            loggedInUserId = -1;
            return;
        }
        Node* current = first;
        while (current != NULL) {
            if (current->data.email == email && current->data.password == password) {
                cout << "Login successful!" << endl;
                loggedInUserId = current->data.id;
                return;
            }
            current = current->next;
        }
        cout << "Login failed. Incorrect email or password." << endl;
        loggedInUserId = -1;
    }

    void updateData_donors(int& id) {
        Node* current = first;
        while (current != NULL) {
            if (current->data.id == id) {
                int choice;
                do {
                    cout << "What data do you want to update?" << endl;
                    cout << "1. Name" << endl;
                    cout << "2. Email" << endl;
                    cout << "3. Password" << endl;
                    cout << "4. Blood Pressure Disorder" << endl;
                    cout << "5. Thyroid Disease" << endl;
                    cout << "6. Diabetes" << endl;
                    cout << "7. Cancer" << endl;
                    cout << "8. Heart Disorder" << endl;
                    cout << "9. Hepatitis" << endl;
                    cout << "10. Other Disease or Medicine" << endl;
                    cout << "11. Date of Latest Donation" << endl;
                    cout << "0. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice) {
                    case 1:
                        cout << "Enter your new name: ";
                        cin >> current->data.name;
                        break;
                    case 2:
                        cout << "Enter your new email: ";
                        cin >> current->data.email;
                        break;
                    case 3:
                        cout << "Enter your new password: ";
                        cin >> current->data.password;
                        break;
                    case 4:
                        cout << "Do you have blood pressure disorder (1 for Yes, 0 for No)? ";
                        cin >> current->data.bloodPressureDisorder;
                        break;
                    case 5:
                        cout << "Do you have thyroid disease (1 for Yes, 0 for No)? ";
                        cin >> current->data.thyroidDisease;
                        break;
                    case 6:
                        cout << "Do you have diabetes (1 for Yes, 0 for No)? ";
                        cin >> current->data.diabetes;
                        break;
                    case 7:
                        cout << "Do you have cancer (1 for Yes, 0 for No)? ";
                        cin >> current->data.cancer;
                        break;
                    case 8:
                        cout << "Do you have a heart disorder (1 for Yes, 0 for No)? ";
                        cin >> current->data.heartDisorder;
                        break;
                    case 9:
                        cout << "Do you have hepatitis (1 for Yes, 0 for No)? ";
                        cin >> current->data.hepatitis;
                        break;
                    case 10:
                        cout << "Enter any other disease or medicine: ";
                        cin >> current->data.otherDiseaseOrMedicine;
                        break;
                    case 11:
                        cout << "Enter the date of your latest donation: ";
                        cin >> current->data.lastDonationDate;
                        break;
                    case 0:
                        cout << "Exiting update menu." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                } while (choice != 0);

                File("donors");
                cout << "Data updated successfully!" << endl;

                return;
            }
            current = current->next;
        }
        cout << "User not found." << endl;
    }

    void loginAndUpdateData(const string& email, const string& password) {
        int loggedInUserId = -1;

        login_donors(email, password, loggedInUserId);
        if (loggedInUserId != -1) {
            updateData_donors(loggedInUserId);
        }
        else {
            cout << "Please sign up first." << endl;
        }
    }

    void deleteAccount_donors() {
        int userId;
        cout << "Enter your ID: ";
        cin >> userId;

        int loggedInUserId = -1;
        string email, password;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;

        login_donors(email, password, loggedInUserId);

        if (loggedInUserId == -1) {
            cout << "User not found or login failed." << endl;
            return;
        }

        Node* current = first;
        while (current != nullptr) {
            if (current->data.id == userId) {
                if (current == first && current == last) { //one node
                    delete current;
                    first = last = nullptr;
                }
                else if (current == first) { //first node
                    first = current->next;
                    first->prev = nullptr;
                    delete current;
                }
                else if (current == last) { //last node
                    last = current->prev;
                    last->next = nullptr;
                    delete current;
                }
                else { //node middle
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                cout << "Account deleted successfully!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "User not found." << endl;
    }

    void requestDonation(int& donorId, string& recipientName, string& requiredBloodType) {
        Node* current = first;
        while (current != NULL) {
            if (current->data.id == donorId) {
                cout << "Donation request details:" << endl;
                cout << "Donor ID: " << current->data.id << endl;
                cout << "Donor Name: " << current->data.name << endl;
                cout << "Recipient Name: " << recipientName << endl;
                cout << "Required Blood Type: " << requiredBloodType << endl;
                cout << "Request Date: " << current->data.lastDonationDate << endl;
                cout << "Donation request submitted successfully!" << endl;
                return;
            }
            current = current->next;
            File("Request Donation");
        }
        cout << "Donor not found." << endl;
    }

    void File(const string& filename) {

        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        Node* current = first;
        while (current != nullptr) {
            file << "==========Donors============" << endl;
            file << "ID: " << current->data.id << endl;
            file << "Name: " << current->data.name << endl;
            file << "Email: " << current->data.email << endl;
            file << "Password: " << current->data.password << endl;
            file << "Age: " << current->data.age << endl;
            file << "Gender: " << current->data.gender << endl;
            file << "Blood Type: " << current->data.bloodType << endl;
            file << "Blood Pressure Disorder: " << (current->data.bloodPressureDisorder ? "Yes" : "No") << endl;
            file << "Thyroid Disease: " << (current->data.thyroidDisease ? "Yes" : "No") << endl;
            file << "Diabetes: " << (current->data.diabetes ? "Yes" : "No") << endl;
            file << "Cancer: " << (current->data.cancer ? "Yes" : "No") << endl;
            file << "Heart Disorder: " << (current->data.heartDisorder ? "Yes" : "No") << endl;
            file << "Hepatitis: " << (current->data.hepatitis ? "Yes" : "No") << endl;
            file << "Other Disease or Medicine: " << current->data.otherDiseaseOrMedicine << endl;
            file << "Last Donation Date: " << current->data.lastDonationDate << endl;

            current = current->next;
        }
        file.close();
    };
};

class Recipient : public User {
private:
    struct RecipientData : public UserData {
        string hospital = "";
        string doctor = "";
        int bloodQuantity = 0;
        string receivedDate = "";
        string expiryDate = "";
    };

    struct Node {
        RecipientData data;
        Node* next;
        Node* prev;
    };
    Node* first = nullptr;
    Node* last = nullptr;
    int length = 0;

public:
    void insert_recipients() {
        Node* newNode = new Node;
        cout << "Enter ID: ";
        cin >> newNode->data.id;
        cout << "Enter Name: ";
        cin >> newNode->data.name;
        cout << "Enter Email: ";
        cin >> newNode->data.email;
        cout << "Enter Password: ";
        cin >> newNode->data.password;
        cout << "Enter Age: ";
        cin >> newNode->data.age;

        cout << "Enter Gender (male/female): ";
        cin >> newNode->data.gender;
        while (newNode->data.gender != "male" && newNode->data.gender != "female" &&
            newNode->data.gender != "Male" && newNode->data.gender != "Female") {
            cout << "Invalid gender. Please enter 'male' or 'female': ";
            cin >> newNode->data.gender;
        }

        cout << "Enter Blood Type: ";
        cin >> newNode->data.bloodType;
        cout << "Enter Hospital Name: ";
        cin >> newNode->data.hospital;
        cout << "Enter Your Doctor Name: ";
        cin >> newNode->data.doctor;

        if (length == 0) {
            first = last = newNode;
        }
        else {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
        length++;

        if (first != nullptr) {
            saveFile("Recipients");
        }
    }

    void login_recipients(string& email, string& password) {
        Node* current = first;
        while (current != NULL) {
            if (current->data.email == email && current->data.password == password) {
                cout << "Login successful!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Login failed. Incorrect email or password." << endl;
    }

    void updateData_recipients(int& id) {
        if (id == -1) {
            cout << "You need to log in first." << endl;
            return;
        }

        Node* current = first;
        while (current != NULL) {
            if (current->data.id == id) {
                cout << "What data do you want to update?" << endl;
                cout << "1. Name" << endl;
                cout << "2. Email" << endl;
                cout << "3. Password" << endl;
                cout << "4. Gender" << endl;
                cout << "5. Age" << endl;
                cout << "6. Blood Type" << endl;
                cout << "7. Hospital Name" << endl;
                cout << "8. Doctor Name" << endl;
                cout << "Enter 0 for exit" << endl;
                int choice;
                cin >> choice;

                switch (choice) {
                case 0:
                    cout << "Exiting update." << endl;
                    return;
                case 1:
                    cout << "Enter your new name: ";
                    cin >> current->data.name;
                    break;
                case 2:
                    cout << "Enter your new email: ";
                    cin >> current->data.email;
                    break;
                case 3:
                    cout << "Enter your new password: ";
                    cin >> current->data.password;
                    break;
                case 4:
                    cout << "Enter your new gender (male/female): ";
                    cin >> current->data.gender;
                    while (current->data.gender != "male" && current->data.gender != "female" &&
                        current->data.gender != "Male" && current->data.gender != "Female") {
                        cout << "Invalid gender. Please enter 'male' or 'female': ";
                        cin >> current->data.gender;
                    }
                    break;
                case 5:
                    cout << "Enter your new age: ";
                    cin >> current->data.age;
                    break;
                case 6:
                    cout << "Enter your new blood type: ";
                    cin >> current->data.bloodType;
                    break;
                case 7:
                    cout << "Enter your new hospital name: ";
                    cin >> current->data.hospital;
                    break;
                case 8:
                    cout << "Enter your new doctor name: ";
                    cin >> current->data.doctor;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                }
                saveFile("Recipients");
                cout << "Data updated successfully!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "User not found." << endl;
    }

    void loginAndUpdate_recipients(string& email, string& password, int& loggedInUserId) {
        login_recipients(email, password);
        if (loggedInUserId != -1) {
            updateData_recipients(loggedInUserId);
        }
        else {
            cout << "User not found. If you are not registered, please sign up first." << endl;
        }
    }

    bool login_recipient(const string& email, const string& password) {
        Node* current = first;
        while (current != NULL) {
            if (current->data.email == email && current->data.password == password) {
                cout << "Login successful!" << endl;
                return true;
            }
            current = current->next;
        }
        cout << "Login failed. Incorrect email or password." << endl;
        return false;
    }

    void deleteAccount_recipients() {
        int userId;
        cout << "Enter your ID: ";
        cin >> userId;

        string email, password;
        cout << "Enter your email: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;

        if (login_recipient(email, password)) {
            Node* current = first;
            while (current != NULL) {
                if (current->data.id == userId) {
                    if (current == first && current == last) {
                        delete current;
                        first = last = NULL;
                    }
                    else if (current == first) {
                        first = current->next;
                        if (first != NULL)
                            first->prev = NULL;
                        delete current;
                    }
                    else if (current == last) {
                        last = current->prev;
                        if (last != NULL)
                            last->next = NULL;
                        delete current;
                    }
                    else {
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                        delete current;
                    }
                    cout << "Account deleted successfully!" << endl;
                    return;
                }
                current = current->next;
            }
            cout << "User not found." << endl;
        }
        else {
            cout << "Cannot delete account. Login failed." << endl;
        }
    }

    string searchBloodType(string& bloodType) {
        Node* current = first;
        while (current != NULL) {
            if (current->data.bloodType == bloodType) {
                return bloodType;
            }
            current = current->next;
        }
        return "Blood Type Not Available.";
    }

    void displayAllBloodData() {
        Node* current = first;
        while (current != NULL) {
            cout << "Blood Type: " << current->data.bloodType << endl;
            cout << "Quantity: " << current->data.bloodQuantity << " units" << endl;
            cout << "Received Date: " << current->data.receivedDate << endl;
            cout << "Expiry Date: " << current->data.expiryDate << endl;
            cout << "-------------------------" << endl;
            current = current->next;
        }
    }

    void requestBlood() {
        string requestedBloodType;
        int requestedQuantity;
        string hospital;

        cout << "Enter the blood type you need: ";
        cin >> requestedBloodType;
        cout << "Enter the quantity of blood you need: ";
        cin >> requestedQuantity;
        cout << "Enter the hospital where the patient is available: ";
        cin >> hospital;

        Node* current = first;
        bool found = false;
        int bestMatchDifference = INT_MAX;
        Node* bestMatchDonor = NULL;

        while (current != NULL) {
            if (current->data.bloodType == requestedBloodType &&
                current->data.bloodQuantity >= requestedQuantity &&
                current->data.hospital == hospital) {
                int quantityDifference = current->data.bloodQuantity - requestedQuantity;
                if (quantityDifference < bestMatchDifference) {
                    bestMatchDifference = quantityDifference;
                    bestMatchDonor = current;
                }
                found = true;
            }
            current = current->next;
            saveFile("Request Blood");
        }

        if (found) {
            cout << "Request confirmed:" << endl;
            cout << "Blood Type: " << bestMatchDonor->data.bloodType << endl;
            cout << "Quantity: " << bestMatchDonor->data.bloodQuantity << " units" << endl;
            cout << "Hospital: " << bestMatchDonor->data.hospital << endl;
            cout << "Doctor: " << bestMatchDonor->data.doctor << endl;
        }
        else {
            cout << "Sorry, the requested blood type, quantity, or hospital information is not available." << endl;
        }
    }

    void saveFile(const string& fileName) {
        ofstream outputFile(fileName + ".txt", ios::app);
        if (outputFile.is_open()) {
            Node* current = first;
            while (current != nullptr) {
                outputFile << "ID: " << current->data.id << "/n"
                    << "Name: " << current->data.name << "/n"
                    << "Email: " << current->data.email << "/n"
                    << "Password: " << current->data.password << "/n"
                    << "Age: " << current->data.age << "/n"
                    << "Gender: " << current->data.gender << "/n"
                    << "Blood Type: " << current->data.bloodType << "/n"
                    << "Hospital: " << current->data.hospital << "/n"
                    << "Doctor: " << current->data.doctor << endl;
                current = current->next;
            }
            outputFile.close();
            cout << "Data saved successfully." << endl;
        }
        else {
            cout << "Error: Unable to open file." << endl;
        }
    }
};

int main() {
    Donor D;
    Recipient R;
    cout << "Blood Bank Management System : " << endl;
    cout << "==================================" << endl;
    int x;

    while (true) {
        cout << "Enter 1 for Donor or 2 for Recipient. Enter 0 to Exit: ";
        cin >> x;

        if (x == 0) {
            break;
        }
        else if (x == 1) {
            int c;
            while (true) {
                cout << "============================You selected Donor============================" << endl;
                cout << "What do you want?\n1: Create account\n2: Login\n3: Update Data\n4: Delete Account\n5: Request Donation\n0: Go back\n";
                cin >> c;
                if (c == 0) break;
                switch (c) {
                case 1:
                    D.insert_donors();
                    break;
                case 2: {
                    string e, p; int id;
                    cout << "Enter id:\n";
                    cin >> id;
                    cout << "Enter email:\n";
                    cin >> e;
                    cout << "Enter password:\n";
                    cin >> p;
                    D.login_donors(e, p, id);
                    break;
                }
                case 3: {

                    string e, p;
                    cout << "Enter email:\n";
                    cin >> e;
                    cout << "Enter your password:\n";
                    cin >> p;
                    D.loginAndUpdateData(e, p);


                    break;
                }
                case 4:
                    D.deleteAccount_donors();
                    break;
                case 5: {
                    int donorId;
                    string recipientName, requiredBloodType;
                    cout << "Enter donor ID, recipient name, and required blood type: ";
                    cin >> donorId >> recipientName >> requiredBloodType;
                    D.requestDonation(donorId, recipientName, requiredBloodType);
                    break;
                }
                default:
                    cout << "Invalid option." << endl;
                    break;
                }

            }
        }
        else if (x == 2) {
            int c;
            while (true) {
                cout << "============================You selected Recipient.============================" << endl;
                cout << "What do you want?\n1: Create account\n2: Login\n3: Update Data\n4: Delete Account\n5: Search Blood Type\n6: Display All Blood Data\n7: Request Donation\n0: Go back\n";
                cin >> c;
                if (c == 0) break;
                switch (c) {
                case 1: {
                    R.insert_recipients();
                    break;
                }
                case 2: {
                    string e, p;
                    cout << "Enter email: ";
                    cin >> e;
                    cout << endl;
                    cout << "Enter password: " << endl;
                    cin >> p;
                    cout << endl;
                    R.login_recipients(e, p);
                    break;
                }
                case 3: {
                    int id;
                    string e, p;
                    cout << "Enter ID:\n ";
                    cin >> id;
                    cout << "Enter email:\n";
                    cin >> e;
                    cout << "Enter your password:\n";
                    cin >> p;
                    R.loginAndUpdate_recipients(e, p, id);
                    break;
                }
                case 4: {
                    R.deleteAccount_recipients();
                    break;
                }
                case 5: {
                    string bloodType;
                    cout << "Enter BloodType to search: ";
                    cin >> bloodType;
                    R.searchBloodType(bloodType);
                    break;
                }
                case 6: {
                    R.displayAllBloodData();
                    break;
                }
                case 7: {
                    R.requestBlood();
                    break;
                }
                default:
                    cout << "Invalid option." << endl;
                    break;
                }

            }
        }
        else {
            cout << "Invalid input." << endl;
        }
    }

    cout << "Exiting the program. Thank you!" << endl;
}