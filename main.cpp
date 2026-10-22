
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
  // Friendship level, species, and catchphrase
  map<string, tuple<int, string, string>> villagers;

  villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
  villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
  villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

  int choice = 0;
  string name;

  while (choice != 6) {
    cout << "\n1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (!cin) {
      cout << "Invalid input." << endl;
      return 1;
    }

    if (choice == 1) {
      // Add a villager with all three attributes
      int level;
      string species;
      string catchphrase;

      cout << "Villager name: ";
      cin >> name;

      if (villagers.find(name) != villagers.end()) {
        cout << name << " already exists." << endl;
      } else {
        cout << "Friendship level: ";
        cin >> level;

        if (!cin || level < 0 || level > 10) {
          cout << "Friendship must be between 0 and 10." << endl;
          return 1;
        }

        cout << "Species: ";
        getline(cin >> ws, species);

        cout << "Catchphrase: ";
        getline(cin, catchphrase);

        villagers[name] = make_tuple(level, species, catchphrase);
        cout << name << " added." << endl;
      }
    } else if (choice == 2) {
      // Deletion will be implemented in the next stage
      cout << "Delete Villager coming next." << endl;
    } else if (choice >= 3 && choice <= 5) {
      cout << "Villager name: ";
      cin >> name;

      auto it = villagers.find(name);

      if (it == villagers.end()) {
        cout << name << " not found." << endl;
      } else if (choice == 3) {
        // Increase friendship up to 10
        if (get<0>(it->second) < 10) {
          get<0>(it->second)++;
        }

        cout << name << "'s friendship level: "
             << get<0>(it->second) << endl;
      } else if (choice == 4) {
        // Decrease friendship down to 0
        if (get<0>(it->second) > 0) {
          get<0>(it->second)--;
        }

        cout << name << "'s friendship level: "
             << get<0>(it->second) << endl;
      } else {
        cout << it->first << " ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
      }
    } else if (choice == 6) {
      cout << "Goodbye!" << endl;
    } else {
      cout << "Invalid choice." << endl;
    }

    // Display all villagers after each operation
    if (choice >= 1 && choice <= 5) {
      cout << "\nVillager details:" << endl;

      for (auto villager : villagers) {
        cout << villager.first << " ["
             << get<0>(villager.second) << ", "
             << get<1>(villager.second) << ", "
             << get<2>(villager.second) << "]" << endl;
      }
    }
  }

  return 0;
}
