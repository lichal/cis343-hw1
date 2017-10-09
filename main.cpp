///////////////////////////////////////////////////////////////////
// Created by Cheng Li and Ryan Basso on 10/6/17.
//
// This file creates 10 Concerts, sorts them, and
// prints them out in order
///////////////////////////////////////////////////////////////////

#include "concert.h"

/*******************************************************************
 * This starts the program...
 *
 * @param argc Number of arguments
 * @param argv Command line arguments
 * @return '0' if program runs correctly
 ******************************************************************/
int main(int argc, char *argv[]) {
    // Holds the Concert items...
    std::vector<Concert> concertItems;

    // Set up times...
    time_t now = time(0) + 174287;
    time_t now2 = time(0) + 353931;
    time_t now3 = time(0) + 523415;
    time_t now4 = time(0) + 694781;
    time_t now5 = time(0) + 870519;
    time_t now6 = time(0) + 1038494;
    time_t now7 = time(0) + 1221656;
    time_t now8 = time(0) + 1391575;
    time_t now9 = time(0) + 1567616;
    time_t now10 = time(0) + 1736478;
    std::tm t = *gmtime(&now);
    std::tm t2 = *gmtime(&now2);
    std::tm t3 = *gmtime(&now3);
    std::tm t4 = *gmtime(&now4);
    std::tm t5 = *gmtime(&now5);
    std::tm t6 = *gmtime(&now6);
    std::tm t7 = *gmtime(&now7);
    std::tm t8 = *gmtime(&now8);
    std::tm t9 = *gmtime(&now9);
    std::tm t10 = *gmtime(&now10);

    // Create all the Concerts, put into vector...
    Concert *c1 = new Concert("The Smokey Bears", {"Friend1","Friend2",
        "Friend3"}, 1, t2);
    Concert *c2 = new Concert("Peanut & Jelly", {"Friend4","Friend5",
        "Friend6"}, 2, t2);
    Concert *c3 = new Concert("The Food Eaters", {"Friend7","Friend8",
        "Friend9"}, 3, t5);
    Concert *c4 = new Concert("Captain Scrunch", {"Friend10","Friend11",
        "Friend12"}, 4, t9);
    Concert *c5 = new Concert("The Squinters", {"Friend13","Friend14",
        "Friend15"}, 5, t);
    Concert *c6 = new Concert("Half-A-Steak", {"Friend16","Friend17",
        "Friend18"}, 6, t10);
    Concert *c7 = new Concert("Cliche Concert Name", {"Friend19",
        "Friend20","Friend21"}, 9, t4);
    Concert *c8 = new Concert("The Quiet Drummers", {"Friend22",
        "Friend23","Friend24"}, 4, t3);
    Concert *c9 = new Concert("Red Mustard", {"Friend25","Friend26",
        "Friend27"}, 9, t8);
    Concert *c10 = new Concert("Gimps R Us", {"Friend28","Friend29",
        "Friend30"}, 10, t7);
    concertItems.push_back(*c1);
    concertItems.push_back(*c2);
    concertItems.push_back(*c3);
    concertItems.push_back(*c4);
    concertItems.push_back(*c5);
    concertItems.push_back(*c6);
    concertItems.push_back(*c7);
    concertItems.push_back(*c8);
    concertItems.push_back(*c9);
    concertItems.push_back(*c10);

    // Sort all the Concerts... found tip at:
    // www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/algorithm/sort.html
    std::sort(std::begin(concertItems), std::end(concertItems));

    // Now print them all out...
    int size = 10;
    for (int i = 0; i < size; i++) {
        std::cout<<concertItems[i];
    }

    // Delete them all
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete c6;
    delete c7;
    delete c8;
    delete c9;
    delete c10;

    return 0;
}
