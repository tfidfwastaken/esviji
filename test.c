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
		svg_filter(svg_img, "idname", 0, 0, 15);
		svg_rectangle(svg_img, 256, 256, 0, 0, "yellow", "#000000", 5, 2, 2, "idname");
		svg_line(svg_img, "#000000", 2, 0, 0, 256, 256);
		svg_finalize(svg_img);
		svg_save(svg_img, "rectangle.svg");
		svg_print(svg_img);
		svg_free(svg_img);
	}
}

