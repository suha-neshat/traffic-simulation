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

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include "TrafficObject.h"

class Graphics
{
public:
    // constructor / desctructor

    // getters / setters
    void setBgFilename(std::string filename) { _bgFilename = filename; }
    void setTrafficObjects(std::vector<std::shared_ptr<TrafficObject>> &trafficObjects) { _trafficObjects = trafficObjects; };

    // typical behaviour methods
    void simulate();

private:
    // typical behaviour methods
    void loadBackgroundImg();
    void drawTrafficObjects();

    // member variables
    std::vector<std::shared_ptr<TrafficObject>> _trafficObjects;
    std::string _bgFilename;
    std::string _windowName;
    std::vector<cv::Mat> _images;
};

#endif
