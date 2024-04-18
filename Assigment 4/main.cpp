#include <iostream>
#include <vector>
#include "Song.cpp"
#include "Playlist.cpp"
#include "RecentlyPlayed.cpp"

using namespace std;

int main() {
   // Create playlists
    Playlist playlist1;
    playlist1.addSong("Confident", 2021);
    playlist1.addSong("Father Time", 2022);
    playlist1.addSong("Dark Red", 2016);

    Playlist playlist2;
    playlist2.addSong("Save Your Tears", 2019);
    playlist2.addSong("505", 2012);
    playlist2.addSong("Tailwhip", 2018);

    Playlist playlist3;
    playlist3.addSong("Homage", 2016);

    Playlist playlist4;
    playlist4.addSong("The Color Violet", 2017);

    // Add playlists to a vector
    vector<Playlist> allPlaylists;
    allPlaylists.push_back(playlist1);
    allPlaylists.push_back(playlist2);
    allPlaylists.push_back(playlist3);
    allPlaylists.push_back(playlist4);

    // Demonstrate adding and removing songs from playlists
    playlist1.addSong("Mona Lisa", 2023);
    // playlist2.removeSong(playlist2.head->getNext()); // Remove second song

    cout << "Playlist 1:" << endl;
    playlist1.printPlaylist();

    cout << "Playlist 2:" << endl;
    playlist2.printPlaylist();

    // Merge playlists
    Playlist mergedPlaylist = Playlist::mergePlaylists(allPlaylists);

    cout << "\nMerged Playlist:" << endl;
    mergedPlaylist.printPlaylist();

    // Recently Played Songs List
    RecentlyPlayedSongsList recentSongs;

    recentSongs.playSong("Fly-Day Chinatown", 1990);
    recentSongs.playSong("Feel it", 2024);
    recentSongs.playSong("I Smoked My Brain Away", 2016);

    recentSongs.recentlyPlayed();

    // Navigate in the history
    recentSongs.moveBack();
    cout << "Playing Now: " << recentSongs.getCurrentSong()->getName() << endl;

    recentSongs.moveForward();
    recentSongs.moveForward();
    cout << "Playing Now: " << recentSongs.getCurrentSong()->getName() <<endl;

    return 0;
}