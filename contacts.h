/** Header file for contacts.cpp. Do not alter this file.
@file contacts.h
@author Hong Tai Wei
*/

#include <iostream>
#include <vector>
using namespace std;

#ifndef CONTACTS_H
#define CONTACTS_H

/// Index to find someone's name in an array representing a single contact
const int NAME_INDEX = 0;
/// Index to find someone's address in an array representing a single contact
const int ADDRESS_INDEX = 1;
/// Index to find someone's phone in an array representing a single contact
const int PHONE_INDEX = 2;
/// Index to find someone's email in an array representing a single contact
const int EMAIL_INDEX = 3;

/**
 * @brief Looks up the index that a contact with this name is stored at
 *
 * If name is not in the contacts array, returns -1.
 * Otherwise, returns the index that this contact is found at.
 *
 * @param[in] contacts Vector containing contacts information
 * @param name Name of person to look up
 * @return Index of the contact with this name, or -1 if unsuccessful.
 */
int lookup_index(const vector<vector<string>>& contacts, string name);

/**
 * @brief Updates reference variables with the info of a person in the contacts
 * list
 *
 * The lookup will succeed if name is the name of someone in contacts. If the
 * lookup is successful, address, phone, and email will be updated with the
 * appropriate values. If the lookup is unsuccessful, they will not be changed.
 *
 * @param[in] contacts Vector containing contacts information
 * @param name Name of person to look up
 * @param[out] address,phone,email References to store the info in
 * @return True if the lookup succeeded, false if it failed.
 */
bool lookup_info(const vector<vector<string>>& contacts, string name,
                 string& address, string& phone, string& email);

/**
 * @brief Updates the address of the specified person in contacts to the
 * specified address
 *
 * If name is not in contacts, does nothing.
 *
 * @param[in] contacts Vector containing contacts information
 * @param name Name of person to look up
 * @param address New address
 * @return void
 */
void update_address(vector<vector<string>>& contacts, string name,
                    string address);

/**
 * @brief Updates the phone number of the specified person in contacts to the
 * specified phone number
 *
 * If name is not in contacts, does nothing.
 *
 * @param[in] contacts Vector containing contacts information
 * @param name Name of person to look up
 * @param phone New phone number
 * @return void
 */
void update_phone(vector<vector<string>>& contacts, string name, string phone);

/**
 * @brief Updates the email of the specified person in contacts to the
 * specified email
 *
 * If name is not in contacts, does nothing.
 *
 * @param[in] contacts Vector containing contacts information
 * @param name Name of person to look up
 * @param email New email
 * @return void
 */
void update_email(vector<vector<string>>& contacts, string name, string email);

/**
 * @brief Adds a contact to the back of the contacts list, if possible
 *
 * If name is already in contacts, do not add the contact and return false.
 * Otherwise, add the contact at the end of the contacts list and return true.
 *
 * @param[in,out] contacts Vector containing contacts information
 * @param name,address,phone,email Info of person to add
 * @return True if successful, false if not
 */
bool add_contact(vector<vector<string>>& contacts, string name, string address,
                 string phone, string email);

// Part 2 functions

/**
 * @brief Deletes a contact from the contacts list, if possible
 *
 * If name is not already in contacts, do not do anything and return.
 * Otherwise, remove contact with that name from the contacts list.
 *
 * @param[in,out] contacts Vector containing contacts information
 * @param name Name of person to remove
 * @return void
 */
void delete_contact(vector<vector<string>>& contacts, string name);

/**
 * @brief Adds a contact to the contacts list, if possible, and keep the list
 * sorted by the contact name
 *
 * If name is already in contacts, do not add the contact and return false.
 * Otherwise, add the contact while keeping the list sorted and return true.
 *
 * @param[in,out] contacts Vector containing contacts information
 * @param name,address,phone,email Info of person to add
 * @return True if successful, false if not
 */
bool add_contact_sorted(vector<vector<string>>& contacts, string name,
                        string address, string phone, string email);

#endif  // CONTACTS_H
