/*************************************************************************//**
* @file
* @brief This file defines colors in 2d arays for use throughout paint.
*****************************************************************************/
#ifndef __COLORS_H
#define __COLORS_H

  enum RGBA {R = 0, G = 1, B = 2, A = 3};
  enum COLORS {Red = 0, DarkRed, Green, DarkGreen, Blue, DarkBlue, Yellow, Gold, Sunset, 
	     Peach, Cream, Olive, Aqua, fog, Black, White, Plum, Sage, Underbrush};
  const int NUM_COLORS = 20;

// Palette colors.
  const float Color[][4] = { // Palette Colors.
	                       {1.0, 0.0, 0.0, 1.0}, // Red
                           {0.5, 0.0, 0.0, 1.0}, // DarkRed
                           {0.0, 1.0, 0.0, 1.0}, // Green
                           {0.0, 0.5, 0.0, 1.0}, // DarkGreen
                           {0.0, 0.0, 1.0, 1.0}, // Blue
                           {0.0, 0.0, 0.5, 1.0}, // DarkBlue
                           {1.0, 1.0, 0.0, 1.0}, // Yellow
                           {0.7222, 0.7451, 0.0509, 1.0}, // Gold
                           {0.9922, 0.4588, 0.0509, 1.0}, // Sunset
                           {0.7521, 0.5, 0.35, 1.0}, // Peach
                           {0.75, 0.75, 0.5, 1.0}, // Cream
                           {0.5, 0.5, 0.25, 1.0}, // Olive
                           {0.2980, 0.4627, 0.9647, 1.0}, // Aqua
                           {0.5961, 0.6039, 0.6627, 1.0}, // Fog
                           // Utility/Window colors.
                           {0.0, 0.0, 0.0, 1.0}, // Black
                           {1.0, 1.0, 1.0, 1.0}, // White
                           {0.4784, 0.3922, 0.4392, 1.0}, // Plum
                           {0.3960, 0.4, 0.4823, 1.0}, // Grey
                           {0.3921, 0.4784, 0.4314, 1.0}, // Sage
                           {0.4784, 0.4745, 0.3922, 1.0} }; // Underbrush
#endif
