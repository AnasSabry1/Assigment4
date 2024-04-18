#include "Playlist.h"
#include <iostream>
using namespace std;

Playlist::Playlist() : head(nullptr), tail(nullptr) {}



void Playlist::addSong(const string& Songname, int releaseDate) {
    Song* newSong = new Song(Songname, releaseDate);

    if (!head) {
        head = tail = newSong;
        return;
    }

    // Maintain sorted order based on release date
    Song* current = head;
    Song* prev = nullptr;
    while (current && current->getReleaseDate() < releaseDate) {
        prev = current;
        current = current->getNext();
    }

    if (!prev) { // Insert at the beginning
        newSong->setNext(head);
        head = newSong;
    } else if (!current) { // Insert at the end
        tail->setNext(newSong);
        tail = newSong;
    } else { // Insert in the middle
        prev->setNext(newSong);
        newSong->setNext(current);
    }
}

void Playlist::removeSong(Song* song) {
    if (!head) {
        return; // Playlist is empty
    }

    Song* prev = nullptr;
    Song* current = head;

    if (current == song) { // Remove head
        head = current->getNext();
        delete song;
        return;
    }

    while (current && current != song) {
        prev = current;
        current = current->getNext();
    }

    if (!current) {
        return; // Song not found
    }

    if (current == tail) { // Remove tail
        tail = prev;
    }
    prev->setNext(current->getNext());
    delete song;
}

void Playlist::printPlaylist() const {
    Song* current = head;
    while (current) {
        cout << current->getName() << " (" << current->getReleaseDate() << ")" << endl;
        current = current->getNext();
    }
    cout << endl;
}

// Function to merge playlists (implementation)
Playlist Playlist::mergePlaylists(const vector<Playlist>& playlists) {
    Playlist mergedPlaylist;

    // Iterate through each playlist and add songs to the merged list
    for (const Playlist& playlist : playlists) {
        Song* current = playlist.head;
        while (current) {
            mergedPlaylist.addSong(current->getName(), current->getReleaseDate());
            current = current->getNext();
        }
    }

    return mergedPlaylist;
}
