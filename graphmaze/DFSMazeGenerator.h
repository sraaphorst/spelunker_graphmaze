/**
 * DFSMazeGenerator.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <boost/graph/adjacency_list.hpp>

#include "MazeGenerator.h"
#include "MazeGraph.h"

namespace spelunker::graphmaze {
    /**
     * This is a MazeGenerator that works based on a randomized breadth first search.
     */
    class DFSMazeGenerator : public MazeGenerator {
    public:
        DFSMazeGenerator() = default;

        const MazeGraph generate(const MazeGraph &tmplt) const final;
    };
}