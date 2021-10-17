/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "char.h"

typedef struct
{
    Class base;
    char c;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    this->c = '\0';
}

static char *Char_str(const CharClass *this)
{
    char *str;
    int size = 1;

    size += strlen(this->base.__name__) + strlen("< (, )>");
    str = malloc(sizeof(char) * size + 1);
    if (str == NULL)
        raise("Out of memory");
    snprintf(str, size + 1, "<%s (%c)>", this->base.__name__, this->c);
    return (str);
}

static Object *Char_addition(const CharClass *this, const CharClass *other)
{
    char c = 0;

    c = this->c + other->c;
    return (new(Char, c));
}

static Object *Char_subtraction(const CharClass *this, const CharClass *other)
{
    char c = 0;

    c = this->c - other->c;
    return (new(Char, c));
}

static Object *Char_multiplication(const CharClass *this,
    const CharClass *other)
{
    char c = 0;

    c = this->c * other->c;
    return (new(Char, c));
}

static Object *Char_division(const CharClass *this, const CharClass *other)
{
    char c = 0;

    if (0 == other->c)
        raise("Division by 0");
    c = this->c / other->c;
    return (new(Char, c));
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    return (this->c == other->c);
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    return (this->c > other->c);
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    return (this->c < other->c);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_addition,
        .__sub__ = (binary_operator_t)&Char_subtraction,
        .__mul__ = (binary_operator_t)&Char_multiplication,
        .__div__ = (binary_operator_t)&Char_division,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt,
    },
    .c = 0
};

const Class *Char = (const Class *)&_description;
