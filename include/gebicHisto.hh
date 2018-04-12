/*
 *  gebicHisto.hh
 *  
 *
 * 
 *	Geant496
 */

#ifndef gebicHisto_h
#define gebicHisto_h 1

//---------------------------------------------------------------------------
//
// ClassName:   gebicHisto
//
// Description: Utility class to hold and manipulate histograms/nTuples
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "globals.hh"
#include <vector>


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

// Root classes
class TFile;
class TH1D;
class TNtuple;


class gebicHistoMessenger;

class gebicHisto
{

public:
  gebicHisto();

  ~gebicHisto();

  void Book();
  // Book predefined histogramms 

  void Save();
  // Save histogramms to file

  void Add1D(const G4String&, const G4String&, G4int nb=100, G4double x1=0., 
                                               G4double x2=1., G4double u=1.);
  // In this method histogramms are predefined

  void SetHisto1D(G4int, G4int, G4double, G4double, G4double);
  // It change bins and boundaries

  void FillHisto(G4int, G4double, G4double);
  // gebicHistogramms are filled

  void ScaleHisto(G4int, G4double);

  void AddTuple(const G4String&, const G4String&, const G4String&);
  // In this method nTuple is booked

  void FillTuple(G4int, const G4String&, G4double);
  // Fill nTuple parameter with a double

  void FillTuple(G4int, G4int, G4double);
  // Fill nTuple at a given col with a double
  void FillTuple(G4int, const G4String&, G4String&);
  // Fill nTuple parameter with a string

  void FillTuple(G4int, const G4String&, G4bool);
  // Fill nTuple parameter with a bool

  void AddRow(G4int);
  // Save tuple event 

  void SetFileName(const G4String&);
  const G4String& GetFileName() const;
  void SetFileType(const G4String&);
  const G4String& FileType() const;

private:

  G4String fHistName;
  G4String fHistType;

  G4int    fNHisto;
  G4int    fNTuple;
  G4int    fVerbose;
  G4int    fDefaultAct;


  TFile* fHfileROOT; 
  std::vector<TH1D*> fROOThisto;
  std::vector<TNtuple*>   fROOTntup;
  std::vector< std::vector<float> > fRarray;
  std::vector<G4int> fRcol;


  gebicHistoMessenger* fMessenger;

  std::vector<G4int>     fActive;
  std::vector<G4int>     fBins;
  std::vector<G4double>  fXmin;
  std::vector<G4double>  fXmax;
  std::vector<G4double>  fUnit;
  std::vector<G4String>  fIds;
  std::vector<G4String>  fTitles;
  std::vector<G4String>  fTupleName;
  std::vector<G4String>  fTupleId;
  std::vector<G4String>  fTupleList;
  std::vector<G4String>  fTupleListROOT; 
};

#endif
