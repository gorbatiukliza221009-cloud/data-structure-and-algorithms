#include <iostream>
#include <string>
using namespace std;

struct Music
{
    string type;
    string name;
    string artist;
    double duration;
    int count;
    double price;
    Music* next;
};

Music* first = 0;

void addToStack(string type, string name, string artist, double duration, int count, double price)
{
    Music* newNode = new Music;
    newNode->type = type;
    newNode->name = name;
    newNode->artist = artist;
    newNode->duration = duration;
    newNode->count = count;
    newNode->price = price;
    newNode->next = first;
    first = newNode;
}

void showStack(Music* first)
{
    Music* current = first;

    while (current != 0)
    {
        cout << current->name << ", "
             << current->type << ", "
             << current->price<<"grn" << endl;

        current = current->next;
    }
}

double totalTimeByArtist(Music* first, string artistName)
{
    double sum = 0;
    Music* current = first;

    while (current != 0)
    {
        if (current->artist == artistName)
            sum += current->duration;

        current = current->next;
    }

    return sum;
}

Music* createCassetteStack(Music* first)
{
    Music* newStack = 0;
    Music* current = first;

    while (current != 0)
    {
        if (current->type == "cassette")
        {
            Music* newNode = new Music;
            newNode->type = current->type;
            newNode->name = current->name;
            newNode->artist = current->artist;
            newNode->duration = current->duration;
            newNode->count = current->count;
            newNode->price = current->price;
            newNode->next = newStack;
            newStack = newNode;
        }

        current = current->next;
    }

    return newStack;
}

double calculateAveragePrice(Music* first)
{
    double sum = 0;
    int count = 0;

    Music* current = first;

    while (current != 0)
    {
        sum += current->price;
        count++;
        current = current->next;
    }

    if (count == 0)
        return 0;

    return sum / count;
}

void clearStack(Music* first)
{
    while (first)
    {
        Music* temp = first->next;
        delete first;
        first = temp;
    }
}

int main()
{
    addToStack("cassette", "StilLovingYou", "Scorpions", 3.5, 10, 300);
    addToStack("cd", "H2LO", "Loboda", 4.5, 8, 500);
    addToStack("cassette", "Superstar", "Loboda", 5.0, 6, 200);

    cout << "Stack:" << endl;
    showStack(first);

    cout << endl;

    cout << "Total time for artist Loboda: "<< totalTimeByArtist(first, "Loboda") <<" min"<< endl;

    Music* newStack = createCassetteStack(first);

    cout << endl << "Cassette stack:" << endl;
    showStack(newStack);

    cout << "Average cassette price: "
         << calculateAveragePrice(newStack)<<"grn" << endl;

    clearStack(first);
    clearStack(newStack);

    return 0;
}