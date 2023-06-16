/** Implementation of functions for an array-based contacts list
@file contacts_array.cpp
@author Hong Tai Wei
*/

#include "contacts_array.h"
#include <iostream>
using namespace std;

int lookup_index(const string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                 string name) {
  if (n_contacts < 0 || n_contacts > MAX_SIZE) {
    return -1;
  }

  for (int i = 0; i < n_contacts; i++) {
    if (contacts[i][NAME_INDEX] == name) {
      return i;
    }
  }

  return -1;
}

bool lookup_info(const string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                 string name, string& address, string& phone, string& email) {
  /* lookup_index is -1 when n_contacts is invalid or the name isn't found so we
   * don't need to check for validity of n_contacts before calling it */
  int i = lookup_index(contacts, n_contacts, name);

  if (i < 0) {
    return false;
  }

  // If the code reaches this point, the lookup was successful and i is valid.
  address = contacts[i][ADDRESS_INDEX];
  phone = contacts[i][PHONE_INDEX];
  email = contacts[i][EMAIL_INDEX];
  return true;
}

void update_address(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                    string name, string address) {
  int i = lookup_index(contacts, n_contacts, name);

  if (i < 0) {
    return;
  }

  contacts[i][ADDRESS_INDEX] = address;
}

void update_phone(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                  string name, string phone) {
  int i = lookup_index(contacts, n_contacts, name);

  if (i < 0) {
    return;
  }

  contacts[i][PHONE_INDEX] = phone;
}

void update_email(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                  string name, string email) {
  int i = lookup_index(contacts, n_contacts, name);

  if (i < 0) {
    return;
  }

  contacts[i][EMAIL_INDEX] = email;
}

bool add_contact(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                 string name, string address, string phone, string email) {
  if (n_contacts < 0 || n_contacts >= MAX_SIZE) {
    return false;
  }

  int i = lookup_index(contacts, n_contacts, name);

  if (i >= 0) {
    return false;
  }

  contacts[n_contacts][NAME_INDEX] = name;
  contacts[n_contacts][ADDRESS_INDEX] = address;
  contacts[n_contacts][PHONE_INDEX] = phone;
  contacts[n_contacts][PHONE_INDEX] = email;
  return true;
}
