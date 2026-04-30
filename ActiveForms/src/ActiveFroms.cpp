#include "ActiveForms.h"

void ActiveForms::Init(char* path){
    afDoc->LoadFile(path);
}
void ActiveForms::Functions(){
    XMLElement* application = afDoc->FirstChildElement("Application");
}