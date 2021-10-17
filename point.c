/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    this->x = 0;
    this->y = 0;
}

static char *Point_str(const PointClass *this)
{
    int size = 0;
    char number[11];
    char *str = NULL;

    sprintf(number, "%d", this->x);
    size += strlen(number);
    sprintf(number, "%d", this->y);
    size += strlen(number);
    size += strlen(this->base.__name__) + strlen("< (, )>");
    str = malloc(sizeof(char) * (size + 1));
    if (NULL == str)
           return (NULL);
    snprintf(str, size + 1, "<%s (%d, %d)>", this->base.__name__, this->x,
        this->y);
    return (str);
}

static Object *Point_addition(const PointClass *this, const PointClass *other)
{
    int x = 0;
    int y = 0;

    x = this->x + other->x;
    y = this->y + other->y;
    return (new(Point, x, y));
}

static Object *Point_subtraction(const PointClass *this, const PointClass *other)
{
    int x = 0;
    int y = 0;

    x = this->x - other->x;
    y = this->y - other->y;
    return (new(Point, x, y));
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_addition,
        .__sub__ = (binary_operator_t)&Point_subtraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
