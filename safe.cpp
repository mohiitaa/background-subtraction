/*
This file is part of BGSLibrary.

BGSLibrary is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BGSLibrary is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BGSLibrary.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <opencv2/opencv.hpp>
#include <ctime>
#include "package_bgs/bgslibrary.h"
#include <fstream>

// using namespace std;
int main(int argc, char **argv)
{
  std::cout << "Using OpenCV " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << "." << CV_SUBMINOR_VERSION << std::endl;
  ofstream myfile;
  std::string TimeFile = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/fluidHighway2/PAWCS/TimeTakenPerFrame.txt";   // CHANGE THE TIME FILE

  myfile.open (TimeFile);
  
 
  
  /* Background Subtraction Methods */                                                 // CHANGE THE METHOD
  IBGS *bgs;

  // bgs = new FrameDifference;
  //bgs = new StaticFrameDifference;
  //bgs = new WeightedMovingMean;
  //bgs = new WeightedMovingVariance;
  //bgs = new MixtureOfGaussianV1; // only on OpenCV 2.x
  //bgs = new MixtureOfGaussianV2;
  //bgs = new AdaptiveBackgroundLearning;
  //bgs = new AdaptiveSelectiveBackgroundLearning;
  //bgs = new GMG; // only on OpenCV 2.x
  //bgs = new KNN; // only on OpenCV 3.x
  //bgs = new DPAdaptiveMedian;
  //bgs = new DPGrimsonGMM;
  //bgs = new DPZivkovicAGMM;
  //bgs = new DPMean;
  //bgs = new DPWrenGA;
  // bgs = new DPPratiMediod;
  //bgs = new DPEigenbackground;
  //bgs = new DPTexture;
  //bgs = new T2FGMM_UM;
  //bgs = new T2FGMM_UV;
  //bgs = new T2FMRF_UM;
  //bgs = new T2FMRF_UV;
  //bgs = new FuzzySugenoIntegral;
  //bgs = new FuzzyChoquetIntegral;
  // bgs = new MultiLayer;
  // bgs = new PixelBasedAdaptiveSegmenter;
  //bgs = new LBSimpleGaussian;
  //bgs = new LBFuzzyGaussian;
  //bgs = new LBMixtureOfGaussians;
  //bgs = new LBAdaptiveSOM;
  //bgs = new LBFuzzyAdaptiveSOM;
  //bgs = new LBP_MRF;
  //bgs = new VuMeter;
  //bgs = new KDE;
  //bgs = new IndependentMultimodal;
  //bgs = new MultiCue;
  // bgs = new SigmaDelta;
  // bgs = new SuBSENSE;
  //bgs = new LOBSTER;
  bgs = new PAWCS;
  //bgs = new TwoPoints;
  // bgs = new ViBe;
  //bgs = new CodeBook;
  double total_time = 0;
  double mean_time = 0;
  int frameNumber = 1;
  int key = 0;
  while (key != 'q')
  {
    std::stringstream ss;
    ss << frameNumber;
    std::string fileName = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/fluidHighway2/input/" + ss.str() + ".jpg";  
    std::cout << "reading " << fileName << std::endl;

    cv::Mat img_input = cv::imread(fileName, CV_LOAD_IMAGE_COLOR);

    if (img_input.empty()){
      // cout<<"HOLA";
      break;
    }
///home/n1703443a/Desktop/opencpp_projects/night_surveillance/fluidHighway/input/
    cv::imshow("input", img_input);
    // cout<<"HOLA"
    cv::Mat img_mask;
    cv::Mat img_bkgmodel;
    std::clock_t begin = clock();
    bgs->process(img_input, img_mask, img_bkgmodel);
    std::clock_t end = clock();

    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    myfile<<"Time elapsed for frame " <<frameNumber<<": "<<elapsed_secs<<std::endl;

    
    total_time = total_time + elapsed_secs;
    

    // by default, "bgs->process(.)" automatically shows the foreground mask image
    // or set "bgs->setShowOutput(false)" to disable

    //if(!img_mask.empty())
    //  cv::imshow("Foreground", img_mask);
    //  do something
 //    int cntr = 0:
 //    // saving part:
	// std::string savingName = "/home/administrator/Desktop/bg_sub/" + std::to_string(++cntr) + ".jpg";
	// cv::imwrite(savingName, image);
	std::string savingName = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/fluidHighway2/PAWCS/" + ss.str() + ".jpg";   // CHANGE THE SAVING DIRECTORY
    cv::imwrite(savingName, img_mask);
    key = cvWaitKey(33);
    frameNumber++;
    
  }
  

  mean_time = total_time/frameNumber;
  std::cout<<"Total number of frames: "<<frameNumber<<std::endl;
  std::cout<<"Total Mean Time: "<<mean_time<<std::endl;

  cvWaitKey(20);
  delete bgs;
  cvDestroyAllWindows();
  myfile.close();
  return 0;
}
