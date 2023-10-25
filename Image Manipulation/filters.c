#include "filters.h"

void grayScale(qtNode *t1, qtNode **res)
{
    (*res) = malloc(sizeof(qtNode));
    if (t1->topLeft != NULL)
    {
        grayScale(t1->topLeft, &(*res)->topLeft);
        grayScale(t1->topRight, &(*res)->topRight);
        grayScale(t1->bottomLeft, &(*res)->bottomLeft);
        grayScale(t1->bottomRight, &(*res)->bottomRight);
    }

    else
    {

        (*res)->topRight = NULL;
        (*res)->topLeft = NULL;
        (*res)->bottomLeft = NULL;
        (*res)->bottomRight = NULL;
    }

    (*res)->area = t1->area;
    (*res)->p.red = t1->p.red * 0.3;
    (*res)->p.blue = t1->p.green * 0.59;
    (*res)->p.green = t1->p.blue * 0.11;
    (*res)->area = t1->area;

    return;
}

void negativeImage(qtNode *t1, qtNode **res)
{
    (*res) = malloc(sizeof(qtNode));
    if (t1->topLeft != NULL)
    {
        negativeImage(t1->topLeft, &(*res)->topLeft);
        negativeImage(t1->topRight, &(*res)->topRight);
        negativeImage(t1->bottomLeft, &(*res)->bottomLeft);
        negativeImage(t1->bottomRight, &(*res)->bottomRight);
    }

    else
    {

        (*res)->topRight = NULL;
        (*res)->topLeft = NULL;
        (*res)->bottomLeft = NULL;
        (*res)->bottomRight = NULL;
    }

    (*res)->area = t1->area;
    (*res)->p.red = 255 - t1->p.red;
    (*res)->p.blue = 255 - t1->p.green;
    (*res)->p.green = 255 - t1->p.blue;
    (*res)->area = t1->area;
    return;
}

