#pragma once


#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"

// forward declarations to avoid include cycle
class Vehicle;

enum class TrafficLightPhase
{
    kRed = 0,
    kGreen = 1,
};


template <class T>
class MessageQueue
{
  public:
    T receive();
    void send(T&& msg);

  private:
    std::mutex mutex_;
    std::condition_variable cond_;
    std::deque<T> queue_;
};



class TrafficLight : public TrafficObject
{
  public:
    // constructor / desctructor
    TrafficLight();

    // getters / setters
    TrafficLightPhase getCurrentPhase() const;
    void setCurrentPhase(const TrafficLightPhase color);

    // typical behaviour methods
    void waitForGreen();
    void simulate() override;

  private:
    // typical behaviour methods
    void cycleThroughPhases();

   
    std::shared_ptr<MessageQueue<TrafficLightPhase>> msg_queue_;
    TrafficLightPhase current_phase_;
    std::condition_variable condition_;
    std::mutex mutex_;
};

#endif
