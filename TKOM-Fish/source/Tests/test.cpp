//
// Created by Wojtek on 29/05/2020.
//

#include <my_class.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( my_test )
{
    my_class test_object( "qwerty" );

    BOOST_CHECK( test_object.is_valid() );
}