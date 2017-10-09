///////////////////////////////////////////////////////////////////
// Created by Cheng Li and Ryan Basso on 10/6/17.
//
// This file implements the Concert class
///////////////////////////////////////////////////////////////////

#include "concert.h"

/*******************************************************************
 * Default constructor for Concert objects
 ******************************************************************/
Concert::Concert() {

}

/*******************************************************************
 *  More flexible constructor for Concert objects that allows
 * @param name The name of the concert
 * @param friendNumbers Tag-along buddies
 * @param desires How badly you want to go
 * @param date2 The date for jamming
 ******************************************************************/
Concert::Concert(std::string name,
                 std::vector<std::string> friendNumbers,
                 int desires, std::tm date2) {
    concertName = name;
    friends = friendNumbers;
    desire = desires;
    date = date2;
}

/*******************************************************************
 * This gives the name of the Concert
 *
 * @return The Concert's name
 ******************************************************************/
std::string Concert::getConcertName(){
    return concertName;
}

/*******************************************************************
 * This gives a number signifying how badly you want to attend
 * this Concert (higher number = higher desire)
 *
 * @return Your desire to attend this Concert
 ******************************************************************/
int Concert::getDesire() {
    return desire;
}

/*******************************************************************
 * This gives the date of the event
 *
 * @return The date when the concert occurs
 ******************************************************************/
std::tm Concert::getDate() {
    return date;
}

//Got help with this one on:
//https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
/*******************************************************************
 * Overrides the << operator, and make a toString for the concert.
 *
 * @param os The stream to ouput to
 * @param concertIn The Concert to print
 * @return What it prints
 ******************************************************************/
std::ostream& operator<<(std::ostream & os, const Concert & concertIn){
    int day = concertIn.date.tm_mday;
    int month = concertIn.date.tm_mon;
    int year = concertIn.date.tm_year;

    os << "\n" << concertIn.concertName << " | Desire: "
       << concertIn.desire;
    os << " | Date: ";
    os << month << "/" << day << "/" << year + 1900 << "\n";
    os << "\tFriends: \n";
    int size = concertIn.friends.size();
    for(int i = 0; i < size; i++){
        os << "\t\t" <<concertIn.friends[i] << "\n";
    }
    return os;
}

/*******************************************************************
 * This function compares this Concert against another
 * to see which one should come first
 *
 * @param other The Concert to compare this Concert against
 * @return True if the host Concert is ranked before 'other'
 ******************************************************************/
bool Concert::operator<(const Concert &other) const {
    if(date.tm_year > other.date.tm_year) {
        return false;
    } else if(date.tm_year < other.date.tm_year) {
        return true;
    } else {
        if(date.tm_yday > other.date.tm_yday) {
            return false;
        } else if(date.tm_yday < other.date.tm_yday) {
            return true;
        } else {
            if(date.tm_hour > other.date.tm_hour){
                return false;
            } else if(date.tm_hour < other.date.tm_hour) {
                return true;
            } else {
                if(date.tm_min > other.date.tm_min){
                    return false;
                } else if(date.tm_min < other.date.tm_min) {
                    return true;
                } else {
                    if(date.tm_sec > other.date.tm_sec){
                        return false;
                    } else if(date.tm_sec < other.date.tm_sec){
                        return true;
                    } else {
                        if(desire < other.desire){
                            return false;
                        } else if (desire > other.desire){
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
    }
}

Concert::~Concert() {

}
