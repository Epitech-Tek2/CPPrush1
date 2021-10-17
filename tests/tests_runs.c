/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush1-clement.muth
** File description:
** tests_runs
*/

#include <criterion/criterion.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include "new.h"
#include "point.h"
#include "vertex.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "player.h"
#include "array.h"

Test(point_str_easy, point_tests)
{
    Object *point = new(Point, 42, -42);
    const char *str = str(point);

    cr_assert_str_eq(str, "<Point (42, -42)>");
    delete(point);
}

// test point addition
Test(point_str_addition, point_tests)
{
    Object *my_point = new(Point, 4242, 4242);
    Object *my_point2 = new(Point, 4242, 4242);
    Object *add = addition(my_point, my_point2);

    cr_assert_str_eq(str(add), "<Point (8484, 8484)>");
    delete(my_point);
    delete(my_point2);
    delete(add);
}

// test point subtraction
Test(point_str_subtraction, point_tests)
{
    Object *my_point = new(Point, 4242, 4242);
    Object *my_point2 = new(Point, 4242, 4242);
    Object *sub = subtraction(my_point, my_point2);

    cr_assert_str_eq(str(sub), "<Point (0, 0)>");
    delete(my_point);
    delete(my_point2);
    delete(sub);
}

Test(vertex_str_easy, point_tests)
{
    Object *vertex = new(Vertex, 0, 1, 2);
    const char *str = str(vertex);

    cr_assert_str_eq(str, "<Vertex (0, 1, 2)>");
    delete(vertex);
}

// test vertex addition
Test(vertex_str_addition, vertex_tests)
{
    Object *my_vertex = new(Vertex, 4242, 4242, 4242);
    Object *my_vertex2 = new(Vertex, 4242, 4242, 4242);
    Object *add = addition(my_vertex, my_vertex2);

    cr_assert_str_eq(str(add), "<Vertex (8484, 8484, 8484)>");
    delete(my_vertex);
    delete(my_vertex2);
    delete(add);
}

// test vertex subtraction
Test(vertex_str_subtraction, vertex_tests)
{
    Object *my_vertex = new(Vertex, 12726, 8484, 8484);
    Object *my_vertex2 = new(Vertex, 12726, 8484, 8484);
    Object *sub = subtraction(my_vertex, my_vertex2);

    cr_assert_str_eq(str(sub), "<Vertex (0, 0, 0)>");
    delete(my_vertex);
    delete(my_vertex2);
    delete(sub);
}

// Int tests

// test int to string
Test(int_str_str, point_tests)
{
    Object *my_int = new(Int, 4242);

    cr_assert_str_eq(str(my_int), "<Int (4242)>");
    delete(my_int);
}

// test int addition
Test(int_str_addition, point_tests)
{
    Object *my_int = new(Int, 4242);
    Object *my_int2 = new(Int, 1);
    Object *add = addition(my_int, my_int2);

    cr_assert_str_eq(str(add), "<Int (4243)>");
    delete(my_int);
    delete(my_int2);
    delete(add);
}

// test int subtraction
Test(int_str_subtraction, point_tests)
{
    Object *my_int = new(Int, 4242);
    Object *my_int2 = new(Int, 1);
    Object *sub = subtraction(my_int, my_int2);

    cr_assert_str_eq(str(sub), "<Int (4241)>");
    delete(my_int);
    delete(my_int2);
    delete(sub);
}

// test int mul
Test(int_str_mul, point_tests)
{
    Object *my_int = new(Int, 4242);
    Object *my_int2 = new(Int, 1);
    Object *mul = multiplication(my_int, my_int2);

    cr_assert_str_eq(str(mul), "<Int (4242)>");
    delete(my_int);
    delete(my_int2);
    delete(mul);
}

// test int mul by 0
Test(int_str_mul_by_zero, point_tests)
{
    Object *my_int = new(Int, 4242);
    Object *my_int2 = new(Int, 0);
    Object *mul = multiplication(my_int, my_int2);

    cr_assert_str_eq(str(mul), "<Int (0)>");
    delete(my_int);
    delete(my_int2);
    delete(mul);
}

// test int div
Test(int_str_div, point_tests)
{
    Object *my_int = new(Int, 10);
    Object *my_int2 = new(Int, 2);
    Object *div = division(my_int, my_int2);

    cr_assert_str_eq(str(div), "<Int (5)>");
    delete(my_int);
    delete(my_int2);
    delete(div);
}

// test int div by zero
Test(int_str_div_by_zero, point_tests, .signal = SIGABRT)
{
    Object *my_int = new(Int, 10);
    Object *my_int2 = new(Int, 0);
    Object *div = division(my_int, my_int2);

    delete(my_int);
    delete(my_int2);
    delete(div);
}

// test int eq
Test(int_str_eq, point_tests)
{
    Object *my_int = new(Int, 10);
    Object *my_int2 = new(Int, 10);
    const bool is_eq = eq(my_int, my_int2);

    cr_assert_eq(is_eq, true);
    delete(my_int);
    delete(my_int2);
}

// test int lt
Test(int_str_lt, point_tests)
{
    Object *my_int = new(Int, 5);
    Object *my_int2 = new(Int, 2);
    const bool is_ls = lt(my_int, my_int2);

    cr_assert_eq(is_ls, false);
    delete(my_int);
    delete(my_int2);
}

// test int gt
Test(int_str_gt, point_tests)
{
    Object *my_int = new(Int, 5);
    Object *my_int2 = new(Int, 2);
    const bool is_ls = gt(my_int, my_int2);

    cr_assert_eq(is_ls, true);
    delete(my_int);
    delete(my_int2);
}

// Float

// test float to string
// TODO - check float around
Test(float_str_str, point_tests)
{
    Object *my_float = new(Float, 0.8);

    printf("%s\n", str(my_float));
    cr_assert_str_eq(str(my_float), "<Float (0.800000)>");
    delete(my_float);
}

// test float addition
Test(float_str_addition, point_tests)
{
    Object *my_float = new(Float, 0.80);
    Object *my_float2 = new(Float, 0.20);
    Object *add = addition(my_float, my_float2);

    cr_assert_str_eq(str(add), "<Float (1.000000)>");
    delete(my_float);
    delete(my_float2);
    delete(add);
}

// test float subtraction
Test(float_str_subtraction, point_tests)
{
    Object *my_float = new(Float, 3.2);
    Object *my_float2 = new(Float, 0.2);
    Object *sub = subtraction(my_float, my_float2);

    cr_assert_str_eq(str(sub), "<Float (3.000000)>");
    delete(my_float);
    delete(my_float2);
    delete(sub);
}

// test float mul
Test(float_str_mul, point_tests)
{
    Object *my_float = new(Float, 5.25);
    Object *my_float2 = new(Float, 2.5);
    Object *mul = multiplication(my_float, my_float2);

    cr_assert_str_eq(str(mul), "<Float (13.125000)>");
    delete(my_float);
    delete(my_float2);
    delete(mul);
}

// test float mul by 0
Test(float_str_mul_by_zero, point_tests)
{
    Object *my_float = new(Float, 1.5);
    Object *my_float2 = new(Float, 0.0);
    Object *mul = multiplication(my_float, my_float2);

    cr_assert_str_eq(str(mul), "<Float (0.000000)>");
    delete(my_float);
    delete(my_float2);
    delete(mul);
}

// test float div
Test(float_str_div, point_tests)
{
    Object *my_float = new(Float, 10.5);
    Object *my_float2 = new(Float, 2.5);
    Object *div = division(my_float, my_float2);

    cr_assert_str_eq(str(div), "<Float (4.200000)>");
    delete(my_float);
    delete(my_float2);
    delete(div);
}

// test float div by zero
Test(float_str_div_by_zero, point_tests, .signal = SIGABRT)
{
    Object *my_float = new(Float, 2.5);
    Object *my_float2 = new(Float, 0.0);
    Object *div = division(my_float, my_float2);

    delete(my_float);
    delete(my_float2);
    delete(div);
}

// test float eq
Test(float_str_eq, point_tests)
{
    Object *my_float = new(Float, 1.5);
    Object *my_float2 = new(Float, 1.5);
    const bool is_eq = eq(my_float, my_float2);

    cr_assert_eq(is_eq, true);
    delete(my_float);
    delete(my_float2);
}

// test float lt
Test(float_str_lt, point_tests)
{
    Object *my_float = new(Float, 10.5);
    Object *my_float2 = new(Float, 5.5);
    const bool is_ls = lt(my_float, my_float2);

    cr_assert_eq(is_ls, false);
    delete(my_float);
    delete(my_float2);
}

// test float gt
Test(float_str_gt, point_tests)
{
    Object *my_float = new(Float, 5.5);
    Object *my_float2 = new(Float, 2.5);
    const bool is_ls = gt(my_float, my_float2);

    cr_assert_eq(is_ls, true);
    delete(my_float);
    delete(my_float2);
}

// Char

// test char to string
Test(char_str_str, point_tests)
{
    Object *my_char = new(Char, '1');

    printf("%s\n", str(my_char));
    cr_assert_str_eq(str(my_char), "<Char (1)>");
    delete(my_char);
}

// test char addition
Test(char_str_addition, point_tests)
{
    Object *my_char = new(Char, '3');
    Object *my_char2 = new(Char, '1');
    Object *add = addition(my_char, my_char2);

    cr_assert_str_eq(str(add), "<Char (d)>");
    delete(my_char);
    delete(my_char2);
    delete(add);
}

// test char subtraction
Test(char_str_subtraction, point_tests)
{
    Object *my_char = new(Char, 'a');
    Object *my_char2 = new(Char, '!');
    Object *sub = subtraction(my_char, my_char2);

    cr_assert_str_eq(str(sub), "<Char (@)>");
    delete(my_char);
    delete(my_char2);
    delete(sub);
}

// test char mul
Test(char_str_mul, point_tests)
{
    Object *my_char = new(Char, '\a');
    Object *my_char2 = new(Char, '\a');
    Object *mul = multiplication(my_char, my_char2);

    cr_assert_str_eq(str(mul), "<Char (1)>");
    delete(my_char);
    delete(my_char2);
    delete(mul);
}

// test char mul by 0
Test(char_str_mul_by_zero, point_tests)
{
    Object *my_char = new(Char, '\a');
    Object *my_char2 = new(Char, '\0');
    Object *mul = multiplication(my_char, my_char2);

    cr_assert_str_eq(str(mul), "<Char (");
    delete(my_char);
    delete(my_char2);
    delete(mul);
}

// test char div
Test(char_str_div, point_tests)
{
    Object *my_char = new(Char, '1');
    Object *my_char2 = new(Char, '\a');
    Object *div = division(my_char, my_char2);

    cr_assert_str_eq(str(div), "<Char (W)>");
    delete(my_char);
    delete(my_char2);
    delete(div);
}

// test char div by zero
Test(char_str_div_by_zero, point_tests, .signal = SIGABRT)
{
    Object *my_char = new(Char, '\a');
    Object *my_char2 = new(Char, '\0');
    Object *div = division(my_char, my_char2);

    delete(my_char);
    delete(my_char2);
    delete(div);
}

// test char eq
Test(char_str_eq, point_tests)
{
    Object *my_char = new(Char, 'a');
    Object *my_char2 = new(Char, 'a');
    const bool is_eq = eq(my_char, my_char2);

    cr_assert_eq(is_eq, true);
    delete(my_char);
    delete(my_char2);
}

// test char lt when true
Test(char_str_lt_true, point_tests)
{
    Object *my_char = new(Char, 'a');
    Object *my_char2 = new(Char, 'b');
    const bool is_ls = lt(my_char, my_char2);

    cr_assert_eq(is_ls, true);
    delete(my_char);
    delete(my_char2);
}

// test char lt when false
Test(char_str_lt_false, point_tests)
{
    Object *my_char = new(Char, 'b');
    Object *my_char2 = new(Char, 'a');
    const bool is_ls = lt(my_char, my_char2);

    cr_assert_eq(is_ls, false);
    delete(my_char);
    delete(my_char2);
}

// test char gt when true
Test(char_str_gt_true, point_tests)
{
    Object *my_char = new(Char, 'b');
    Object *my_char2 = new(Char, 'a');
    const bool is_ls = gt(my_char, my_char2);

    cr_assert_eq(is_ls, true);
    delete(my_char);
    delete(my_char2);
}

// test char gt when false
Test(char_str_gt_false, point_tests)
{
    Object *my_char = new(Char, 'a');
    Object *my_char2 = new(Char, 'b');
    const bool is_ls = gt(my_char, my_char2);

    cr_assert_eq(is_ls, false);
    delete(my_char);
    delete(my_char2);
}

// test player
Test(test_player, point_tests)
{
    Object *my_player = new(Player);

    delete(my_player);
}

// test array
Test(test_array_value, point_tests)
{
    Object *array1 = new(Array, 10, Int, 5);
    Object *array2 = new(Array, 10, Float, 3.1415);
    Object *array3 = new(Array, 10, Char, 'M');
    Object *array4 = new(Array, 10, Player);
    Object *array5 = new(Array, 10, Point, 42, 26);
    Object *array6 = new(Array, 10, Vertex, 6, 12, 26);

    Object *my_array = new(Array, 10, Float, 0.0f);
    Object *i = getitem(array1, 3);
    Object *f = getitem(array2, 1);
    Object *c = getitem(array3, 5);
    //Object *player = getitem(array4, 6);
    Object *point = getitem(array5, 8);
    Object *vertex = getitem(array6, 4);

    cr_assert_str_eq(str(i), "<Int (5)>");
    cr_assert_str_eq(str(f), "<Float (3.141500)>");
    cr_assert_str_eq(str(c), "<Char (M)>");
    cr_assert_str_eq(str(point), "<Point (42, 26)>");
    cr_assert_str_eq(str(vertex), "<Vertex (6, 12, 26)>");

    setitem(array1, 3, 551);
    setitem(array2, 1, 3.14160);
    setitem(array3, 5, 'S');
    //setitem(array4, 6);
    setitem(array5, 8, 539, 436);
    setitem(array6, 4, 290, 209, 218);


    cr_assert_str_eq(str(getitem(array1, 3)), "<Int (551)>");
    cr_assert_str_eq(str(getitem(array2, 1)), "<Float (3.141600)>");
    cr_assert_str_eq(str(getitem(array3, 5)), "<Char (S)>");
    cr_assert_str_eq(str(getitem(array5, 8)), "<Point (539, 436)>");
    cr_assert_str_eq(str(getitem(array6, 4)), "<Vertex (290, 209, 218)>");

    delete(array1);
    delete(array2);
    delete(array3);
    delete(array5);
    delete(array6);

    cr_assert_str_eq(str(array1), "");
    cr_assert_str_eq(str(array2), "");
    cr_assert_str_eq(str(array3), "");
    cr_assert_str_eq(str(array5), "");
}