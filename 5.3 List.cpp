#include <iostream>
#include <string>
using namespace std;

struct ListCar
{
    string name;
    int year;
    double price;     
    ListCar* next;  
};

ListCar* first = 0;
ListCar* last = 0;

ListCar* addLast(ListCar* first, string name, int year, double price)  // Add element to the end
{
    ListCar* newNode = new ListCar;
    newNode->name = name;
    newNode->year = year;
    newNode->price = price;
    newNode->next = 0;

    if (first == 0)
    {
        first = newNode;
        last = newNode;
        return first;
    }

    last->next = newNode;
    last = newNode;

    return first;
}

void showListCars(ListCar* first)  // Print all cars
{
    if (first == 0)
    {
        cout << "List is empty" << endl;
        return;
    }

    ListCar* current = first;

    while (current != 0)
    {
        cout << current->name << ", "
             << current->year << ", "
             << current->price << " $" << endl;

        current = current->next;
    }

    cout << endl;
}

void findOldAndCheapCars(ListCar* first, int currentYear, int ageLimit, double maxPrice)
{
    if (first == 0)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Cars older than " << ageLimit
         << " years and price < " << maxPrice << ":" << endl;

    ListCar* current = first;
    bool found = false;

    while (current != 0)
    {
        if ((currentYear - current->year > ageLimit) && current->price < maxPrice)
        {
            cout << current->name << ", "
                 << current->year << ", "
                 << current->price << " $" << endl;

            found = true;
        }

        current = current->next;
    }

    if (!found)
        cout << "No such cars found" << endl;
}

void clearList(ListCar* first)   // Free memory
{
    while (first)
    {
        ListCar* temp = first->next;
        delete first;
        first = temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of cars: ";
    cin >> n;

    string name;
    int year;
    double price;
    int currentYear = 2026;
    int ageLimit = 10;
    double maxPrice = 5000;

    for (int i = 0; i < n; i++)
    {
        cout << "Car name: ";
        cin >> name;

        cout << "Year: ";
        cin >> year;

        cout << "Price: ";
        cin >> price;

        first = addLast(first, name, year, price);
    }

    cout << endl << "----------------------" << endl;

    cout << "All cars:" << endl;
    showListCars(first);

    cout << endl;
    findOldAndCheapCars(first, currentYear, ageLimit, maxPrice);

    clearList(first);

    return 0;
}