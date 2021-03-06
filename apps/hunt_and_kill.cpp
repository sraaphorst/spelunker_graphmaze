/**
 * hunt_and_kill.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <iostream>

#include <graphmaze/GraphUtils.h>
#include <graphmaze/MazeGraph.h>
#include <graphmaze/HuntAndKillMazeGenerator.h>
#include <graphmaze/StringGridMazeRenderer.h>

using namespace spelunker::graphmaze;

constexpr auto W = 50;
constexpr auto H = 40;
constexpr auto R = 3;

int main() {
    const auto grid = GraphUtils::makeGrid(W, H);
    const auto [maze, start] = HuntAndKillMazeGenerator{}.generate(grid);
    GraphUtils::outputGraph(std::cout, maze);

    StringGridMazeRenderer r{std::cout};
    r.render(maze);
}