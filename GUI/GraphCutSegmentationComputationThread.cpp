/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "GraphCutSegmentationComputationThread.h"
#include "GraphCutSegmentationComputationObject.h"

#include "itkGraphCutSegmentation.h"

GraphCutSegmentationComputationThread::GraphCutSegmentationComputationThread() : ComputationThreadClass()
{

}

void GraphCutSegmentationComputationThread::Compute()
{
  emit StartProgressBarSignal();

  // Start the procedure
  this->Stop = false;

  this->Object->Compute();

  //unsigned int num = dynamic_cast<SuperPixelSegmentationComputationObject<ImageT*>(this->Object)->FinalNumberOfSegments;
  //emit IterationCompleteSignal();
  //emit IterationCompleteSignal(dynamic_cast<SuperPixelSegmentationComputationObject*>(this->Object)->FinalNumberOfSegments);
  emit IterationCompleteSignal(this->Object->FinalNumberOfSegments);

  // When the function is finished, end the thread
  exit();
}