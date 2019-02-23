#include <stdlib.h>
#include <stdbool.h>
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
	strcat(pSvg->svg, length);
}

static void appendnumbertosvg(Svg *pSvg, int n)
{
	char numstr[16];
	sprintf(numstr, "%d", n);
	appendstringtosvg(pSvg, numstr);
}

// Exposed functions
Svg *create(int width, int height)
{
	Svg *pSvg = malloc(sizeof(Svg));
	if (pSvg != NULL) {
		*pSvg = (Svg){.svg = NULL, .width = width, .height = height, finalized = false};
		pSvg->svg = malloc(1);
		sprintf(pSvg->svg, "%s", "\0");
		
		appendstringtosvg(pSvg, "<svg width='");
		appendnumbertosvg(pSvg, width);
		appendstringtosvg(pSvg, "px' height='");
		appendnumbertosvg(pSvg, height);
		appendstringtosvg(pSvg, "px', xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n");
		
		return pSvg;
	} else {
		return NULL;
	}
}

void svg_finalize(Svg *pSvg)
{
	appendstringtosvg(pSvg, "</svg>");
	psvg->finalized = true;
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
	fp = fopen(filepath, 'w');
	if (fp != NULL) {
		fwrite(pSvg->svg, 1, strlen(pSvg->svg), fp);
		fclose(fp);
	}
}

// Shapes
void svg_rectangle(svg* psvg, int width, int height, int x, int y, char* fill, char* stroke, int strokewidth, int radiusx, int radiusy)
{
	appendstringtosvg(psvg, "    <rect fill='");
	appendstringtosvg(psvg, fill);
	appendstringtosvg(psvg, "' stroke='");
	appendstringtosvg(psvg, stroke);
	appendstringtosvg(psvg, "' stroke-width='");
	appendnumbertosvg(psvg, strokewidth);
	appendstringtosvg(psvg, "px' width='");
	appendnumbertosvg(psvg, width);
	appendstringtosvg(psvg, "' height='");
	appendnumbertosvg(psvg, height);
	appendstringtosvg(psvg, "' y='");
	appendnumbertosvg(psvg, y);
	appendstringtosvg(psvg, "' x='");
	appendnumbertosvg(psvg, x);
	appendstringtosvg(psvg, "' ry='");
	appendnumbertosvg(psvg, radiusy);
	appendstringtosvg(psvg, "' rx='");
	appendnumbertosvg(psvg, radiusx);
	appendstringtosvg(psvg, "' />\n");
}
