#include "tlist.h"
#include <gtest.h>

TEST(tlist, can_create_list_with_positive_length) {
	ASSERT_NO_THROW(List<int> l(5));
}

TEST(tlist, throw_when_create_list_with_negative_length) {
	ASSERT_ANY_THROW(List<int> l(-5, 0));
}

TEST(tlist, can_create_copied_list) {
	List<int> l1(4, 3);
	ASSERT_NO_THROW(List<int> l2(l1));
}

TEST(tlist, copied_list_has_its_own_memory) {
	List<int> l1(4, 1);
	List<int> l2(l1);
	EXPECT_NE(&l1, &l2);
}

TEST(tlist, can_assign_list_to_itself) {
	List<int> l(4);
	ASSERT_NO_THROW(l = l);
}

TEST(tlist, can_assign_lists_of_different_sizes) {
	List<int> l1(4,1), l2(8,3);
	ASSERT_NO_THROW(l1 = l2);
}

TEST(tlist, can_set_element_index) {
	List<int> l;
	l.insert_front(3);
	l.insert_front(2);
	l.insert_front(1);
	EXPECT_EQ(l[0], 1);
	EXPECT_EQ(l[2], 3);
}

TEST(tlist, correctly_copy_list) {
	List<int> l;
	l.insert_front(3);
	l.insert_front(2);
	l.insert_front(1);
	List<int> lc = l;
	for(int i=0;i<3;i++)
		EXPECT_EQ(l[i], lc[i]);
}

TEST(tlist, throw_when_set_element_with_negative_index) {
	List<int> l(4,1);
	ASSERT_ANY_THROW(l[-1]);
}

TEST(tlist, throw_when_set_element_with_too_large_index) {
	List<int> l(4,1);
	ASSERT_ANY_THROW(l[4]);
}

TEST(tlist, can_insert_front) {
	List<int> l(1);
	ASSERT_NO_THROW(l.insert_front(2));
}

TEST(tlist, can_insert_front_in_empty_list) {
	List<int> l;
	ASSERT_NO_THROW(l.insert_front(2));
}

TEST(tlist, can_give_begin_iterator) {
	List<int> l(2, 1);
	List<int>::iterator it = l.begin();
	EXPECT_EQ(1, *it);
}

TEST(tlist, iterator_can_use_increment) {
	List<int> l;
	l.insert_front(1);
	l.insert_front(2);
	List<int>::iterator it = l.begin();
	it++;
	EXPECT_TRUE(1 == *it);
}

TEST(tlist, can_give_size) {
	List<int> l(7, 4);
	EXPECT_EQ(7, l.size());
}

TEST(tlist, can_give_size_of_empty_list) {
	List<int> l;
	EXPECT_EQ(0, l.size());
}

TEST(tlist, can_find_element) {
	List<int> l;
	l.insert_front(3);
	l.insert_front(2);
	l.insert_front(1);
	ASSERT_NO_THROW(l.find(2));
}

TEST(tlist, correctly_returns_in_list_without_target_element) {
	List<int> l;
	l.insert_front(3);
	l.insert_front(2);
	l.insert_front(1);
	EXPECT_EQ(nullptr, l.find(7));
}

TEST(tlist, can_erase_front_element) {
	List<int> l;
	l.insert_front(3);
	l.insert_front(2);
	l.insert_front(1);
	ASSERT_NO_THROW(l.erase_front());
}

TEST(tlist, can_erase_element) {
	List<int> l;
	l.insert_front(3);
	l.insert_front(2);
	l.insert_front(1);
	ASSERT_NO_THROW(l.erase(l.find(2)));
}

TEST(tlist, can_erase_all_element) {
	List<int> l(5, 3);
	for (int i = 0; i < 5; ++i) {
		l.erase_front();
	}
	EXPECT_EQ(nullptr, l.get_first());
}

TEST(tlist, throw_when_erase_front_in_empty_list) {
	List<int> l;
	ASSERT_ANY_THROW(l.erase_front());
}

TEST(tlist, reverse_list) {
	List<int> l;
	l.insert_front(0);
	l.insert_front(1);
	l.insert_front(2);
	l.insert_front(3);
	l.insert_front(4);

	l.reverse();
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(i, l[i]);	
}

TEST(tlist, can_reverse_list_of_size_1) {
	List<int> l;
	l.insert_front(0);
	l.reverse();
	EXPECT_EQ(0, l[0]);
}

TEST(tlist, add_number_and_list) {
	List<int> l;
	l.insert_front(5);
	l.add(4);
	EXPECT_EQ(9, l[0]);
}

TEST(tlist, add_zero_to_empty_list) {
	List<int> l;
	l.add(0);
	EXPECT_EQ(0, l[0]);
}

TEST(tlist, add_number_to_empty_list) {
	List<int> l;
	l.add(456);
	EXPECT_EQ(4, l[0]);
	EXPECT_EQ(5, l[1]);
	EXPECT_EQ(6, l[2]);
}

TEST(tlist, add_number_and_list_equal_length) {
	List<int> l;
	l.insert_front(9);
	l.add(9);
	EXPECT_EQ(1, l[0]);
	EXPECT_EQ(8, l[1]);
}

TEST(tlist, add_with_of_creation_new_digit_number) {
	List<int> l;
	l.insert_front(6);
	l.insert_front(9);
	l.add(4);
	EXPECT_EQ(1, l[0]);
	EXPECT_EQ(0, l[1]);
	EXPECT_EQ(0, l[2]);
}

TEST(tlist,	can_add_when_number_longer_than_list) {
	List<int> l;
	l.insert_front(6);
	l.insert_front(9);

	l.add(997);
	EXPECT_EQ(1, l[0]);
	EXPECT_EQ(0, l[1]);
	EXPECT_EQ(9, l[2]);
	EXPECT_EQ(3, l[3]);
}
