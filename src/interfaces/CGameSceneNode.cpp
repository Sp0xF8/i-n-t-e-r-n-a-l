#include <CGameSceneNode.h>
#include <client_dll.hpp>
#include <defines.h>
#include <exception>

Vector3 CGameSceneNode::getVecOrigin()
{
    try{

        if(this == 0){
            throw std::exception("CGameSceneNode::getVecOrigin() - this->address == 0");
        }
        
        return *(Vector3*)(getAddress() + client_dll::CGameSceneNode::m_vecOrigin);
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        Vector3 falseList = {0, 0, 0};
        return falseList;
    }
}