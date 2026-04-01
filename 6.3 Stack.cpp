#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

struct Queue
{
    int value;
    Queue* next;
};

Queue* first = 0;
Queue* last = 0;

void addToQueue(int value)
{
    Queue* newNode = new Queue;
    newNode->value = value;
    newNode->next = 0;

    if (first == 0)
    {
        first = last = newNode;
        return;
    }

    last->next = newNode;
    last = newNode;
}

void showQueue(Queue* first)
{
    if (first == 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Queue* current = first;

    while (current != 0)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

Queue* processQueue(Queue* first, int insertValue)
{
    Queue* newFirst = 0;
    Queue* newLast = 0;

    while (first != 0)
    {
        Queue* temp = first;
        int value = temp->value;
        first = first->next;
        delete temp;
        if (value % 2 == 0)
        {
            Queue* newNode = new Queue;
            newNode->value = value;
            newNode->next = 0;

            if (newFirst == 0)
                newFirst = newLast = newNode;
            else
            {
                newLast->next = newNode;
                newLast = newNode;
            }

            newNode = new Queue;
            newNode->value = insertValue;
            newNode->next = 0;

            newLast->next = newNode;
            newLast = newNode;
        }
    }

    return newFirst;
}

double geometricMean(Queue* first)
{
    double product = 1;
    int count = 0;

    Queue* current = first;

    while (current != 0)
    {
        product *= current->value;
        count++;
        current = current->next;
    }

    if (count == 0) return 0;

    return pow(product, 1.0 / count);
}

void clearQueue(Queue* first)
{
    while (first)
    {
        Queue* temp = first->next;
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

    int insertValue = 100;

    for (int i = 0; i < n; i++)
    {
        int value = rand() % 10 + 1;
        addToQueue(value);
    }

    cout << "Queue:" << endl;
    showQueue(first);

    Queue* newQueue = processQueue(first, insertValue);

    cout << "New queue:" << endl;
    showQueue(newQueue);

    cout << "Geometric mean: " << geometricMean(newQueue) << endl;

    clearQueue(newQueue);

    return 0;
}