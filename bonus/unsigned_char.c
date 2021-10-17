/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "unsigned_char.h"

typedef struct
{
    Class base;
    unsigned char c;
} UnsignedCharClass;

static void UnsignedChar_ctor(UnsignedCharClass *this, va_list *args)
{
    this->c = va_arg(*args, unsigned char);
}

static void UnsignedChar_dtor(UnsignedCharClass *this)
{
    this->c = '\0';
}

static char *UnsignedChar_str(const UnsignedCharClass *this)
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

static Object *UnsignedChar_addition(const UnsignedCharClass *this, const UnsignedCharClass *other)
{
    unsigned char c = 0;

    c = this->c + other->c;
    return (new(Char, c));
}

static Object *UnsignedChar_subtraction(const UnsignedCharClass *this, const UnsignedCharClass *other)
{
    unsigned char c = 0;

    c = this->c - other->c;
    return (new(Char, c));
}

static Object *UnsignedChar_multiplication(const UnsignedCharClass *this,
    const CharClass *other)
{
    char c = 0;

    c = this->c * other->c;
    return (new(Char, c));
}

static Object *UnsignedChar_division(const UnsignedCharClass *this, const UnsignedCharClass *other)
{
    unsigned char c = 0;

    if (0 == other->c)
        raise("Division by 0");
    c = this->c / other->c;
    return (new(Char, c));
}

static bool UnsignedChar_eq(const UnsignedCharClass *this, const UnsignedCharClass *other)
{
    return (this->c == other->c);
}

static bool UnsignedChar_gt(const UnsignedCharClass *this, const UnsignedCharClass *other)
{
    return (this->c > other->c);
}

static bool UnsignedChar_lt(const UnsignedCharClass *this, const UnsignedCharClass *other)
{
    return (this->c < other->c);
}

static const UnsignedCharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Unsigned Char",
        .__ctor__ = (ctor_t)&UnsignedChar_ctor,
        .__dtor__ = (dtor_t)&UnsignedChar_dtor,
        .__str__ = (to_string_t)&UnsignedChar_str,
        .__add__ = (binary_operator_t)&UnsignedChar_addition,
        .__sub__ = (binary_operator_t)&UnsignedChar_subtraction,
        .__mul__ = (binary_operator_t)&UnsignedChar_multiplication,
        .__div__ = (binary_operator_t)&UnsignedChar_division,
        .__eq__ = (binary_comparator_t)&UnsignedChar_eq,
        .__gt__ = (binary_comparator_t)&UnsignedChar_gt,
        .__lt__ = (binary_comparator_t)&UnsignedChar_lt,
    },
    .c = 0
};

const Class *Unsignedchar = (const Class *)&_description;
