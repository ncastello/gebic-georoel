/*
 *  gebicPhysicsListMessenger.cc
 *  
 *
 * 
 *	Geant496
 */
//re-checked 25/11/2013
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "gebicPhysicsListMessenger.hh"

#include "gebicPhysicsList.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

gebicPhysicsListMessenger::gebicPhysicsListMessenger(gebicPhysicsList* pPhys)
: fPPhysicsList(pPhys)
{   
  fPhysDir = new G4UIdirectory("/gebic/phys/");
  fPhysDir->SetGuidance("physics control.");

  fGammaCutCmd = new G4UIcmdWithADoubleAndUnit("/gebic/phys/setGCut",this);  
  fGammaCutCmd->SetGuidance("Set gamma cut.");
  fGammaCutCmd->SetParameterName("Gcut",false);
  fGammaCutCmd->SetUnitCategory("Length");
  fGammaCutCmd->SetRange("Gcut>0.0");
  fGammaCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fElectCutCmd = new G4UIcmdWithADoubleAndUnit("/gebic/phys/setECut",this);  
  fElectCutCmd->SetGuidance("Set electron cut.");
  fElectCutCmd->SetParameterName("Ecut",false);
  fElectCutCmd->SetUnitCategory("Length");
  fElectCutCmd->SetRange("Ecut>0.0");
  fElectCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
  
  fProtoCutCmd = new G4UIcmdWithADoubleAndUnit("/gebic/phys/setPCut",this);  
  fProtoCutCmd->SetGuidance("Set positron cut.");
  fProtoCutCmd->SetParameterName("Pcut",false);
  fProtoCutCmd->SetUnitCategory("Length");
  fProtoCutCmd->SetRange("Pcut>0.0");
  fProtoCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);  

  fAllCutCmd = new G4UIcmdWithADoubleAndUnit("/gebic/phys/setCuts",this);
  fAllCutCmd->SetGuidance("Set cut for all.");
  fAllCutCmd->SetParameterName("cut",false);
  fAllCutCmd->SetUnitCategory("Length");
  fAllCutCmd->SetRange("cut>0.0");
  fAllCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fECutCmd = new G4UIcmdWithADoubleAndUnit("/gebic/phys/TargetCuts",this);
  fECutCmd->SetGuidance("Set cuts for the target");
  fECutCmd->SetParameterName("Ecut",false);
  fECutCmd->SetUnitCategory("Length");
  fECutCmd->SetRange("Ecut>0.0");
  fECutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fMCutCmd = new G4UIcmdWithADoubleAndUnit("/gebic/phys/DetectorCuts",this);
  fMCutCmd->SetGuidance("Set cuts for the Detector");
  fMCutCmd->SetParameterName("Ecut",false);
  fMCutCmd->SetUnitCategory("Length");
  fMCutCmd->SetRange("Ecut>0.0");
  fMCutCmd->AvailableForStates(G4State_PreInit,G4State_Idle);

  fPListCmd = new G4UIcmdWithAString("/gebic/phys/SelectPhysics",this);
  fPListCmd->SetGuidance("Select modul physics list.");
  fPListCmd->SetParameterName("PList",false);
  fPListCmd->AvailableForStates(G4State_PreInit,G4State_Idle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

gebicPhysicsListMessenger::~gebicPhysicsListMessenger()
{
  delete fPhysDir;
  delete fGammaCutCmd;
  delete fElectCutCmd;
  delete fProtoCutCmd;
  delete fAllCutCmd;
  delete fPListCmd;
  delete fECutCmd;
  delete fMCutCmd;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void gebicPhysicsListMessenger::SetNewValue(G4UIcommand* command,
                                          G4String newValue)
{
  if( command == fGammaCutCmd )
   { fPPhysicsList->SetCutForGamma(fGammaCutCmd->GetNewDoubleValue(newValue));}

  if( command == fElectCutCmd )
   { fPPhysicsList->SetCutForElectron(fElectCutCmd->GetNewDoubleValue(newValue));}

  if( command == fProtoCutCmd )
   { fPPhysicsList->SetCutForPositron(fProtoCutCmd->GetNewDoubleValue(newValue));}

  if( command == fAllCutCmd )
    {
      G4double cut = fAllCutCmd->GetNewDoubleValue(newValue);
      fPPhysicsList->SetCutForGamma(cut);
      fPPhysicsList->SetCutForElectron(cut);
      fPPhysicsList->SetCutForPositron(cut);
    }

  if( command == fECutCmd )
   { fPPhysicsList->SetTargetCut(fECutCmd->GetNewDoubleValue(newValue));}

  if( command == fMCutCmd )
   { fPPhysicsList->SetDetectorCut(fMCutCmd->GetNewDoubleValue(newValue));}

  if( command == fPListCmd )
   { fPPhysicsList->SelectPhysicsList(newValue);}
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
