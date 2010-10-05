#ifndef __EXVDETECTOR_h_
#define __EXVDETECTOR_h_

#include "TVector3.h"
#include "kaltest/TVKalDetector.h"
#include "kaltest/TAttDrawable.h"

class TVMeasLayer;
class TNode;

class EXVKalDetector : public TVKalDetector, public TAttDrawable {
public:
   EXVKalDetector(Int_t m = 100);
   virtual ~EXVKalDetector();

   inline virtual Bool_t IsPowerOn() const { return fIsPowerOn;   }
   inline virtual void   PowerOn  ()       { fIsPowerOn = kTRUE;  }
   inline virtual void   PowerOff ()       { fIsPowerOn = kFALSE; }

   static Double_t GetBfield (const TVector3 &xx = TVector3(0.))
                             { return fgBfield; }

  inline void SetBField( double b ) {  fgBfield = b ; }

   using  TAttDrawable::Draw;
   virtual void Draw(Int_t color, const Char_t *opt = "");

   static void   SetNodePtr(TNode *nodep) { fgNodePtr = nodep; }
   static TNode *GetNodePtr();

private:
   Bool_t  fIsPowerOn;         // power status
   static Double_t fgBfield;   // magnetic field [kG]
   static TNode   *fgNodePtr;  // pointer to TNode

   //ClassDef(EXVKalDetector,1)   // Sample hit class
};

#endif
