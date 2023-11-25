#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "realstate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    build1.fillBuildings("SomeStreet 1", "VillaOnes", 1821.81);
    build2.fillBuildings("SomeStreet 2", "VillaOnesTwo", 1227.12);
    build3.fillBuildings("SomeStreet 3", "VillaOnesThree", 2821.61);
    build4.fillBuildings("SomeStreet 4", "VillaOnesFour", 17821.81);
    own1.fillOwner("James", "Bond", 0271612, 1961.2, 0, build1);
    own2.fillOwner("Adam", "Smyth", 0716241, 4812.2, 0, build2);
    own3.fillOwner("Martin", "King", 0316726, 872.2, 0, build3);
    own3.fillOwner("Martin", "Martin", 0316726, 872.2, 1, build4);

    ui->owner->addItem(own1.ownerName + " " + own1.ownerSurname);
    ui->owner->addItem(own2.ownerName + " " + own2.ownerSurname);
    ui->owner->addItem(own3.ownerName + " " + own3.ownerSurname);

    ui->onw1Ch->addItem(own1.ownerName + " " + own1.ownerSurname);
    ui->onw1Ch->addItem(own2.ownerName + " " + own2.ownerSurname);
    ui->onw1Ch->addItem(own3.ownerName + " " + own3.ownerSurname);

    ui->trade->setEnabled(false);
    ui->bldCh->setEnabled(false);
    ui->own2Ch->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myMove(owners& inp, owners& outp, int k){
    delete inp.buildInfo[k];

    inp.buildInfo[k] = std::move(outp.buildInfo[ui->bldCh->currentIndex() - 1]);

    outp.money += outp.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice();
    inp.money -= outp.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice();

    outp.buildInfo[ui->bldCh->currentIndex() - 1] = nullptr;

}

void MainWindow::on_trade_clicked()
{
    int k = 0;
    if(ui->onw1Ch->currentIndex() == 1){
        if(ui->own2Ch->currentIndex() == 2){
            if(own1.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice() <= own2.money){
                do{
                    k++;
                }while(own2.buildInfo[k] != nullptr);
                myMove(own2, own1, k);
                ui->status->setText("Status: transaction successfull!");
            }else{
                ui->status->setText("Status: transaction failed! Not enough money!");
            }
        }else if(ui->own2Ch->currentIndex() == 3){
            if(own1.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice() <= own3.money){
                do{
                    k++;
                }while(own3.buildInfo[k] != nullptr);
                myMove(own3, own1, k);
                ui->status->setText("Status: transaction successfull!");
            }else{
                ui->status->setText("Status: transaction failed! Not enough money!");
            }
        }
    }else if (ui->onw1Ch->currentIndex() == 2){
        if(ui->own2Ch->currentIndex() == 1){
            if(own2.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice() <= own1.money){
                do{
                    k++;
                }while(own1.buildInfo[k] != nullptr);
                myMove(own1, own2, k);
                ui->status->setText("Status: transaction successfull!");
            }else{
                ui->status->setText("Status: transaction failed! Not enough money!");
            }
        }else if(ui->own2Ch->currentIndex() == 3){
            if(own2.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice() <= own3.money){
                do{
                    k++;
                }while(own3.buildInfo[k] != nullptr);
                myMove(own3, own2, k);
                ui->status->setText("Status: transaction successfull!");
            }else{
                ui->status->setText("Status: transaction failed! Not enough money!");
            }
        }
    }else if (ui->onw1Ch->currentIndex() == 3){
        if(ui->own2Ch->currentIndex() == 1){
            if(own3.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice() <= own1.money){
                do{
                    k++;
                }while(own1.buildInfo[k] != nullptr);
                myMove(own1, own3, k);
                ui->status->setText("Status: transaction successfull!");
            }else{
                ui->status->setText("Status: transaction failed! Not enough money!");
            }
        }else if(ui->own2Ch->currentIndex() == 2){
            if(own3.buildInfo[ui->bldCh->currentIndex() - 1]->getPrice() <= own2.money){
                do{
                    k++;
                }while(own2.buildInfo[k] != nullptr);
                myMove(own2, own3, k);
                ui->status->setText("Status: transaction successfull!");
            }else{
                ui->status->setText("Status: transaction failed! Not enough money!");
            }
        }
    }
    ui->own2Ch->clear();
    ui->own2Ch->setEnabled(false);
    ui->bldCh->clear();
    ui->bldCh->setEnabled(false);
    ui->onw1Ch->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    close();

}


void MainWindow::on_owner_activated(int index)
{
    if (index == 0){
        ui->building->clear();
        ui->building->addItem("(none)");
        ui->buildAdd->clear();
        ui->buildName->clear();
        ui->buildPrice->clear();
        ui->ownName->clear();
        ui->ownSurname->clear();
        ui->ownID->clear();
        ui->ownMoney->clear();
    }else if (index == 1){
        ind = 0;
        ui->building->clear();
        ui->ownName->setText("Name: " + own1.ownerName);
        ui->ownSurname->setText("Surname: " + own1.ownerSurname);
        ui->ownID->setText("Owner ID: " + QString::number(own1.ownerID));
        ui->ownMoney->setText("Owner Money: " + QString::number(own1.money));
        for(int i = 0; own1.buildInfo[i] != nullptr; i++){
            ui->building->addItem(own1.buildInfo[i]->getName());
        }
    }else if (index == 2){
        ind = 1;
        ui->building->clear();
        ui->ownName->setText("Name: " + own2.ownerName);
        ui->ownSurname->setText("Surname: " + own2.ownerSurname);
        ui->ownID->setText("Owner ID: " + QString::number(own2.ownerID));
        ui->ownMoney->setText("Owner Money: " + QString::number(own2.money));
        for(int i = 0; own2.buildInfo[i] != nullptr; i++){
            ui->building->addItem(own2.buildInfo[i]->getName());
        }
    }else if (index == 3){
        ind = 2;
        ui->building->clear();
        ui->ownName->setText("Name: " + own3.ownerName);
        ui->ownSurname->setText("Surname: " + own3.ownerSurname);
        ui->ownID->setText("Owner ID: " + QString::number(own3.ownerID));
        ui->ownMoney->setText("Owner Money: " + QString::number(own3.money));
        for(int i = 0; own3.buildInfo[i] != nullptr; i++){
            ui->building->addItem(own3.buildInfo[i]->getName());
        }
    }


}


void MainWindow::on_building_activated(int index)
{
    switch (ind) {
    case 0:
        ui->buildAdd->setText("Building address: " + own1.buildInfo[index]->getAddress());
        ui->buildName->setText("Building name: " + own1.buildInfo[index]->getName());
        ui->buildPrice->setText("Building price: " + QString::number(own1.buildInfo[index]->getPrice()));
        break;
    case 1:
        ui->buildAdd->setText("Building address: " + own2.buildInfo[index]->getAddress());
        ui->buildName->setText("Building name: " + own2.buildInfo[index]->getName());
        ui->buildPrice->setText("Building price: " + QString::number(own2.buildInfo[index]->getPrice()));
        break;
    case 2:
        ui->buildAdd->setText("Building address: " + own3.buildInfo[index]->getAddress());
        ui->buildName->setText("Building name: " + own3.buildInfo[index]->getName());
        ui->buildPrice->setText("Building price: " + QString::number(own3.buildInfo[index]->getPrice()));
        break;
    default:
        break;
    }
}


void MainWindow::on_onw1Ch_activated(int index)
{
    if(index == 0) {
        ui->trade->setEnabled(false);
        ui->onw1Ch->clear();
        ui->onw1Ch->addItem("(none)");
        ui->bldCh->clear();
        ui->bldCh->addItem("none");
    }else if (index == 1){
        own = 0;
        ui->bldCh->setEnabled(true);
        ui->bldCh->clear();
        ui->bldCh->addItem("(none)");
        for(int i = 0; own1.buildInfo[i] != nullptr; i++){
            ui->bldCh->addItem(own1.buildInfo[i]->getName());
        }

    }else if (index == 2){
        own = 1;
        ui->bldCh->setEnabled(true);
        ui->bldCh->clear();
        ui->bldCh->addItem("(none)");
        for(int i = 0; own2.buildInfo[i] != nullptr; i++){
            ui->bldCh->addItem(own2.buildInfo[i]->getName());
        }
    }else if (index == 3){
        own = 2;
        ui->bldCh->setEnabled(true);
        ui->bldCh->clear();
        ui->bldCh->addItem("(none)");
        for(int i = 0; own3.buildInfo[i] != nullptr; i++){
            ui->bldCh->addItem(own3.buildInfo[i]->getName());
        }
    }
}


void MainWindow::on_own2Ch_activated(int index)
{
    if(index == 0){
        ui->trade->setEnabled(false);
        ui->status->setText("Status: ");
        ui->balance->setText("Balance: ");
    }else if(index == 1){
        ui->trade->setEnabled(true);
        ui->status->setText("Status: ");
        if(ui->onw1Ch->currentIndex() == index){
            ui->status->setText("Status: ERROR. Same owners!");
            ui->balance->setText("ERROR!");
            ui->trade->setEnabled(false);
        }else{
          ui->balance->setText("Balance: " + QString::number(own1.money));
        }
    }else if(index == 2){
        ui->trade->setEnabled(true);
        ui->status->setText("Status: ");
        ui->balance->setText("Balance: ");
        if(ui->onw1Ch->currentIndex() == index){
            ui->status->setText("Status: ERROR. Same owners!");
            ui->balance->setText("ERROR!");
            ui->trade->setEnabled(false);
        }else{
            ui->balance->setText("Balance: " + QString::number(own2.money));
        }

    }else if(index == 3){
        ui->trade->setEnabled(true);
        ui->status->setText("Status: ");
        ui->balance->setText("Balance: ");
        if(ui->onw1Ch->currentIndex() == index){
            ui->status->setText("Status: ERROR. Same owners!");
            ui->balance->setText("ERROR!");
            ui->trade->setEnabled(false);
        }else {
            ui->balance->setText("Balance: " + QString::number(own3.money));
        }

    }
}


void MainWindow::on_bldCh_activated(int index)
{
    if(index == 0) {
        ui->trade->setEnabled(false);
    }else{
        switch (own) {
        case 0:
            ui->own2Ch->setEnabled(true);
            ui->own2Ch->clear();
            ui->own2Ch->addItem("(none)");
            ui->own2Ch->addItem(own1.ownerName + " " + own1.ownerSurname);
            ui->own2Ch->addItem(own2.ownerName + " " + own2.ownerSurname);
            ui->own2Ch->addItem(own3.ownerName + " " + own3.ownerSurname);
            ui->priceToBuy->setText(QString::number(own1.buildInfo[index - 1]->getPrice()));
            break;
        case 1:
            ui->own2Ch->setEnabled(true);
            ui->own2Ch->clear();
            ui->own2Ch->addItem("(none)");
            ui->own2Ch->addItem(own1.ownerName + " " + own1.ownerSurname);
            ui->own2Ch->addItem(own2.ownerName + " " + own2.ownerSurname);
            ui->own2Ch->addItem(own3.ownerName + " " + own3.ownerSurname);
            ui->priceToBuy->setText(QString::number(own2.buildInfo[index - 1]->getPrice()));
            break;
        case 2:
            ui->own2Ch->setEnabled(true);
            ui->own2Ch->clear();
            ui->own2Ch->addItem("(none)");
            ui->own2Ch->addItem(own1.ownerName + " " + own1.ownerSurname);
            ui->own2Ch->addItem(own2.ownerName + " " + own2.ownerSurname);
            ui->own2Ch->addItem(own3.ownerName + " " + own3.ownerSurname);
            ui->priceToBuy->setText(QString::number(own3.buildInfo[index - 1]->getPrice()));
            break;
        default:
            ui->own2Ch->setEnabled(false);
            break;
        }
    }
}

