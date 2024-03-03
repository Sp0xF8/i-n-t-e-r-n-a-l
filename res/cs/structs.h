#pragma once

#include <cstdint>
#include <defines.h>



class dwGameTypes
{
public:
	char pad_0000[4]; //0x0000
	char m_sMapName[16]; //0x0004
}; //Size: 0x0014




// Created with ReClass.NET 1.2 by KN4CK3R




class CEntityInstance
{
public:
	void *m_pClassType; //0x0000
	void *m_iszPrivateVScripts; //0x0008
	class CEntityIdentity *m_pEntity; //0x0010
	char pad_0018[16]; //0x0018
	class CScriptComponent *m_CScriptComponent; //0x0028
	bool m_bVisibleinPVS; //0x0030
	char pad_0031[7]; //0x0031
}; //Size: 0x0038

class C_BaseEntity : public CEntityInstance
{
public:
	class CBodyComponent *m_CBodyComponent; //0x0038
	void *m_NetworkTransmitComponent; //0x0040
	char pad_0048[720]; //0x0048
	class CGameSceneNode *m_pGameSceneNode; //0x0318
	void *m_pCRenderComponent; //0x0320
	void *m_pColission; //0x0328
	int32_t m_iMaxHealth; //0x0330
	int32_t m_iHealth; //0x0334
	uint8_t m_lifeState; //0x0338
	bool m_bTakesDamage; //0x0339
	char pad_033A[145]; //0x033A
	uint8_t m_iTeamNum; //0x03CB
	char pad_03CC[388]; //0x03CC
}; //Size: 0x0550

class CBodyComponent
{
public:
	char pad_0000[8]; //0x0000
	class CGameSceneNode *m_pSkeletonInstance; //0x0008
}; //Size: 0x0010

class CGameSceneNode
{
public:
	char pad_0000[48]; //0x0000
	class CEntityInstance *m_pOwner; //0x0030
	class CGameSceneNode *m_pParent; //0x0038
	class CGameSceneNode *m_pChild; //0x0040
	class CGameSceneNode *m_pNextSibling; //0x0048
	char pad_0050[48]; //0x0050
	Vector3 m_vecOrigin; //0x0080
	char pad_008C[56]; //0x008C
	float m_flScane; //0x00C4
	Vector3 m_vecAbsOrigin; //0x00C8
	char pad_00D4[18]; //0x00D4
	bool m_bDebugAbsOriginChanges; //0x00E6
	bool m_bDormant; //0x00E7
	char pad_00E8[8]; //0x00E8
	char m_name[8]; //0x00F0
	char m_hierarchyAttachName[8]; //0x00F8
	char pad_0100[528]; //0x0100
	class CModelState *m_pModelState; //0x0310
}; //Size: 0x0318

class CModelState
{
public:
	char pad_0000[128]; //0x0000
	uintptr_t pBoneMatrix; //0x0080
}; //Size: 0x0088

class CEntityIdentity
{
public:
	char pad_0000[20]; //0x0000
	int32_t m_nameStringableIndex; //0x0014
	char *m_name; //0x0018
	char *m_designerName; //0x0020
	char pad_0028[8]; //0x0028
	int32_t m_flags; //0x0030
	char pad_0034[4]; //0x0034
	int32_t m_worldGroupId; //0x0038
	int32_t m_fDataObjectTypes; //0x003C
	int64_t m_PathIndex; //0x0040
	char pad_0048[16]; //0x0048
	class CEntityIdentity *m_pPrev; //0x0058
	class CEntityIdentity *m__pNext; //0x0060
	class CEntityIdentity *m_pPrevByClass; //0x0068
	class CEntityIdentity *m_pNextByClass; //0x0070
}; //Size: 0x0078

class CScriptComponent
{
public:
	char pad_0000[48]; //0x0000
	char *m_scriptClassName; //0x0030
}; //Size: 0x0038

class C_CommandContext
{
public:
	bool needsprocessing; //0x0000
	char pad_0001[143]; //0x0001
	int32_t command_number; //0x0090
}; //Size: 0x0094

class CBasePlayerController : public C_BaseEntity
{
public:
	char pad_0550[8]; //0x0550
	int32_t m_nFinalPredictedTick; //0x0558
	char pad_055C[4]; //0x055C
	class C_CommandContext m_CommandContext; //0x0560
	char pad_05F4[4]; //0x05F4
	uint64_t m_nInButtonsWhichAreToggles; //0x05F8
	uint32_t m_nTickBase; //0x0600
	uint32_t m_hPawn; //0x0604
	uint32_t m_hPredictedPawn; //0x0608
	char pad_060C[36]; //0x060C
	bool m_bIsHLTV; //0x0630
	char pad_0631[3]; //0x0631
	uint32_t m_iConnected; //0x0634
	char m_iszPlayerName[128]; //0x0638
	char pad_06B8[8]; //0x06B8
	uint64_t m_steamID; //0x06C0
	bool m_bIsLocalPlayerController; //0x06C8
	char pad_06C9[3]; //0x06C9
	int32_t N000008B3; //0x06CC
}; //Size: 0x06D0

class CCSPlayerController : public CBasePlayerController
{
public:
	char pad_06D0[40]; //0x06D0
	class CCSPlayerController_InGameMoneyServices *m_pInGameMoneyServices; //0x06F8
	void *m_pInventoryServices; //0x0700
	class CCSPlayerController_ActionTrackingServices *m_pActionTrackingServices; //0x0708
	class CCSPlayerController_DamageServices *m_pDamageServices; //0x0710
	uint32_t m_iPing; //0x0718
	bool m_bHasCommunicationAbuseMute; //0x071C
	char pad_071D[3]; //0x071D
	char *m_szCrosshairCodes; //0x0720
	char pad_0728[24]; //0x0728
	char *m_szClan; //0x0740
	char *m_sSanitizedPlayerName; //0x0748
	int32_t m_iCoachingTeam; //0x0750
	char pad_0754[4]; //0x0754
	uint64_t m_nPlayerDominated; //0x0758
	uint64_t m_nPlayerDominatingMe; //0x0760
	int32_t m_iCompetitiveRanking; //0x0768
	int32_t m_iCompetitiveWins; //0x076C
	int8_t m_iCompetitiveRankType; //0x0770
	char pad_0771[3]; //0x0771
	int32_t m_iCompetitiveRankingPredicted_Win; //0x0774
	int32_t m_iCompetitiveRankingPredicted_Loss; //0x0778
	int32_t m_iCompetitiveRankingPredicted_Tie; //0x077C
	int32_t m_nEndMatchNextMapVote; //0x0780
	char pad_0784[64]; //0x0784
	bool m_bCannotBeKicked; //0x07C4
	bool m_bEverFullyConnected; //0x07C5
	bool m_bAbandonAllowsSurrender; //0x07C6
	bool m_bAbandonOffersInstantSurrender; //0x07C7
	bool m_bDisconnection1MinWarningPrinted; //0x07C8
	bool m_bScoreReported; //0x07C9
	char pad_07CA[2]; //0x07CA
	int32_t m_nDisconnectionTick; //0x07CC
	char pad_07D0[20]; //0x07D0
	int32_t m_hPlayerPawn; //0x07E4
	int32_t m_hObserverPawn; //0x07E8
	bool m_bPawnIsAlive; //0x07EC
	char pad_07ED[3]; //0x07ED
	uint32_t m_iPawnHealth; //0x07F0
	int32_t m_iPawnArmor; //0x07F4
	bool m_bPawnHasDefuser; //0x07F8
	bool m_bPawnHasHelmet; //0x07F9
	int16_t m_nPawnCharacterDefIndex; //0x07FA
	int32_t m_iPawnLifetimeStart; //0x07FC
	int32_t m_iPawnLifetimeEnd; //0x0800
	char pad_0804[8]; //0x0804
	int32_t m_iScore; //0x080C
	char pad_0810[40]; //0x0810
	int32_t m_iMVPs; //0x0838
	bool m_bIsPlayerNameDirty; //0x083C
}; //Size: 0x083D

class CCSPlayerController_DamageServices
{
public:
	char pad_0000[64]; //0x0000
	int32_t m_nSendUpdate; //0x0040
	char pad_0044[4]; //0x0044
	class CDamageRecord *m_DamageList; //0x0048
}; //Size: 0x0050

class CDamageRecord
{
public:
	char pad_0000[64]; //0x0000
}; //Size: 0x0040

class CCSPlayerController_InGameMoneyServices
{
public:
	char pad_0000[64]; //0x0000
	int32_t m_iAccount; //0x0040
	int32_t m_iStartAccount; //0x0044
	int32_t m_iTotalCashSpent; //0x0048
	int32_t m_iCashSpentThisRound; //0x004C
	int32_t m_nPreviousAccount; //0x0050
}; //Size: 0x0054

class CCSPlayerController_ActionTrackingServices
{
public:
	char pad_0000[272]; //0x0000
	int32_t m_iNumRoundKills; //0x0110
	int32_t m_iNumRoundKillsHeadshots; //0x0114
	uint32_t m_unTotalRoundDamageDealt; //0x0118
}; //Size: 0x011C

class CCSPlayerController_InventoryServices
{
public:
	char pad_0000[96]; //0x0000
	int32_t m_nPersonaDataPublicCommendsLeader; //0x0060
	int32_t m_nPersonaDataPublicCommendsTeacher; //0x0064
	int32_t m_nPersonaDataPublicCommendsFriendly; //0x0068
	char pad_006C[156]; //0x006C
}; //Size: 0x0108

class CCSPlayer_ActionTrackingServices
{
public:
	char pad_0000[64]; //0x0000
	int32_t m_hLastWeaponBeforeC4AutoSwitch; //0x0040
	bool m_bIsRescuing; //0x0044
	char pad_0045[179]; //0x0045
}; //Size: 0x00F8

class CCollisionProperty
{
public:
	char pad_0000[172]; //0x0000
	float m_flCapsuleRadius; //0x00AC
}; //Size: 0x00B0

class CGlowProperty
{
public:
	char pad_0000[8]; //0x0000
	Vector3 m_fGlowColor; //0x0008
	char pad_0014[28]; //0x0014
	int32_t m_iGlowType; //0x0030
	int32_t m_iGlowTeam; //0x0034
	int32_t m_nGlowRange; //0x0038
	int32_t m_nGlowRangeMin; //0x003C
	int32_t m_glowColorOverride; //0x0040
	bool m_bFlashing; //0x0044
	char pad_0045[3]; //0x0045
	float m_flGlowTime; //0x0048
	float m_flGlowStartTime; //0x004C
	bool m_bEligibleForScreenHighlight; //0x0050
	bool m_bGlowing; //0x0051
}; //Size: 0x0052

class C_BaseModelEntity : public C_BaseEntity
{
public:
	char pad_0550[1232]; //0x0550
	void *m_CRenderComponent; //0x0A20
	char pad_0A28[88]; //0x0A28
	bool m_nRenderMode; //0x0A80
	char pad_0A81[119]; //0x0A81
	class CCollisionProperty m_Collision; //0x0AF8
	class CGlowProperty m_Glow; //0x0BA8
	char pad_0BFA[154]; //0x0BFA
	bool m_bUseClientOverrideTint; //0x0C94
}; //Size: 0x0C95

class CBaseAnimGraph : public C_BaseModelEntity
{
public:
	char pad_0C95[219]; //0x0C95
	Vector3 m_vecForce; //0x0D70
	int32_t m_nForceBone; //0x0D7C
	class CBaseAnimGraph *m_pClientsideRagdoll; //0x0D80
	char pad_0D88[32]; //0x0D88
	bool m_bClientRagdoll; //0x0DA8
	char pad_0DA9[15]; //0x0DA9
	bool m_bHasAnimatedMaterialAttributes; //0x0DB8
}; //Size: 0x0DB9

class C_BaseFlex_Emphasized_Phoneme
{
public:
	char m_sClassName[24]; //0x0000
	float m_flAmount; //0x0018
	bool m_bRequired; //0x001C
	bool m_bBasechecked; //0x001D
	bool m_bValid; //0x001E
}; //Size: 0x001F

class C_BaseFlex : public CBaseAnimGraph
{
public:
	char pad_0DB9[599]; //0x0DB9
	class C_BaseFlex_Emphasized_Phoneme m_PhonemeClasses[3]; //0x1010
}; //Size: 0x106D

class C_BaseCombatCharacter : public C_BaseFlex
{
public:
	char pad_106D[27]; //0x106D
	int32_t m_bloodColor; //0x1088
	bool m_leftFootAttachment; //0x108C
	bool m_rightFootAttachment; //0x108D
	char pad_108E[14]; //0x108E
	float m_flFieldOfView; //0x109C
}; //Size: 0x10A0

class C_BasePlayerPawn : public C_BaseCombatCharacter
{
public:
	char pad_10A0[96]; //0x10A0
	void *m_pWeaponServices; //0x1100
	void *m_pItemServices; //0x1108
	void *m_pAutoaimServices; //0x1110
	void *m_pObserverServices; //0x1118
	void *m_pWaterServices; //0x1120
	void *m_pUseServices; //0x1128
	void *m_pFlashlightServices; //0x1130
	void *m_pCameraServices; //0x1138
	void *m_pMovementServices; //0x1140
	char pad_1148[300]; //0x1148
	float m_flFOVSensitivityAdjust; //0x1274
	float m_flMouseSensitivity; //0x1278
	char pad_127C[24]; //0x127C
	int32_t m_hController; //0x1294
	bool m_bIsSwappingToPredictableController; //0x1298
}; //Size: 0x1299

class C_CSPlayerPawnBase : public C_BasePlayerPawn
{
public:
	char pad_1299[39]; //0x1299
	void *m_pPingServices; //0x12C0
	void *m_pViewModelServices; //0x12C8
	char pad_12D0[304]; //0x12D0
	bool m_bIsScoped; //0x1400
	bool m_bIsWalking; //0x1401
	bool m_bResumeZoom; //0x1402
	char pad_1403[1]; //0x1403
	int32_t m_iPlayerState; //0x1404
	bool m_bIsDefusing; //0x1408
	bool m_bIsGrabbingHostage; //0x1409
	char pad_140A[2]; //0x140A
	int32_t m_iBlockingUseActionInProgress; //0x140C
	bool m_bIsRescuing; //0x1410
	char pad_1411[16]; //0x1411
	bool m_bHasMovedSinceSpawn; //0x1421
	char pad_1422[46]; //0x1422
	bool m_bCanMoveDuringFreezePeriod; //0x1450
	char pad_1451[7]; //0x1451
	bool m_bStrafing; //0x1458
	char pad_1459[35]; //0x1459
	int32_t m_iShotsFired; //0x147C
	char pad_1480[12]; //0x1480
	int32_t m_nHitBodyPart; //0x148C
	char pad_1490[40]; //0x1490
	float m_flFlashBangTime; //0x14B8
	float m_flFlashScreenshotAlpha; //0x14BC
	float m_flFlashOverlayAlpha; //0x14C0
	bool m_bFlashBuildUp; //0x14C4
	bool m_bFlashDspHasBeenCleared; //0x14C5
	bool m_bFlashScreenshotHasBeenGrabbed; //0x14C6
	char pad_14C7[1]; //0x14C7
	float m_flFlashMaxAlpha; //0x14C8
	float m_flFlashDuration; //0x14CC
	char pad_14D0[160]; //0x14D0
	int32_t m_ArmorValue; //0x1570
	char pad_1574[36]; //0x1574
	int32_t m_nLastKillerIndex; //0x1598
	char pad_159C[8]; //0x159C
	int32_t m_iIDEntIndex; //0x15A4
	char pad_15A8[24]; //0x15A8
	int32_t m_iTargetedWeaponEntIndex; //0x15C0
	char pad_15C4[84]; //0x15C4
	float m_flLastSmokeOverlayAlpha; //0x1618
	Vector3 m_vLastSmokeOverlayColor; //0x161C
	int32_t m_nPlayerSmokedFx; //0x1628
	int32_t m_nPlayerInfernoBodyFx; //0x162C
	int32_t m_nPlayerInfernoFootFx; //0x1630
	char pad_1634[148]; //0x1634
	bool m_bKilledByHeadshot; //0x16C8
	char pad_16C9[3]; //0x16C9
	int32_t m_hOriginalController; //0x16CC
}; //Size: 0x16D0

class C_EconItemView
{
public:
	char pad_0000[1088]; //0x0000
	bool m_bInitializedTags; //0x0440
	char pad_0441[3]; //0x0441
}; //Size: 0x0444

class C_CSPlayerPawn : public C_CSPlayerPawnBase
{
public:
	char pad_16D0[72]; //0x16D0
	void *m_pBulletServices; //0x1718
	void *m_pHostageServices; //0x1720
	void *m_pBuyServices; //0x1728
	void *m_pGlowServices; //0x1730
	void *m_pActionTrackingServices; //0x1738
	char pad_1740[4]; //0x1740
	int32_t m_flLastFiredWeaponTime; //0x1744
	char pad_1748[12]; //0x1748
	char m_szLastPlaceName[18]; //0x1754
	char pad_1766[10]; //0x1766
	uint32_t m_unPreviousWeaponHash; //0x1770
	uint32_t m_unWeaponHash; //0x1774
	char pad_1778[4]; //0x1778
	Vector3 m_aimPunchAngle; //0x177C
	Vector3 m_aimPunchAngleVel; //0x1788
	int32_t m_aimPunchTickBase; //0x1794
	float m_aimPunchTickFraction; //0x1798
	char pad_179C[36]; //0x179C
	bool m_bInLanding; //0x17C0
	char pad_17C1[3]; //0x17C1
	float m_flLandingTime; //0x17C4
	bool m_bInHostageRescueZone; //0x17C8
	bool m_bInBombZone; //0x17C9
	bool m_bIsBuyMenuOpen; //0x17CA
	char pad_17CB[1]; //0x17CB
	int32_t m_flTimeOfLastInjury; //0x17CC
	char pad_17D0[328]; //0x17D0
	bool m_bNeedToReApplyGloves; //0x1918
	char pad_1919[7]; //0x1919
	class C_EconItemView m_EconGloves; //0x1920
	char pad_1D64[4]; //0x1D64
	uint8_t m_nEconGlovesChanged; //0x1D68
	bool m_bMustSyncRagdollState; //0x1D69
	char pad_1D6A[2]; //0x1D6A
	int32_t m_nRagdollDamageBone; //0x1D6C
	Vector3 m_vRagdollDamageForce; //0x1D70
	Vector3 m_vRagdollDamagePosition; //0x1D7C
	char m_szRagdollDamageWeaponName[64]; //0x1D88
	bool m_bRagdollDamageHeadshot; //0x1DC8
	char pad_1DC9[3]; //0x1DC9
	Vector3 m_vRagdollServerOrigin; //0x1DCC
	char pad_1DD8[1580]; //0x1DD8
	Vector3 m_qDeathEyeAngles; //0x2404
	bool m_bSkipOneHeadConstraintUpdate; //0x2410
	char pad_2411[3]; //0x2411
}; //Size: 0x2414

