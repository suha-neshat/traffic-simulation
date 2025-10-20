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

#include <algorithm>
#include <iostream>
#include <chrono>
#include "TrafficObject.h"

// init static variable
int TrafficObject::id_cnt_ = 0;

std::mutex TrafficObject::mtx_;

void TrafficObject::setPosition(double x, double y)
{
    posX_ = x;
    posY_ = y;
}

void TrafficObject::getPosition(double &x, double &y)
{
    x = posX_;
    y = posY_;
}

TrafficObject::TrafficObject()
{
    type_ = ObjectType::noObject;
    id_ = id_cnt_++;
}

TrafficObject::~TrafficObject()
{   
    // Test for Task L1.1
    // set up thread barrier before this object is destroyed
    std::for_each(threads_.begin(), threads_.end(), [](std::thread &t) {
        t.join();
    });
}
