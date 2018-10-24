//
//  Code by Jacob "Andey" Tuttle
//  Last Update October 9, 2018
//  Liscenced under Mozilla Public Liscence 2.0
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

//function declarations
void recordData(float n, List* data [], int day);
void dailySummary(List* data [], int day);
void weeklySummary();

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
            weeklySummary();

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

void recordData(float n, List* data [], int d) {

    List* today = data[d % 14];
    cout << today->first << " " << today->day << endl;

    //if the day hasn't been made before
    if (d != today->day) {
        cout << "new thing" << endl;
        today->day = d;
    }

    today->addData(n);

}

void dailySummary(List* data [], int day) {

    List* head;
    head = data[day % 14];

    cout << "The sum of all readings today: " << head->sum() << endl;

}

void weeklySummary() {

}
