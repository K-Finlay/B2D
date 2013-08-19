#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include "../B2D.h"

namespace b2d{

	struct Node{

		float hScore, totalScore;
		int gScore;
		int x, y;
		int parent;
		int listPos;
		bool isWalkable, isChecked;
	};

	class PathFinder{
	public:

		// Variables
		std::vector <Node> openList;
		std::vector <Node> closedList;
		static std::vector <Sprite> spriteList;
		std::vector <Vector2::Point> path;
		int nodeSize;

		// Functions
		void CalculatePath (std::vector <Node> NodeList, int NodeSize, int StartNode, int EndNode, int MapWidth, int MapHeight, int CalcSpeed = 5, int StripNodes = 0);
		void FollowPath (Vector2::Point &Vector, float speed);
	};
}

#endif