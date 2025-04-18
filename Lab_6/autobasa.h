/**************************************************************************************
 * Filename: autobasa.h
 * Developer: Perkova Elena
 * Description: Лабораторная 6 задание 3
 * Исследование С++ классов в IDE Qt Creator
 * ************************************************************************************/

#ifndef AUTOBASA_H
#define AUTOBASA_H


#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

// Перечисления для статусов
enum class CarStatus {
  OK,
  NEED_REPAIR
};

enum class DriverStatus {
  AVAILABLE,
  SUSPENDED
};

enum class TripStatus {
  IN_PROGRESS,
  COMPLETED,
  CANCELLED
};

// Класс Автомобиль
class Automobile {
private:
  std::string model;
  CarStatus status;

public:
  Automobile(const std::string& model);
  std::string getModel() const;
  CarStatus getStatus() const;

  void setStatus(CarStatus newStatus);
  void displayInfo() const;
};

// Класс Водитель
class Driver {
private:
  std::string name;
  int id;
  DriverStatus status;
  Automobile* assignedCar;

public:
  Driver(const std::string& name, int id);

  std::string getName() const;
  int getId() const;
  DriverStatus getStatus() const;
  Automobile* getAssignedCar() const;

  void requestRepair();
  void completeTrip(bool carDamaged);
  void assignCar(Automobile* car);
  void suspend();
  void reinstate();
  void displayInfo() const;
};

// Класс Рейс
class Trip {
private:
  int id;
  std::string destination;
  std::string cargo;
  TripStatus status;
  Driver* assignedDriver;
  Automobile* assignedCar;

public:
  Trip(int id, const std::string& dest, const std::string& cargo);

  int getId() const;
  std::string getDestination() const;
  std::string getCargo() const;
  TripStatus getStatus() const;
  Driver* getAssignedDriver() const;
  Automobile* getAssignedCar() const;

  void startTrip(Driver* driver, Automobile* car);
  void completeTrip(bool carDamaged);
  void cancelTrip();
  void displayInfo() const;
};

// Класс Диспетчер
class Dispatcher {
private:
  std::string name;
  std::vector<Driver*> drivers;
  std::vector<Automobile*> automobiles;
  std::vector<Trip*> trips;

public:
  Dispatcher(const std::string& name);

  void addDriver(Driver* driver);
  void addAutomobile(Automobile* autoMobile);
  Trip* createTrip(int id, const std::string& dest, const std::string& cargo);

  void assignTrip(Trip* trip, Driver* driver, Automobile* autoMobile);
  void suspendDriver(Driver* driver);
  void reinstateDriver(Driver* driver);

  void displayAllDrivers() const;
  void displayAllAutomobiles() const;
  void displayAllTrips() const;
};

#endif // AUTOBASE_H

