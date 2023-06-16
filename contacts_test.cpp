/** Test cases for functions defined in contacts.h
@file contacts_test.cpp
@author Angel Fuentes
*/

#include "contacts.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>
#include "lib/test_utils.h"
using namespace std;

TEST(ContactsTest, LookupTests) {
  // Vector of contact info, to be used by all test cases in this section
  // TODO: Fill this.
  vector<vector<string>> contacts = {

      {"Chris", "123 Fair Road", "(111) 689-8744", "Jerry@fakeemail.com"},
      {"Daniel", "444 Duke Street", "(999)999-9999", "Sam@fakeemail.com"},
  };

  // 3 test cases for lookup_index()
  string name1 = "Chris";
  int expected_index1 = 0;
  bool expected_lookup_info1 = true;
  string expected_address1 = "123 Fair Road";
  string expected_phone1 = "(111) 689-8744";
  string expected_email1 = "Jerry@fakeemail.com";

  string name2 = "Daniel";
  int expected_index2 = 1;
  bool expected_lookup_info2 = true;
  string expected_address2 = "444 Duke Street";
  string expected_phone2 = "(999)999-9999";
  string expected_email2 = "Sam@fakeemail.com";

  string name3 = "Elon";
  int expected_index3 = -1;
  bool expected_lookup_info3 = false;
  string expected_address3 = "";
  string expected_phone3 = "";
  string expected_email3 = "";

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
  // TODO: Fill this out with a starting state for the contacts list.
  vector<vector<string>> contacts = {
      {"Andrew", "123 Cool Street", "(787)787-5656", "andrew@fakeemail.com"},
      {"Blake", "1111 Rare Road", "(989)678-9566", "blake@fakeemail.com"},
      {"Craig", "799 Bear Street", "(989)888-7878", "craig@fakeemail.com"},
  };

  // Call the update_address(), update_phone(), and update_email() functions.
  // TODO: Make 5 or more function calls (at least once each).
  update_address(contacts, "Andrew", "128 Lain Street");
  update_phone(contacts, "Andrew", "(787)899-3422");
  update_email(contacts, "Blake", "blakerules@fakeemail.com");
  update_address(contacts, "Craig", "897 Front Street");
  update_phone(contacts, "Craig", "(787)893-2234");
  // TODO: Don't forget to add at least 2 more function calls.

  // TODO: Fill this out with the expected final state of the contacts list.
  vector<vector<string>> expected_contacts = {
      {"Andrew", "128 Lain Street", "(787)899-3422", "andrew@fakeemail.com"},
      {"Blake", "1111 Rare Road", "(989)678-9566", "blakerules@fakeemail.com"},
      {"Craig", "897 Front Street", "(787)893-2234", "craig@fakeemail.com"},
  };

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}

TEST(ContactsTest, AddContactTest) {
  // TODO: Fill this out with a starting state for the contacts list.
  vector<vector<string>> contacts = {
      {"Alex", "400 Serial Street", "(232)131-1331", "alex@fakeemail.com"},
      {"Bryan", "923 Rare Road", "(949)787-1414", "bryan@fakeemail.com"},
  };

  // TODO: Fill these.
  // add_contact() will be called with this the 1st time:
  string name1 = "Craig";
  string address1 = "300 Lain Street";
  string phone1 = "(211)909-7877";
  string email1 = "craig@fakeemail.com";
  bool expected_result1 = true;

  // add_contact() will be called with this the 2nd time:
  string name2 = "Elon";
  string address2 = "120 Science Street";
  string phone2 = "(120)909-5655";
  string email2 = "tesla@fakeemali.com";
  bool expected_result2 = true;

  // add_contact() will be called with this the 3rd time:
  string name3 = "Craig";
  string address3 = "303 Nowhere Raod";
  string phone3 = "(999)000-9900";
  string email3 = "craigg@fakeemail.com";
  bool expected_result3 = false;

  // If you want to add additional calls to add_contact(), declare variables
  // with similar names here. Follow the same pattern.

  // TODO: Fill this out with the expected final state of the contacts list.
  vector<vector<string>> expected_contacts = {
      {"Alex", "400 Serial Street", "(232)131-1331", "alex@fakeemail.com"},
      {"Bryan", "923 Rare Road", "(949)787-1414", "bryan@fakeemail.com"},
      {"Craig", "300 Lain Street", "(211)909-7877", "craig@fakeemail.com"},
      {"Elon", "120 Science Street", "(120)909-5655", "tesla@fakeemali.com"},
  };

  // Do not edit anything after this unless you added more tests.
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
  // TODO: Fill this out with a starting state for the contacts list.
  vector<vector<string>> contacts = {
      {"Alice", "444 Lain Street", "(123)456-888", "aliceWorld@fakeemail.com"},
      {"Charlie", "444 Blank Road", "(979)979-9779", "Charile@fakeemail.com"},
      {"Elon", "999 Elm Street", "(898)678-1238", "Elon@fakeemail.com"},
      {"Frank", "899 Helm Street", "(343)434-9000", "Franky@fakeemail.com"},
      {"Hunter", "000 Rare Road", "(999)999-9999", "Hunter@fakeemail.com"},
  };

  // TODO: Make at least 3 calls to delete_contact().
  delete_contact(contacts, "Alice");
  delete_contact(contacts, "Frank");
  delete_contact(contacts, "Hunter");

  // TODO: Fill this out with the expected final state of the contacts list.
  vector<vector<string>> expected_contacts = {
      {"Charlie", "444 Blank Road", "(979)979-9779", "Charile@fakeemail.com"},
      {"Elon", "999 Elm Street", "(898)678-1238", "Elon@fakeemail.com"},
  };

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}

TEST(ContactsTest, AddContactSortedTest) {
  // TODO: Fill this out with a starting state for the contacts list.
  vector<vector<string>> contacts = {
      {"Alice", "444 Lain Street", "(123)456-888", "aliceWorld@fakeemail.com"},
      {"Elon", "999 Elm Street", "(898)678-1238", "Elon@fakeemail.com"},
      {"Hunter", "000 Rare Road", "(999)999-9999", "Hunter@fakeemail.com"},
  };

  // TODO: Fill these.
  // add_contact_sorted() will be called with this the 1st time:
  string name1 = "Bryan";
  string address1 = "900 Lain Road";
  string phone1 = "(989)009-7877";
  string email1 = "bryan@fakeemail.com";
  bool expected_result1 = true;

  // add_contact() will be called with this the 2nd time:
  string name2 = "Craig";
  string address2 = "000 Berserk Road";
  string phone2 = "(090)000-8789";
  string email2 = "craig88@gmail.com";
  bool expected_result2 = true;

  // add_contact() will be called with this the 3rd time:
  string name3 = "Izaak";
  string address3 = "909 Main Street";
  string phone3 = "(949)909-9900";
  string email3 = "izaak@fakeemail.com";
  bool expected_result3 = true;

  // If you want to add additional calls to add_contact(), declare variables
  // with similar names here. Follow the same pattern.

  // TODO: Fill this out with the expected final state of the contacts list.
  vector<vector<string>> expected_contacts = {
      {"Alice", "444 Lain Street", "(123)456-888", "aliceWorld@fakeemail.com"},
      {"Bryan", "900 Lain Road", "(989)009-7877", "bryan@fakeemail.com"},
      {"Craig", "000 Berserk Road", "(090)000-8789", "craig88@gmail.com"},
      {"Elon", "999 Elm Street", "(898)678-1238", "Elon@fakeemail.com"},
      {"Hunter", "000 Rare Road", "(999)999-9999", "Hunter@fakeemail.com"},
      {"Izaak", "909 Main Street", "(949)909-9900", "izaak@fakeemail.com"},
  };

  // Do not edit anything after this unless you added more tests.
  // If you added more tests, add additional GENERATE_ADD_CONTACT_TEST(n);
  // lines below the existing ones. There should be the same number of
  // these lines as function calls and they should all be numbered in order.
  GENERATE_ADD_CONTACT_SORTED_TEST(1);
  GENERATE_ADD_CONTACT_SORTED_TEST(2);
  GENERATE_ADD_CONTACT_SORTED_TEST(3);

  // Do not change this code
  EXPECT_THAT(contacts, ::testing::ContainerEq(expected_contacts));
}
