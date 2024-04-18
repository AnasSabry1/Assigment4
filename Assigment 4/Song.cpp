#include "Song.h"

Song::Song(const string& Songname, int releaseDate) : name(Songname), releasedate(releaseDate), next(nullptr), previous(nullptr)
{
}

string Song::getName() const
{
    return name;
}

int Song::getReleaseDate() const
{
    return releasedate;
}

void Song::setNext(Song* nextSong)
{
    next = nextSong;
}

Song* Song::getNext() const
{
    return next;
}

void Song::setPrevious(Song* previousSong)
{
    previous = previousSong;
}

Song* Song::getPrevious() const
{
    return previous;
}