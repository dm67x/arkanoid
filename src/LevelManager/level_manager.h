#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include "singleton.h"
#include "Level/level.h"

class LevelManager : public Singleton<LevelManager>
{
private:
    static int next_id;
    Level * current;
    std::vector<Level *> levels; // contient les niveaux

public:
    ~LevelManager();
    void add(Level * l);
    void remove(Level * l);
    bool next();
    inline Level * get() { return current; }
};




#endif
