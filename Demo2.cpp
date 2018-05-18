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
#include <string>

// using namespace std;
int main(int argc, char **argv)
{
  std::cout << "Using OpenCV " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << "." << CV_SUBMINOR_VERSION << std::endl;
  ofstream myfile;
  std::string TimeFile = "/home/n1703443a/Desktop/myResults/time-taken/bridgeEntry/PAWCS/TimeTakenPerFrame.txt";   // CHANGE THE TIME FILE

  myfile.open (TimeFile);
  // std::cout<<"HELLO";
  unsigned long int gtcount = 0;
  
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
  int frameNumber = 1;  //Change this to 1 (default)
  int key = 0;
  int tp,fp,tn,fn;
  // long int wid, ht;
  // wid = ht = 0;
  
  unsigned long int total_tp, total_tn, total_fp, total_fn;
  total_tp = total_tn = total_fp = total_fn = 0;
  tp = 0;
  fp = 0;
  tn = 0;
  fn = 0;
  while (key != 'q')
  {
  	tp = 0;
    fp = 0;
    tn = 0;
    fn = 0;
  	  
    std::stringstream ss;
    ss << frameNumber;

    // std::cout<<ss;
    std::string fileName = "/home/n1703443a/Downloads/dataset2014/dataset/nightVideos/bridgeEntry/input/" + ss.str() + ".jpg";  
   // std::string fileName = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/bridgeEntry/input/" + ss.str() + ".jpg";  
    std::cout << "reading " << fileName << std::endl;
    // 
    // std::cout<<"Hey you"<<std::endl;

    cv::Mat img_input = cv::imread(fileName,CV_LOAD_IMAGE_COLOR);
    // std::cout<<"HEY";

    cv::Mat img_fg;
    // if (img_input.empty()){
    //   // cout<<"HOLA";
    //   break;
    // }

    // std::cout<<"HEY";

    std::string gtr = "/home/n1703443a/Downloads/dataset2014/dataset/nightVideos/bridgeEntry/groundtruth/" + ss.str() + ".png";


    cv::Mat gt = cv::imread(gtr, CV_LOAD_IMAGE_COLOR);
    int width_gt = gt.size().width;
    int height_gt = gt.size().height;
  
    // std::cout<<"GROUNDTRUTH:"<<width_gt<<","<<height_gt<<std::endl;

///home/n1703443a/Desktop/opencpp_projects/night_surveillance/bridgeEntry/input/
    cv::imshow("input", img_input);
    // cout<<"HOLA"
    cv::Mat img_mask;
    cv::Mat img_input_gray;

    cv::Mat img_mask_bin;
    cv::Mat img_bkgmodel;
    std::clock_t begin = clock();
    bgs->process(img_input, img_mask, img_bkgmodel);
    std::clock_t end = clock();
    // uint8_t *fg= img_mask.data;
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    myfile<<"Time elapsed for frame " <<frameNumber<<": "<<elapsed_secs<<std::endl;
    // std::cout<<"Time elapsed for frame " <<frameNumber<<": "<<elapsed_secs<<std::endl;
    
    total_time = total_time + elapsed_secs;
    // cout << ss;
        // std::cout<<"Time elapsed for frame " <<frameNumber<<": "<<elapsed_secs<<std::endl;
    // if(frameNumber==459)
    if ((frameNumber >= 1000) && (frameNumber < 1749))
  {

    	// unsigned long int gtcount = 0;
    // std::string gtr = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/bridgeEntry2/groundtruth/" + ss.str() + ".png";
    // cv::Mat gt = cv::imread(gtr, CV_LOAD_IMAGE_COLOR);
    // uint8_t *gt= mygt.data;
    int width_mask = img_mask.size().width;
    int height_mask = img_mask.size().height;

      // std::cout<<"Wid"<<width_gt<<std::endl;
  		// std::cout<<"height"<<height_gt<<std::endl;

    // int _stride = gt.step;
    // int _stride_fg  = img_mask.step;
    

    // std::cout<<"MASK:"<<width_mask<<","<<height_mask<<std::endl;;
     
    // int width_gt = gt.size().width;
    // wid = width_gt;
    // ht = height_gt;
   
    // int height_gt = gt.size().height;
    int i,j;
    i=j=0;
    if(width_mask == width_gt && height_mask==height_gt)
    {
    	// std::cout<<"YES..MATCHED"<<std::endl;

      for(i = 0;i<height_gt;i++)
      {
        for(j = 0; j<width_gt;j++)
        {


			Scalar maskVal;
			maskVal = img_mask.at<uchar>(i, j);
			int maskIntVal = (int)maskVal.val[0];

			Scalar gtVal;
			gtVal = gt.at<uchar>(i, j);
			int gtIntVal = (int)gtVal.val[0];

        	
        	// uint8_t val_gt = gt[ i * _stride + j];
        	// uint8_t val_fg = fg[ i * _stride_fg + j];
        	        // std::cout<<stoi(to_string(img_mask.at<uchar>(i,j)))<<std::endl;
        	// cvWaitKey(); 
        	// std::cout<<gt.at<uchar>(i,j)<<std::endl;
        	//std::cout<<width_gt<<std::endl;
          // if((stoi(to_string(img_mask.at<uchar>(i,j))))&&(stoi(to_string(gt.at<uchar>(i,j))) == 0))
          // {
          //   tn = tn + 1;
          // }
        	

          // else if((stoi(to_string(img_mask.at<uchar>(i,j))) == 1)&&(stoi(to_string(gt.at<uchar>(i,j))) == 0))
          // {
          //   fp = fp + 1;
          // }
          // else if((stoi(to_string(img_mask.at<uchar>(i,j))) == 0)&&(stoi(to_string(gt.at<uchar>(i,j))) == 1))
          // {
          //   fn = fn + 1;
          // }
          // else
          // {
          //   tp = tp + 1;

          // }
		  if (((gtIntVal==170)||(gtIntVal==255)||(gtIntVal==50)||(gtIntVal==0)))
			//if(gtIntVal == 0)
		  {
		  	gtcount++;
		  	// std::cout<<"Total pixels in fg as of now:"<<gtcount<<std::endl;
		  }
    		
		  // std::cout<<"MASK:"<<maskIntVal<<","<<"GT:"<<gtIntVal<<"----"; 
		  if(gtIntVal == 85)
		  {
		  	continue;
		  }
          else if((maskIntVal <= 5)&&(gtIntVal == 0))
          {
            tn = tn + 1;
            // std::cout<<"TRUE NEG"<<std::endl;
            // getchar();
          }
          else if(((maskIntVal>=200) && (maskIntVal <= 255))&&(gtIntVal == 0))
          {
            fp = fp + 1;
            // std::cout<<"MASK:"<<maskIntVal<<","<<"GT:"<<gtIntVal<<"----";
            // std::cout<<"FALSE POS"<<std::endl;
            // getchar();
          }
          else if((maskIntVal <= 5)&&((gtIntVal==170)||(gtIntVal==255)||(gtIntVal==50)))
          {
            fn = fn + 1;
            // std::cout<<"MASK:"<<maskIntVal<<","<<"GT:"<<gtIntVal<<"----";
            // std::cout<<"FALSE NEG"<<std::endl;
            // getchar();

            
          }
          else if(((maskIntVal>=200) && (maskIntVal <= 255))&&((gtIntVal==170)||(gtIntVal==255)||(gtIntVal==50)))
          {
            tp = tp + 1;
            // std::cout<<"MASK:"<<maskIntVal<<","<<"GT:"<<gtIntVal<<"----"; 
            // std::cout<<"TRUE POS"<<std::endl;
            // getchar();

            
          }
          // getchar();
    //     	// 
			// if (maskIntVal != 0)
			// {
			// 	std::cout<<"val_fg__________________<"<<maskIntVal<<"at coordinates"<<i<<j<<std::endl;
			// }
   //        if (gtIntVal != 0)
			// {
			// 	std::cout<<"val_fg__________________<"<<gtIntVal<<"at coordinates"<<i<<j<<std::endl;
			// }
          	// std::cout<<"val_fg__________________<"<<maskIntVal<<std::endl;
    		// std::cout<<"val_gt__________________<"<<gtIntVal<<std::endl;
    		
        	// std::cout<<"HAHA"<<std::endl;

        }
    	
      }// std::cout<<"HAHA"<<std::endl;
    }
    else 
    	{
    		std::cout<<"Dimensions do not match"<<std::endl;
    		break;
    	}
    
    	// exit(0);
  }


    // long int temp_p = 0;
    // long int temp_r = 0;

    // temp_p = tp/(tp+fp);
    // temp_r = tp/(tp+fn);

    // std::cout<<"Temp precision:"<<temp_p<<","<<"Temp Recall:"<<temp_r<<std::endl;



    // std::cout<<"fn :"<<fn<<std::endl;
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
     // cv::

	  std::string savingName = "/home/n1703443a/Desktop/myResults/bridgeEntry/PAWCS/" + ss.str() + ".jpg";   // CHANGE THE SAVING DIRECTORY
    cv::imwrite(savingName, img_mask);


    // std::string FG = "/home/n1703443a/Desktop/opencpp_projects/night_surveillance/bridgeEntry2/SuBSENSE/fg/" + ss.str() + ".jpg";   // CHANGE THE SAVING DIRECTORY
    
    // cv::threshold( img_mask, img_mask_bin, 125,255,THRESH_BINARY );
    // cv::cvtColor( img_input, img_input_gray, CV_RGB2GRAY );
    // cv::bitwise_and(img_mask_bin,img_input_gray,img_fg);
    // cv::imwrite(FG, img_fg);
    key = cvWaitKey(33);
    frameNumber++;
    if(frameNumber == 2501)
    {
      break;
    }
  }
  std::cout<<"total_tp :"<<total_tp<<std::endl;
  std::cout<<"total_tn :"<<total_tn<<std::endl;
  std::cout<<" total_fn :"<<total_fn<<std::endl;
  std::cout<<"total_fp:"<<total_fp<<std::endl;

  mean_time = total_time/frameNumber;
  double TruePositive, TrueNegative, FalsePositive, FalseNegative;
  TruePositive = TrueNegative = FalsePositive = FalseNegative = 0;
  TruePositive = total_tp/1;
  TrueNegative = total_tn/1;
  FalseNegative = total_fn/1;
  FalsePositive = total_fp/1;
  double Precision;
  double Recall;

  Precision = TruePositive/(TruePositive + FalsePositive);
  Recall = TruePositive/(TruePositive+FalseNegative);
  // double prod =0;
  // prod = width_mask*height_mask;
  std::cout<<"Total number of frames: "<<frameNumber<<std::endl;
  std::cout<<"Total Mean Time: "<<mean_time<<std::endl;
  std::cout<<"FalsePositive :"<<FalsePositive<<std::endl;
  std::cout<<"TruePositive :"<<TruePositive<<std::endl;
  std::cout<<" FalseNegative :"<<FalseNegative<<std::endl;
  std::cout<<"TrueNegative :"<<TrueNegative<<std::endl;
  std::cout<<" Precision :"<<Precision<<std::endl;
  std::cout<<"Recall :"<<Recall<<std::endl;

  double Fscore;
  Fscore = 2*(Precision/(Precision+Recall))*Recall;
  std::cout<<"Fscore :"<<Fscore<<std::endl;
  std::cout<<"FG in ground truth:"<<gtcount<<std::endl;


  
  // std::cout<<"Total Pixels in each frame :"<<prod<<std::endl;

  cvWaitKey(20);
  delete bgs;
  cvDestroyAllWindows();
  myfile.close();
  return 0;
}
