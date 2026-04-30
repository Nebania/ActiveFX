#include <imgui.h>
#include <tinyxml2.h>
using namespace tinyxml2;
class ActiveForms{
    
    XMLDocument* afDoc;
    void Init(char* path);
    void Functions();
};