#include "Defs.h"

Room::Room() {};
Room::~Room() {};

int Room::GetCoins15()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < GetRooms15(); i++)
    {
        _roomCoins = rand() % 100;
    }
   
    return _roomCoins;
}

int Room::GetCoins30()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < GetRooms30(); i++)
    {
        _roomCoins = rand() % 100;
    }

    return _roomCoins;
}

int Room::GetCoins45()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < GetRooms45(); i++)
    {
        _roomCoins = rand() % 100;
    }

    return _roomCoins;
}

int Room::GetRooms15()
{
    srand((unsigned)time(NULL));
    _roomCount = rand() % 30;
    
    return  _roomCount;
}

int Room::GetRooms30()
{
    srand((unsigned)time(NULL));
    _roomCount = rand() % 65;

    return  _roomCount;
}

int Room::GetRooms45()
{
    srand((unsigned)time(NULL));
    _roomCount = rand() % 110;

    return  _roomCount;
}



