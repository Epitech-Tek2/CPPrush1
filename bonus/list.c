/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 06
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"
#include "player.h"

typedef struct ListClass_s
{
    Container base;
    Class *_type;
    Object *_object;
    struct ListClass_s *_next;
} ListClass;

typedef struct
{
    Iterator base;
    ListClass *_list;
    int idx;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->idx++;
    if (this->_list == NULL)
        raise("Out of range");
    this->_list = this->_list->_next;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_list == NULL)
        raise("Out of range");
    return (this->_list->_object);
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list ap;

    if (this->_list == NULL)
        raise("Out of range");
    va_start(ap, this);
    this->_list->base.__setitem__((Container *)this->_list, ap);
    va_end(ap);
}

static const ListIteratorClass ListIteratorDescr = {
        {   /* Iterator struct */
                {   /* Class struct */
                        .__size__ = sizeof(ListIteratorClass),
                        .__name__ = "ListIterator",
                        .__ctor__ = (ctor_t)&ListIterator_ctor,
                        .__dtor__ = NULL,
                        .__str__ = NULL,
                        .__add__ = NULL,
                        .__sub__ = NULL,
                        .__mul__ = NULL,
                        .__div__ = NULL,
                        .__eq__ = NULL,
                        .__gt__ = NULL,
                        .__lt__ = NULL,
                },
                .__incr__ = (incr_t)&ListIterator_incr,
                .__getval__ = (getval_t)&ListIterator_getval,
                .__setval__ = (setval_t)&ListIterator_setval,
        },
        ._list = NULL,
        .idx = 0,
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static void List_ctor(ListClass *this, va_list *args)
{
    va_list tmp;

    this->_type = va_arg(*args, Object *);
    this->_object = malloc(sizeof(this->_type));
    this->_next = NULL;
    if (NULL == this->_object)
        raise("Not enough memory");
    va_copy(tmp, *args);
    this->_object = va_new(this->_type, &tmp);
    va_end(*args);
}

static void List_dtor(ListClass *this)
{
    free(this->_object);
}

static size_t List_len(ListClass *this)
{
    size_t len = 0;
    ListClass *tmp;

    tmp = this;
    while (tmp->_next != NULL) {
        tmp = tmp->_next;
        len++;
    }
    return (len);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this));
}

static Object *List_getitem(ListClass *this, ...)
{
    ListClass *tmp = NULL;
    va_list ap;
    size_t size = 0;

    va_start(ap, this);
    tmp = this;
    size = va_arg(ap, int);
    if (this->_next == NULL & size > 1)
        raise("Not enough memory");
    for (size_t i = 0; tmp->_next != NULL; i++) {
        if (i > size)
            raise("Not enough memory");
        tmp = tmp->_next;
    }
    va_end(ap);
    return (tmp->_object);
}

static void List_setitem(ListClass *this, ...)
{
    va_list ap;
    ListClass *tmp = NULL;
    Object *freeitem;
    size_t size = 0;

    va_start(ap, this);
    tmp = this;
    size = va_arg(ap, int);
    if (this->_next == NULL & size > 1)
        raise("Not enough memory");
    for (size_t i = 0; tmp->_next != NULL; i++) {
        if (i > size)
            raise("Not enough memory");
        if (i == size)
            break;
        tmp = tmp->_next;
    }
    freeitem = tmp->_object;
    tmp->_object = va_new(this->_object, &ap);
    delete(freeitem);
    this = tmp;
    va_end(ap);
}

static const ListClass _descr = {
        {
                {
                        .__size__ = sizeof(ListClass),
                        .__name__ = "List",
                        .__ctor__ = (ctor_t)&List_ctor,
                        .__dtor__ = (dtor_t)&List_dtor,
                        .__str__ = NULL,
                        .__add__ = NULL,
                        .__sub__ = NULL,
                        .__mul__ = NULL,
                        .__div__ = NULL,
                        .__eq__ = NULL,
                        .__gt__ = NULL,
                        .__lt__ = NULL,
                },
                .__len__ = (len_t)&List_len,
                .__begin__ = (iter_t)&List_begin,
                .__end__ = (iter_t)&List_end,
                .__getitem__ = (getitem_t)&List_getitem,
                .__setitem__ = (setitem_t)&List_setitem,
        },
        ._type = NULL,
        ._object = NULL,
        ._next = NULL,
};

const Class *List = (const Class *)&_descr;
