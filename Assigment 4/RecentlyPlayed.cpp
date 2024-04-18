#include "RecentlyPlayed.h"

RecentlyPlayedSongsList::RecentlyPlayedSongsList() : head(nullptr), tail(nullptr), current(nullptr) {}

void RecentlyPlayedSongsList::playSong(const string& name, int releaseDate) {
    Song* newSong = new Song(name, releaseDate);

        if (!head) { // Empty list
            head = tail = current = newSong;
        } else {
            // Add new song to the head (most recently played)
            newSong->setNext(head);
            head->setPrevious(newSong); // Set the previous pointer of the current head to the new song
            head = newSong;
        }
}

void RecentlyPlayedSongsList::moveBack() {
    if (!head || !current || current == head) {
            return; // No previous song or at the beginning
        }

        current = current->getPrevious(); // Move current pointer backward
}

void RecentlyPlayedSongsList::moveForward() {
    if (!current || !current->getNext()) {
            return; // No next song or at the end
        }

        current = current->getNext(); // Move current pointer forward
}

Song* RecentlyPlayedSongsList::getCurrentSong()const
{
    return current;
}

void RecentlyPlayedSongsList::recentlyPlayed()const
{
    cout << "Recently Played:" << endl;
    Song* temp = head; // Start from the head of the list

    while (temp) {
        cout << temp->getName() << endl;
        temp = temp->getNext(); // Move to the next song
    }

    cout<< endl;
}