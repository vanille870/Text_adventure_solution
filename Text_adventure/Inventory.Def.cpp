#include <iostream>
#include <string>
#include <map>
#include "Inventory_Deca.h"
#include "InventoryItems_Deca.h"

Inventory* InitializeInventory()
{
	Inventory* PlayerInventoryP = new Inventory(5); 

	PlayerInventoryP->AdditemToInventory("key");
	PlayerInventoryP->AdditemToInventory("hatchet");
	PlayerInventoryP->AdditemToInventory("sword");

	return PlayerInventoryP;
}
