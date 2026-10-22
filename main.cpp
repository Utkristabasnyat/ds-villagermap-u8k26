
/*
  Name: Utkrista Mardan Basnyat
  Course: COMSC-210 Data Structures
  Lab 27: Villager Map
  File: main.cpp
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
  // Store villagers and their favorite colors
  map<string, vector<string>> villagerColors;

  // Add villagers
  villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
  villagerColors["Raymond"] = {"Black", "Gray", "White"};
  villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

  // Display villagers using a range-based loop
  cout << "Villagers and their favorite colors:" << endl;

  for (auto villager : villagerColors) {
    cout << villager.first << ": ";

    for (auto color : villager.second) {
      cout << color << " ";
    }

    cout << endl;
  }

  // Display villagers using iterators
  cout << "\nVillagers using iterators:" << endl;

  for (map<string, vector<string>>::iterator it =
       villagerColors.begin(); it != villagerColors.end(); ++it) {
    cout << it->first << ": ";

    for (auto color : it->second) {
      cout << color << " ";
    }

    cout << endl;
  }

  // Delete Raymond
  villagerColors.erase("Raymond");

  // Search for Audie
  string searchKey = "Audie";
  auto it = villagerColors.find(searchKey);

  if (it != villagerColors.end()) {
    cout << "\nFound " << searchKey << ": ";

    for (auto color : it->second) {
      cout << color << " ";
    }

    cout << endl;
  } else {
    cout << searchKey << " not found." << endl;
  }

  // Check the map size before and after clearing
  cout << "\nSize before clear: "
       << villagerColors.size() << endl;

  villagerColors.clear();

  cout << "Size after clear: "
       << villagerColors.size() << endl;

  return 0;
}
