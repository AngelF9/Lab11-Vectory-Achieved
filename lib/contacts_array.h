/** Header file for contacts_array.cpp. Do not alter this file.
@file contacts_array.h
@author Hong Tai Wei
*/

#include <iostream>
using namespace std;

#ifndef CONTACTS_ARRAY_H
#define CONTACTS_ARRAY_H

// Max number of people allowed in the contact list
const int MAX_SIZE = 50;

// Size of an array representing a single contact's info
const int CONTACT_SIZE = 4;

// Index to find someone's name in an array representing a single contact
const int NAME_INDEX = 0;
// Index to find someone's address in an array representing a single contact
const int ADDRESS_INDEX = 1;
// Index to find someone's phone in an array representing a single contact
const int PHONE_INDEX = 2;
// Index to find someone's email in an array representing a single contact
const int EMAIL_INDEX = 3;

/**
 * @brief Looks up the index that a contact with this name is stored at
 *
 * If n_contacts is invalid or if name is not in the contacts array, returns -1.
 * Otherwise, returns the index that this contact is found at.
 *
 * @param[in] contacts Array containing contacts information
 * @param n_contacts Number of entries in the contacts list
 * @param name Name of person to look up
 * @return Index of the contact with this name, or -1 if unsuccessful.
 */
int lookup_index(const string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                 string name);

/**
 * @brief Updates reference variables with the info of a person in the contacts
 * list
 *
 * The lookup will succeed if n_contacts is valid and name is the name of
 * someone in contacts. If the lookup is successful, address, phone, and email
 * will be updated with the appropriate values. If the lookup is unsuccessful,
 * they will not be changed.
 *
 * @param[in] contacts Array containing contacts information
 * @param n_contacts Number of entries in the contacts list
 * @param name Name of person to look up
 * @param[out] address,phone,email References to store the info in
 * @return True if the lookup succeeded, false if it failed.
 */
bool lookup_info(const string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                 string name, string& address, string& phone, string& email);

/**
 * @brief Updates the address of the specified person in contacts to the
 * specified address
 *
 * If n_contacts is invalid or name is not in contacts, does nothing.
 *
 * @param[in] contacts Array containing contacts information
 * @param n_contacts Number of entries in the contacts list
 * @param name Name of person to look up
 * @param address New address
 * @return void
 */
void update_address(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                    string name, string address);

/**
 * @brief Updates the phone number of the specified person in contacts to the
 * specified phone number
 *
 * If n_contacts is invalid or name is not in contacts, does nothing.
 *
 * @param[in] contacts Array containing contacts information
 * @param n_contacts Number of entries in the contacts list
 * @param name Name of person to look up
 * @param phone New phone number
 * @return void
 */
void update_phone(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                  string name, string phone);

/**
 * @brief Updates the email of the specified person in contacts to the specified
 * email
 *
 * If n_contacts is invalid or name is not in contacts, does nothing.
 *
 * @param[in] contacts Array containing contacts information
 * @param n_contacts Number of entries in the contacts list
 * @param name Name of person to look up
 * @param email New email
 * @return void
 */
void update_email(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                  string name, string email);

/**
 * @brief Adds a contact to the back of the contacts list, if possible
 *
 * If n_contacts is invalid or the contacts list is full, or name is already in
 * contacts, do not add the contact and return false. Otherwise, add the contact
 * and return true.
 *
 * @param[in,out] contacts Array containing contacts information
 * @param n_contacts Number of entries in the contacts list
 * @param name,address,phone,email Info of person to add
 * @return True if successful, false if not
 */
bool add_contact(string contacts[MAX_SIZE][CONTACT_SIZE], int n_contacts,
                 string name, string address, string phone, string email);

#endif  // CONTACTS_ARRAY_H
