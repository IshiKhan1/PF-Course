// Lead by 63568
// /62590/53731

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
using namespace std;

// Hardcoded login credentials for simplicity
string adminUsername = "admin";
string adminPassword = "admin123";

struct Bus
{
    int busid;
    string busname;
    string departuretime;
    int availableseats;
};

struct booking
{
    string customername;
    int busid;
    int seatsbooked;
};

booking book[20];
int currentBookingCount = 0;

Bus buses[10];
int currentbusscount = 4;

// File names
// const string CUSTOMER_FILE = "G:\\RIU\\Programming Fundamentals\\Project\\sawari.txt";

// Structure to store customer information
struct Customer
{
    string name;
    string username;
    string password;
};

bool customerExists(string username)
{
    ifstream file("sawari.txt");
    if (file.is_open())
    {
        Customer sawari;
        while (file >> sawari.username >> sawari.password)
        {
            if (sawari.username == username)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void signUpCustomer()
{
    Customer newsawari;

    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, newsawari.name);

    cout << "Enter a username: ";
    cin >> newsawari.username;

    // Check if username already exists
    if (customerExists(newsawari.username))
    {
        cout << "Username already exists, Please try again with a different one." << endl;
        return;
    }

    cout << "Enter a password: ";
    cin >> newsawari.password;

    // Save customer data to file
    ofstream file("sawari.txt", ios::app); // Append mode
    if (file.is_open())
    {
        file << newsawari.username << " " << newsawari.password << endl;
        file.close();
        cout << "Account created successfully!" << endl;
    }
    else
    {
        cout << "Error saving customer data!" << endl;
    }
}

// Function to login an existing customer
bool loginCustomer(string &loggedInUsername)
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // Check if the username and password are correct
    ifstream file("sawari.txt");
    if (file.is_open())
    {
        Customer sawari;
        while (file >> sawari.username >> sawari.password)
        {
            if (sawari.username == username && sawari.password == password)
            {
                file.close();
                loggedInUsername = username; // Store the logged-in username
                cout << "Login successful!" << endl;
                return true;
            }
        }
        file.close();
    }
    cout << "Invalid username or password!" << endl;
    return false;
}

string customeraccount()
{
    int choice;
    bool loggedIn = false;
    string loggedInUsername; // Variable to store the logged-in user's username

    while (!loggedIn)
    {
        cout << "\nCustomer Account Menu:" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            signUpCustomer(); // Calls the function to sign up a new customer
            break;
        case 2:
            loggedIn = loginCustomer(loggedInUsername); // Pass the variable to store the username
            break;
        case 3:
            cout << "Exiting program..." << endl;
            return ""; // Return an empty string if the user chooses to exit
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        if (!loggedIn)
        {
            cout << "Please try again by signing up or logging in." << endl;
        }
    }

    cout << "Welcome to the Bus Reservation System, " << loggedInUsername << "!" << endl;

    return loggedInUsername; // Return the username of the logged-in customer
}

// Function to save buses to file after any change
void saveBuses()
{
    ofstream busFile("buses.txt");

    if (busFile.is_open())
    {
        for (int i = 0; i < currentbusscount; ++i)
        {
            busFile << buses[i].busid << endl;
            busFile << buses[i].busname << endl;
            busFile << buses[i].departuretime << endl;
            busFile << buses[i].availableseats << endl;
        }
        busFile.close();
    }
    else
    {
        cout << "Error: Could not save bus data!" << endl;
    }
}

// Function to save bookings to file
void saveBookings()
{
    ofstream bookingFile("bookings.txt");

    if (bookingFile.is_open())
    {
        for (int i = 0; i < currentBookingCount; ++i)
        {
            bookingFile << book[i].customername << endl;
            bookingFile << book[i].busid << endl;
            bookingFile << book[i].seatsbooked << endl;
        }
        bookingFile.close();
    }
    else
    {
        cout << "Error: Could not save booking data!" << endl;
    }
}

void parmaBuses()
{
    if (currentbusscount == 0)
    { // Add only if no buses are present
        buses[0] = {1, "Bus A", "09:00 AM", 20};
        buses[1] = {2, "Bus B", "12:00 PM", 15};
        buses[2] = {3, "Bus C", "03:00 PM", 10};
        buses[3] = {4, "Bus D", "06:00 PM", 25};
        currentbusscount = 4; // Update the count
        cout << "DBA\n";
    }
}

// Function to load buses from file at the start
void loadBuses()
{
    ifstream busFile("buses.txt");

    if (busFile.is_open())
    {
        currentbusscount = 0;
        while (busFile >> buses[currentbusscount].busid)
        {
            if (currentbusscount >= 10)
            {
                cout << "[WARNING] Maximum bus limit reached. Skipping remaining buses.\n";
                break;
            }
            busFile.ignore(); // Ignore the newline after reading busID
            getline(busFile, buses[currentbusscount].busname);
            getline(busFile, buses[currentbusscount].departuretime);
            busFile >> buses[currentbusscount].availableseats;
            currentbusscount++;
        }
        busFile.close();
    }
    else
    {
        cout << "Error: Could not load bus data!" << endl;
    }
}

// Function to load bookings from file at the start
void loadBookings()
{
    ifstream bookingFile("bookings.txt");

    if (bookingFile.is_open())
    {
        while (bookingFile >> book[currentBookingCount].customername)
        {
            bookingFile >> book[currentBookingCount].busid;
            bookingFile >> book[currentBookingCount].seatsbooked;
            currentBookingCount++;
        }
        bookingFile.close();
    }
    else
    {
        cout << "Error: Could not load booking data!" << endl;
    }
}

void customerMenu()
{

    cout << "\nCustomer Menu:" << endl;
    cout << "1. View Available Buses" << endl;
    cout << "2. Book a Ticket" << endl;
    cout << "3. View My Bookings" << endl;
    cout << "4. Cancel a Booking" << endl;
    cout << "5. Exit" << endl;
}

void viewAvailbuses()
{
    cout << "\n----- Available Buses -----\n"
         << endl;
    cout << "Bus ID  | Bus Name | Departure Time | Available Seats \n";
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < currentbusscount; ++i)
    {
        cout << buses[i].busid << "\t| " << buses[i].busname << "\t   | " << buses[i].departuretime << "\t    | " << buses[i].availableseats << endl;
    }
}

void booktickets(string customerUsername)
{
    int busid, numseats;
    viewAvailbuses();

    cout << "Enter the Bus id to book a ticket: ";
    cin >> busid;

    bool busfound = false;
    for (int i = 0; i < currentbusscount; ++i)
    {
        if (buses[i].busid == busid)
        {
            busfound = true;

            cout << "Enter the number of seats to booked: ";
            cin >> numseats;

            if (numseats <= buses[i].availableseats)
            {
                buses[i].availableseats = buses[i].availableseats - numseats;

                if (currentBookingCount < 20)
                {
                    book[currentBookingCount] = {customerUsername, busid, numseats};
                    currentBookingCount++;
                    saveBookings();
                    saveBuses();
                    cout << "Successfully booked " << numseats << " seat(s) on " << buses[i].busname << "!" << endl;
                }
                else
                {
                    cout << "Booking limit reached, please try again later." << endl;
                }
            }
            else
            {
                cout << "Not enough seats available, Try different bus!" << endl;
            }
            break;
        }
    }
    if (!busfound)
    {
        cout << "Invalid Bus ID, Please try again" << endl;
    }
}

void viewbooking(string customerUsername)
{

    bool found = false;
    if (currentBookingCount == 0)
    {
        cout << "No bookings found";
        return;
    }

    cout << "\nYour Bookings:" << endl;
    cout << "Customer Name | Bus ID | Bus Name | Seats Booked" << endl;
    cout << "------------------------------------------------" << endl;

    for (int i = 0; i < currentBookingCount; ++i)
    {
        if (book[i].customername == customerUsername)
        {
            found = true;
            for (int j = 0; j < currentbusscount; ++j)
            {
                if (buses[j].busid == book[i].busid)
                {
                    cout << book[i].customername << "         | " << book[i].busid << "      | " << buses[j].busname << "      | " << book[i].seatsbooked << endl;
                }
            }
        }
    }
}

// Function to cancel a customer's booking
void cancelBooking(string customerUsername)
{
    int busID, indexToRemove = -1;
    cout << "Enter the Bus ID to cancel your booking: ";
    cin >> busID;

    // Search for the booking to cancel
    bool bookingFound = false;
    for (int i = 0; i < currentBookingCount; ++i)
    {
        if (book[i].customername == customerUsername && book[i].busid == busID)
        {
            bookingFound = true;
            indexToRemove = i;
            break;
        }
    }

    if (bookingFound)
    {
        for (int i = 0; i < currentbusscount; ++i)
        {
            if (buses[i].busid == busID)
            {
                buses[i].availableseats += book[indexToRemove].seatsbooked;
                break;
            }
        }

        for (int i = indexToRemove; i < currentBookingCount - 1; ++i)
        {
            book[i] = book[i + 1];
        }
        currentBookingCount--;

        saveBookings();
        saveBuses();
        cout << "Booking cancelled successfully!" << endl;
    }
    else
    {
        cout << "Booking not found! Please check the Bus ID and try again." << endl;
    }
}

void addNewBus()
{
    if (currentbusscount >= 10)
    {
        cout << "Bus limit reached. Cannot add more buses." << endl;
        return;
    }
    Bus newbus;
    cout << "Enter Bus id: ";
    cin >> newbus.busid;
    cin.ignore();

    cout << "Enter Bus Name: ";
    getline(cin, newbus.busname);

    cout << "Enter Departure Time: ";
    getline(cin, newbus.departuretime);

    cout << "Enter Available Seats: ";
    cin >> newbus.availableseats;

    buses[currentbusscount] = newbus;
    currentbusscount++;

    saveBuses();
    cout << "New bus added successfully!" << endl;
}

// Function to show admin menu
void adminMenu()
{
    cout << "\nAdmin Menu:" << endl;
    cout << "1. Add a New Bus" << endl;
    cout << "2. View available Buses" << endl;
    cout << "3. View Bookings" << endl;
    cout << "4. Update Bus Schedules" << endl;
    cout << "5. Remove a Bus" << endl;
    cout << "6. Exit" << endl;
}

// Function to update the bus schedule details
void updateBusSchedule()
{
    int busID;
    cout << "Enter the Bus ID to update: ";
    cin >> busID;

    bool busFound = false;
    // Loop through the buses to find the one with the provided Bus ID
    for (int i = 0; i < currentbusscount; ++i)
    {
        if (buses[i].busid == busID)
        {
            busFound = true;

            // Prompt for new details to update the bus
            cout << "Enter new Bus Name: ";
            cin.ignore(); // Clear any leftover newline character
            getline(cin, buses[i].busname);

            cout << "Enter new Departure Time (format: HH:MM): ";
            getline(cin, buses[i].departuretime);

            cout << "Enter new Available Seats: ";
            while (true)
            {
                cin >> buses[i].availableseats;
                if (cin.fail() || buses[i].availableseats < 0)
                {
                    cin.clear();                                         // Clear input buffer to restore cin to a usable state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the last input
                    cout << "Invalid input! Please enter a valid number of available seats: ";
                }
                else
                {
                    break; // Valid input, exit loop
                }
            }

            cout << "Bus schedule updated successfully!" << endl;
            saveBuses();
            break;
        }
    }

    if (!busFound)
    {
        cout << "Bus ID not found!" << endl;
    }
}

void removeBus()
{
    int busID;
    cout << "Enter the Bus ID to remove: ";
    cin >> busID;

    bool busFound = false;
    for (int i = 0; i < currentbusscount; ++i)
    {
        if (buses[i].busid == busID)
        {
            busFound = true;

            // Shift buses to fill the gap
            for (int j = i; j < currentbusscount - 1; ++j)
            {
                buses[j] = buses[j + 1];
            }
            currentbusscount--;
            saveBuses();
            cout << "Bus removed successfully!" << endl;
            break;
        }
    }

    if (!busFound)
    {
        cout << "Bus ID not found!" << endl;
    }
}

// Function to view all bookings for the admin
void viewAdminBookings()
{
    bool found = false;

    cout << "\n----- All Bookings -----" << endl;
    cout << "Customer Name | Bus ID | Bus Name | Seats Booked" << endl;
    cout << "------------------------------------------------3" << endl;

    for (int i = 0; i < currentBookingCount; ++i)
    {
        for (int j = 0; j < currentbusscount; ++j)
        {
            if (book[i].busid == buses[j].busid)
            {
                cout << book[i].customername << "         | " << book[i].busid << "      | " << buses[j].busname << "      | " << book[i].seatsbooked << endl;
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "No bookings found!" << endl;
    }
}

bool validLogin(string username, string password, string correctUsername, string correctPassword)
{
    return (username == correctUsername && password == correctPassword);
}

bool customercredentials(string username, string password)
{
    string fileUsername, filePassword;
    ifstream customerFile("customers.txt");

    while (getline(customerFile, fileUsername) && getline(customerFile, filePassword))
    {
        if (username == fileUsername && password == filePassword)
        {
            return true;
        }
    }
    return false;
}

bool login(string role)
{
    string username, password;
    int attempt = 0;

    while (attempt < 3)
    {
        cout << (role == "admin" ? "Admin" : "Customer") << " Login:" << endl;
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter Password: ";
        getline(cin, password);

        if (role == "admin")
        {

            if (validLogin(username, password, adminUsername, adminPassword))
            {
                cout << "\nAdmin Login Successful! Welcome, Admin!" << endl;
                return true;
            }
        }
        else if (role == "customer")
        {

            if (customercredentials(username, password))
            {
                cout << "\nCustomer Login Successful! Welcome, " << username << "!" << endl;
                return true;
            }
        }

        cout << "Invalid credentials! You have " << 2 - attempt << " attempt(s) left." << endl;
        attempt++;

        if (attempt == 3)
        {

            cout << "Too many failed attempts. Do you want to try again? (y/n): ";
            char tryAgain;
            cin >> tryAgain;
            cin.ignore();

            if (tryAgain == 'n' || tryAgain == 'N')
            {
                cout << "Exiting system... Goodbye!" << endl;
                return false;
            }
            else
            {
                attempt = 0;
            }
        }
    }

    return false;
}

int main()
{
    int roleChoice;

    cout << "*** Welcome to MADI Movers ***" << endl;
    currentbusscount = 0;
    parmaBuses(); // Function to pre-load buses
    loadBuses();  // Load buses from file
    loadBookings();

    cout << "Enter (1) for Customer Login or (2) for Admin Login: ";
    cin >> roleChoice;
    cin.ignore(); // To clear the newline left by previous input

    string role;

    if (roleChoice == 1)
    {                                                // Customer login
        string loggedInUsername = customeraccount(); // Get the logged-in username

        if (loggedInUsername.empty())
        {
            // If the user exits without logging in, end the program
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        }

        // string customerUsername;
        // cout << "Enter your username So you can find your relevent Data as well.";
        // cin.ignore();
        // getline(cin, customerUsername);

        int choice;

        while (true)
        {
            customerMenu();

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                viewAvailbuses(); // Display available buses
                break;

            case 2:
                booktickets(loggedInUsername); // Pass customer username for booking
                break;

            case 3:
                viewbooking(loggedInUsername); // Pass customer username to view bookings
                break;

            case 4:
                cancelBooking(loggedInUsername); // Pass customer username for canceling booking
                break;

            case 5:
                cout << "Exiting customer login page. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid Choice. Please Try Again." << endl;
                break;
            }
        }
    }

    else if (roleChoice == 2)
    { // Admin login
        role = "admin";

        if (login(role))
        { // Admin login with predefined credentials
            int choice;
            while (true)
            {
                adminMenu(); // Display admin menu
                cout << "Enter Choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    addNewBus(); // Admin can add a new bus
                    break;

                case 2:
                    viewAvailbuses(); // View all available buses
                    break;

                case 3:
                    viewAdminBookings(); // View all customer bookings
                    break;

                case 4:
                    updateBusSchedule(); // Update bus schedules
                    break;

                case 5:
                    removeBus(); // Remove a bus from the list
                    break;

                case 6:
                    cout << "Exiting Admin login page. Goodbye!" << endl;
                    return 0;

                default:
                    cout << "Invalid choice. Please try again!" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid Credentials. Please Try again." << endl;
        }
    }
    else
    {
        cout << "Invalid choice! Exiting System." << endl;
    }

    return 0;
}
