/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush1-clement.muth
** File description:
** float
*/

#include <stdio.h>
#include <stdbool.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float f;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->f = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    this->f = 0.0;
}

static char *Float_str(FloatClass *this)
{
    const int max_size = 30;
    char *str = malloc(max_size);

    if (!str)
        return (NULL);
    snprintf(str, max_size, "<%s (%f)>", this->base.__name__, this->f);
    return (str);
}

static Object *Float_addition(const FloatClass *this,
    const FloatClass *other)
{
    return (new(Float, this->f + other->f));
}

static Object *Float_subtraction(const FloatClass *this,
    const FloatClass *other)
{
    return (new(Float, this->f - other->f));
}

static Object *Float_multiplication(const FloatClass *this,
    const FloatClass *other)
{
    return (new(Float, this->f * other->f));
}

static Object *Float_division(const FloatClass *this,
    const FloatClass *other)
{
    if (!this || !other || other->f == 0)
        raise("Invalid Parameter\n");
    return (new(Float, this->f / other->f));
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    return (this->f == other->f);
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    return (this->f > other->f);
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    return (this->f < other->f);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_addition,
        .__sub__ = (binary_operator_t)&Float_subtraction,
        .__mul__ = (binary_operator_t)&Float_multiplication,
        .__div__ = (binary_operator_t)&Float_division,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .f = 0
};

const Class *Float = (const Class *)&_description;
