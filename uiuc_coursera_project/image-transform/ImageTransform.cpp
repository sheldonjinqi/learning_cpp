#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name: Qi Jin
Email: qijin1@seas.upenn.edu

(...end multi-line comment.)
******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a reference to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly. No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
  for(unsigned x=0; x<image.width();x++){
    for(unsigned y=0;y<image.height();y++){
      double d2c = sqrt(pow(int(centerX-x),2)+pow(int(centerY-y),2));
      if(d2c>160){
        d2c = 160;
      }
      double l_perct = 1-d2c*(0.5/100);

      HSLAPixel & pixel = image.getPixel(x,y);
      pixel.l = pixel.l*l_perct;
    }
  }
  return image;
  
}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
PNG illinify(PNG image) {
  for(unsigned x=0;x<image.width();x++){
    for(unsigned y=0;y<image.height();y++){
      HSLAPixel & pixel = image.getPixel(x,y);
      double curr_hue = pixel.h;
      if(abs(curr_hue-11)>abs(curr_hue-216) && abs(curr_hue-216)<(361-curr_hue)){
        pixel.h = 216;
      }
      else{
        pixel.h = 11;
      }
    }
  }
  return image;
}
 

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
PNG watermark(PNG firstImage, PNG secondImage) {
  unsigned x_bound, y_bound;
  // std::cout<<"first image dimension"<<int(firstImage.width())<<"\t"<<int(firstImage.height())<<std::endl
  // <<"second image dimention"<<int(secondImage.width())<<"\t"<<int(secondImage.height());
  if(firstImage.width()<secondImage.width()){
    x_bound = firstImage.width();
  }
  else{
    x_bound = secondImage.width();
  }
  if(firstImage.height()<secondImage.height()){
    y_bound = firstImage.height();
  }
  else{
    y_bound = secondImage.height();
  }
  for(unsigned x = 0; x<x_bound;x++){
    for(unsigned y =0 ; y< y_bound;y++){
      HSLAPixel &pixel_1 = firstImage.getPixel(x,y);
      HSLAPixel &pixel_2 = secondImage.getPixel(x,y);
      if(pixel_2.l == 1.0 && pixel_1.l <1.0){
        pixel_1.l += 0.2;
      }
    }
  }
  return firstImage;
}
