/*
** EPITECH PROJECT, 2021
** new.c
** File description:
** new and delete implementations
*/

#include <string.h>
#include "raise.h"
#include "object.h"
#include "player.h"
#include "new.h"

Object *va_new(const Class *class, va_list *ap)
{
    Object *this = malloc(class->__size__);

    if (this == NULL || memcpy(this, class, class->__size__) == NULL)
        raise("Out of memory");
    if (class->__ctor__ != NULL)
        class->__ctor__(this, ap);
    return (this);
}

Object *new(const Class *class, ...)
{
    Object *this;
    va_list ap;

    if (strcmp(class->__name__, "Player") == 0) {
        this = malloc(class->__size__);
        if (this == NULL || memcpy(this, class, class->__size__) == NULL)
            raise("Out of memory");
        if (class->__ctor__ != NULL)
            class->__ctor__(this, NULL);
    } else {
        va_start(ap, class);
        this = va_new(class, &ap);
        va_end(ap);
    }
    return (this);
}

void delete(Object *this)
{
    Class *to_delete;

    if (this == NULL)
        raise("Invalid parameter");
    to_delete = this;
    if (to_delete->__dtor__ != NULL)
        to_delete->__dtor__(this);
    free(this);
}
