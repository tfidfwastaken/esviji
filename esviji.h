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
void svg_finalize(Svg *pSvg);
void svg_print(Svg *pSvg);
void svg_save(Svg *pSvg, char *filepath);
void svg_free(Svg *pSvg);
void svg_circle(Svg *pSvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy);
void svg_line(Svg *pSvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2);
void svg_rectangle(Svg* pSvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy, char *filter);
void svg_fill(Svg *pSvg, char *fill);
void svg_text(Svg *pSvg, int x, int y, char *fontfamily, int fontsize, char *fill, char *stroke, char *text);
void svg_ellipse(Svg* pvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int strokewidth);
void svg_polygon(int n, Svg* pSvg, int points[n][2], int strokewidth, char* stroke, char *fill);
void svg_polyline(int n, Svg* pSvg, int points[n][2], int strokewidth, char* stroke, char *fill);
void svg_filter(Svg *pSvg, char *id, int x, int y, int stddev);