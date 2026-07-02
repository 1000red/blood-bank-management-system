# DonorManagement
A C++ Blood Bank Management System developed as a **Data Structures project**, using a **Doubly Linked List** to manage donor and recipient records.

## Overview
This console application demonstrates the use of **Object-Oriented Programming (OOP)**, **Doubly Linked Lists**, and **File Handling** in C++.
The application allows users to:
- Register as a donor or recipient
- Login with email and password
- Update account details
- Delete an account
- Request a donation (donor side)
- Search blood types and request blood (recipient side)
- Persist data using text files

## Data Structures Used
- Doubly Linked List
- Custom Node implementation
- Dynamic Memory Allocation

## Technologies
- C++
- Object-Oriented Programming (OOP)
- File Handling
- Doubly Linked List

## Files
- `DonorManagement.cpp` - Main application source code
- `DonorManagement.vcxproj` - Visual Studio project
- `Recipients.txt` - Output data file
- `Donors.txt` - Output data file

## Build Instructions
### Linux / macOS
```bash
g++ DonorManagement.cpp -std=c++17 -o DonorManagement
./DonorManagement
```
### Windows
Open `DonorManagement.vcxproj` using Visual Studio and build the project.

## Notes
- This project was developed for learning **Data Structures** and **Object-Oriented Programming**.
- Donor and recipient records are stored using a custom Doubly Linked List.
- Data is saved to text files rather than a database.

## License
This project is provided for educational purposes.
