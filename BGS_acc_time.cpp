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
  int tp,fp,tn,fn;
  int total_tp, total_tn, total_fp, total_fn;
  total_tp = total_tn = total_fp = total_fn = 0;
  tp = 0;
  fp = 0;
  tn = 0;
  fn = 0;
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
    // cout << ss;
    if ((frameNumber >= 400) && (frameNumber < 882))
    {
    std::string gtr = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/fluidHighway2/groundtruth/" + ss.str() + ".png";
    cv::Mat gt = cv::imread(gtr, CV_LOAD_IMAGE_COLOR);
    int width_mask = img_mask.size().width;
    int height_mask = img_mask.size().height;
    int width_gt = gt.size().width;
    int height_gt = gt.size().height;
    int i,j;
    if(width_mask == width_gt && height_mask==height_gt)
    {
      for(i = 0;i<width_mask;i++)
      {
        for(j = 0; j<height_mask;j++)
        {
          if((img_mask.at<uchar>(i,j) == 0)&&(gt.at<uchar>(i,j) == 0))
          {
            tn = tn + 1;
          }
          else if((img_mask.at<uchar>(i,j) == 1)&&(gt.at<uchar>(i,j) == 0))
          {
            fp = fp + 1;
          }
          else if((img_mask.at<uchar>(i,j) == 0)&&(gt.at<uchar>(i,j) == 1))
          {
            fn = fn + 1;
          }
          else
          {
            tp = tp + 1;
          }
        }
      }
    }
    else std::cout<<"Dimensions do not match"<<std::endl;

    

    }

    total_tp = total_tp + tp;
    total_tn = total_tn + tn;
    total_fp = total_fp + fp;
    total_fn = total_fn + fn;
    
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
  double TruePositive, TrueNegative, FalsePositive, FalseNegative;
  TruePositive = TrueNegative = FalsePositive = FalseNegative = 0;
  TruePositive = total_tp/frameNumber;
  TrueNegative = total_tn/frameNumber;
  FalseNegative = total_fn/frameNumber;
  FalsePositive = total_fp/frameNumber;


  std::cout<<"Total number of frames: "<<frameNumber<<std::endl;
  std::cout<<"Total Mean Time: "<<mean_time<<std::endl;
  std::cout<<"TruePositive :"<<TruePositive<<std::endl;
  std::cout<<"TrueNegative :"<<TrueNegative<<std::endl;
  std::cout<<" FalseNegative :"<<FalseNegative<<std::endl;
  std::cout<<"FalsePositive :"<<FalsePositive<<std::endl;

  cvWaitKey(20);
  delete bgs;
  cvDestroyAllWindows();
  myfile.close();
  return 0;
}
