#include "TFile.h"
#include "TTree.h"
#include <iostream>
#include "TH1D.h"

void rate_Digis()
{
	using namespace std;
	TFile* lFile = TFile::Open("/export/d00/scratch/luck/HydjetMB_740pre8_MCHI2_74_V3_53XBS_L1UpgradeAnalyzer_GT_MCHI2_74_V3.root");	

	TH1D* taupt = new TH1D("taupt","L1 Track Et",100,0.0,100.0);

	TTree* l1Tree;
  l1Tree = (TTree*)lFile->Get("L1UpgradeAnalyzer/L1UpgradeTree");
Int_t MAXTRACKS = 20000;

  Int_t l1_event, l1_run;
  Int_t l1_num;
  Int_t l1_hwPt[MAXTRACKS], l1_hwEta[MAXTRACKS], l1_hwPhi[MAXTRACKS], l1_hwQual[MAXTRACKS];
  Double_t l1_pt[MAXTRACKS], l1_eta[MAXTRACKS], l1_phi[MAXTRACKS];

  Int_t l1_numJets;
  Int_t l1_hwPtJets[MAXTRACKS], l1_hwEtaJets[MAXTRACKS], l1_hwPhiJets[MAXTRACKS], l1_hwQualJets[MAXTRACKS];
  Double_t l1_ptJets[MAXTRACKS], l1_etaJets[MAXTRACKS], l1_phiJets[MAXTRACKS];

  l1Tree->SetBranchAddress("event",&l1_event);
  l1Tree->SetBranchAddress("run",&l1_run);
  l1Tree->SetBranchAddress("nTau",&l1_num);
  l1Tree->SetBranchAddress("tau_hwPt",l1_hwPt);
  l1Tree->SetBranchAddress("tau_hwEta",l1_hwEta);
  l1Tree->SetBranchAddress("tau_hwPhi",l1_hwPhi);
  l1Tree->SetBranchAddress("tau_hwQual",l1_hwQual);
  l1Tree->SetBranchAddress("tau_pt",l1_pt);
  l1Tree->SetBranchAddress("tau_eta",l1_eta);
  l1Tree->SetBranchAddress("tau_phi",l1_phi);

int entries = l1Tree->GetEntries();
double maxl1pt = 0.0;
double maxl1Eta = 0.0;
double maxl1Phi = 0.0; 
int numpassed = 0;
int numtotal = 0;
int threshold = 12.0;

for (int i = 0; i < entries; i++)
{
l1Tree->GetEntry(i);

if (l1_num > 0)
{
      maxl1pt = l1_pt[0];
      maxl1Eta = l1_eta[0];
      maxl1Phi = l1_phi[0]; 
      numtotal++;	
	taupt->Fill(maxl1pt);
	cout << maxl1pt << endl;
}

if (maxl1pt >= threshold)
{
	numpassed++;
} 	
      
}                                                   

cout << numpassed << " " << numtotal << " " << (double)numpassed/(double)numtotal << endl;

taupt->Draw();
		
}
