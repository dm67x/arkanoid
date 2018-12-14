#include "level.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Entity/Brick/brick.h"
#include "Component/transform.h"
#include "Component/sprite.h"
#include "Component/points.h"
#include "Component/health.h"
#include "Component/bonus.h"

using namespace std;
using namespace Components;

Level::Level(std::string filename)
{
	manager = new EntityManager();

	string ligne;
	ifstream fichier(filename, ios::in);  // on ouvre le fichier en lecture
	int pts, x, y, bonus, hit;
	Entities::Brick * brick = nullptr;

	while(getline(fichier,ligne))
	{   
		if (ligne[0] == '#') continue;  
		std::istringstream iss (ligne);
		string token;
		for (int i = 0; getline(iss, token, ';'); i++) {
			if (i == 0) pts = std::stoi(token, nullptr);
			else if (i == 1) x = std::stoi(token, nullptr);
			else if (i == 2) y = std::stoi(token, nullptr);
			else if (i == 3) hit = std::stoi(token, nullptr);
			else bonus = std::stoi(token, nullptr);
		}

		brick = new Entities::Brick(manager);
		Transform * tc = brick->get<Transform>("transform");
		Sprite * sc = brick->get<Sprite>("sprite");
		Points * points = brick->get<Points>("points");
		Health * hc = brick->get<Health>("health");
		Bonus * b = brick->get<Bonus>("bonus");
		
		tc->position.x = x * (sc->src.w);
		tc->position.y = y * (sc->src.h);
		
		points->points = pts;
		hc->life = hit;
		if (hit < 0) hc->invicible = true;
		b->bonus = bonus;
	}
}
 
 Level::~Level() {
	 delete manager;
 }
