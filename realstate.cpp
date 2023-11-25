#include "realstate.h"

QString buildings::getAddress(){return _address;}
QString buildings::getName(){return _name;}
double buildings::getPrice(){return _price;}

buildings::buildings(){
    _address = "NaN";
    _name = "NaN";
    _price = 0.0;
}

buildings::buildings(QString add, QString name, double price){
    _address = add;
    _name = name;
    _price = price;
}

void buildings::operator =(buildings&& xCLass) {


    _address = std::move(xCLass._address);
    _name = std::move(xCLass._name);
    _price = std::move(xCLass._price);

    xCLass._address = xCLass._name = nullptr;
    xCLass._price = 0;
}

void buildings::fillBuildings(QString address, QString name, double price){
    _address = address;
    _name = name;
    _price = price;
}


owners::owners(){
    QString ownerName = "John";
    QString ownerSurname = "Dow";
    long ownerID = 0000000;
    double money= 000000.0;
    *buildInfo = nullptr;
}
owners::owners(QString name, QString surname, long ID, double money, buildings* b){
    ownerName = name;
    ownerSurname = surname;
    ownerID = ID;
    this->money = money;
    *buildInfo = b;
}

owners::~owners(){delete[] *buildInfo;}

void owners::fillOwner (QString name, QString surname, long ID, double money, int bID, buildings& b){
    ownerName = name;
    ownerSurname = surname;
    ownerID = ID;
    this->money = money;
    buildInfo[bID] = &b;
}

