# esviji
A simple svg library written in C

### Basic Usage

1. Create the image
```c
Svg *svg_img;
svg_img = svg_create(512, 512); // 512 * 512 px
```
2. Refer to prototypes in `esviji.h` for creating a shape, like this:
```c
if (svg_img == NULL) {
  puts("svg_img is NULL");
} else {
  svg_rectangle(svg_img, 256, 256, 0, 20, "#123123", "#FFFFFF", 5, 2, 2);
}
```
3. Finalize and save
```c
// put this in the else block above
svg_finalize(svg_img);
svg_save(svg_img, "rectangle.svg");
svg_free(svg_img); // To free allocated memory
```
