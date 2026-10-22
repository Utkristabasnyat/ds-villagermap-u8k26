
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

  villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
  villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
  villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

  int choice = 0;
  string name;

  // Show the menu until the user exits
  while (choice != 4) {
    cout << "\n1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= 3) {
      cout << "Villager name: ";
      cin >> name;

      auto it = villagers.find(name);

      if (it == villagers.end()) {
        cout << name << " not found." << endl;
      } else if (choice == 1) {
        // Increase friendship, but not above 10
        if (get<0>(it->second) < 10) {
          get<0>(it->second)++;
        }

        cout << name << "'s friendship level: "
             << get<0>(it->second) << endl;
      } else if (choice == 2) {
        // Decrease friendship, but not below 0
        if (get<0>(it->second) > 0) {
          get<0>(it->second)--;
        }

        cout << name << "'s friendship level: "
             << get<0>(it->second) << endl;
      } else {
        // Display the searched villager
        cout << it->first << " ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
      }

      // Display all villagers after each operation
      cout << "\nVillager details:" << endl;

      for (auto villager : villagers) {
        cout << villager.first << " ["
             << get<0>(villager.second) << ", "
             << get<1>(villager.second) << ", "
             << get<2>(villager.second) << "]" << endl;
      }
    } else if (choice == 4) {
      cout << "Goodbye!" << endl;
    } else {
      cout << "Invalid choice." << endl;
    }
  }

  return 0;
}
