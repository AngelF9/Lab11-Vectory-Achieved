/** Test cases for functions defined in contacts.h
@file contacts_test.cpp
@author YOUR NAME HERE
*/

#include "contacts.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "lib/test_utils.h"
using namespace std;

TEST(ContactsTest, LookupTests) {
  // Vector of contact info, to be used by all test cases in this section
  vector<vector<string>> contacts = {
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
  };

  // 3 test cases for lookup_index()
  string name1 = "Alice";
  int expected_index1 = 0;
  bool expected_lookup_info1 = true;
  string expected_address1 = "123 Main Street";
  string expected_phone1 = "(123)456-7890";
  string expected_email1 = "alice@fakeemail.com";

  string name2 = "Drew";
  int expected_index2 = -1;
  bool expected_lookup_info2 = false;
  string expected_address2 = "";
  string expected_phone2 = "";
  string expected_email2 = "";

  string name3 = "Carly";
  int expected_index3 = 2;
  bool expected_lookup_info3 = true;
  string expected_address3 = "999 University Ave";
  string expected_phone3 = "(200)300-4000";
  string expected_email3 = "carly@fakeemail.com";

  // Don't change this code
  EXPECT_EQ(lookup_index(contacts, name1), expected_index1);
  EXPECT_EQ(lookup_index(contacts, name2), expected_index2);
  EXPECT_EQ(lookup_index(contacts, name3), expected_index3);

  string actual_address, actual_phone, actual_email;

  GEN_LOOKUP_INFO_TEST(1);
  GEN_LOOKUP_INFO_TEST(2);
  GEN_LOOKUP_INFO_TEST(3);
}

TEST(ContactsTest, UpdateTests) {
  vector<vector<string>> contacts = {
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
  };

  // Call the update_address(), update_phone(), and update_email() functions.
  update_address(contacts, "Alice", "321 Rodeo Drive");
  update_phone(contacts, "Bob", "(888)888-8888");
  update_email(contacts, "Carly", "carly@fakeemail.com");
  update_phone(contacts, "Drew", "(777)777-7777");
  update_address(contacts, "Alice", "444 Rodeo Ave");

  vector<vector<string>> expected_contacts = {
      {"Alice", "444 Rodeo Ave", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(888)888-8888", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
  };

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}

TEST(ContactsTest, AddContactTest) {
  vector<vector<string>> contacts = {
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
  };

  // add_contact() will be called with this the 1st time:
  string name1 = "Drew";
  string address1 = "888 Lucky Street";
  string phone1 = "(444)444-4444";
  string email1 = "drew@fakeemail.com";
  bool expected_result1 = true;

  // add_contact() will be called with this the 2nd time:
  string name2 = "Alice";
  string address2 = "123 Main Street";
  string phone2 = "(123)456-7890";
  string email2 = "alice@fakeemail.com";
  bool expected_result2 = false;

  // add_contact() will be called with this the 3rd time:
  string name3 = "Drew";
  string address3 = "999 Lucky Street";
  string phone3 = "(444)444-4444";
  string email3 = "drew@fakeemail.com";
  bool expected_result3 = false;

  // If you want to add additional calls to add_contact(), declare variables
  // with similar names here. Follow the same pattern.

  vector<vector<string>> expected_contacts = {
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
      {"Drew", "888 Lucky Street", "(444)444-4444", "drew@fakeemail.com"},
  };

  // Do not edit anything after this unless you added more tests
  // If you added more tests, add additional GENERATE_ADD_CONTACT_TEST(n);
  // lines below the existing ones. There should be the same number of
  // these lines as function calls and they should all be numbered in order.
  GENERATE_ADD_CONTACT_TEST(1);
  GENERATE_ADD_CONTACT_TEST(2);
  GENERATE_ADD_CONTACT_TEST(3);

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}

TEST(ContactsTest, DeleteContactTest) {
  vector<vector<string>> contacts = {
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
      {"Drew", "888 Lucky Street", "(444)444-4444", "drew@fakeemail.com"},
  };

  delete_contact(contacts, "Alice");
  delete_contact(contacts, "Eric");
  delete_contact(contacts, "Alice");

  vector<vector<string>> expected_contacts = {
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
      {"Drew", "888 Lucky Street", "(444)444-4444", "drew@fakeemail.com"},
  };

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}

TEST(ContactsTest, AddContactSortedTest) {
  vector<vector<string>> contacts = {
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Drew", "888 Lucky Street", "(444)444-4444", "drew@fakeemail.com"},
  };

  // add_contact_sorted() will be called with this the 1st time:
  string name1 = "Carly";
  string address1 = "999 University Ave";
  string phone1 = "(200)300-4000";
  string email1 = "carly@fakeemail.com";
  bool expected_result1 = true;

  // add_contact() will be called with this the 2nd time:
  string name2 = "Carly";
  string address2 = "888 University Ave";
  string phone2 = "(200)300-4000";
  string email2 = "carly@fakeemail.com";
  bool expected_result2 = false;

  // add_contact() will be called with this the 3rd time:
  string name3 = "Ahilan";
  string address3 = "999 Grand Boulevard";
  string phone3 = "(987)654-3210";
  string email3 = "ahilan@fakeemail.com";
  bool expected_result3 = true;

  // If you want to add additional calls to add_contact(), declare variables
  // with similar names here. Follow the same pattern.

  vector<vector<string>> expected_contacts = {
      {"Ahilan", "999 Grand Boulevard", "(987)654-3210",
       "ahilan@fakeemail.com"},
      {"Alice", "123 Main Street", "(123)456-7890", "alice@fakeemail.com"},
      {"Bob", "1111 Blahblahblah Road", "(999)999-9999", "bob@fakeemail.com"},
      {"Carly", "999 University Ave", "(200)300-4000", "carly@fakeemail.com"},
      {"Drew", "888 Lucky Street", "(444)444-4444", "drew@fakeemail.com"},
  };

  // Do not edit anything after this unless you added more tests
  // If you added more tests, add additional GENERATE_ADD_CONTACT_TEST(n);
  // lines below the existing ones. There should be the same number of
  // these lines as function calls and they should all be numbered in order.
  GENERATE_ADD_CONTACT_SORTED_TEST(1);
  GENERATE_ADD_CONTACT_SORTED_TEST(2);
  GENERATE_ADD_CONTACT_SORTED_TEST(3);

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}
