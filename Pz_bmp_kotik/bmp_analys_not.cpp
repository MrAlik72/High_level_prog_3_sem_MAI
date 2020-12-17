﻿// bmp_analys.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

typedef struct
{
    unsigned int    bfType;
    unsigned long   bfSize;
    unsigned int    bfReserved1;
    unsigned int    bfReserved2;
    unsigned long   bfOffBits;
} BITMAPFILEHEADER;

typedef struct
{
    unsigned int    biSize;
    int             biWidth;
    int             biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int    biCompression;
    unsigned int    biSizeImage;
    int             biXPelsPerMeter;
    int             biYPelsPerMeter;
    unsigned int    biClrUsed;
    unsigned int    biClrImportant;
} BITMAPINFOHEADER;

typedef struct
{
    int   rgbBlue;
    int   rgbGreen;
    int   rgbRed;
    int   rgbReserved;
} RGBQUAD;

static unsigned short read_u16(FILE* fp);
static unsigned int   read_u32(FILE* fp);
static int            read_s32(FILE* fp);

int main()
{
    FILE* pFile = fopen("C:/Code/HLPL/cat_grey.bmp", "rb"); //cat_grey mouse

    // считываем заголовок файла
    BITMAPFILEHEADER header;

    header.bfType = read_u16(pFile);
    header.bfSize = read_u32(pFile);
    header.bfReserved1 = read_u16(pFile);
    header.bfReserved2 = read_u16(pFile);
    header.bfOffBits = read_u32(pFile);

    printf("%x %d %d\n", header.bfType, header.bfSize, header.bfOffBits);
    //system("pause");
    // считываем заголовок изображения
    BITMAPINFOHEADER bmiHeader;

    bmiHeader.biSize = read_u32(pFile);
    bmiHeader.biWidth = read_s32(pFile);
    bmiHeader.biHeight = read_s32(pFile);
    bmiHeader.biPlanes = read_u16(pFile);
    bmiHeader.biBitCount = read_u16(pFile);
    bmiHeader.biCompression = read_u32(pFile);
    bmiHeader.biSizeImage = read_u32(pFile);
    bmiHeader.biXPelsPerMeter = read_s32(pFile);
    bmiHeader.biYPelsPerMeter = read_s32(pFile);
    bmiHeader.biClrUsed = read_u32(pFile);
    bmiHeader.biClrImportant = read_u32(pFile);
    printf("width\theight\n%d\t%d\n", bmiHeader.biWidth, bmiHeader.biHeight);
    printf("bits per pixel\n%d\n", bmiHeader.biBitCount);
    printf("biCompression\n%d\n", bmiHeader.biCompression);
    //cout << bmiHeader.biSize << ' ' << bmiHeader.biWidth << ' ' << bmiHeader.biHeight << endl;

    system("pause");

    RGBQUAD** rgb = new RGBQUAD * [bmiHeader.biWidth];
    for (int i = 0; i < bmiHeader.biWidth; i++) {
        rgb[i] = new RGBQUAD[bmiHeader.biHeight];
    }

    uint32_t** colors = new uint32_t * [bmiHeader.biWidth];
    for (int i = 0; i < bmiHeader.biWidth; i++) {
        colors[i] = new uint32_t[bmiHeader.biHeight];
    }

    for (int i = 0; i < bmiHeader.biWidth; i++) {
        for (int j = 0; j < bmiHeader.biHeight; j++) {
            rgb[i][j].rgbBlue = getc(pFile);
            rgb[i][j].rgbGreen = getc(pFile);
            rgb[i][j].rgbRed = getc(pFile);
            //colors[i][j] = rgb[i][j].rgbBlue + (rgb[i][j].rgbGreen << 8) + (rgb[i][j].rgbRed << 16);
        }

        // пропускаем последний байт в строке
        getc(pFile);
    }
    fclose(pFile);

    uint8_t transformUint(int dest){
        if (dest >= 0 && dest < 128){
            if (dest >= 0)
                return 0;
            else
                return 1;
        else if (dest >=128 && dest <=255){
            if (dest >= 128 && dest < 192)
                return 2;
            else 
                return 3;
        }
        else
            cout << "Error" << endl;
        }
    }

    uint8_t getindex(int red, int green, int blue){
        return transformUint(red) + transformUint(green) << 2 + transformUint(blue) << 4;
    }

    uint8_t vect[64];

    for (int i = 0; i < bmiHeader.biWidth; i++) {
        for (int j = 0; j < bmiHeader.biHeight; j++) {
            vect[getindex(rgb[i][j].rgbRed, rgb[i][j].rgbGreen, rgb[i][j].rgbBlue)]++;
        }
    }

    for (int i = 0; i < 64; i++){
        cout << vect[i] << ' ';
    }
    cout << endl;

    // выводим результат
    /*
    for (int i = 0; i < bmiHeader.biWidth; i++) {
        for (int j = 0; j < bmiHeader.biHeight; j++) {
            if ((rgb[i][j].rgbRed != 102) && (rgb[i][j].rgbGreen != 102) && (rgb[i][j].rgbBlue != 102))
                printf("%d %d %d\n", rgb[i][j].rgbRed, rgb[i][j].rgbGreen, rgb[i][j].rgbBlue);
                
        }
        printf("\n");
    }
    
    int parts = 30;
    int* vect = (int*)calloc(sizeof(int), parts);
    uint32_t max = UINT32_MAX & 0x00FFFFFF;
    uint32_t step = (max / parts)+1;
    uint32_t border;

    for (int i = 0; i < bmiHeader.biWidth; i++) {
        for (int j = 0; j < bmiHeader.biHeight; j++) {
            border = step;
            for (int k = 0; k < parts; k++)
            {
                if (colors[i][j] < border)
                {
                    vect[k]++;
                    break;
                }
                border += step;
            }
        }
    }

    for (int k = 0; k < parts; k++)
    {
        cout << vect[k] <<endl;
        
    }
    */
    for (int i = 0; i < bmiHeader.biWidth; i++) {
        delete rgb[i];
        delete colors[i];
    }
    delete rgb;
    delete colors;
    
    return 0;
}


static unsigned short read_u16(FILE* fp)
{
    unsigned char b0, b1;

    b0 = getc(fp);
    b1 = getc(fp);

    return ((b1 << 8) | b0);
}


static unsigned int read_u32(FILE* fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}


static int read_s32(FILE* fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((int)(((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}