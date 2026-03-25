#include <iostream>
#include <string>
using namespace std;

struct ListCity
{
    string name;
    double distance;     
    ListCity* next;  
};

ListCity* first = 0;
ListCity* last = 0;

ListCity* addLast(ListCity* first, string name, double distance) // Add element to the end
{
    ListCity* newNode = new ListCity;
    newNode->name = name;
    newNode->distance = distance;
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

void showListCities(ListCity* first) // Print all elements of list
{
    if (first == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    
    ListCity* current = first;

    while (current != 0)
    {
        cout << current->name << ", "<<current->distance<<"km."<<endl;
        current = current->next;
    }
    cout << endl;
}

void findFarthestCities(ListCity* first, int amount)
{
    if (first == 0)
    {
        cout << "List is empty" << endl;
        return;
    }

    double previousMax = 1000000000;

    cout << amount << " the farthest cities:" << endl;

    for (int i = 0; i < amount; i++)
    {
        ListCity* current = first;
        ListCity* maxCity = 0;

        while (current != 0)
        {
            if (current->distance < previousMax)
            {
                if (maxCity == 0 || current->distance > maxCity->distance)
                {
                    maxCity = current;
                }
            }
            current = current->next;
        }

        if (maxCity == 0)
            break;

        cout << maxCity->name << ", " << maxCity->distance << " km" << endl;

        previousMax = maxCity->distance;
    }
}

void clearList(ListCity* first)  // Free memory of list
{
    while (first)
    {
        ListCity* temp = first->next;
        delete first;
        first = temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    string name;
    double distance;

    for (int i = 0; i < n; i++)
    {
        cout << "City name: ";
        cin >> name;

        cout << "Distance from Kyiv: ";
        cin >> distance;

        first = addLast(first, name, distance);
    }

    cout << endl << "----------------------" << endl;

    cout << "All cities:" << endl;
    showListCities(first);

    cout << endl;
    findFarthestCities(first, 2);

    cout << endl << "Add foreign city:" << endl;
    cout << "City name: ";
    cin >> name;

    cout << "Distance from Kyiv: ";
    cin >> distance;

    first = addLast(first, name, distance);

    cout << endl << "Updated list:" << endl;
    showListCities(first);

    clearList(first);

    return 0;
}