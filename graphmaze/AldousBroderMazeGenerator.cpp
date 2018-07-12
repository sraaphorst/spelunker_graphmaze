/**
 * AldousBroderMazeGenerator.cpp
 *
 * By Sebastian Raaphorst, 2018.
 */

#include <boost/graph/adjacency_list.hpp>

#include <algorithm>
#include <map>
#include <stack>
#include <vector>

#include "GraphUtils.h"
#include "MazeGraph.h"
#include "MazeGenerator.h"
#include "AldousBroderMazeGenerator.h"

#include <iostream>

namespace spelunker::graphmaze {

    const MazeGraph AldousBroderMazeGenerator::generate(const MazeGraph &tmplt) const {
        MazeGraph out = GraphUtils::createInitialMaze(tmplt);
        UnvisitedVertices unvisited = GraphUtils::initializeUnvisitedVertices(tmplt);

        // Keep track of the number of cells visited so that we know when to stop.
        const auto nCells = GraphUtils::numCells(out);

        // Pick a random vertex to start.
        auto v = GraphUtils::randomStartVertex(out);
        auto visitedCells = 1;
        unvisited[v] = false;

        // Continue until we have visited all the cells.
        while (visitedCells < nCells) {
            // Get all the neighbours of the current cell and move to one at random.
            const auto nbrs = GraphUtils::neighbours(tmplt, v);

            // Select an unvisited neighbour at random.
            // TODO: Improve randomization.
            const int idx = rand() % nbrs.size();
            const auto nxt = nbrs[idx];

            if (unvisited[nxt]) {
                unvisited[nxt] = false;
                ++visitedCells;
                boost::add_edge(v, nxt, out);
            }
            v = nxt;
        }
        return out;
    }
}
