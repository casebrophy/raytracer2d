#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./stb_image_write.h"
#include "math.h"

const int IMG_HEIGHT = 512;
const int IMG_WIDTH = 512;
const int NUM_CHANNELS = 3;

unsigned char *checker;
unsigned char *gradient;

// red in checkerboard = 255, 0, 0
// blue in checkerboard = 0, 0, 255

void makeCheckerBoard(int x, int y, unsigned char *image) {
    int row = x / 64; 
    int column = y / 64;
    if ( (row % 2 == 0 && column % 2 == 0) || ( row % 2 == 1 && column % 2 == 1))  {
        image[0] = 255;
        image[1] = 0;
        image[2] = 0;
    } else {
        image[0] = 0;
        image[1] = 0;
        image[2] = 255;
    }
}

void makeGradient(int x, int y, unsigned char *image) {

    if (x >= 2) {
        x++;
        if (x >= 255) {
            x++;
        }
    } 
    if (y >= 2) {
        y++;
        if (y >= 255) {
            y++;
        }
    }

    // when x is 0 the the red channel is off and when x 512, the red channel should be 255
    float x_adj = x / 512.0;
    // when y is 0 the greeen chanel is off and when why is 512 the green chanell should be 255
    float y_adj = y / 512.0;

    if (x == 255 || x == 256 || x == 257) {
        printf("%f\n", x_adj);
    }

    float rval = floor(255.0 * x_adj);
    float gval = floor(255.0 * y_adj);


    //printf("%f\n", rval);
    
    image[0] = rval;    
    image[1] = gval;    
    image[2] = 128;    
}

int main(int argc, char **argv) {
    int index = 0;
    
    // initialize array for holding image
    checker = malloc(IMG_WIDTH * NUM_CHANNELS * IMG_HEIGHT);
    gradient = malloc(IMG_WIDTH * NUM_CHANNELS * IMG_HEIGHT);
    if (checker == NULL || gradient == NULL) {
        printf("ERROR: malloc of images failed\n");
        return 1;
    }

    for (int i = 0; i < IMG_WIDTH; i++) {
        for (int j = 0; j < IMG_HEIGHT; j++) {
            makeCheckerBoard(j, i, &checker[index]);
            makeGradient(j, i, &gradient[index]);
            index += 3;
        }
    }

    stbi_write_png("checkerboard.png", IMG_WIDTH, IMG_HEIGHT, 3, checker, IMG_WIDTH*3);
    stbi_write_png("gradient.png", IMG_WIDTH, IMG_HEIGHT, 3, gradient, IMG_WIDTH*3);
    free(checker);
    free(gradient);

    return 0;
}