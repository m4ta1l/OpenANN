#pragma once

#include <layers/Layer.h>
#include <io/Logger.h>
#include <ActivationFunctions.h>

namespace OpenANN {

class Convolutional : public Layer
{
  Logger debugLogger;
  int I, fmin, inRows, inCols, fmout, kernelRows, kernelCols;
  bool bias, weightForBias;
  ActivationFunction act;
  fpt stdDev;
  Vt* x;
  //! output feature maps X input feature maps X kernel rows X kernel cols
  std::vector<std::vector<Mt> > W;
  std::vector<std::vector<Mt> > Wd;
  //! output feature maps X input feature maps
  Mt Wb;
  Mt Wbd;
  Vt a;
  Vt y;
  Vt yd;
  Vt deltas;
  Vt e;
  int fmInSize, outRows, outCols, fmOutSize, maxRow, maxCol;

public:
  Convolutional(OutputInfo info, int featureMaps, int kernelRows, int kernelCols, bool bias, ActivationFunction act, fpt stdDev);
  virtual OutputInfo initialize(std::list<fpt*>& parameterPointers, std::list<fpt*>& parameterDerivativePointers);
  virtual void forwardPropagate(Vt* x, Vt*& y);
  virtual void backpropagate(Vt* ein, Vt*& eout);
};

}