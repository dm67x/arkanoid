#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "singleton.h"
#include "Entity/Brick/brick.h"
#include "Level/level.h.h"

class LevelManager : public Level<LevelManager>
{
private:
    std::vector<std::string *> Niveau;// conitent les fichier lvl

public:
    void go_to_next_level(Level * lvl);
    void reset_level();
      ~LevelManager();
};




#endif
