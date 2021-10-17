/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "bool.h"
#include "new.h"

typedef struct
{
    Class base;
    bool x;
} BoolClass;

static void Bool_ctor(BoolClass *this, va_list *args)
{
    this->x = va_arg(*args, bool);
}

static void Bool_dtor(BoolClass *this)
{
    this->x = 0;
}

static char *Bool_str(const BoolClass *this)
{
    char *str;
    int size = 1;

    size += strlen(this->base.__name__) + strlen("< (, )>");
    str = malloc(sizeof(char) * size + 1);
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<%s (%c)>", this->base.__name__, this->x);
    return (str);
}

static Object *Bool_addition(const BoolClass *this, const BoolClass *other)
{
    return (new(Bool, (this->x && other->x)));
}

static Object *Bool_subtraction(const BoolClass *this, const BoolClass *other)
{
    return (new(Bool, (this->x && other->x)));
}

static Object *Bool_multiplication(const BoolClass *this, const BoolClass *other)
{
    return (new(Bool, (this->x && other->x)));
}

static Object *Bool_division(const BoolClass *this, const BoolClass *other)
{
    if (0 == other->x && this->x == 0)
        raise("Invalid parameter");
    return (new(Bool, (this->x && other->x)));
}

static bool Bool_equal(const BoolClass *this, const BoolClass *other)
{
    return (this->x == other->x);
}

static bool Bool_lesser(const BoolClass *this, const BoolClass *other)
{
    return (this->x < other->x);
}

static bool Bool_greater(const BoolClass *this, const BoolClass *other)
{
    return (this->x > other->x);
}

static const BoolClass _description = {
    {
        .__size__ = sizeof(BoolClass),
        .__name__ = "Bool",
        .__ctor__ = (ctor_t)&Bool_ctor,
        .__dtor__ = (dtor_t)&Bool_dtor,
        .__str__ = (to_string_t)&Bool_str,
        .__add__ = (binary_operator_t)&Bool_addition,
        .__sub__ = (binary_operator_t)&Bool_subtraction,
        .__mul__ = (binary_operator_t)&Bool_multiplication,
        .__div__ = (binary_operator_t)&Bool_division,
        .__eq__ = (binary_comparator_t)&Bool_equal,
        .__gt__ = (binary_comparator_t)&Bool_greater,
        .__lt__ = (binary_comparator_t)&Bool_lesser
    },
    .x = 0
};

const Class *Bool = (const Class *)&_description;