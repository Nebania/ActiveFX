#include <iostream>
#include <string>
#include <unordered_map>
#include "structs.h"

std::unordered_map<std::string,Object> objs;
std::unordered_map<std::string, SDL_Texture*> textureCache;
int ifNotFoundID = 0;