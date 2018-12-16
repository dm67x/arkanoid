#include "level_manager.h"


void LevelManager::go_to_next_level(int lvl)
{
	if(!loadFileLevel(lvl))
	{
		//quelle truc qui verife qu'il ya plus de bmoc
	}
}

void LevelManager::loadFileLevel( int lvl) // charger un fichier en foncionde son lvl
{
	Niveau.push("level1.txt");
	Niveau.push("level2.txt");
	Niveau.push("level3.txt");
	Niveau.push("level4.txt");
	
	if(lvl <1 && lvl >4 )
	{
		std::cout<<"Level inconnu, lvl<1..4>" <<std::endl;
	}
	switch(lvl)
	{
		case 1 : return Niveau.get(1);
		break;
		case 2 : return Niveau.get(2);
		break;
		case 3 : return Niveau.get(3);
		break;
		case 4 : return Niveau.get(4);
		break;
	}
}
