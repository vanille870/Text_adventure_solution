#include <iostream>
#include <string>
#include <map>
#include "Inventory_Deca.h"
#include "InventoryItems_Deca.h"

Inventory* InitializeInventory()
{
	Inventory* PlayerInventoryP = new Inventory(5); 

	PlayerInventoryP->AdditemToInventory("key", "A shiny key");
	PlayerInventoryP->AdditemToInventory("hatchet", "A worn hatchet");
	PlayerInventoryP->AdditemToInventory("sword", "A rusty sword");

	return PlayerInventoryP;
}
