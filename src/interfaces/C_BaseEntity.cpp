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


int C_BaseEntity::getPlayerHealth(){
    
    try{

        if(this == 0){
            throw std::exception("C_CSPlayerPawn::getPlayerHealth() - this->address == 0");
        }
        
        return *(int*)(getAddress() + client_dll::C_BaseEntity::m_iHealth);
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        return -1;
    }


}

CBodyComponent C_BaseEntity::getBodyComponent(){
    
    try{

        if(this == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - this->address == 0");
        }
        
        return *(CBodyComponent*)(getAddress() + client_dll::C_BaseEntity::m_CBodyComponent);
        
    }
    catch(std::exception e){
        printf("%s\n", e.what());
        uintptr_t falseList = 0x00000000;
        return *(CBodyComponent*)falseList;
    }

}