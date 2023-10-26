#include "filters.h"

// Grayscale 
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

// Negative image 
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

// Sepia filter 
void sepia(qtNode* t1,qtNode** res)
{
    (*res) = malloc(sizeof(qtNode));

    if (t1->topLeft != NULL)
    {
        sepia(t1->topLeft, &(*res)->topLeft);
        sepia(t1->topRight, &(*res)->topRight);
        sepia(t1->bottomLeft, &(*res)->bottomLeft);
        sepia(t1->bottomRight, &(*res)->bottomRight);
    }

    else
    {

        (*res)->topRight = NULL;
        (*res)->topLeft = NULL;
        (*res)->bottomLeft = NULL;
        (*res)->bottomRight = NULL;
    }

    (*res)->area = t1->area;
    (*res)->p.red = 0.393*t1->p.red+0.769*t1->p.green+0.189*t1->p.blue;
    (*res)->p.blue = 0.349*t1->p.red+0.686*t1->p.green+0.168*t1->p.blue;
    (*res)->p.green = 0.272*t1->p.red+0.534*t1->p.green+0.131*t1->p.blue;
    (*res)->area = t1->area;
    return;

}

// Blur image 

void blurImage(qtNode *t1, qtNode **res)
{
    (*res) = malloc(sizeof(qtNode));

    if (t1->topLeft != NULL)
    {
        blurImage(t1->topLeft, &(*res)->topLeft);
        blurImage(t1->topRight, &(*res)->topRight);
        blurImage(t1->bottomLeft, &(*res)->bottomLeft);
        blurImage(t1->bottomRight, &(*res)->bottomRight);
    }
    else
    {
        (*res)->topRight = NULL;
        (*res)->topLeft = NULL;
        (*res)->bottomLeft = NULL;
        (*res)->bottomRight = NULL;
    }

    // Calculate the average RGB values for the current node and its neighbors
    int totalRed = t1->p.red;
    int totalGreen = t1->p.green;
    int totalBlue = t1->p.blue;

    if (t1->topLeft != NULL)
    {
        totalRed += t1->topLeft->p.red;
        totalGreen += t1->topLeft->p.green;
        totalBlue += t1->topLeft->p.blue;

        totalRed += t1->topRight->p.red;
        totalGreen += t1->topRight->p.green;
        totalBlue += t1->topRight->p.blue;

        totalRed += t1->bottomLeft->p.red;
        totalGreen += t1->bottomLeft->p.green;
        totalBlue += t1->bottomLeft->p.blue;

        totalRed += t1->bottomRight->p.red;
        totalGreen += t1->bottomRight->p.green;
        totalBlue += t1->bottomRight->p.blue;
    }

    (*res)->p.red = totalRed / 5;     // Current node + 4 neighbors
    (*res)->p.green = totalGreen / 5;
    (*res)->p.blue = totalBlue / 5;

    (*res)->area = t1->area;

    return;
}
