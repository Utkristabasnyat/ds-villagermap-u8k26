
/*
  Name: Utkrista Mardan Basnyat
  Course: COMSC-210 Data Structures
  Lab 27: Villager Map
  File: main.cpp
*/

#include <iostream>
#include <map>
#include <tuple>
#include <string>

using namespace std;

int main() {
  // Store friendship level, species, and catchphrase
  map<string, tuple<int, string, string>> villagers;

  // Add three villagers
  villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
  villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
  villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

  // Display all villagers
  cout << "Villager details:" << endl;

  for (auto villager : villagers) {
    cout << villager.first << " ["
         << get<0>(villager.second) << ", "
         << get<1>(villager.second) << ", "
         << get<2>(villager.second) << "]" << endl;
  }

  // Search for a villager
  string searchName = "Raymond";
  auto it = villagers.find(searchName);

  if (it != villagers.end()) {
    cout << "\nFound " << it->first << " ["
         << get<0>(it->second) << ", "
         << get<1>(it->second) << ", "
         << get<2>(it->second) << "]" << endl;
  } else {
    cout << searchName << " not found." << endl;
  }

  // Delete a villager
  villagers.erase("Kyle");

  cout << "\nAfter deleting Kyle:" << endl;

  for (auto villager : villagers) {
    cout << villager.first << " ["
         << get<0>(villager.second) << ", "
         << get<1>(villager.second) << ", "
         << get<2>(villager.second) << "]" << endl;
  }

  // Show map size
  cout << "\nVillagers remaining: " << villagers.size() << endl;

  return 0;
}
