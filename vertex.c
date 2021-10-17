/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

static char *Vertex_str(const VertexClass *this)
{
    int size = 0;
    char number[11];
    char *str = NULL;

    sprintf(number, "%d", this->x);
    size += strlen(number);
    sprintf(number, "%d", this->y);
    size += strlen(number);
    sprintf(number, "%d", this->z);
    size += strlen(number);
    size += strlen(this->base.__name__) + strlen("< (, , )>");
    str = malloc(sizeof(char) * (size + 1));
    if (NULL == str)
        return (NULL);
    snprintf(str, size + 1, "<%s (%d, %d, %d)>", this->base.__name__, this->x,
        this->y, this->z);
    return (str);
}

static VertexClass *Vertex_addition(const VertexClass *this,
    const VertexClass *other)
{
    return (this && other) ?
        ((VertexClass *)(new(Vertex, this->x + other->x, this->y + other->y,
        this->z + other->z)))
    : (NULL);
}

static VertexClass *Vertex_subtraction(const VertexClass *this,
    const VertexClass *other)
{
    return (this && other) ?
        ((VertexClass *)(new(Vertex, this->x - other->x, this->y - other->y,
        this->z - other->z)))
    : (NULL);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_addition,
        .__sub__ = (binary_operator_t)&Vertex_subtraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
