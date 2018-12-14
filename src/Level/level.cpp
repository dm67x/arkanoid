#include "level.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Entity/Brick/brick.h"
#include "Component/component.h"

using namespace std;

Level::Level(std::string filename)
{
	manager = new EntityManager();
	
	string ligne;
	ifstream fichier(filename, ios::in);  // on ouvre le fichier en lecture
	int points, x, y, bonus, hit;
	Entities::Brick * brick = nullptr;
	
	while(getline(fichier,ligne))
	{   
		if (ligne[0] == '#') 
			continue;  
		std::istringstream iss (ligne);
		string token;
		for (int i = 0; getline(iss, token, ';'); i++) {
			if (i == 0) points = std::stoi(token, nullptr);
			else if (i == 1) x = std::stoi(token, nullptr);
			else if (i == 2) y = std::stoi(token, nullptr);
			else if (i == 3) hit = std::stoi(token, nullptr);
			else bonus = std::stoi(token, nullptr);
		}
		brick = new Entities::Brick(manager);
		//~ brick->transform->position.x = x * (brick->sprite->src.w );
		//~ brick->transform->position.y = y * (brick->sprite->src.h);
		Components::Transform * tc = static_cast<Component::Transform *>(brick->get("transform"));
		Components::Sprite * sc = static_cast<Component::Sprite *>(brick->get("sprite"));
		Components::Points * points = static_cast<Component::Points *>(brick->get("points"));
		Components::Health * hc = static_cast<Component::Health *>(brick->get("health"));
		Components::Bonus * b = static_cast<Component::Bonus *>(brick->get("bonus"));
		
		tc->position.x = x * (sc->src.w );
		tc->position.y = y * (sc->src.h);
		
		points->points = points 
		hc->life = hit
		b->bonus = bonus
	}
 }
 

 Level::~Level() {
	 delete manager;
 }
