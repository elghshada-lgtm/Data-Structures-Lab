Graphs 2 / Shada Elghariani / CISC187

## Task #1
- Dijkstra’s algorithm fails when there are negative edge weights because it assumes that once it finds the shortest path to a node, that value will not change. This works fine when all the other edges are positive, but with the negative edges, a shorter path can appear later. For example, if we go from A to B with cost 1, and later find a path A → C → B with a total cost of -2, Dijkstra will ignore it because it already “locked in” the earlier value for B. This basically means the algorithm gives the wrong answer. Dijkstra can't handle negative weights because it finalizes nodes too early and can't update them when a better path is found later on.
