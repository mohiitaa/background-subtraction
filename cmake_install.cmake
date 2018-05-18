# Install script for directory: /home/n1703443a/bgslibrary

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "runtime")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/n1703443a/bgslibrary/libbgs.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/package_bgs" TYPE FILE FILES
    "/home/n1703443a/bgslibrary/package_bgs/SuBSENSE.h"
    "/home/n1703443a/bgslibrary/package_bgs/FrameDifference.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPEigenbackground.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2FMRF_UM.h"
    "/home/n1703443a/bgslibrary/package_bgs/KDE/NPBGmodel.h"
    "/home/n1703443a/bgslibrary/package_bgs/KDE/KernelTable.h"
    "/home/n1703443a/bgslibrary/package_bgs/KDE/NPBGSubtractor.h"
    "/home/n1703443a/bgslibrary/package_bgs/KDE.h"
    "/home/n1703443a/bgslibrary/package_bgs/LOBSTER.h"
    "/home/n1703443a/bgslibrary/package_bgs/CodeBook.h"
    "/home/n1703443a/bgslibrary/package_bgs/TwoPoints.h"
    "/home/n1703443a/bgslibrary/package_bgs/SigmaDelta/sdLaMa091.h"
    "/home/n1703443a/bgslibrary/package_bgs/PixelBasedAdaptiveSegmenter.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBFuzzyAdaptiveSOM.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBP_MRF/graph.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBP_MRF/block.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBAdaptiveSOM.h"
    "/home/n1703443a/bgslibrary/package_bgs/FuzzyChoquetIntegral.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBFuzzyGaussian.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2FGMM_UM.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2FGMM_UV.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/AdaptiveMedianBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/GrimsonGMM.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/PratiMediodBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/MeanBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/Image.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/Eigenbackground.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/ZivkovicAGMM.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/Error.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/BgsParams.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/WrenGA.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/Bgs.h"
    "/home/n1703443a/bgslibrary/package_bgs/dp/TextureBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBP_MRF.h"
    "/home/n1703443a/bgslibrary/package_bgs/WeightedMovingVariance.h"
    "/home/n1703443a/bgslibrary/package_bgs/VuMeter/TBackground.h"
    "/home/n1703443a/bgslibrary/package_bgs/VuMeter/TBackgroundVuMeter.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPAdaptiveMedian.h"
    "/home/n1703443a/bgslibrary/package_bgs/AdaptiveBackgroundLearning.h"
    "/home/n1703443a/bgslibrary/package_bgs/GMG.h"
    "/home/n1703443a/bgslibrary/package_bgs/FuzzySugenoIntegral.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2F/MRF.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2F/T2FMRF.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2F/FuzzyUtils.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2F/T2FGMM.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPGrimsonGMM.h"
    "/home/n1703443a/bgslibrary/package_bgs/MixtureOfGaussianV2.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBMixtureOfGaussians.h"
    "/home/n1703443a/bgslibrary/package_bgs/ViBe.h"
    "/home/n1703443a/bgslibrary/package_bgs/PBAS/PBAS.h"
    "/home/n1703443a/bgslibrary/package_bgs/IBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/StaticFrameDifference.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPWrenGA.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPZivkovicAGMM.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/BackgroundSubtractionAPI.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/OpenCvDataConversion.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/blob.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/LocalBinaryPattern.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/BlobLibraryConfiguration.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/OpenCvLegacyIncludes.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/BlobResult.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/CMultiLayerBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/BGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer/BlobExtraction.h"
    "/home/n1703443a/bgslibrary/package_bgs/KNN.h"
    "/home/n1703443a/bgslibrary/package_bgs/PAWCS.h"
    "/home/n1703443a/bgslibrary/package_bgs/IndependentMultimodal.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPTexture.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/RandUtils.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/BackgroundSubtractorSuBSENSE.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/DistanceUtils.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/BackgroundSubtractorLBSP_.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/LBSP.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/BackgroundSubtractorPAWCS.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/BackgroundSubtractorLOBSTER.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/BackgroundSubtractorLBSP.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSP/LBSP_.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPPratiMediod.h"
    "/home/n1703443a/bgslibrary/package_bgs/SigmaDelta.h"
    "/home/n1703443a/bgslibrary/package_bgs/DPMean.h"
    "/home/n1703443a/bgslibrary/package_bgs/T2FMRF_UV.h"
    "/home/n1703443a/bgslibrary/package_bgs/bgslibrary.h"
    "/home/n1703443a/bgslibrary/package_bgs/TwoPoints/two_points.h"
    "/home/n1703443a/bgslibrary/package_bgs/MixtureOfGaussianV1.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/BGModel.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/Types.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/BGModelFuzzySom.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/BGModelGauss.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/BGModelMog.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/BGModelFuzzyGauss.h"
    "/home/n1703443a/bgslibrary/package_bgs/lb/BGModelSom.h"
    "/home/n1703443a/bgslibrary/package_bgs/VuMeter.h"
    "/home/n1703443a/bgslibrary/package_bgs/ViBe/vibe-background-sequential.h"
    "/home/n1703443a/bgslibrary/package_bgs/LBSimpleGaussian.h"
    "/home/n1703443a/bgslibrary/package_bgs/_template_/amber/amber.h"
    "/home/n1703443a/bgslibrary/package_bgs/_template_/Amber.h"
    "/home/n1703443a/bgslibrary/package_bgs/_template_/MyBGS.h"
    "/home/n1703443a/bgslibrary/package_bgs/WeightedMovingMean.h"
    "/home/n1703443a/bgslibrary/package_bgs/AdaptiveSelectiveBackgroundLearning.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiLayer.h"
    "/home/n1703443a/bgslibrary/package_bgs/MultiCue.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "app")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/n1703443a/bgslibrary/bgslibrary")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary"
         OLD_RPATH "/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/bgslibrary")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/n1703443a/bgslibrary/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
