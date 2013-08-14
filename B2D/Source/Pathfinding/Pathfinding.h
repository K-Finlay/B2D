#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include "../B2D.h"

namespace b2d{

	struct Node{

		float gScore, hScore, totalScore;
		int x, y;
		int parent;
		bool isWalkable, isChecked;
		int listPos;
	};

	class PathFinder{
	public:

		static std::vector <Node> nodeList;
		static std::vector <Node> openList;
		static std::vector <Node> closedList;
		static std::vector <Sprite> spriteList;

		static std::vector <Vector2::Point> CalculatePath (Node &StartNode, Node &EndNode, int MapWidth, int MapHeight, int CalcSpeed);
	};
}

#endif