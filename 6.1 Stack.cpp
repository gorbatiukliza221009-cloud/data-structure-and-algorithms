#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Stack
{
    double value;
    Stack* next;
};

Stack* first = 0;

void addToStack(double value)  //stack filling 
{
    Stack* newNode = new Stack;
    newNode->value = value;
    newNode->next = first;
    first = newNode;
}

void showStack(Stack* first) // Print all elements of Stack
{
    if (first == 0)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    Stack* current = first;

    while (current != 0)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

Stack* createNewStackWithoutNumbersLessThatGiven(Stack* first, double given)
{
    Stack* newStack = 0;
    Stack* current = first;

    while (current != 0)
    {
        if (current->value >= given)
        {
            Stack* newNode = new Stack;
            newNode->value = current->value;
            newNode->next = newStack;
            newStack = newNode;
        }

        current = current->next;
    }

    return newStack;
}

double calculateAverageAfterDeletion(Stack* first)  // Calculate average value of elements after deletion
{
    double sum = 0;
    int count = 0;

    Stack* current = first;

    while (current != 0)
    {
        sum += current->value;
        count++;
        current = current->next;
    }

    if (count == 0)
        return 0;

    return sum / count;
}

void clearStack(Stack* first)  // Free memory of Stack
{
    while (first)
    {
        Stack* temp = first->next;
        delete first;
        first = temp;
    }
}

int main()
{
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double value = -6 + (rand() / (double)RAND_MAX) * 17;
        addToStack(value);
    }

    cout << "Stack:" << endl;
    showStack(first);

    double given;
    cout << "Enter limit: ";
    cin >> given;

    Stack* newStack = createNewStackWithoutNumbersLessThatGiven(first, given);

    cout << "New stack:" << endl;
    showStack(newStack);

    cout << "Average: " << calculateAverageAfterDeletion(newStack) << endl;

    clearStack(first);
    clearStack(newStack);

    return 0;
}