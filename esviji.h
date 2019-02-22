#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// Our main svg struct
typedef struct svg {
	char *svg;
	int height;
	int width;
	bool finalized;
} Svg;

// All our function prototypes
Svg *svg_create(int width, int height);
void svg_finalize(Svg *psvg);
void svg_print(Svg *psvg);
void svg_free(Svg *psvg);
void svg_circle(Svg *psvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy);
void svg_line(Svg *psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2);
void svg_rectangle(Svg *psvg, int width, int height, int x, int y, char *fill, char *stroke, int radiusx, int radiusy);
void svg_fill(Svg *psvg, char *fill);
void svg_text(Svg *psvg, int x, int y, char *fontfamily, int fontsize, char *fill, char *stroke, char *text);
void svg_ellipse(Svg *psvg, int cx, int cy, int radiusx, int radiusy, char *width, char *stroke, int strokewidth);
