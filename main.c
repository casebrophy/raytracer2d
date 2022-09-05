#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

const int IMG_HEIGHT = 512;
const int IMG_WIDTH = 512;
const int NUM_CHANNELS = 3;

unsigned char *image;


void getPixelColor(int i, int j, unsigned char *image) {
    image[0] = image[1] = image[2] = 0;
}

int main(int argc, char **argv) {
    
    // initialize array for holding image
    image = malloc(IMG_WIDTH * NUM_CHANNELS * IMG_HEIGHT);
    if (image == NULL) {
        printf("ERROR: image is null\n");
        return 1;
    }

    int index = 0;

    for (int i = 0; i < IMG_WIDTH; i++) {
        for (int j = 0; j < IMG_HEIGHT; j++) {
            getPixelColor(i, j, &image[index]);
            index += 3;
        }
    }

    stbi_write_png("image", IMG_WIDTH, IMG_HEIGHT, 3, image, IMG_WIDTH*3);
    free(image);
}