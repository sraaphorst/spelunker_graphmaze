/**
 * MazeGenerator.h
 *
 * By Sebastian Raaphorst, 2018.
 */

#pragma once

#include <map>

#include "MazeGraph.h"

namespace spelunker::graphmaze {
/**
 * Abstract case for a graph generator.
 * Given a MazeGraph and a subclass of this class, which embodies an
 * essential algorithm, derive a Maze.
 */
    class MazeGenerator {
    public:
        using UnvisitedVertices = std::map<vertex, bool>;

        MazeGenerator(int w, int h);

        /**
         * Generate a maze using the given technique of size width by height.
         * @param tplt the template graph, as described above
         * @return
         */
        virtual const MazeGraph generate(const MazeGraph &tplt) const = 0;

    protected:
        MazeGraph createInitialMaze(const MazeGraph &tmplt) const noexcept;

        UnvisitedVertices initializeUnvisitedVertices(const MazeGraph &tmplt) const noexcept;
    private:
        const int width;
        const int height;
    };
}