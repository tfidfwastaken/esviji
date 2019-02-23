#include <stdio.h>
#include "esviji.h"

void drawrectangles();

int main()
{
	drawrectangles();
	return 0;
}

void drawrectangles()
{
	Svg *svg_img;
	svg_img = svg_create(512, 512);
	if (svg_img == NULL) {
		puts("svg_img is NULL");
	} else {
		svg_rectangle(svg_img, 256, 256, 0, 20, "#123123", "#FFFFFF", 5, 2, 2);
		svg_finalize(svg_img);
		svg_save(svg_img, "rectangle.svg");
		svg_free(svg_img);
	}
}

