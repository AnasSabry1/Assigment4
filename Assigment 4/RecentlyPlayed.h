#pragma once
#include <iostream>
#include "Song.h"

using namespace std;

class RecentlyPlayedSongsList {
public:
    RecentlyPlayedSongsList();
    void playSong(const string& Songname, int releaseDate);
    void moveBack();
    void moveForward();
    Song* getCurrentSong() const; // Return pointer to currently playing song
    void recentlyPlayed () const;


private:
    Song* head;
    Song* tail;
    Song* current;
};