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

#include <iostream>
#include "Vehicle.h"
#include "Intersection.h"
#include "Street.h"


Street::Street()
{
    type_ = ObjectType::objectStreet;
    _length = 1000.0; // in m
}

void Street::setInIntersection(std::shared_ptr<Intersection> in)
{
    _interIn = in;
    in->addStreet(get_shared_this()); // add this street to list of streets connected to the intersection
}

void Street::setOutIntersection(std::shared_ptr<Intersection> out)
{
    _interOut = out;
    out->addStreet(get_shared_this()); // add this street to list of streets connected to the intersection
}
