#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "esviji.h"

// static functions (we don't want to expose these to the client file)
static void appendstringtosvg(Svg *pSvg, char *text)
{
	int length = strlen(pSvg->svg) + strlen(text) + 1; // + 1 for null character
	char *newtext = realloc(pSvg->svg, length);
	if (newtext != NULL) {
		pSvg->svg = newtext;
	}
	strcat(pSvg->svg, text);
}

static void appendnumbertosvg(Svg *pSvg, int n)
{
	char numstr[16];
	sprintf(numstr, "%d", n);
	appendstringtosvg(pSvg, numstr);
}

// Exposed functions
Svg *svg_create(int width, int height)
{
	Svg *pSvg = malloc(sizeof(Svg));
	if (pSvg != NULL) {
		*pSvg = (Svg){.svg = NULL, .width = width, .height = height, .finalized = false};
		pSvg->svg = malloc(1);
		sprintf(pSvg->svg, "%s", "\0");
		
		appendstringtosvg(pSvg, "<svg width='");
		appendnumbertosvg(pSvg, width);
		appendstringtosvg(pSvg, "px' height='");
		appendnumbertosvg(pSvg, height);
		appendstringtosvg(pSvg, "px' xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n");
		
		return pSvg;
	} else {
		return NULL;
	}
}

void svg_finalize(Svg *pSvg)
{
	appendstringtosvg(pSvg, "</svg>");
	pSvg->finalized = true;
}

void svg_free(Svg *pSvg)
{
	free(pSvg->svg);
	free(pSvg);
}

void svg_save(Svg *pSvg, char *filepath)
{
	if(!pSvg->finalized) {
		svg_finalize(pSvg);
	}
	
	FILE *fp;
	fp = fopen(filepath, "w");
	if (fp != NULL) {
		fwrite(pSvg->svg, 1, strlen(pSvg->svg), fp);
		fclose(fp);
	}
}

// Shapes
void svg_rectangle(Svg* pSvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy)
{
	appendstringtosvg(pSvg, "    <rect fill='");
	appendstringtosvg(pSvg, fill);
	appendstringtosvg(pSvg, "' stroke='");
	appendstringtosvg(pSvg, stroke);
	appendstringtosvg(pSvg, "' stroke-width='");
	appendnumbertosvg(pSvg, strokewidth);
	appendstringtosvg(pSvg, "px' width='");
	appendnumbertosvg(pSvg, width);
	appendstringtosvg(pSvg, "' height='");
	appendnumbertosvg(pSvg, height);
	appendstringtosvg(pSvg, "' y='");
	appendnumbertosvg(pSvg, y);
	appendstringtosvg(pSvg, "' x='");
	appendnumbertosvg(pSvg, x);
	appendstringtosvg(pSvg, "' ry='");
	appendnumbertosvg(pSvg, radiusy);
	appendstringtosvg(pSvg, "' rx='");
	appendnumbertosvg(pSvg, radiusx);
	appendstringtosvg(pSvg, "' />\n");
}

void svg_fill(Svg *pSvg, char *fill)
{
	svg_rectangle(pSvg, pSvg->width, pSvg->height, 0, 0, Fill, Fill, 0, 0, 0);
}

void svg_print(Svg *pSvg)
{
	printf("%s", pSvg->svg);
}

void svg_line(Svg *pSvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2);
{
	appendstringtosvg(pSvg, "	<line stroke='");
	appendstringtosvg(pSvg, stroke);
	appendstringtosvg(pSvg, "'  stokewidth='");
	appendstringtosvg(pSvg, stokewidth);
	appendstringtosvg(pSvg, "px' y2='");
	appendstringtosvg(pSvg, y2);
	appendstringtosvg(pSvg, "' x2='");
	appendstringtosvg(pSvg, x2);
	appendstringtosvg(pSvg, "' y1='");
	appendstringtosvg(pSvg, y1);
	appendstringtosvg(pSvg, "' x1='");
	appendstringtosvg(pSvg, x1);
	appendstringtosvg(pSvg, "' />\n'");
}

void svg_text(Svg *pSvg, int x, int y, char *fontfamily, int fontsize, char *fill, char *stroke, char *text)
{
	appendstringtosvg(pSvg, "	<text x='");
	appendstringtosvg(pSvg, x);
	appendstringtosvg(pSvg, "' y='");
	appendstringtosvg(pSvg, y);
	appendstringtosvg(pSvg, "'	font-family='");
	appendstringtosvg(pSvg, fontfamily);
	appendstringtosvg(pSvg, "'	stroke ='");
	appendstringtosvg(pSvg, stroke);
	appendstringtosvg(pSvg, "'	fill='");
	appendstringtosvg(pSvg, fill);
	appendstringtosvg(pSvg, " px'>");
	appendstringtosvg(pSvg, text);
	appendstringtosvg(pSvg, "</test>\n");
}

void svg_circle(svg* pSvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy)
{
	appendstringtosvg(pSvg, "	<circle stroke='");
	appendstringtosvg(pSvg, stroke);
	appendstringtosvg(pSvg, "' stoke-width='");
	appendstringtosvg(pSvg, strokewidth);
	appendstringtosvg(pSvg, "px' fill='");
	appendstringtosvg(pSvg, fill);
	appendstringtosvg(pSvg, "' r='");
	appendstringtosvg(pSvg, r);
	appendstringtosvg(pSvg, "' cy='");
	appendstringtosvg(pSvg, cy);
	appendstringtosvg(pSvg, "' cx='");
	appendstringtosvg(pSvg, cx);
	appendstringtosvg(pSvg, "' />\n");
}
void svg_ellipse(Svg *pSvg, int cx, int cy, int radiusx, int radiusy, char *width, char *stroke, int strokewidth);
{
	appendstringtosvg(pSvg, "	<ellipse cx='");
	appendstringtosvg(pSvg, cx);
	appendstringtosvg(pSvg, "' cy='");
	appendstringtosvg(pSvg, cy);
	appendstringtosvg(pSvg, "' rx='");
	appendstringtosvg(pSvg, readiusx);
	appendstringtosvg(pSvg, "' ry='");
	appendstringtosvg(pSvg, radiusy);
	appendstringtosvg(pSvg, "' fill='");
	appendstringtosvg(pSvg, fill);
	appendstringtosvg(pSvg, "' stroke='");
	appendstringtosvg(pSvg, stroke);
	appendstringtosvg(pSvg, "' strokewidth='");
	appendstringtosvg(pSvg, strokewidth);
	appendstringtosvg(pSvg, "' />\n");
}