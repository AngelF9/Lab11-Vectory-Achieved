/** Header file for contactstest.cpp. Do not alter this file.
@file test_utils.h
@author Hong Tai Wei
*/

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#define GEN_LOOKUP_INFO_TEST(i)                                            \
  {                                                                        \
    actual_address = "";                                                   \
    actual_phone = "";                                                     \
    actual_email = "";                                                     \
    EXPECT_EQ(lookup_info(contacts, name##i, actual_address, actual_phone, \
                          actual_email),                                   \
              expected_lookup_info##i);                                    \
    if (expected_lookup_info##i) {                                         \
      EXPECT_EQ(actual_address, expected_address##i);                      \
      EXPECT_EQ(actual_phone, expected_phone##i);                          \
      EXPECT_EQ(actual_email, expected_email##i);                          \
    }                                                                      \
  }

#define GENERATE_ADD_CONTACT_TEST(i)                                          \
  {                                                                           \
    int old_size = contacts.size();                                           \
    ASSERT_EQ(add_contact(contacts, name##i, address##i, phone##i, email##i), \
              expected_result##i);                                            \
    if (expected_result##i) {                                                 \
      ASSERT_EQ(contacts.size(), old_size + 1);                               \
      vector<string> new_contact = {name##i, address##i, phone##i, email##i}; \
      EXPECT_THAT(contacts.back(), ::testing::ContainerEq(new_contact));      \
    }                                                                         \
  }

#define GENERATE_ADD_CONTACT_SORTED_TEST(i)                                    \
  {                                                                            \
    int old_size = contacts.size();                                            \
    ASSERT_EQ(                                                                 \
        add_contact_sorted(contacts, name##i, address##i, phone##i, email##i), \
        expected_result##i);                                                   \
    if (expected_result##i) {                                                  \
      ASSERT_EQ(contacts.size(), old_size + 1);                                \
    }                                                                          \
  }

#endif  // TEST_UTILS_H
