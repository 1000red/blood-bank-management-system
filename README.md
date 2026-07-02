# DonorManagement

A simple C++ Blood Bank Management System for managing donor and recipient data.

## Overview

This console application allows users to:

- Register as a donor or recipient
- Login with email and password
- Update account details
- Delete an account
- Request a donation (donor side)
- Search blood types and request blood (recipient side)
- Persist data to text output files

## Files

- `DonorManagement.cpp` - main source file for the application
- `DonorManagement.vcxproj` - Visual Studio C++ project file
- `Recipients.txt` - sample or output data file used by the app

## Build Instructions

### Linux / macOS

Use `g++`:

```bash
cd /home/alfred/University/projects/Data/Project01/DonorManagement
g++ DonorManagement.cpp -o DonorManagement
./DonorManagement
```

### Windows

You can open `DonorManagement.vcxproj` in Visual Studio and build the project there.

## Usage

1. Run the application.
2. Choose `1` for Donor or `2` for Recipient.
3. Follow prompts to create an account, login, update data, delete account, or request blood/donation.

## Notes

- The current implementation stores donors and recipients in memory and appends some output to text files.
- Data persistence is implemented through simple file writes, not a database.

## License

This project is provided as-is for educational purposes.
