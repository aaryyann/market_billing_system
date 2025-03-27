# Supermarket Billing System

## Overview

The **Supermarket Billing System** is a console-based C++ application designed to manage the billing process in a supermarket. It allows users to add items to an inventory and generate bills for purchased items. The system also updates stock levels after each transaction.

## Features

- **Add Items**: Users can add new items to the inventory by specifying the item name, price, and quantity.
- **Generate Bill**: Customers can select items and quantities to generate a bill with total pricing.
- **Inventory Management**: The system keeps track of item stock and updates it after each purchase.
- **File Storage**: Inventory data is stored in a text file (`Bill.txt`) for persistence.

## Technologies Used

- **Programming Language**: C++
- **File Handling**: Uses file I/O operations to store and retrieve inventory data.
- **Windows-Specific Features**: Utilizes `windows.h` for system commands and delays.

## How to Run

1. **Compile the Code**: Use any C++ compiler like `g++` or an IDE like Code::Blocks, Dev-C++, or Visual Studio.

   ```sh
   g++ billing_system.cpp -o billing_system.exe
   ```

2. **Run the Program**:

   ```sh
   ./billing_system.exe
   ```

## File Structure

- `billing_system.cpp` → Main C++ source file containing the logic.
- `Bill.txt` → Stores inventory details (created automatically if not present).

## Usage Instructions

1. **Main Menu**:
   - Choose **1** to add an item.
   - Choose **2** to generate a bill.
   - Choose **3** to exit the program.
2. **Adding an Item**:
   - Enter item name, price, and quantity.
   - Data is stored in `Bill.txt`.
3. **Generating a Bill**:
   - Enter item name and quantity.
   - The system calculates the bill and updates stock.
4. **Exit**: The program exits gracefully when the user selects option 3.

## Notes

- Ensure that `D:/Bill.txt` is accessible. You may change the file path if needed.
- Running the program multiple times will retain previously added inventory.

## Future Improvements

- Implement a graphical user interface (GUI) for better user interaction.
- Add a database system for efficient data handling.
- Include authentication and user roles for secure access.

## License

This project is open-source and free to use and modify.

## Author

- **Your Name** Aryan Gupta

