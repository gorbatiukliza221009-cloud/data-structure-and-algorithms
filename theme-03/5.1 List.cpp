#include <iostream>
#include <string>
using namespace std;

struct List
{
    int value;     
    List* next;  
};

List* first = 0;
List* last = 0;

List* addFirst(List* first, int value) // Add element to the beginning
{
    List* newNode = new List;
    newNode->value = value;
    newNode->next = first;
    first = newNode;

    if (last == 0)
    last = first;

    return first;
}

List* addLast(List* first, int value) // Add element to the end
{
    List* newNode = new List;
    newNode->value = value;
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

List* addAfter(List* first, int afterValue, int newValue) // Insert element after given value
{
    List* current = first;

    while (current != 0 && current->value != afterValue)
        current = current->next;

    if (current == 0)
    {
        cout << "Value not found" << endl;
        return first;
    }

    List* newNode = new List;
    newNode->value = newValue;
    newNode->next = current->next;
    current->next = newNode;

    return first;
}

void showList(List* first) // Print all elements of list
{
    if (first == 0)
    {
        cout << "List is empty" << endl;
        return;
    }
    
    List* current = first;

    while (current != 0)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

double calculateAverage(List* first)  // Calculate average value of elements
{
    int sum = 0;
    int count = 0;
    List* current = first;

    while (current != 0)
    {
        sum += current->value;
        count++;
        current = current->next;
    }

    if (count == 0)
        return 0;

    return (double)sum / count;
}

List* deleteFirstEven(List* first)  // Delete first even element
{
    if (first == 0)
    return first;

    if (first->value % 2 == 0)
    {
        List* temp = first;
        first = first->next;
        delete temp;
        return first;
    }

    List* current = first;

    while (current->next != 0)
    {
        if (current->next->value % 2 == 0)
        {
            List* temp = current->next;
            current->next = temp->next;
            delete temp;
            return first;
        }
        current = current->next;
    }

    return first;
}

void clearList(List* first)  // Free memory of list
{
    while (first)
    {
        List* temp = first->next;
        delete first;
        first = temp;
    }
}

int main()
{
    first = addFirst(first, 5);
    first = addLast(first, 10);
    first = addAfter(first, 5, 7);
    first = addLast(first, 3);

    cout << "List:" << endl;
    showList(first);

    cout << "Average value: " << calculateAverage(first) << endl;

    first = deleteFirstEven(first);
    cout << "After deleting first even element:" << endl;
    showList(first);

    clearList(first);

    return 0;
}