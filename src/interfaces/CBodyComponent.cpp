#include <CBodyComponent.h>
#include <client_dll.hpp>
#include <defines.h>

#include <exception>


CGameSceneNode CBodyComponent::getGameSceneNode()
{

    try{

        if(this == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - this->address == 0");
        }
        
        return *(CGameSceneNode*)(getAddress() + client_dll::C_BaseEntity::m_CBodyComponent);
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        uintptr_t falseList = 0x00000000;
        return *(CGameSceneNode*)falseList;
    }


}