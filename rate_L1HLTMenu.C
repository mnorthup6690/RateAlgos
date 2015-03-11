#include "TFile.h"
#include "TTree.h"
#include <iostream>

void rate()
{
	using namespace std;

	TFile* f = TFile::Open("/export/d00/scratch/men1/L1Trigger/L1HLTMenu/5.02Hydjet_L1Menuv1_openHLT/L1openHLT.root");
	TTree* hlttree = (TTree*)f->Get("HltTree");
	
	int L1SingleTrack12bit = 0;
	int L1SingleTrack16bit = 0;
        int L1SingleTrack20bit = 0;	

	int L1Centrality05bit = 0;
	int L1Centrality510bit = 0;
	int L1Centrality1030bit = 0;	
	int L1Centrality3050bit = 0;
	int L1Centrality5070bit = 0;
	int L1Centrality70100bit = 0;
	
	int events = 0;

	hlttree->SetBranchAddress("L1_SingleTrack12",&L1SingleTrack12bit);
	hlttree->SetBranchAddress("L1_SingleTrack16",&L1SingleTrack16bit);
	hlttree->SetBranchAddress("L1_SingleTrack20",&L1SingleTrack20bit);
	
	hlttree->SetBranchAddress("L1_Centrality0_5",&L1Centrality05bit);
	hlttree->SetBranchAddress("L1_Centrality5_10",&L1Centrality510bit);
	hlttree->SetBranchAddress("L1_Centrality10_30",&L1Centrality1030bit);
	hlttree->SetBranchAddress("L1_Centrality30_50",&L1Centrality3050bit);	
	hlttree->SetBranchAddress("L1_Centrality50_70",&L1Centrality5070bit);
	hlttree->SetBranchAddress("L1_Centrality70_100",&L1Centrality70100bit);

	events = hlttree->GetEntries();

	int itertrack12Cen05 = 0;
	int itertrack12Cen510 = 0;
	int itertrack12Cen1030 = 0;
	int itertrack12Cen3050 = 0;
	int itertrack12Cen5070 = 0;
	int itertrack12Cen70100 = 0;

	int itertrack16Cen05 = 0;
        int itertrack16Cen510 = 0;
        int itertrack16Cen1030 = 0;
        int itertrack16Cen3050 = 0;
        int itertrack16Cen5070 = 0;
        int itertrack16Cen70100 = 0;

	int itertrack20Cen05 = 0;
        int itertrack20Cen510 = 0;
        int itertrack20Cen1030 = 0;
        int itertrack20Cen3050 = 0;
        int itertrack20Cen5070 = 0;
        int itertrack20Cen70100 = 0;


	for (int i = 0; i < events; i++)
	{
		hlttree->GetEntry(i);
		
		if ((L1SingleTrack12bit == 1) && (L1Centrality05bit == 1))
		{
			itertrack12Cen05++;
		}	
		else if ((L1SingleTrack12bit == 1) && (L1Centrality510bit == 1))
		{
			itertrack12Cen510++;
		}	
		else if ((L1SingleTrack12bit == 1) && (L1Centrality1030bit == 1))
                {
                        itertrack12Cen1030++;
                }
		else if ((L1SingleTrack12bit == 1) && (L1Centrality3050bit == 1))
                {
                        itertrack12Cen3050++;
                }
		else if ((L1SingleTrack12bit == 1) && (L1Centrality5070bit == 1))
                {
                        itertrack12Cen5070++;
                }
		else if ((L1SingleTrack12bit == 1) && (L1Centrality70100bit == 1))
                {
                        itertrack12Cen70100++;
                }
		if ((L1SingleTrack16bit == 1) && (L1Centrality05bit == 1))
		{
			itertrack16Cen05++;
		}
		else if ((L1SingleTrack16bit == 1) && (L1Centrality510bit == 1))
                {
                        itertrack16Cen510++;
                }
                else if ((L1SingleTrack16bit == 1) && (L1Centrality1030bit == 1))
                {
                        itertrack16Cen1030++;
                }
                else if ((L1SingleTrack16bit == 1) && (L1Centrality3050bit == 1))
                {
                        itertrack16Cen3050++;
                }
                else if ((L1SingleTrack16bit == 1) && (L1Centrality5070bit == 1))
                {
                        itertrack16Cen5070++;
                }
                else if ((L1SingleTrack16bit == 1) && (L1Centrality70100bit == 1))
                {
                        itertrack16Cen70100++;
                }
		if ((L1SingleTrack20bit == 1) && (L1Centrality05bit == 1))
		{
			itertrack20Cen05++;
		}
		else if ((L1SingleTrack20bit == 1) && (L1Centrality510bit == 1))
                {
                        itertrack20Cen510++;
                }
                else if ((L1SingleTrack20bit == 1) && (L1Centrality1030bit == 1))
                {
                        itertrack20Cen1030++;
                }
                else if ((L1SingleTrack20bit == 1) && (L1Centrality3050bit == 1))
                {
                        itertrack20Cen3050++;
                }
                else if ((L1SingleTrack20bit == 1) && (L1Centrality5070bit == 1))
                {
                        itertrack20Cen5070++;
                }
                else if ((L1SingleTrack20bit == 1) && (L1Centrality70100bit == 1))
                {
                        itertrack20Cen70100++;
                }
	}
	cout << (double)itertrack12Cen05/(double)events << (double)itertrack12Cen510/(double)events << (double)itertrack12Cen1030/(double)events << (double)itertrack12Cen3050/(double)events
		<< (double)itertrack12Cen5070/(double)events << (double)itertrack12Cen70100/(double)events << ((double)itertrack12Cen05/(double)events + (double)itertrack12Cen510/(double)events
		+ (double)itertrack12Cen1030/(double)events + (double)itertrack12Cen3050/(double)events + (double)itertrack12Cen5070/(double)events + (double)itertrack12Cen70100/(double)events) << endl;

	cout << endl;
	cout << (double)itertrack16Cen05/(double)events << (double)itertrack16Cen510/(double)events << (double)itertrack16Cen1030/(double)events << (double)itertrack16Cen3050/(double)events
                << (double)itertrack16Cen5070/(double)events << (double)itertrack16Cen70100/(double)events << ((double)itertrack16Cen05/(double)events + (double)itertrack16Cen510/(double)events
                + (double)itertrack16Cen1030/(double)events + (double)itertrack16Cen3050/(double)events + (double)itertrack16Cen5070/(double)events + (double)itertrack16Cen70100/(double)events) << endl;

	cout << endl;
	cout << (double)itertrack20Cen05/(double)events << (double)itertrack20Cen510/(double)events << (double)itertrack20Cen1030/(double)events << (double)itertrack20Cen3050/(double)events
                << (double)itertrack20Cen5070/(double)events << (double)itertrack20Cen70100/(double)events << ((double)itertrack20Cen05/(double)events + (double)itertrack20Cen510/(double)events
                + (double)itertrack20Cen1030/(double)events + (double)itertrack20Cen3050/(double)events + (double)itertrack20Cen5070/(double)events + (double)itertrack20Cen70100/(double)events) << endl;
}

