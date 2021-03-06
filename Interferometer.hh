#ifndef INTER_HEAD
#define INTER_HEAD

#include "IceRayTracing.cc"
#include "gsl/gsl_multimin.h"
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include "AntennaConfig.hh"

using namespace std;

namespace Interferometer{

  double pi=4*atan(1);

  void XYZtoThPhR(Double_t XYZ[3],Double_t ThPhR[3]);
  
  void ThPhRtoXYZ(Double_t ThPhR[3],Double_t XYZ[3]);
  
  void GenerateChHitTimeAndCheckHits(double TxCor[3],double timeRay[2][TotalAntennasRx],int IgnoreCh[2][TotalAntennasRx]);

  bool CheckTrigger(int IgnoreCh[2][TotalAntennasRx]);
  
  void ReadChHitTimeFromData(const char * filename,double ChHitTime[2][TotalAntennasRx]);

  void FindFirstHitAndNormalizeHitTime(double ChHitTime[2][TotalAntennasRx],int IgnoreCh[2][TotalAntennasRx],double ChDRTime[TotalAntennasRx]);
  
  void AddGaussianJitterToHitTimes(double JitterNumber,double ChHitTime[2][TotalAntennasRx]);

  double Minimizer_f(const gsl_vector *v, void *params);

  void Minimizer(double InitialTxCor[3], double FinalTxCor[3], double ExpectedTxCor[3], double ExpectedUncertainty, double ChHitTime[2][TotalAntennasRx], int IgnoreCh[2][TotalAntennasRx], double ChSNR[2][TotalAntennasRx], double &FinalMinValue, int &Iterations);

  double Minimizer_ftest(double InitialTxCor[3], double FinalTxCor[3], double ExpectedTxCor[3], double ChHitTime[2][TotalAntennasRx],int IgnoreCh[2][TotalAntennasRx],double ChSNR[2][TotalAntennasRx], double &FinalMinValue);

  void DoInterferometery(double InitialTxCor[3], double FinalTxCor[3], double ExpectedTxCor[3], double ExpectedUncertainty, double ChHitTime[2][TotalAntennasRx], int IgnoreCh[2][TotalAntennasRx],double ChSNR[2][TotalAntennasRx], double &FinalMinValue, double &Duration,int &Iterations);
  
}
#endif
