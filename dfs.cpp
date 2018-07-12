#include "graphmaze/GraphUtils.h"
#include "graphmaze/MazeGraph.h"
#include "graphmaze/MazeGenerator.h"
#include "graphmaze/DFSMazeGenerator.h"
#include <cassert>
#include <tuple>
#include <vector>
#include <iostream>

using namespace spelunker::graphmaze;

constexpr auto W = 6;
constexpr auto H = 4;

int main() {
    MazeGraph torus = GraphUtils::makeTorus(W, H);
    const auto maze = DFSMazeGenerator{}.generate(torus);
    GraphUtils::outputGraph(std::cout, maze);
}