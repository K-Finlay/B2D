#include "Pathfinding.h"
#include <VML/VML.h>

namespace b2d{

	std::vector <Sprite> PathFinder::spriteList;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Calculate The Path
	void PathFinder::CalculatePath (std::vector <Node> NodeList, int NodeSize, int StartNode, int EndNode, int MapWidth, int MapHeight, int CalcSpeed, int StripNodes){

		// Set Variables
		std::vector <Node> tempNodeList = NodeList;
		Node currentNode = tempNodeList[StartNode];
		PathFinder::nodeSize = NodeSize;
		bool hasReachedEnd = false;
		float lowestScore = 0;
		int lowestNode = 0, moves = 1;

		// Main Loop
		do{

			// Get The Node With The Lowest Score
			for (int i = 0; i < (int) openList.size(); ++i){

				if (currentNode.totalScore > openList[i].totalScore){
					lowestNode = i;
				}

				else if (openList[i].totalScore < lowestScore){

					lowestScore = openList[i].totalScore;
					lowestNode = i;
				}
			}

			// Erase Lowest Node
			if (openList.size() != 0){

				// Remove Node From Open List, Move To Closed List, Set As Current Node
				closedList.push_back (openList[lowestNode]);
				currentNode = closedList[closedList.size() - 1];
			    openList.erase (openList.begin() + lowestNode);
			}

		    // Get Adjacent Nodes
			int ind = currentNode.listPos;
		    
		    // Up
			if (ind - MapWidth > -1){

			    if (!tempNodeList[ind - MapWidth].isChecked && tempNodeList[ind - MapWidth].isWalkable && tempNodeList[ind - MapWidth].x == currentNode.x){

					// Calc Score
					tempNodeList[ind - MapWidth].gScore = moves;
					tempNodeList[ind - MapWidth].hScore = Vector2::Magnitude ((float) tempNodeList[ind - MapWidth].x, (float) tempNodeList[ind - MapWidth].y, (float) tempNodeList[EndNode].x, (float) tempNodeList[EndNode].y);
					tempNodeList[ind - MapWidth].hScore *= CalcSpeed;

					tempNodeList[ind - MapWidth].totalScore = tempNodeList[ind - MapWidth].gScore + tempNodeList[ind - MapWidth].hScore;
					
					// Set Parent And Add To Open List
					tempNodeList[ind - MapWidth].parent = currentNode.listPos;
					tempNodeList[ind - MapWidth].isChecked = true;
		        	openList.push_back (tempNodeList[ind - MapWidth]);
		        }
			}
		    
		    // Down
			if (ind + MapWidth < MapWidth * MapHeight){

		        if (!tempNodeList[ind + MapWidth].isChecked && tempNodeList[ind + MapWidth].isWalkable && tempNodeList[ind + MapWidth].x == currentNode.x){

					// Calc Score
					tempNodeList[ind + MapWidth].gScore = moves;
					tempNodeList[ind + MapWidth].hScore = Vector2::Magnitude ((float) tempNodeList[ind + MapWidth].x, (float) tempNodeList[ind + MapWidth].y, (float) tempNodeList[EndNode].x, (float) tempNodeList[EndNode].y);
					tempNodeList[ind + MapWidth].hScore *= CalcSpeed;

					tempNodeList[ind + MapWidth].totalScore = tempNodeList[ind + MapWidth].gScore + tempNodeList[ind + MapWidth].hScore;
					
					// Set Parent And Add To Open List
					tempNodeList[ind + MapWidth].parent = currentNode.listPos;
					tempNodeList[ind + MapWidth].isChecked = true;
		        	openList.push_back (tempNodeList[ind + MapWidth]);
		        }
			}
		    
		    // Left
			if (ind - 1 > -1){

			    if (!tempNodeList[ind - 1].isChecked && tempNodeList[ind - 1].isWalkable && tempNodeList[ind - 1].y == currentNode.y){

					// Calc Score
					tempNodeList[ind - 1].gScore = moves;
					tempNodeList[ind - 1].hScore = Vector2::Magnitude ((float) tempNodeList[ind - 1].x, (float) tempNodeList[ind - 1].y, (float) tempNodeList[EndNode].x, (float) tempNodeList[EndNode].y);
					tempNodeList[ind - 1].hScore *= CalcSpeed;

					tempNodeList[ind - 1].totalScore = tempNodeList[ind - 1].gScore + tempNodeList[ind - 1].hScore;
					
					// Set Parent And Add To Open List
					tempNodeList[ind - 1].parent = currentNode.listPos;
					tempNodeList[ind - 1].isChecked = true;
		        	openList.push_back (tempNodeList[ind - 1]);
		        }
			}
		    
		    // Right
			if (ind + 1 < MapWidth * MapHeight){

		        if (!tempNodeList[ind + 1].isChecked && tempNodeList[ind + 1].isWalkable && tempNodeList[ind + 1].y == currentNode.y){

					// Calc Score
					tempNodeList[ind + 1].gScore = moves;
					tempNodeList[ind + 1].hScore = Vector2::Magnitude ((float) tempNodeList[ind + 1].x, (float) tempNodeList[ind + 1].y, (float) tempNodeList[EndNode].x, (float) tempNodeList[EndNode].y);
					tempNodeList[ind + 1].hScore *= CalcSpeed;

					tempNodeList[ind + 1].totalScore = tempNodeList[ind + 1].gScore + tempNodeList[ind + 1].hScore;

					// Set Parent And Add To Open List
					tempNodeList[ind + 1].parent = currentNode.listPos;
					tempNodeList[ind + 1].isChecked = true;
		        	openList.push_back (tempNodeList[ind + 1]);
		        }
			}

			// Increment Number Of Moves
			moves += 1;

			// Check If The Current Node Is The End Node
			if (currentNode.x == tempNodeList[EndNode].x && currentNode.y == tempNodeList[EndNode].y){

				// Create The Return Vector
				std::vector <Vector2::Point> returnVector;

				// Loop Back Through Path
				while (hasReachedEnd == false){
					
					// Check If The Current Node Has Returned To The Start 
					if (currentNode.x == tempNodeList[StartNode].x && currentNode.y == tempNodeList[StartNode].y){

						openList.clear();
						closedList.clear();
						hasReachedEnd = true;
					}

					else{

						// Remove Unneeded Nodes
						for (int i = 0; i < StripNodes; ++i){

							if (currentNode.x == tempNodeList[currentNode.parent].x && tempNodeList[currentNode.parent].x == tempNodeList[tempNodeList[currentNode.parent].parent].x){
						    	currentNode.parent = tempNodeList[currentNode.parent].parent;
						    }

							else if (currentNode.y == tempNodeList[currentNode.parent].y && tempNodeList[currentNode.parent].y == tempNodeList[tempNodeList[currentNode.parent].parent].y){
								currentNode.parent = tempNodeList[currentNode.parent].parent;
							}
						}

						// Add Current Node To Return Vector, And Set Current Node As It's Parent
						spriteList[tempNodeList[currentNode.listPos].listPos].SwapTexture ("./Node5.png");
						returnVector.push_back (Vector2::Point ((float) currentNode.x * NodeSize, (float) currentNode.y * NodeSize));
						currentNode = tempNodeList[currentNode.parent];
					}
				}

				// Reuturn The Final Path
				PathFinder::path = returnVector;
				return;
			}
		}

		while (openList.size() > 0);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Follow Path
	void PathFinder::FollowPath (Vector2::Point &Vector, float speed){

		// Check If There Are Nodes Remaining In Path
		if (PathFinder::path.size() != 0){

			// Check X Position
		    if (Vector.x > (PathFinder::path[PathFinder::path.size() - 1].x)){
		    	Vector.x -= speed;
		    }
		    
		    else if (Vector.x < (PathFinder::path[PathFinder::path.size() - 1].x)){
		    	Vector.x += speed;
		    }
		    
			// Check Y Position
		    else if (Vector.y > (PathFinder::path[PathFinder::path.size() - 1].y)){
		    	Vector.y -= speed;
		    }
		    
		    else if (Vector.y < (PathFinder::path[PathFinder::path.size() - 1].y)){
		    	Vector.y += speed;
		    }
		    
			// Check If Node Has Been Reached
			else{
		    	PathFinder::path.pop_back();
		    }
		}

		// If There Are No Nodes, Return
		else{
			return;
		}
	}
}