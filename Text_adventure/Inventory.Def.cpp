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

	ToolItem* axe = new ToolItem("slash", 1);
	axe->Name = "AXE";
	PlayerInventoryP->Map["AXE"] = axe;


	return PlayerInventoryP;
}
