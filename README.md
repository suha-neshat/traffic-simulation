# Concurrency Traffic Simulation

![Traffic Simulation](/traffic_simulation.gif)


## Overview
The **Concurrency Traffic Simulation** project models a busy city intersection with realistic traffic behavior using **C++** and **multithreading**.  
Vehicles and traffic lights are represented as concurrent objects that communicate via **message queues**, allowing for parallel updates without blocking the main thread.

The project visualizes the simulation using **SFML** (Simple and Fast Multimedia Library), where each vehicle obeys the state of its traffic light. This results in a dynamic, visually engaging simulation that demonstrates concurrency control and thread-safe communication patterns.

###  Key Features
- **Multithreaded design:** Each vehicle runs on its own thread to simulate independent movement.
- **Message queue system:** Manages real-time communication between traffic lights and vehicles.
- **SFML-based visualization:** Interactive window showing live traffic flow and light changes.
- **Synchronization mechanisms:** Uses mutexes and condition variables to avoid race conditions.

###  Concepts Demonstrated
- Object-oriented design in C++
- Thread lifecycle management
- Concurrency and synchronization
- Event-driven simulation


