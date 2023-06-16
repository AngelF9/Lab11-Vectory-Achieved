# Lab 11: Vectory Achieved

In this lab, you will learn how to:
- use vectors
- use iterators

You will write a series of functions related to storing contacts (separated into 2 parts), then test them using the GoogleTest framework.

## File structure

* `Makefile` - Configuration for `make`.
* `contacts.cpp` - Your code goes here.
* `contacts_test.cpp` - Your tests go here.
* `contacts.h` - Header file for `contacts.cpp`, already written for you.
* `googletest/` - Contains code for the GoogleTest framework.
* `lib/` - Contains library files you may reference.
    * `contacts_array.cpp` - Implemention of some of the contacts related functions, but using arrays instead.
    * `contacts_array.h` - Header for `contacts_array.cpp`.
    * `test_utils.h` - Some helper functions for the testing framework, irrelevant to you.

**Do not change any files other than `contacts.cpp` and `contacts_test.cpp`!**

## Make commands

You have the same `make` commands (format, test, all, clean) as usual except there is no `make build` command. **Don't use g++**.

## Part 1

#### Convert code that uses arrays to code that uses vectors

For this part, you will write code in `contacts.cpp` that does the same exact thing as the code in `contacts_array.cpp` but uses vectors instead of arrays.

Read the code and documentation in `contacts_array.cpp` and `contacts_array.h`. This code uses arrays to store a contacts list (name, address, phone, and email).

### The contacts list

The array-based version uses a 2D string array to store contacts. Each row of the array has the name, address, phone number, and email of a person (in that order).
There is a `MAX_SIZE` for how many people can be stored in this contacts list and `n_contacts` represents how many people are actually in it.

The vector-based version uses a 2D string vector. Each row of the vector has the name, address, phone number, and email of a person (in that order). **The vector based version does not have a max size, and should not limit the number of contacts that can be stored.**

For both versions, there are constants like `NAME_INDEX`, `ADDRESS_INDEX`, `PHONE_INDEX`, and `EMAIL_INDEX` defined. You should use these values if you need the index for where something is stored. See `contacts_array.cpp` for examples. 

### Test cases

Write test cases in `contacts_test.cpp`. Follow the instructions for the specific test cases:

#### `TEST(ContactsTest, LookupTests)`

This tests `lookup_index()` and `lookup_info()`.

**Do the following:**

1. Come up with a single contacts list that you will use for all the test cases for these two functions and change the value of the `contacts` vector accordingly.
1. Write 3 test cases. For each test case, come up with these things:
   * name: The name to look up
   * expected_index: The index that name is found at (or -1 if the name is not present in the contacts list)
   * expected_lookup_info: A bool (`true` or `false`) for the expected return value of calling `lookup_info()` with this name.
   * expected_address, expected_phone, expected_email: Leave these as the empty string if the name isn't present in the contacts list, otherwise the values should be the address/phone/email corresponding to the name.

**Example:**

1. Here is an example of a contacts list containing info for 2 people (Alice and Bob). Remember that the order of things is: name, address, phone, email.
  ```c++
  vector<vector<string>> contacts = {
    {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  };
  ```

2. If you want to look up Alice's info for the first test case, `expected_index` would be 0 since Alice's info is stored at index 0. `expected_lookup_info` is `true` because `lookup_info` should be able to find her info. Then her expected address, phone, and email are the address, phone, and email stored in the contacts list. So you would write the following:
  ```c++
  string name1 = "Alice";
  int expected_index1 = 0;
  bool expected_lookup_info1 = true;
  string expected_address1 = "123 Main Street";
  string expected_phone1 = "(123)456-7890";
  string expected_email1 = "alice@fakeemail.com";
  ```

3. If you want to use the name `"Charlie"` for the second test case, `expected_index` is -1 and `expected_lookup_info` is `false` since there is no one named Charlie in `contacts`. Then you would just leave the expected address/phone/email as `""`.
  ```c++
  string name2 = "Charlie";
  int expected_index2 = -1;
  bool expected_lookup_info2 = false;
  string expected_address2 = "";
  string expected_phone2 = "";
  string expected_email2 = "";
  ```

#### `TEST(ContactsTest, UpdateTests)`

This tests `update_address()`, `update_phone()` and `update_email()`.

**Do the following:**

1. Come up with a single contacts list that you will use as a starting point and set the value of the `contacts` vector accordingly.
1. Call the `update_address()`, `update_phone()`, and `update_email()` functions. You must make at least 5 function calls total and you must call each function at least once.
1. Figure out what the contacts array should look like once all of the function calls are done, and assign that value to `expected_contacts`.

**Example:**

1. Here is an example of a contacts list containing the info for 2 people (Alice and Bob). Remember that the order of things is: name, address, phone, email.
  ```c++
  vector<vector<string>> contacts = {
    {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  };
  ```

2. If you want to change Alice's phone number to `"(111)111-1111"`, then you would call `update_phone(contacts, "Alice", "(111)111-1111");`. Afterwards, you should write at least 4 more function calls and make sure that the other two functions get called at least once.

3. For this example with just a single function call, the only thing that should change in the contacts list is Alice's phone number. Everything else remains the same:
  ```c++
  vector<vector<string>> expected_contacts = {
    {"Alice", "123 Main Street", "(111)111-1111", "alice@fakeemail.com"},
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  };
  ```

#### `TEST(ContactsTest, AddContactTest)`

This tests `add_contact()`.

**Do the following:**

1. Come up with a single contacts list that you will use as a starting point and set the value of the `contacts` vector accordingly.
1. For each test case, come up with the name, address, phone, and email of someone to try adding and fill those in in the code. Also set `expected_result` to `true` or `false` based on what `add_contact()` should return when called with those inputs.
1. Write 3 test cases and fill them in where specified in the code. 
1. Figure out what the contacts array should look like once all of the function calls are done, and assign that value to `expected_contacts`.

**Example:**

1. Here is an example of a contacts list containing info for 2 people (Alice and Bob). Remember that the order of things is: name, address, phone, email.
  ```c++
  vector<vector<string>> contacts = {
    {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  };
  ```

2. If you want to add someone named Charlie with the address `"999 A Street"`, phone number `"(888)888-8888"`, and email address `"charlie@fakeemail.com"`, You should expect this function call to succeed because there's nobody named Charlie in the contacts list. So the first test case would look like this:
  ```c++
  string name1 = "Charlie";
  string address1 = "999 A Street";
  string phone1 = "(888)888-8888";
  string email1 = "charlie@fakeemail.com";
  bool expected_result1 = true;
  ```

3. If you want to add another person named Charlie, you should expect this function call to fail because there is already someone named Charlie in the contacts list after the previous addition. So the second test case could look like this:
  ```c++
  string name2 = "Charlie";
  string address2 = "12345 Somewhere Road";
  string phone2 = "(000)000-0000";
  string email2 = "charlie2@fakeemail.com";
  bool expected_result2 = false;
  ```

4. For this example with just 2 function calls, the contacts list should end up having the first Charlie's information but not the second:
  ```c++
  vector<vector<string>> expected_contacts = {
    {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
    {"Charlie", "999 A Street", "(888)888-8888", "charlie@fakeemail.com"},
  };
  ```

### Implementation

Now implement the 6 functions below:
* lookup_index
* lookup_info
* update_address
* update_phone
* update_email
* add_contact - remember that there is no limit to how many contacts can be stored in the vector-based version.

You may use any function in the [C++ Vector standard library](http://www.cplusplus.com/reference/vector/vector/) including ones we have not covered in class. You may not use other external library functions.

A few hints / reminders:
* Do not use arrays at all in your implementation.
* For the first 5 functions, you should be able to write code that is very similar to the code in `contacts_arrays.cpp`. Vectors are very similar to arrays so you should not need to change many things to make your code work.
* Since vectors know how big they are, these functions no longer need to pass an argument about the size, and there is no need to check for validity.
* Since vectors can be resized, there is also no need to worry about having a max size. For the `add_contact()` function, since there is no maximum size, you can always add the contact if there's not someone with that name already.
* For `add_contact()`, it may be easier for you if you first construct a 1D string vector containing the new contact info, then insert it at the end of the vector.

### Running your code

There is no `make build` command this time. Test your code with the unit tests by running `make test`.

## Part 2

In this part you will implement two functions:
* `void delete_contact(vector<vector<string>>& contacts, string name);`
* `bool add_contact_sorted(vector<vector<string>>& contacts, string name, string address, string phone, string email);`

### Function specifications

#### `delete_contact()`
   
**Arguments:** The contacts list and the name of a contact to delete.
   
**Function behavior:** If there is no contact with this name in the contacts list, return without changing anything. Otherwise, change the `contacts` vector so that the entry for the contact with that name is gone. Do not change anything else.

**Examples:** Suppose we have the following vector for `contacts`:
```c++
{ {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
  {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  {"Cathy", "999 A Street", "(111)111-1111", "cathy@fakeemail.com"} }
```

If we call `delete_contact(contacts, "Dan");`, then `contacts` is unchanged because there is nobody named Dan.

If we call `delete_contact(contacts, "Bob");`, then `contacts` becomes the following vector of size 2 after removing Bob's info:
```c++
{ {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
  {"Cathy", "999 A Street", "(111)111-1111", "cathy@fakeemail.com"} }
```

If we call `delete_contact(contacts, "Cathy");` then `contacts` becomes a vector of size 1 containing just Alice's info:
```c++
{ {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"} }
```

And if we call `delete_contact(contacts, "Alice");` then `contacts` becomes the empty vector (size 0, contains nothing).

#### `add_contact_sorted()`

**Arguments:** A contacts list which is sorted alphabetically by name, and the name/address/phone/email of a new contact to add.

**Function behavior:** If a contact with this name is already in `contacts`, do not add anything and return false. Otherwise, add the new contact, but add it at the right place in the `contacts` vector so that it stays sorted in alphabetical order.

**Examples:** Suppose we have the following vector for `contacts`:
```c++
{ {"Anne", "999 Main Street", "(222)222-2222", "anne@fakeemail.com"},
  {"Cathy", "999 A Street", "(111)111-1111", "cathy@fakeemail.com"} }
```

If we call `add_contact(contacts, "Anne", "111 Some Road", "(789)012-3456", "anne@somewhere.com");` the function should return `false` and not change `contacts` since there is already someone named Anne.

If we call `add_contact(contacts, "Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com");` then Bob's info should be added between Anne and Cathy's info to keep things alphabetized by name:
```c++
{ {"Anne", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
  {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  {"Cathy", "999 A Street", "(111)111-1111", "cathy@fakeemail.com"} }
```

Then if we call `add_contact(contacts, "Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com");` Alice should be added before Anne to keep things sorted:
```c++
{ {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
  {"Anne", "999 Main Street", "(222)222-2222", "anne@fakeemail.com"},
  {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
  {"Cathy", "999 A Street", "(111)111-1111", "cathy@fakeemail.com"} }
```

### Test cases

Follow these instructions to write test cases for the 2 functions you will implement in Part 2:

#### `TEST(ContactsTest, DeleteContactTest)`

This tests `delete_contact()`.

**Do the following:**

1. Come up with a single contacts list that you will use as a starting point and set the value of the `contacts` vector accordingly.
1. Call the `delete_contact()` function at least 3 times.
1. Figure out what the contacts array should look like once all of the function calls are done, and assign that value to `expected_contacts`.

**Example:**

1. Here is an example of a contacts list containing info for 2 people (Alice and Bob). Remember that the order of things is: name, address, phone, email.
  ```c++
  vector<vector<string>> contacts = {
    {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"}.
  };
  ```

2. If you call `delete_contact(contacts, "Charlie");`, the `contacts` vector shouldn't change because there is nobody to delete. If you call `delete_contact(contacts, "Alice");`, then the vector should only contain Bob's info after the function returns.

3. For this example, after these 2 function calls, only Bob's info remains in the contacts list:
  ```c++
  vector<vector<string>> expected_contacts = {
    {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"}.
  };
  ```

#### `TEST(ContactsTest, AddContactSortedTest)`

This tests `add_contact_sorted()`.

**Do the following:**

Follow the same process as for `TEST(ContactsTest, AddContactTest)` in Part 1, but this time, remember that the final result should be sorted alphabetically by name.

**Example:**

The same example as for `TEST(ContactsTest, AddContactTest)` in Part 1 works.

### Implementation

Now implement the functions.

Reminder: You may use any function in the [C++ Vector standard library](http://www.cplusplus.com/reference/vector/vector/) including ones we have not covered in class. You may not use other external library functions.

Hints:
* You can use comparison operators like `==` and `<` and `>` to compare two strings. Operators like `<` use alphabetical order for comparison. This was discussed in more detail in an earlier lecture.

### Running your code

Run `make test` to test your program. There is no `make build` command for this lab.
