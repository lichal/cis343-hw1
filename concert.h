///////////////////////////////////////////////////////////////////
// Created by Cheng Li and Ryan Basso on 10/6/17.
//
// This class holds details of an upcoming Concert
///////////////////////////////////////////////////////////////////

#ifndef CPP_HW_CONCERT_H
#define CPP_HW_CONCERT_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctime>

/*******************************************************************
 * The class for all "Concert" objects
 ******************************************************************/
class Concert {
    private:
        // Who will be performing?
        std::string concertName;

        // A list of the people you want
        // to take with you.  May be empty
        // or arbitrarily full.
        std::vector<std::string> friends;

        // A value from 1-10 concerning how
        // badly you want to see this show.
        int desire;

        // The date of the show
        // See http://en.cppreference.com/w/cpp/chrono/c/tm
        std::tm date;

    public:
        Concert();
        Concert(std::string name, std::vector<std::string>friendNumbers,
                int desires, std::tm date2);
        std::string getConcertName();
        int getDesire();
        bool operator<(const Concert& other) const;
        friend std::ostream &operator<<(std::ostream& os,
                                        const Concert& event);
	std::tm getDate();
        ~Concert();

};

#endif //CPP_HW_CONCERT_H
