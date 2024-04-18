#pragma once
#include "Song.h"
#include <iostream>
#include <vector>

using namespace std;

class Playlist {
public:
    Playlist();
    void addSong(const string&, int);
    void removeSong(Song* song); // Takes pointer to the song to remove
    void printPlaylist() const;

    // Function to merge playlists (implementation in Playlist.cpp)
    static Playlist mergePlaylists(const vector<Playlist>& playlists);

   
private:
    Song* head;
    Song* tail;
};


