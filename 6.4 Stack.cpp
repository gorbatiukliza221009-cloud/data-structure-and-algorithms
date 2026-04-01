#include <iostream>
#include <string>
using namespace std;

struct Team
{
    string name;
    string city;
    int points;
    Team* next;
};

Team* first = 0;
Team* last = 0;

// add to queue
void addToQueue(string name, string city, int points)
{
    Team* newNode = new Team;
    newNode->name = name;
    newNode->city = city;
    newNode->points = points;
    newNode->next = 0;

    if (first == 0)
    {
        first = last = newNode;
        return;
    }

    last->next = newNode;
    last = newNode;
}

// print queue
void showTeams(Team* first)
{
    if (first == 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Team* current = first;

    while (current != 0)
    {
        cout << current->name << ", "
             << current->city << ", "
             << current->points << endl;

        current = current->next;
    }
}

// find leader and outsider
void findLeaderAndOutsider(Team* first)
{
    if (first == 0)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Team* maxTeam = first;
    Team* minTeam = first;

    Team* current = first;

    while (current != 0)
    {
        if (current->points > maxTeam->points)
            maxTeam = current;

        if (current->points < minTeam->points)
            minTeam = current;

        current = current->next;
    }

    cout << "Leader: " << maxTeam->name << endl;
    cout << "Outsider: " << minTeam->name << endl;
}

// new queue (one team per city)
Team* createUniqueCityQueue(Team* first)
{
    Team* newFirst = 0;
    Team* newLast = 0;

    Team* current = first;

    while (current != 0)
    {
        bool found = false;
        Team* check = newFirst;

        while (check != 0)
        {
            if (check->city == current->city)
                found = true;

            check = check->next;
        }

        if (!found)
        {
            Team* newNode = new Team;
            newNode->name = current->name;
            newNode->city = current->city;
            newNode->points = current->points;
            newNode->next = 0;

            if (newFirst == 0)
                newFirst = newLast = newNode;
            else
            {
                newLast->next = newNode;
                newLast = newNode;
            }
        }

        current = current->next;
    }

    return newFirst;
}

// new queue (points > limit)
Team* createQueueWithMorePoints(Team* first, int limit)
{
    Team* newFirst = 0;
    Team* newLast = 0;

    Team* current = first;

    while (current != 0)
    {
        if (current->points > limit)
        {
            Team* newNode = new Team;
            newNode->name = current->name;
            newNode->city = current->city;
            newNode->points = current->points;
            newNode->next = 0;

            if (newFirst == 0)
                newFirst = newLast = newNode;
            else
            {
                newLast->next = newNode;
                newLast = newNode;
            }
        }

        current = current->next;
    }

    return newFirst;
}

// free memory
void clearQueue(Team* first)
{
    while (first)
    {
        Team* temp = first->next;
        delete first;
        first = temp;
    }
}

int main()
{
    int n;
    cout << "Enter number of teams: ";
    cin >> n;

    string name, city;
    int points;

    for (int i = 0; i < n; i++)
    {
        cout << "Team name: ";
        cin >> name;

        cout << "City: ";
        cin >> city;

        cout << "Points: ";
        cin >> points;

        addToQueue(name, city, points);
    }

    cout << endl << "All teams:" << endl;
    showTeams(first);

    cout << endl;
    findLeaderAndOutsider(first);

    Team* uniqueQueue = createUniqueCityQueue(first);

    cout << endl << "Unique teams (one per city):" << endl;
    showTeams(uniqueQueue);

    int limit;
    cout << endl << "Enter points limit: ";
    cin >> limit;

    Team* strongTeams = createQueueWithMorePoints(first, limit);

    cout << endl << "Teams with more points:" << endl;
    showTeams(strongTeams);

    clearQueue(first);
    clearQueue(uniqueQueue);
    clearQueue(strongTeams);

    return 0;
}