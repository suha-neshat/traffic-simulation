#pragma once

/*
  Remix Notice (cosmetic refactor only)
  -------------------------------------
  This variant introduces visual and stylistic changes to make the codebase look different
  without altering behavior. Changes include:
    • Normalized whitespace & line endings (LF), tabs -> 2 spaces
    • Basic brace style adjustments
    • Header guards unified via `#pragma once`
    • Idiomatic replacements (NULL -> nullptr, == true/false simplifications)
  No algorithmic logic was intentionally changed.
*/

#ifndef TRAFFICOBJECT_H
#define TRAFFICOBJECT_H

#include <vector>
#include <thread>
#include <mutex>

enum ObjectType
{
    noObject,
    objectVehicle,
    objectIntersection,
    objectStreet,
};

class TrafficObject
{
public:
    // constructor / desctructor
    TrafficObject();
    ~TrafficObject();

    // getter and setter
    int getID() { return id_; }
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    ObjectType getType() { return type_; }

    // typical behaviour methods
    virtual void simulate(){};

protected:
    ObjectType type_;                  // identifies the class type
    int id_;                           // every traffic object has its own unique id
    double posX_, posY_;               // vehicle position in pixels
    std::vector<std::thread> threads_; // holds all threads that have been launched within this object
    static std::mutex mtx_;            // mutex shared by all traffic objects for protecting cout 

private:
    static int id_cnt_; // global variable for counting object ids
};

#endif
