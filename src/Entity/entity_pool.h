#ifndef ENTITY_POOL_H
#define ENTITY_POOL_H

#include <map>
#include <memory>
#include <string>
#include "entity.h"
#include "singleton.h"

class EntityPool : public Singleton<EntityPool>
{

private:
    std::map<std::string, std::shared_ptr<Entity>> entities;

public:
    EntityPool();
    ~EntityPool();

    void add(std::string id, std::shared_ptr<Entity> e);
    std::shared_ptr<Entity> get(std::string id);
    std::map<std::string, std::shared_ptr<Entity>> getAll();

};

#endif
