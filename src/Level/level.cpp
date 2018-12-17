#include "level.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/points.h"
#include "Component/health.h"
#include "Component/bonus.h"

using namespace std;
using namespace Components;

unsigned int Level::next_id = 0;

Level::Level(std::string filename)
{
	id = next_id++;
	board = new Board(25, 13);

	string ligne;
	ifstream fichier(filename, ios::in);  // on ouvre le fichier en lecture
	int pts, line, column, bonus, hit, bl, bc;
	Entities::Brick * brick = nullptr;

	while(getline(fichier,ligne))
	{   
		std::istringstream iss (ligne);
		string token;
		
		if (ligne[0] == '#') continue;
		if (ligne[0] == '&') {
			for (int i = 0; getline(iss, token, ';'); i++) {
				if (i == 1) bl = std::stoi(token, nullptr);
				else if (i == 2) bc = std::stoi(token, nullptr);
			}
			std::cout << bl << "," << bc << std::endl;
			board->setSize(bl, bc);
			continue;
		}
		
		for (int i = 0; getline(iss, token, ';'); i++) {
			if (i == 0) pts = std::stoi(token, nullptr);
			else if (i == 1) column = std::stoi(token, nullptr);
			else if (i == 2) line = std::stoi(token, nullptr);
			else if (i == 3) hit = std::stoi(token, nullptr);
			else bonus = std::stoi(token, nullptr);
		}

		brick = new Entities::Brick();
		Transform * tc = brick->get<Transform>("transform");
		Sprite * sc = brick->get<Sprite>("sprite");
		Points * points = brick->get<Points>("points");
		Health * hc = brick->get<Health>("health");
		Bonus * b = brick->get<Bonus>("bonus");
		
		tc->position = board->getPosition(line, column);
		tc->scale = board->getBrickScale();
		
		points->points = pts;
		hc->life = hit;
		if (hit < 0) hc->invicible = true;
		b->bonus = bonus;

		bricks.push_back(brick);
	}
}

Level::~Level() {
	delete board;
}

void Level::load() {
	for (auto b : bricks) b->setActive(true);
}

void Level::unload() {
	for (auto b : bricks) b->setActive(false);
}

