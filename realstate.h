#ifndef REALSTATE_H
#define REALSTATE_H

#include <QString>

class buildings
{
    QString _address;
    QString _name;
    double _price;
public:
    QString getAddress();
    QString getName();
    double getPrice();

    buildings();

    buildings(QString add, QString name, double price);

    buildings(buildings&& xCLass): _address(xCLass._address), _name(xCLass._name), _price(xCLass._price){
        xCLass._address = xCLass._name = nullptr;
        xCLass._price = 0;
    }

    void operator =(buildings&& xCLass);

    void fillBuildings(QString address, QString name, double price);

};




class owners
{

public:

    QString ownerName;
    QString ownerSurname;
    long ownerID;
    double money;
    buildings* buildInfo [10] {nullptr};

    owners();
    owners(QString name, QString surname, long ID, double money, buildings* b);

    owners(owners&& k) = default;

    ~owners();

    void fillOwner (QString name, QString surname, long ID, double money, int bID, buildings& b);

};

#endif // REALSTATE_H
