//
//  Code by Jacob "Andey" Tuttle
//  Last Update October 24, 2018
//  Liscenced under Mozilla Public Liscence 2.0
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <cmath>

using namespace std;

//function declarations
void recordData(float n, List* data [], int day);
void dailySummary(List* data [], int day);
void weeklySummary(List* data [], int day);

int main(){

    //preliminary variable initialization
    bool cont = true;
    string nextCommand;
    regex nums("-?[0-9]+([.][0-9]+)?");

    List* pastDays [14];
    for (int i = 0; i < 14; i++){
        pastDays[i] = new List;
    }
    int day = 0;

    //main program loop
    while (cont) {

        //prompt the user for input
        cout << "Enter a number to record a data entry, 'next' to go to the next day, \n'day' to get the daily summary, and 'week' to get the summary \nfrom the last 7 days" << endl;

        //get the user input for the command
        getline(cin, nextCommand);

        //check to see if the input is a number
        if (regex_match(nextCommand, nums)) {
            float inNum = stof(nextCommand);

            //only record if the value is positive and non-zero
            if (inNum > 0) {
                recordData(inNum, pastDays, day);
            }

        } else if (nextCommand == "d" || nextCommand == "Day" || nextCommand == "day") {
            //execute daily code
            dailySummary(pastDays, day % 14);

        } else if (nextCommand == "w" || nextCommand == "Week" || nextCommand == "week") {
            //execute weekly code
            weeklySummary(pastDays, day);

        } else if (nextCommand == "n" || nextCommand == "Next" || nextCommand == "next") {
            //move to the next day
            day++;

        } else if (nextCommand == "q" || nextCommand == "Quit" || nextCommand == "quit") {
            //execute quit code
            cout << endl << "Thank You." << endl;
            cont = false;
        }

        cout << endl << endl;
    }

    return 0;
}

//add an entry to the day
void recordData(float n, List* data [], int d) {

    List* today = data[d % 14];

    //if the day hasn't had an entry before, create a list for it
    if (d != today->day) {
        today->day = d;
    }

    //add data to the list
    today->addData(n);

}

//provide the daily summary of information
void dailySummary(List* data [], int day) {

    List* head;
    head = data[day % 14];

    cout << "The sum of all readings today: " << head->sum() << endl;
    cout << "The maximum value read today : " << head->max() << endl;
    cout << "The minimum value read today : " << head->min() << endl;
    cout << "The count of all values today: " << head->count() << endl;

}

//generate the weekly summary
void weeklySummary(List* data [], int day) {

    //error checks if you want a weekly summary before 7 days have been recorded
    int validDays;
    if (day < 7) {
        validDays = day + 1;
    } else {
        validDays = 7;
    }

    //fill this week with the last seven days. Today being in index 0 and 1 week ago in index 6
    List* thisWeek [validDays];
    for (int i = 0; i < validDays; i++) {
        thisWeek[i] = data[(day - i) % 14];
    }

    //calculate total sum of the week
    float totalSum = 0.f;
    for (int i = 0; i < validDays; i++) {
        List* today = thisWeek[i];
        totalSum += today->sum();
    }

    //find the maximum and minimum values for the week
    float max = 0.f;
    float min = numeric_limits<float>::max();
    for (int i = 0; i < validDays; i++) {
        List* today = thisWeek[i];

        if (today->max() > max) {
            max = today->max();
        }

        if (today->min() < min) {
            min = today->min();
        }
    }

    //find the count of readings taken this week
    int count = 0;
    for (int i = 0; i < validDays; i++) {
        List* today = thisWeek[i];
        count += today->count();
    }

    //find the deltas
    int deltaDay = 1;
    float delta = 0.f;
    for (int i = 1; i < validDays; i++) {
        List* today = thisWeek[i];
        List* yesterday = thisWeek[i - 1];

        if (abs(today->count() - yesterday->count()) > delta) {
            delta = abs(today->count() - yesterday->count());
            deltaDay = i;
        }
    }

    //full output of weekly summary
    cout << "The sum of all readings this week: " << totalSum << endl;
    cout << "The maximum of readings this week: " << max << endl;
    cout << "The minimum of readings this week: " << min << endl;
    cout << "The count of readings this week  : " << count << endl;
    cout << deltaDay << " day(s) ago, the delta was the greatest." << endl;

}
