#include <C_BaseEntity.h>

#include <client_dll.hpp>
#include <GPointers.h>
#include <defines.h>


// bool C_BaseEntity::IsController() {
    
//     return this->getAddress() == (uintptr_t)gPointers.LocalPlayerController.GetAddress();
// }

// bool C_BaseEntity::IsPawn() {
//     return this->address == *(uintptr_t*)gPointers.LocalPlayerPawn.GetAddress();
// }

// bool C_BaseEntity::IsLocalController() {
//     return this->address == *(uintptr_t*)*(uintptr_t*)gPointers.LocalPlayerController.GetAddress();
// }

// bool C_BaseEntity::IsLocalPawn() {
//     return this->address == *(uintptr_t*)*(uintptr_t*)gPointers.LocalPlayerPawn.GetAddress();
// }

// bool C_BaseEntity::IsValid() {
//     return this->address != 0;
// }

// int C_BaseEntity::GetTeam() {
//     return *(int*)(this->address + client_dll::C_BaseEntity::m_iTeamNum);
// }
#include <exception> // Add this line to include the <exception> header


int C_BaseEntity::getHealth(){
    
    try{

        if(this == 0){
            throw std::exception("C_CSPlayerPawn::getPlayerHealth() - this->address == 0");
        }
        
        return offset<int>(client_dll::C_BaseEntity::m_iHealth);
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        return -1;
    }


}

int C_BaseEntity::getTeam(){
    
    try{

        if(this == 0){
            throw std::exception("C_CSPlayerPawn::getTeam() - this->address == 0");
        }
        
        return offset<int>(client_dll::C_BaseEntity::m_iTeamNum);
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        return -1;
    }

}

Vector3 C_BaseEntity::getPosition(){
    
    try{

        if(this == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - this->address == 0");
        }

        uintptr_t CGameSceneNodeAddress = offset<uintptr_t>(client_dll::C_BaseEntity::m_pGameSceneNode);
        if(CGameSceneNodeAddress == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - CGameSceneNodeAddress == 0");
        }

        return *(Vector3*)(CGameSceneNodeAddress + client_dll::CGameSceneNode::m_vecOrigin);
        
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        return {0,0,0};
    }

}