#include "PVPMap_Pup.h"
#include "Contents.h"
#include "Script/CameraController.h"
#include "Script/Map/Pup.h"

void PVPMap_Pup::WorldLoad()
{
	
}

void PVPMap_Pup::WorldDestroy()
{
	__super::WorldDestroy();
}

void PVPMap_Pup::WorldEnter()
{
	map = CreateObject<Actor>("Map", LayerTag::Map, ObjectTag::Defalut);
	mapCore = map->AddComponent<MAP::Pup>();
	__super::WorldEnter();
}

void PVPMap_Pup::WorldExit()
{	
}
