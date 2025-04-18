/**************************************************************************************
 * Filename: t3.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 6
 * Исследование С++ классов в IDE Qt Creator
 * Задание 3
 * ************************************************************************************/


#include <iostream>
#include "autobasa.h"
#include <algorithm>


// Реализация методов класса Automobile
Automobile::Automobile(const std::string& model)
  : model(model), status(CarStatus::OK) {}

std::string Automobile::getModel() const { return model; }
CarStatus Automobile::getStatus() const { return status; }

void Automobile::setStatus(CarStatus newStatus) { status = newStatus; }

void Automobile::displayInfo() const {
  std::cout << "Автомобиль: " << model << ", статус: " << static_cast<int>(status) << std::endl;
}

// Реализация методов класса Driver
Driver::Driver(const std::string& name, int id)
  : name(name), id(id), status(DriverStatus::AVAILABLE), assignedCar(nullptr) {}

std::string Driver::getName() const { return name; }
int Driver::getId() const { return id; }
DriverStatus Driver::getStatus() const { return status; }
Automobile* Driver::getAssignedCar() const { return assignedCar; }

void Driver::requestRepair() {
  if (assignedCar) {
    std::cout << "Водитель " << name << " запросил ремонт автомобиля "
                  << assignedCar->getModel() << std::endl;
    assignedCar->setStatus(CarStatus::NEED_REPAIR);
  } else {
    std::cout << "У водителя " << name << " нет назначенного автомобиля" << std::endl;
  }
}

void Driver::completeTrip(bool carDamaged) {
  if (assignedCar) {
    if (carDamaged) {
      assignedCar->setStatus(CarStatus::NEED_REPAIR);
      std::cout << "Рейс завершен. Автомобиль требует ремонта." << std::endl;
    } else {
      assignedCar->setStatus(CarStatus::OK);
      std::cout << "Рейс завершен успешно. Автомобиль в хорошем состоянии." << std::endl;
    }
  }
  status = DriverStatus::AVAILABLE;
}

void Driver::assignCar(Automobile* car) {
  assignedCar = car;
  std::cout << "Водителю " << name << " назначен автомобиль " << car->getModel() << std::endl;
}

void Driver::suspend() {
  status = DriverStatus::SUSPENDED;
  std::cout << "Водитель " << name << " отстранен от работы." << std::endl;
}

void Driver::reinstate() {
  status = DriverStatus::AVAILABLE;
  std::cout << "Водитель " << name << " восстановлен в должности." << std::endl;
}

void Driver::displayInfo() const {
  std::cout << "Водитель: " << name << " (ID: " << id << "), статус: "
              << static_cast<int>(status);
  if (assignedCar) {
    std::cout << ", автомобиль: " << assignedCar->getModel();
  }
  std::cout << std::endl;
}

// Реализация методов класса Trip
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
    std::cout << "Рейс #" << id << " начат и назначен водитель " << driver->getName()
                  << " на автомобиле " << car->getModel() << std::endl;
  } else {
    std::cout << "Невозможно начать рейс - не назначен водитель или автомобиль." << std::endl;
  }
}

void Trip::completeTrip(bool carDamaged) {
  status = TripStatus::COMPLETED;
  if (assignedDriver) {
    assignedDriver->completeTrip(carDamaged);
  }
  std::cout << "Рейс #" << id << " завершен." << std::endl;
}

void Trip::cancelTrip() {
  status = TripStatus::CANCELLED;
  std::cout << "Рейс #" << id << " отменен." << std::endl;
}

void Trip::displayInfo() const {
  std::cout << "Рейс #" << id << ": " << destination << ", груз: " << cargo
              << ", статус: " << static_cast<int>(status);
  if (assignedDriver) {
    std::cout << ", водитель: " << assignedDriver->getName();
  }
  if (assignedCar) {
    std::cout << ", автомобиль: " << assignedCar->getModel();
  }
  std::cout << std::endl;
}

// Реализация методов класса Dispatcher
Dispatcher::Dispatcher(const std::string& name) : name(name) {}

void Dispatcher::addDriver(Driver* driver) {
  drivers.push_back(driver);
  std::cout << "Диспетчер " << name << " добавил водителя " << driver->getName() << std::endl;
}

void Dispatcher::addAutomobile(Automobile* autoMobile) {
  automobiles.push_back(autoMobile);
  std::cout << "Диспетчер " << name << " добавил автомобиль "
              << autoMobile->getModel() << std::endl;
}

Trip* Dispatcher::createTrip(int id, const std::string& dest, const std::string& cargo) {
  Trip* trip = new Trip(id, dest, cargo);
  trips.push_back(trip);
  std::cout << "Диспетчер " << name << " создал рейс #" << id << " в " << dest << std::endl;
  return trip;
}

void Dispatcher::assignTrip(Trip* trip, Driver* driver, Automobile* autoMobile) {
  if (driver && autoMobile) {
    trip->startTrip(driver, autoMobile);
  } else {
    std::cout << "Не удалось назначить рейс - отсутствует водитель или автомобиль." << std::endl;
  }
}

void Dispatcher::suspendDriver(Driver* driver) {
  auto it = std::find(drivers.begin(), drivers.end(), driver);
  if (it != drivers.end()) {
    (*it)->suspend();
  } else {
    std::cout << "Водитель не найден." << std::endl;
  }
}

void Dispatcher::reinstateDriver(Driver* driver) {
  auto it = std::find(drivers.begin(), drivers.end(), driver);
  if (it != drivers.end()) {
    (*it)->reinstate();
  } else {
    std::cout << "Водитель не найден." << std::endl;
  }
}

void Dispatcher::displayAllDrivers() const {
  std::cout << "Список всех водителей:" << std::endl;
  for (const auto& driver : drivers) {
    driver->displayInfo();
  }
}

void Dispatcher::displayAllAutomobiles() const {
  std::cout << "Список всех автомобилей:" << std::endl;
  for (const auto& autoMobile : automobiles) {
    autoMobile->displayInfo();
  }
}

void Dispatcher::displayAllTrips() const {
  std::cout << "Список всех рейсов:" << std::endl;
  for (const auto& trip : trips) {
    trip->displayInfo();
  }
}
