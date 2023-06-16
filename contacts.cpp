/** Implementation of functions for a vector-based contacts list
@file contacts.cpp
@author Angel Fuentes
*/

#include "contacts.h"
#include <iostream>
#include <vector>
using namespace std;

int lookup_index(const vector<vector<string>>& contacts, string name) {
  for (int i = 0; i < contacts.size(); i++) {
    if (contacts[i][NAME_INDEX] == name) {
      return i;
    }
  }
  return -1;
}

bool lookup_info(const vector<vector<string>>& contacts, string name,
                 string& address, string& phone, string& email) {
  int i = lookup_index(contacts, name);
  if (i < 0) {
    return false;
  }
  address = contacts[i][ADDRESS_INDEX];
  phone = contacts[i][PHONE_INDEX];
  email = contacts[i][EMAIL_INDEX];
  return true;
}

void update_address(vector<vector<string>>& contacts, string name,
                    string address) {
  int i = lookup_index(contacts, name);

  if (i < 0) {
    return;
  }

  contacts[i][ADDRESS_INDEX] = address;
}

void update_phone(vector<vector<string>>& contacts, string name, string phone) {
  int i = lookup_index(contacts, name);

  if (i < 0) {
    return;
  }

  contacts[i][PHONE_INDEX] = phone;
}

void update_email(vector<vector<string>>& contacts, string name, string email) {
  int i = lookup_index(contacts, name);

  if (i < 0) {
    return;
  }

  contacts[i][EMAIL_INDEX] = email;
}

bool add_contact(vector<vector<string>>& contacts, string name, string address,
                 string phone, string email) {
  int i = lookup_index(contacts, name);

  if (i >= 0) {
    return false;
  }

  contacts.push_back({name, address, phone, email});
  return true;
}

void delete_contact(vector<vector<string>>& contacts, string name) {
  int i = lookup_index(contacts, name);

  if (i < 0) {
    return;
  }

  auto it = contacts.begin() + i;
  contacts.erase(it);
}

bool add_contact_sorted(vector<vector<string>>& contacts, string name,
                        string address, string phone, string email) {
  int i = lookup_index(contacts, name);

  if (i >= 0) {
    return false;
  }
  int x = 0;

  while ( x < contacts.size() && name > contacts[x][NAME_INDEX]) {
    x++;
  }
  auto it = contacts.begin() + x;
  contacts.insert(it, {name, address, phone, email});
  return true;
}
