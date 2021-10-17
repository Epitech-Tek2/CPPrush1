/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    this->x = 0;
}

static char *Int_str(const IntClass *this)
{
    int size = 0;
    char number[11];
    char *str = NULL;

    sprintf(number, "%d", this->x);
    size += strlen(number);
    size += strlen(this->base.__name__) + strlen("< (, )>");
    str = malloc(sizeof(char) * (size + 1));
    if (NULL == str)
           return (NULL);
    snprintf(str, size + 1, "<%s (%d)>", this->base.__name__, this->x);
    return (str);
}

static Object *Int_addition(const IntClass *this, const IntClass *other)
{
    int x = 0;

    x = this->x + other->x;
    return (new(Int, x));
}

static Object *Int_subtraction(const IntClass *this, const IntClass *other)
{
    int x = 0;

    x = this->x - other->x;
    return (new(Int, x));
}

static Object *Int_multiplication(const IntClass *this, const IntClass *other)
{
    int x = 0;

    x = this->x * other->x;
    return (new(Int, x));
}

static Object *Int_division(const IntClass *this, const IntClass *other)
{
    int x = 0;

    if (0 == other->x)
        raise("Invalid parameter");
    x = this->x / other->x;
    return (new(Int, x));
}

static bool Int_equal(const IntClass *this, const IntClass *other)
{
    return (this->x == other->x);
}

static bool Int_lesser(const IntClass *this, const IntClass *other)
{
    return (this->x < other->x);
}

static bool Int_greater(const IntClass *this, const IntClass *other)
{
    return (this->x > other->x);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_addition,
        .__sub__ = (binary_operator_t)&Int_subtraction,
        .__mul__ = (binary_operator_t)&Int_multiplication,
        .__div__ = (binary_operator_t)&Int_division,
        .__eq__ = (binary_comparator_t)&Int_equal,
        .__gt__ = (binary_comparator_t)&Int_greater,
        .__lt__ = (binary_comparator_t)&Int_lesser
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;
