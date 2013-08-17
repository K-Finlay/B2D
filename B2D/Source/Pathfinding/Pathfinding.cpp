#include "Pathfinding.h"
#include <VML/VML.h>

namespace b2d{

    std::vector <Node> PathFinder::openList;
	std::vector <Node> PathFinder::closedList;
	std::vector <Sprite> PathFinder::spriteList;

	std::vector <Vector2::Point> PathFinder::CalculatePath (std::vector <Node> NodeList, int StartNode, int EndNode, int MapWidth, int MapHeight, int CalcSpeed){

		// Set Variables
		std::vector <Node> tempNodeList = NodeList;
		Node currentNode = tempNodeList[StartNode];
		//currentNode.totalScore = 0;
		bool hasReachedEnd = false;
		float lowestScore = 9999;
		int lowestNode = 0, moves = 1;

		// Main Loop
		do{

			// Set Lowest Score To High Value
			lowestScore = 999999;

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

				/*Window::Clear();
				for (int i = 0; i < PathFinder::spriteList.size(); ++i){
					for (int j = 0; j < 100; ++j)
			            PathFinder::spriteList[i].Draw();
		        }*/

				// Remove Node From Open List, Move To Closed List, Set As Current Node
				//spriteList[openList[lowestNode].listPos].SwapTexture ("./Node3.png");
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

				/*Window::Clear();
				for (int i = 0; i < PathFinder::spriteList.size(); ++i){
					for (int j = 0; j < 100; ++j)
			            PathFinder::spriteList[i].Draw();
		        }*/
					
					// Check If The Current Node Has Returned To The Start 
					if (currentNode.x == tempNodeList[StartNode].x && currentNode.y == tempNodeList[StartNode].y){

						openList.clear();
						closedList.clear();
						hasReachedEnd = true;
					}

					else{

						// Add Current Node To Return Vector, And Set Current Node As It's Parent
						spriteList[tempNodeList[currentNode.listPos].listPos].SwapTexture ("./Node5.png");
						returnVector.push_back (Vector2::Point ((float) currentNode.x, (float) currentNode.y));
						currentNode = tempNodeList[currentNode.parent];
					}
				}

				// Reuturn The Final Path
				std::cout << "Found End" << '\n';
				return returnVector;
			}
		}

		while (openList.size() > 0 && !hasReachedEnd);

		// If No Path Is Found, Return Empty Vector
		std::cout << "No Path Found" << '\n';
		return std::vector <Vector2::Point>();
	}
}