#ifndef ROOM_H
#define ROOM_H

struct Room {
    int roomNumber;
    bool isAvailable;

    Room() : roomNumber(0), isAvailable(true) {}
    Room(int number, bool available) : roomNumber(number), isAvailable(available) {}
};

#endif
