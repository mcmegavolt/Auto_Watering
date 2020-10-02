#pragma once
#include <Arduino.h>

byte lineFrames[4][8] = {
    {B00001,
     B00010,
     B00010,
     B00100,
     B00100,
     B01000,
     B01000,
     B10000},
    {B00100,
     B00100,
     B00100,
     B00100,
     B00100,
     B00100,
     B00100,
     B00100},
    {B10000,
     B01000,
     B01000,
     B00100,
     B00100,
     B00010,
     B00010,
     B00001},
    {B00000,
     B00000,
     B00000,
     B00000,
     B11111,
     B00000,
     B00000,
     B00000}};

byte snakeFrames[11][8] = {
    {B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B10000,
     B10000,
     B10000},
    {B00000,
     B00000,
     B00000,
     B10000,
     B10000,
     B10000,
     B00000,
     B00000},
    {B00000,
     B10000,
     B10000,
     B10000,
     B00000,
     B00000,
     B00000,
     B00000},
    {B11000,
     B10000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000},
    {B01110,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000},
    {B00011,
     B00001,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000},
    {B00000,
     B00001,
     B00001,
     B00001,
     B00000,
     B00000,
     B00000,
     B00000},
    {B00000,
     B00000,
     B00000,
     B00001,
     B00001,
     B00001,
     B00000,
     B00000},
    {B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00001,
     B00001,
     B00001},
    {B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00111},
    {B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B11100}};

byte zoomFrames[6][8] = {
    {B00000,
     B00000,
     B00000,
     B00100,
     B00100,
     B00000,
     B00000,
     B00000},
    {B00000,
     B00000,
     B01110,
     B01110,
     B01110,
     B01110,
     B00000,
     B00000},
    {B00000,
     B11111,
     B11111,
     B11011,
     B11011,
     B11111,
     B11111,
     B00000},
    {B11111,
     B11111,
     B10001,
     B10001,
     B10001,
     B10001,
     B11111,
     B11111},
    {B11111,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B11111},
    {B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000,
     B00000}}