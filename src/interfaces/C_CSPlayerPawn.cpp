#include <C_CSPlayerPawn.h>
#include <client_dll.hpp>

#include <exception>




void C_CSPlayerPawn::setSkeleton(){
    try{
        
        uintptr_t CBodyComponent = offset<uintptr_t>(client_dll::C_BaseEntity::m_CBodyComponent);
        if(CBodyComponent == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - CGameSceneNodeAddress == 0");
        }

        uintptr_t SkeletonInstance = *(uintptr_t*)(CBodyComponent + client_dll::CBodyComponent::m_pSceneNode);
        if(SkeletonInstance == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - SkeletonInstance == 0");
        }

        uintptr_t ModdelState = *(uintptr_t*)(SkeletonInstance + client_dll::CSkeletonInstance::m_modelState);
        if(ModdelState == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - ModdelState == 0");
        }

        skeleton = *(uintptr_t*)(ModdelState + 0x80);
        if(skeleton == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - Skeleton == 0");
        }
    }
    catch (std::exception e) {
        DLOG("Error in C_CSPlayerPawn::jointPos\n");
    }
}
Vector3 C_CSPlayerPawn::jointPos(int i){
    try{

        if(skeleton == 0){
            throw std::exception("C_CSPlayerPawn::getBodyComponent() - Skeleton == 0");
        }

        Vector3 JointPos = *(Vector3*)(skeleton + i * 0x20);

        return JointPos;

    }
    catch (std::exception e) {
        DLOG("Error in C_CSPlayerPawn::jointPos\n");
        return {0,0,0};
    }
}


bool C_CSPlayerPawn::bSpotted(){

    bool spottedEnt = offset<bool>(client_dll::C_CSPlayerPawn::m_entitySpottedState + client_dll::EntitySpottedState_t::m_bSpotted);
    DLOG("Spotted %d\n", spottedEnt);

    if(spottedEnt == 0){
        DLOG("Spotted == 0\n");
        return false;
    }

    return spottedEnt;
}