// boost_game_test.cpp

#define BOOST_TEST_MODULE game
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "functions.hpp"

BOOST_AUTO_TEST_SUITE(test_game);

BOOST_AUTO_TEST_CASE(test_angle) {
  BOOST_REQUIRE(angle(::QPointF{0, 0}, ::QPointF{1, 1}));

  BOOST_CHECK_CLOSE_FRACTION(angle(::QPointF{0, 0}, ::QPointF{5, 5}), 45, 0.01f);

  BOOST_CHECK_CLOSE_FRACTION(angle(::QPointF{0, 0}, ::QPointF{5, 0}), 0, 0.01f);

  BOOST_CHECK_CLOSE_FRACTION(angle(::QPointF{0, 0}, ::QPointF{0, 5}), 90, 0.01f);

  BOOST_CHECK_CLOSE_FRACTION(angle(::QPointF{0, 0}, ::QPointF{0, -5}), 270, 0.01f);

  BOOST_CHECK_CLOSE_FRACTION(angle(::QPointF{0, 0}, ::QPointF{-5, -5}), 225, 0.01f);

  BOOST_CHECK_CLOSE_FRACTION(angle(::QPointF{0, 0}, ::QPointF{-5, 0}), 180, 0.01f);
};

BOOST_AUTO_TEST_SUITE_END();
