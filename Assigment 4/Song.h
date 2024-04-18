#pragma once
#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    Song(const string&, int);

    string getName() const;
    int getReleaseDate() const;
    Song* getNext() const;
    void setNext(Song* next);
    Song* getPrevious() const;
    void setPrevious(Song* next);

private:
    string name;
    int releasedate;
    Song* next;
    Song* previous;
};