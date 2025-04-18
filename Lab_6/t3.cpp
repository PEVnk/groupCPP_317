/**************************************************************************************
 * Filename: t3.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 6
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ������� 3
 * ************************************************************************************/


#include <iostream>
#include "autobasa.h"
#include <algorithm>


// ��������� ��⮤�� ����� Automobile
Automobile::Automobile(const std::string& model)
  : model(model), status(CarStatus::OK) {}

std::string Automobile::getModel() const { return model; }
CarStatus Automobile::getStatus() const { return status; }

void Automobile::setStatus(CarStatus newStatus) { status = newStatus; }

void Automobile::displayInfo() const {
  std::cout << "��⮬�����: " << model << ", �����: " << static_cast<int>(status) << std::endl;
}

// ��������� ��⮤�� ����� Driver
Driver::Driver(const std::string& name, int id)
  : name(name), id(id), status(DriverStatus::AVAILABLE), assignedCar(nullptr) {}

std::string Driver::getName() const { return name; }
int Driver::getId() const { return id; }
DriverStatus Driver::getStatus() const { return status; }
Automobile* Driver::getAssignedCar() const { return assignedCar; }

void Driver::requestRepair() {
  if (assignedCar) {
    std::cout << "����⥫� " << name << " ����ᨫ ६��� ��⮬����� "
                  << assignedCar->getModel() << std::endl;
    assignedCar->setStatus(CarStatus::NEED_REPAIR);
  } else {
    std::cout << "� ����⥫� " << name << " ��� �����祭���� ��⮬�����" << std::endl;
  }
}

void Driver::completeTrip(bool carDamaged) {
  if (assignedCar) {
    if (carDamaged) {
      assignedCar->setStatus(CarStatus::NEED_REPAIR);
      std::cout << "���� �����襭. ��⮬����� �ॡ�� ६���." << std::endl;
    } else {
      assignedCar->setStatus(CarStatus::OK);
      std::cout << "���� �����襭 �ᯥ譮. ��⮬����� � ��襬 ���ﭨ�." << std::endl;
    }
  }
  status = DriverStatus::AVAILABLE;
}

void Driver::assignCar(Automobile* car) {
  assignedCar = car;
  std::cout << "����⥫� " << name << " �����祭 ��⮬����� " << car->getModel() << std::endl;
}

void Driver::suspend() {
  status = DriverStatus::SUSPENDED;
  std::cout << "����⥫� " << name << " ����࠭�� �� ࠡ���." << std::endl;
}

void Driver::reinstate() {
  status = DriverStatus::AVAILABLE;
  std::cout << "����⥫� " << name << " ����⠭����� � ��������." << std::endl;
}

void Driver::displayInfo() const {
  std::cout << "����⥫�: " << name << " (ID: " << id << "), �����: "
              << static_cast<int>(status);
  if (assignedCar) {
    std::cout << ", ��⮬�����: " << assignedCar->getModel();
  }
  std::cout << std::endl;
}

// ��������� ��⮤�� ����� Trip
Trip::Trip(int id, const std::string& dest, const std::string& cargo)
  : id(id), destination(dest), cargo(cargo), status(TripStatus::IN_PROGRESS),
  assignedDriver(nullptr), assignedCar(nullptr) {}

int Trip::getId() const { return id; }
std::string Trip::getDestination() const { return destination; }
std::string Trip::getCargo() const { return cargo; }
TripStatus Trip::getStatus() const { return status; }
Driver* Trip::getAssignedDriver() const { return assignedDriver; }
Automobile* Trip::getAssignedCar() const { return assignedCar; }


void Trip::startTrip(Driver* driver, Automobile* car) {
  assignedDriver = driver;
  assignedCar = car;
  driver->assignCar(car);
  if (assignedDriver && assignedCar) {
    status = TripStatus::IN_PROGRESS;
    std::cout << "���� #" << id << " ���� � �����祭 ����⥫� " << driver->getName()
                  << " �� ��⮬����� " << car->getModel() << std::endl;
  } else {
    std::cout << "���������� ����� ३� - �� �����祭 ����⥫� ��� ��⮬�����." << std::endl;
  }
}

void Trip::completeTrip(bool carDamaged) {
  status = TripStatus::COMPLETED;
  if (assignedDriver) {
    assignedDriver->completeTrip(carDamaged);
  }
  std::cout << "���� #" << id << " �����襭." << std::endl;
}

void Trip::cancelTrip() {
  status = TripStatus::CANCELLED;
  std::cout << "���� #" << id << " �⬥���." << std::endl;
}

void Trip::displayInfo() const {
  std::cout << "���� #" << id << ": " << destination << ", ���: " << cargo
              << ", �����: " << static_cast<int>(status);
  if (assignedDriver) {
    std::cout << ", ����⥫�: " << assignedDriver->getName();
  }
  if (assignedCar) {
    std::cout << ", ��⮬�����: " << assignedCar->getModel();
  }
  std::cout << std::endl;
}

// ��������� ��⮤�� ����� Dispatcher
Dispatcher::Dispatcher(const std::string& name) : name(name) {}

void Dispatcher::addDriver(Driver* driver) {
  drivers.push_back(driver);
  std::cout << "��ᯥ��� " << name << " ������� ����⥫� " << driver->getName() << std::endl;
}

void Dispatcher::addAutomobile(Automobile* autoMobile) {
  automobiles.push_back(autoMobile);
  std::cout << "��ᯥ��� " << name << " ������� ��⮬����� "
              << autoMobile->getModel() << std::endl;
}

Trip* Dispatcher::createTrip(int id, const std::string& dest, const std::string& cargo) {
  Trip* trip = new Trip(id, dest, cargo);
  trips.push_back(trip);
  std::cout << "��ᯥ��� " << name << " ᮧ��� ३� #" << id << " � " << dest << std::endl;
  return trip;
}

void Dispatcher::assignTrip(Trip* trip, Driver* driver, Automobile* autoMobile) {
  if (driver && autoMobile) {
    trip->startTrip(driver, autoMobile);
  } else {
    std::cout << "�� 㤠���� �������� ३� - ��������� ����⥫� ��� ��⮬�����." << std::endl;
  }
}

void Dispatcher::suspendDriver(Driver* driver) {
  auto it = std::find(drivers.begin(), drivers.end(), driver);
  if (it != drivers.end()) {
    (*it)->suspend();
  } else {
    std::cout << "����⥫� �� ������." << std::endl;
  }
}

void Dispatcher::reinstateDriver(Driver* driver) {
  auto it = std::find(drivers.begin(), drivers.end(), driver);
  if (it != drivers.end()) {
    (*it)->reinstate();
  } else {
    std::cout << "����⥫� �� ������." << std::endl;
  }
}

void Dispatcher::displayAllDrivers() const {
  std::cout << "���᮪ ��� ����⥫��:" << std::endl;
  for (const auto& driver : drivers) {
    driver->displayInfo();
  }
}

void Dispatcher::displayAllAutomobiles() const {
  std::cout << "���᮪ ��� ��⮬������:" << std::endl;
  for (const auto& autoMobile : automobiles) {
    autoMobile->displayInfo();
  }
}

void Dispatcher::displayAllTrips() const {
  std::cout << "���᮪ ��� ३ᮢ:" << std::endl;
  for (const auto& trip : trips) {
    trip->displayInfo();
  }
}
