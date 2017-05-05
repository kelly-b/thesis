#include "tracking.h"
#include <stdio.h>
#include "TDirectory.h"
#include "TLatex.h"



clusters_15215 *clu_tracking1;

void load_tree_objects(const char *run15215_processed)
{
    
    //Get file
    root_file = new TFile(run15215_processed,"READ");
    
    if(root_file){
        cout<<"* ~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout<<"* Open File..." <<endl;
        //   cout<<"* ~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    }
    else{
        cout<<"Open File: FAIL..."<<endl;
    }
    
    //Load all cluster trees from file
    clu_tracking1  = new clusters_15215((TTree*)root_file->Get("clusters_15215"));  //tracking.h
    
    //cout<<"* ~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    cout<<"* Get tree: CLUSTERS("<< clu_tracking1 << ")" <<endl;
    cout<<"* ~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    
    
    
}


void tracking (string file){
    
    
    load_tree_objects(file.c_str());
    
    size_t nEntries = clu_tracking1->fChain->GetEntries();
    
    std::cout << "Entries : " << nEntries << std::endl;
    
    TH1F *h_cluster_position_Tmm2Y = new TH1F ("cluster_position_Tmm2Y", "cluster_position_Tmm2Y", 800, -60, 60);
    TH1F *h_cluster_position_Tmm2Y1 = new TH1F ("cluster_position_Tmm2Y1", "cluster_position_Tmm2Y1", 800, -60, 60);
    TH1F *h_cluster_position_Tmm2Y2 = new TH1F ("cluster_position_Tmm2Y2", "cluster_position_Tmm2Y2", 800, -60, 60);

    TH1F *h_cluster_position_Tmm5Y = new TH1F ("cluster_position_Tmm5Y", "cluster_position_Tmm5Y", 800, -60, 60);
    TH1F *h_cluster_position_Tmm5Y1 = new TH1F ("cluster_position_Tmm5Y1", "cluster_position_Tmm5Y1", 800, -60, 60);
    TH1F *h_cluster_position_Tmm5Y2 = new TH1F ("cluster_position_Tmm5Y2", "cluster_position_Tmm5Y2", 800, -60, 60);

    TH1F *h_cluster_position_Tmm6Y = new TH1F ("cluster_position_Tmm6Y", "cluster_position_Tmm6Y", 800, -60, 60);
    TH1F *h_cluster_position_Tmm6Y1 = new TH1F ("cluster_position_Tmm6Y1", "cluster_position_Tmm6Y1", 800, -60, 60);
    TH1F *h_cluster_position_Tmm6Y2 = new TH1F ("cluster_position_Tmm6Y2", "cluster_position_Tmm6Y2", 800, -60, 60);
    
    TH1F *h_cluster_position_NTUA_MM3Y = new TH1F ("cluster_position_NTUA_MM3Y", "cluster_position_NTUA_MM3Y", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3Y1 = new TH1F ("cluster_position_NTUA_MM3Y1", "cluster_position_NTUA_MM3Y1", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3Y2 = new TH1F ("cluster_position_NTUA_MM3Y2", "cluster_position_NTUA_MM3Y2", 800, -60, 60);
    
    TH1F *h_cluster_position_NTUA_MM2Y = new TH1F ("cluster_position_NTUA_MM2Y", "cluster_position_NTUA_MM2Y", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2Y1 = new TH1F ("cluster_position_NTUA_MM2Y1", "cluster_position_NTUA_MM2Y1", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2Y2 = new TH1F ("cluster_position_NTUA_MM2Y2", "cluster_position_NTUA_MM2Y2", 800, -60, 60);

    
    TF1 *f1 = new TF1("f1","[0]*x+[1]",-500,1100);
    TF1 *f2 = new TF1("f2","[0]*x+[1]",-500,1100);
    
    TH1F *h_pillars_NTUA_MM3Y = new TH1F ("h_pillars_NTUA_MM3Y", "h_pillars_NTUA_MM3Y", 300, -100, 60);
    TH1F *h_pillars_NTUA_MM3Y1 = new TH1F ("h_pillars_NTUA_MM3Y1", "h_pillars_NTUA_MM3Y1", 400, -100, 60);
    TH1F *h_pillars_NTUA_MM3Y2 = new TH1F ("h_pillars_NTUA_MM3Y2", "h_pillars_NTUA_MM3Y2", 500, -100, 60);
    TH1F *h_pillars_NTUA_MM3Y3 = new TH1F ("h_pillars_NTUA_MM3Y3", "h_pillars_NTUA_MM3Y3", 600, -100, 60);
    TH1F *h_expected_NTUA_MM3Y = new TH1F ("h_expected_NTUA_MM3Y", "h_expected_NTUA_MM3Y", 300, -60, 60);
    TH1F *h_observed_NTUA_MM3Y = new TH1F ("h_observed_NTUA_MM3Y", "h_observed_NTUA_MM3Y", 300, -60, 60);
    TH1F *h_excluded_NTUA_MM3Y = new TH1F ("h_excluded_NTUA_MM3Y", "h_excluded_NTUA_MM3Y", 200, -2, 2);
    TH1F *h_excluded_NTUA_MM3Y1 = new TH1F ("h_excluded_NTUA_MM3Y1", "h_excluded_NTUA_MM3Y1", 200, -2, 2);
    TH1F *h_included_NTUA_MM3Y = new TH1F ("h_included_NTUA_MM3Y", "h_included_NTUA_MM3Y", 200, -2, 2);
    TH1F *h_included_NTUA_MM3Y1 = new TH1F ("h_included_NTUA_MM3Y1", "h_included_NTUA_MM3Y1", 200, -2, 2);

    TH1F *h_inefficiency_NTUA_MM3Y = new TH1F ("h_inefficiency_NTUA_MM3Y", "h_inefficiency_NTUA_MM3Y", 300, -60, 60);
    TH1F *h_inefficiency_NTUA_MM3Y1 = new TH1F ("h_inefficiency_NTUA_MM3Y1", "h_inefficiency_NTUA_MM3Y1", 300, -60, 60);
       

    
    //Loop over ENTRIES!
    for(size_t iEntry=0; iEntry < nEntries; iEntry++)
    {
        
        clu_tracking1->GetEntry(iEntry);
        cout<<"* ENTRY["<<iEntry<<"]"<< endl;
        
        float cl_pos_Tmm2 = 0;
        float cl_pos_Tmm5 = 0;
        float cl_pos_Tmm6 = 0;
        float cl_pos_MM3 = 0;
        float cl_pos_MM2 = 0;
        
        float single_cl_pos_Tmm6 = 29999;
        float single_cl_pos_MM3 = 19999;
        float single_cl_pos_MM2 = 9999;
                
        double Tmm2_z_pos = 3426.;
        double Tmm5_z_pos = 3458.;
        double Tmm6_z_pos = 0.;
        double MM3_z_pos = 25.;
        double MM2_z_pos = 541.;

		double Tmm2_z_pos_error = 0.;		
        double Tmm5_z_pos_error = 0.;
		double Tmm6_z_pos_error = 0.; 
		double MM3_z_pos_error = 0.;		
        double MM2_z_pos_error = 0.;   
		
		double Tmm2_y_pos_error = 0.;
		double Tmm5_y_pos_error = 0.;
		double Tmm6_y_pos_error = 0.;
		double MM3_y_pos_error = 0.;
		double MM2_y_pos_error = 0.;
		
		bool dyo = false;
		bool pente = false;
		bool eksi = false;
		bool MM3 = false;
		bool MM2 = false;
		
		bool eksi_nclu = false;
		bool MM3_nclu = false;
		bool MM2_nclu = false;
		
		int nclu_Tmm6 = 0;
		int nclu_NTUA_MM3 = 0;
		int nclu_NTUA_MM2 =0;
		
		double Tmm2_correction = 0. ;
		double Tmm5_correction = 0 ;
		double Tmm6_correction = 0. -2.229; 
		double MM3_correction = 0. -1.807 ;
		double MM2_correction = 0. -3.127   ;                              //allign to Tmm6
		
		double Tmm2_mean = 0;
		double Tmm5_mean = 0;
		double Tmm6_mean = 0;
		double MM3_mean = 0;
		double MM2_mean = 0;
		
		float cl_pos_Tmm2_new = 0;
        float cl_pos_Tmm5_new = 0;
        float cl_pos_Tmm6_new = 0;
        float cl_pos_MM3_new = 0;
        float cl_pos_MM2_new = 0;
		
		//Double_t y_pos[0] = 0;
		//Double_t z_pos[0] = 0;
		//Double_t y_pos_error[0] = 0;
		//Double_t z_pos_error[0] = 0;
		//Double_t y_pos[1] = 0;
		//Double_t z_pos[1] = 0;
		//Double_t y_pos_error[1] = 0;
		//Double_t z_pos_error[1] = 0;
		
		float ch_name = 0;
		ch_name = clu_tracking1->cl_chamber_name->size();
				
		
        for(int jEntry=0; jEntry< ch_name; jEntry++)
        {
			
			if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm2" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm2Y
					{
						cl_pos_Tmm2 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + Tmm2_correction;	
						dyo = true;
					}
					
			if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm5" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm5Y
					{
						cl_pos_Tmm5 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + Tmm5_correction;
						pente = true;
					}		
					
			if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm6" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm6Y
					{
						cl_pos_Tmm6 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + Tmm6_correction;
						eksi = true;
						
						if(eksi_nclu==false){	
							
							//cl_pos_Tmm6 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + Tmm6_correction;
							//eksi = true;						
					        
					        nclu_Tmm6=clu_tracking1->cl_nclu->at(jEntry);
                            eksi_nclu= true;
						}
						
						
						if(nclu_Tmm6==1 && clu_tracking1->cl_width->at(jEntry)>1){
							
							single_cl_pos_Tmm6 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + Tmm6_correction;								
						}					
					}
					
						
			if(clu_tracking1->cl_chamber_name->at(jEntry)=="NTUA_MM3" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm2Y
					{
						cl_pos_MM3 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + MM3_correction;	
						MM3 = true;
						
						if(MM3_nclu==false){	
							
							//cl_pos_MM3 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + MM3_correction;	
							//MM3 = true;						
					        
					        nclu_NTUA_MM3=clu_tracking1->cl_nclu->at(jEntry);
                            MM3_nclu= true;
						}						
						
						if(nclu_NTUA_MM3==1 && clu_tracking1->cl_width->at(jEntry)>1){
							
							single_cl_pos_MM3 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + MM3_correction;								
						}					
					}
					
			if(clu_tracking1->cl_chamber_name->at(jEntry)=="NTUA_MM2" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm2Y
					{
						cl_pos_MM2 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + MM2_correction;	
						MM2 = true;
						
						if(MM2_nclu==false){
							
							//cl_pos_MM2 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + MM2_correction;	
							//MM2 = true;							
					        
					        nclu_NTUA_MM2=clu_tracking1->cl_nclu->at(jEntry);
                            MM2_nclu= true;
						}
						
						
						if(nclu_NTUA_MM2==1 && clu_tracking1->cl_width->at(jEntry)>1){
							
							single_cl_pos_MM2 = clu_tracking1->cl_pos_cm_mm->at(jEntry) + MM2_correction;							
						}					
					}
					
			}  //jEntry	
			
			if(dyo==true)
			{
				h_cluster_position_Tmm2Y1->Fill(cl_pos_Tmm2);	
			}
			
			if(pente==true)
			{
				h_cluster_position_Tmm5Y1->Fill(cl_pos_Tmm5);
			}
			
			if(eksi==true)
			{
				h_cluster_position_Tmm6Y1->Fill(cl_pos_Tmm6);
				//h_cluster_position_Tmm6Y2->Fill(single_cl_pos_Tmm6);
				//Tmm6_mean=h_cluster_position_Tmm6Y2->GetMean();
				//cl_pos_Tmm6_new=single_cl_pos_Tmm6-Tmm6_mean;
				//h_cluster_position_Tmm6Y->Fill(cl_pos_Tmm6_new);
			}
			
			if(MM3==true)
			{
				h_cluster_position_NTUA_MM3Y1->Fill(cl_pos_MM3);	
			}
			
			if(MM2==true)
			{
				h_cluster_position_NTUA_MM2Y1->Fill(cl_pos_MM2);
				//h_cluster_position_NTUA_MM2Y2->Fill(single_cl_pos_MM2);
				//MM2_mean=h_cluster_position_NTUA_MM2Y2->GetMean();
				//cl_pos_MM2_new=single_cl_pos_MM2-MM2_mean;	
				//h_cluster_position_NTUA_MM2Y->Fill(cl_pos_MM2_new);
			}

			if(MM2==true && eksi==true )                                    //test chamber NTUA_MM3
			{
				h_cluster_position_NTUA_MM2Y2->Fill(single_cl_pos_MM2);
				MM2_mean=h_cluster_position_NTUA_MM2Y2->GetMean();
				cl_pos_MM2_new=single_cl_pos_MM2-MM2_mean;
				h_cluster_position_Tmm6Y2->Fill(single_cl_pos_Tmm6);
				Tmm6_mean=h_cluster_position_Tmm6Y2->GetMean();
				cl_pos_Tmm6_new=single_cl_pos_Tmm6-Tmm6_mean;
				h_cluster_position_NTUA_MM2Y->Fill(cl_pos_MM2_new);
				h_cluster_position_Tmm6Y->Fill(cl_pos_Tmm6_new);
				
				if(MM3==true)
				{
					h_cluster_position_NTUA_MM3Y2->Fill(single_cl_pos_MM3);	
					MM3_mean=h_cluster_position_NTUA_MM3Y2->GetMean();
					cl_pos_MM3_new=single_cl_pos_MM3-MM3_mean;
					h_cluster_position_NTUA_MM3Y->Fill(cl_pos_MM3_new);
				
				}
               
				//Double_t y_pos[0] = cl_pos_Tmm6; 
				//Double_t z_pos[0] = Tmm6_z_pos;
				//Double_t y_pos[1] = cl_pos_Tmm2;
				//Double_t z_pos[1] = Tmm2_z_pos;

				//Double_t y_pos_error[0] = Tmm6_y_pos&& clu_tracking1->cl_width->at(jEntry)>1_error;
				//Double_t z_pos_error[0] = Tmm6_z_pos_error;
				//Double_t y_pos_error[1] = Tmm2_y_pos_error; 
				//Double_t z_pos_error[1] = Tmm2_z_pos_error;
				
				const Int_t n = 2;
				Double_t y_pos[n] = {cl_pos_Tmm6_new, cl_pos_MM2_new}; 
				Double_t z_pos[n] = {Tmm6_z_pos, MM2_z_pos}; 
				Double_t y_pos_error[n] = {Tmm6_y_pos_error, MM2_y_pos_error};
				Double_t z_pos_error[n] = {Tmm6_z_pos_error, MM2_z_pos_error};


				TGraphErrors *data = new TGraphErrors(n, z_pos, y_pos, z_pos_error, y_pos_error);
				f1->SetParameter(0,0);
				f1->SetParameter(1,0);
				data->Fit("f1","Q");

				double extrapolated_MM3_position = f1->Eval(MM3_z_pos);
				
				if (MM3==false)                                                      //pillars
				{
					h_pillars_NTUA_MM3Y->Fill(extrapolated_MM3_position);
					h_pillars_NTUA_MM3Y1->Fill(extrapolated_MM3_position);
					h_pillars_NTUA_MM3Y2->Fill(extrapolated_MM3_position);
					h_pillars_NTUA_MM3Y3->Fill(extrapolated_MM3_position);
				}
				
				h_expected_NTUA_MM3Y->Fill(extrapolated_MM3_position);                    //expected
				
				if (MM3==true)                                                       //observed
				{
					h_observed_NTUA_MM3Y->Fill(extrapolated_MM3_position);      
				}
				
				if (MM3==true)                                                       //excluded & included
				{ 
					
						
					h_excluded_NTUA_MM3Y->Fill(extrapolated_MM3_position-cl_pos_MM3_new); 
					double NTUA_MM3_mean=h_excluded_NTUA_MM3Y->GetMean();
					h_excluded_NTUA_MM3Y1->Fill(extrapolated_MM3_position-cl_pos_MM3_new-NTUA_MM3_mean); 
				

					
					const Int_t n1 = 3;
					Double_t y_pos1[n1] = {cl_pos_Tmm6_new, cl_pos_MM3_new, cl_pos_MM2_new}; 
					Double_t z_pos1[n1] = {Tmm6_z_pos, MM3_z_pos, MM2_z_pos}; 
					Double_t y_pos_error1[n1] = {Tmm6_y_pos_error, MM3_y_pos_error, MM2_y_pos_error};
					Double_t z_pos_error1[n1] = {Tmm6_z_pos_error, MM3_z_pos_error, MM2_z_pos_error};


					TGraphErrors *data1 = new TGraphErrors(n1, z_pos1, y_pos1, z_pos_error1, y_pos_error1);
					f2->SetParameter(0,0);
					f2->SetParameter(1,0);
					data1->Fit("f2","Q");
									
				
				//TCanvas *c1 = new TCanvas("c1","Graph Draw Options", 200,10,600,400);
                             
				//data1->Draw("A*");

				    double extrapolated_MM3_position1 = f2->Eval(MM3_z_pos);
				    //double absolute1 = abs(extrapolated_Tmm2_position1-cl_pos_Tmm2_new);
				    
				    
				    h_included_NTUA_MM3Y->Fill(extrapolated_MM3_position1-cl_pos_MM3_new); 
				    double NTUA_MM3_mean1=h_included_NTUA_MM3Y->GetMean();
				    h_included_NTUA_MM3Y1->Fill(extrapolated_MM3_position1-cl_pos_MM3_new-NTUA_MM3_mean1); 
								    
				    
				    data1->Clear();
					data1->Delete();
				
					
				}		
				
				//h_inefficiency_Tmm2Y = (TH1F*)h_expected_Tmm2Y->Clone("h_inefficiency_Tmm2Y");
				//h_inefficiency_Tmm2Y->Divide(h_observed_Tmm2Y);
				
								
				data->Clear();
                data->Delete();		      
									
			} //pente+eksi
			
			
        
	}   //iEntry
	
	TLatex *ltx1 = new TLatex();	
    ltx1->SetTextColor(8);
	TLatex *ltx2 = new TLatex();
    ltx2->SetTextColor(2);
    TLatex *ltx11 = new TLatex();	
    ltx11->SetTextColor(kBlack);
	TLatex *ltx21 = new TLatex();
    ltx21->SetTextColor(kBlue);
    
    TF1 *f_gaus = new TF1("f_gaus", "gaus", -5, 5);                               //tails excluded                                       
    f_gaus->SetParameters(20, 0, 0.8);
    TF1 *f_gaus1 = new TF1("f_gaus1", "gaus", -0.5, 0.5);                             //core excluded                    
    f_gaus1->SetParameters(100, 0, 0.08);
     TF1 *f_gaus2 = new TF1("f_gaus2", "gaus", -5, 5);                            //tails included                       
    f_gaus2->SetParameters(50, 0, 0.3);
    TF1 *f_gaus3 = new TF1("f_gaus3", "gaus", -0.2, 0.2);                         //core included                        
    f_gaus3->SetParameters(100, 0, 0.03);
    TF1 *f_doublegaus5 = new TF1("f_doublegaus5", "f_gaus+f_gaus1", -5,5);
    TF1 *f_doublegaus6 = new TF1("f_doublegaus6", "f_gaus2+f_gaus3", -5,5);
    //h_excluded_Tmm2Y1->Fit("f_gaus","f_gaus1","f_doublegaus5");
    h_excluded_NTUA_MM3Y1->Fit("f_gaus");
    h_excluded_NTUA_MM3Y1->Fit("f_gaus1");
    f_gaus1->SetLineColor(kBlack);
    h_excluded_NTUA_MM3Y1->Fit("f_doublegaus5");
    f_doublegaus5->SetLineColor(kGreen);
    //h_included_Tmm2Y1->Fit("f_gaus2", "f_gaus3", "f_doublegaus6");
    //h_included_Tmm2Y1->Fit("f_gaus3");
    h_included_NTUA_MM3Y1->Fit("f_gaus2");
    h_included_NTUA_MM3Y1->Fit("f_gaus3");
    f_gaus3->SetLineColor(kBlack);
    h_included_NTUA_MM3Y1->Fit("f_doublegaus6");
    f_doublegaus6->SetLineColor(kGreen);
    
    TF1 *f_doublegaus3 = new TF1("f_doublegaus3", "gaus(0)+gaus(3)", -0.5, 0.5);                                                 //fit_Tmm2_Tmm5
    f_doublegaus3->SetParameter(0, 40);
    f_doublegaus3->SetParameter(1, 0);
    f_doublegaus3->SetParameter(2, 0.05);
    f_doublegaus3->SetParameter(3, 5);
    f_doublegaus3->SetParameter(4, 0.);
    f_doublegaus3->SetParameter(5, 0.1);
    f_doublegaus3->SetParLimits(0, 0, 10000);
    f_doublegaus3->SetParLimits(1, -0.1, 0.1);
    f_doublegaus3->SetParLimits(2, 0, 10000);
    f_doublegaus3->SetParLimits(3, 0, 10000);
    f_doublegaus3->SetParLimits(4, -0.5, 0.5);
    f_doublegaus3->SetParLimits(5, 0, 10000);
    TF1 *f_doublegaus4 = new TF1("f_doublegaus4", "gaus(0)+gaus(3)", -0.5, 0.5);                                                 //fit_Tmm2_Tmm5
    f_doublegaus4->SetParameter(0, 60);
    f_doublegaus4->SetParameter(1, 0.);
    f_doublegaus4->SetParameter(2, 0.04);
    f_doublegaus4->SetParameter(3, 5);
    f_doublegaus4->SetParameter(4, 0.);
    f_doublegaus4->SetParameter(5, 0.1);
    f_doublegaus4->SetParLimits(0, 0, 10000);
    f_doublegaus4->SetParLimits(1, -0.1, 0.1);
    f_doublegaus4->SetParLimits(2, 0, 1000);
    f_doublegaus4->SetParLimits(3, 0, 10000);
    f_doublegaus4->SetParLimits(4, -0.5, 0.5);
    f_doublegaus4->SetParLimits(5, 0, 1000);
    f_doublegaus4->SetLineColor(kGreen);
    
    h_excluded_NTUA_MM3Y->Fit("f_doublegaus3");
    h_included_NTUA_MM3Y->Fit("f_doublegaus4");
	
	TCanvas *Tmm2Y_cluster_position = new TCanvas("Tmm2Y_cluster_position","Tmm2Y_cluster_position",800,600);
    Tmm2Y_cluster_position->Divide(2,1);
    Tmm2Y_cluster_position->cd(1);
    h_cluster_position_Tmm2Y->Draw();
    Tmm2Y_cluster_position->cd(2);
    h_cluster_position_Tmm2Y1->Draw();
    
    TCanvas *Tmm5Y_cluster_position = new TCanvas("Tmm5Y_cluster_position","Tmm5Y_cluster_position",800,600);
    Tmm5Y_cluster_position->Divide(2,1);
    Tmm5Y_cluster_position->cd(1);
    h_cluster_position_Tmm5Y->Draw();
    Tmm5Y_cluster_position->cd(2);
    h_cluster_position_Tmm5Y1->Draw();
    
    TCanvas *Tmm6Y_cluster_position = new TCanvas("Tmm6Y_cluster_position","Tmm6Y_cluster_position",800,600);
    Tmm6Y_cluster_position->Divide(2,1);
    Tmm6Y_cluster_position->cd(1);
    h_cluster_position_Tmm6Y->Draw();
    Tmm6Y_cluster_position->cd(2);
    h_cluster_position_Tmm6Y1->Draw();
    
    TCanvas *NTUA_MM3Y_cluster_position = new TCanvas("NTUA_MM3Y_cluster_position","NTUA_MM3Y_cluster_position",800,600);
    NTUA_MM3Y_cluster_position->Divide(2,1);
    NTUA_MM3Y_cluster_position->cd(1);
    h_cluster_position_NTUA_MM3Y->Draw();
    NTUA_MM3Y_cluster_position->cd(2);
    h_cluster_position_NTUA_MM3Y1->Draw();
    
    TCanvas *NTUA_MM2Y_cluster_position = new TCanvas("NTUA_MM2Y_cluster_position","NTUA_MM2Y_cluster_position",800,600);
    NTUA_MM2Y_cluster_position->Divide(2,1);
    NTUA_MM2Y_cluster_position->cd(1);
    h_cluster_position_NTUA_MM2Y->Draw();
    NTUA_MM2Y_cluster_position->cd(2);
    h_cluster_position_NTUA_MM2Y1->Draw();
    
    TCanvas *cluster_positions = new TCanvas("cluster_positions","cluster_positions",800,600);
    cluster_positions->Divide(1,3);
    cluster_positions->cd(1);
    h_cluster_position_Tmm6Y1->Draw();
    cluster_positions->cd(2);    
    h_cluster_position_NTUA_MM3Y1->Draw();
    cluster_positions->cd(3);
    h_cluster_position_NTUA_MM2Y1->Draw();
    
    TCanvas *cluster_positions1 = new TCanvas("cluster_positions1","cluster_positions1",800,600);
    cluster_positions1->Divide(1,3);
    cluster_positions1->cd(1);
    h_cluster_position_Tmm6Y->Draw();
    cluster_positions1->cd(2);
    h_cluster_position_NTUA_MM3Y->Draw();
    cluster_positions1->cd(3);
    h_cluster_position_NTUA_MM2Y->Draw();
    
    TCanvas *pillars = new TCanvas("pillars","pillars",800,600);
    pillars->Divide(2,2);
    pillars->cd(1);
    h_pillars_NTUA_MM3Y->Draw();
    pillars->cd(2);
    h_pillars_NTUA_MM3Y1->Draw();
    pillars->cd(3);
    h_pillars_NTUA_MM3Y2->Draw();
    pillars->cd(4);
    h_pillars_NTUA_MM3Y3->Draw();
    
    TCanvas *extra = new TCanvas("extra","extra",800,600);
    gStyle->SetOptFit(1111);
    extra->Divide(2,2);
    extra->cd(1);
    h_pillars_NTUA_MM3Y2->Draw();
    extra->cd(2);
    h_expected_NTUA_MM3Y->Draw();      
    h_expected_NTUA_MM3Y->SetLineColor(kGreen+3);    
    ltx1->DrawLatex(20, 50, "expected");
    h_observed_NTUA_MM3Y->Draw("sames");
    h_observed_NTUA_MM3Y->SetLineColor(kRed);
    ltx2->DrawLatex(20, 20, "observed");
    extra->cd(3);
    //h_excluded_NTUA_MM3Y->SetAxisRange(0, 1200, "Y");
    h_included_NTUA_MM3Y->Draw();
    h_included_NTUA_MM3Y->SetLineColor(kBlack);
    //h_included_NTUA_MM3Y->SetAxisRange(0, 1200, "Y");
    h_excluded_NTUA_MM3Y->SetLineColor(kBlue);
    h_excluded_NTUA_MM3Y->Draw("sames");
    
    
    TCanvas *pillars_NTUA_MM3 = new TCanvas("pillars_NTUA_MM3","pillars_NTUA_MM3",800,600);
    h_pillars_NTUA_MM3Y2->Draw();
    
    TCanvas *expected_observed_NTUA_MM3 = new TCanvas("expected_observed_NTUA_MM3","expected_observed_NTUA_MM3",800,600);
	h_expected_NTUA_MM3Y->Draw();      
    h_expected_NTUA_MM3Y->SetLineColor(kGreen+3);    
    ltx1->DrawLatex(20, 50, "expected");
    h_observed_NTUA_MM3Y->Draw("sames");
    h_observed_NTUA_MM3Y->SetLineColor(kRed);
    ltx2->DrawLatex(20, 20, "observed"); 
    
    TCanvas *included_excluded_NTUA_MM3 = new TCanvas("included_excluded_NTUA_MM3","included_excluded_NTUA_MM3",800,600);
	h_included_NTUA_MM3Y->Draw();
    h_included_NTUA_MM3Y->SetLineColor(kBlack);
    ltx11->DrawLatex(1, 30, "included");
    h_excluded_NTUA_MM3Y->Draw("sames");
    h_excluded_NTUA_MM3Y->SetLineColor(kBlue);
    ltx21->DrawLatex(1, 10, "excluded"); 
       
    //TCanvas *extra1 = new TCanvas("extra1","extra1",800,600);
    //gStyle->SetOptFit(1111);
    //extra1->Divide(2,1);
    //extra1->cd(1);
    //h_excluded_NTUA_MM3Y1->Draw();
    //h_excluded_NTUA_MM3Y1->SetLineColor(kBlue);
    ////h_excluded_NTUA_MM3Y1->SetAxisRange(0, 1200, "Y");
    ////h_excluded_Tmm2Y1->Fit("f_doublegaus5");
    //f_gaus->Draw("sames");
    //f_gaus1->Draw("sames");
    //f_doublegaus5->Draw("sames");
    //extra1->cd(2);
    ////h_included_Tmm2Y1->SetLineColor(kBlack);
    //h_included_NTUA_MM3Y1->Draw();
    ////h_included_NTUA_MM3Y1->SetAxisRange(0, 400, "Y");
    ////h_included_Tmm2Y1->Fit("f_doublegaus6");
    //f_gaus2->Draw("sames");
    //f_gaus3->Draw("sames");
    //f_doublegaus6->Draw("sames");
    
    TCanvas *extra2 = new TCanvas("extra2","extra2",800,600);
    gStyle->SetOptFit(1111);
    extra2->cd(1);
    h_included_NTUA_MM3Y->SetLineColor(kBlack);
    h_included_NTUA_MM3Y->Draw();
    h_excluded_NTUA_MM3Y->Draw("sames");
    h_excluded_NTUA_MM3Y->SetLineColor(kBlue);
    //h_excluded_NTUA_MM3Y->SetAxisRange(0, 400, "Y");
    //h_included_NTUA_MM3Y->SetAxisRange(0, 400, "Y"); 
    
    
    
    double excluded_sigma = 0;
    double excluded_sigma1 = 0;
    double excluded_constant = 0;
    double excluded_constant1 = 0;
    double excluded_resolution = 0;
    double excluded_weighted = 0;
    double included_sigma = 0;
    double included_sigma1 = 0;
    double included_constant = 0;
    double included_constant1 = 0;
    double included_resolution = 0; 
    double included_weighted = 0;
    double sigma = 0;
    double weighted_sigma = 0;
    excluded_sigma = f_doublegaus3->GetParameter(2);
    excluded_sigma1 = f_doublegaus3->GetParameter(5);
    excluded_constant = f_doublegaus3->GetParameter(0);
    excluded_constant1 = f_doublegaus3->GetParameter(3);
    included_sigma = f_doublegaus4->GetParameter(2);
    included_sigma1 = f_doublegaus4->GetParameter(5);
    included_constant = f_doublegaus4->GetParameter(0);
    included_constant1 = f_doublegaus4->GetParameter(3);
    excluded_resolution = excluded_sigma / sqrt(2) ;
    included_resolution = included_sigma / sqrt(2) ; 
    excluded_weighted = (((excluded_constant)*TMath::Power(excluded_sigma,2))+((excluded_constant1)*TMath::Power(excluded_sigma1,2)))/((excluded_constant*excluded_sigma)+(excluded_constant1*excluded_sigma1)) ;
    included_weighted = (((included_constant)*TMath::Power(included_sigma,2))+((included_constant1)*TMath::Power(included_sigma1,2)))/((included_constant*included_sigma)+(included_constant1*included_sigma1)) ;
    sigma = sqrt(excluded_resolution*included_resolution);
    weighted_sigma = sqrt(excluded_weighted*included_weighted);
    std::cout << "sigma Tmm2: " << sigma << std::endl;	
    std::cout << "weighted_sigma Tmm2: " << weighted_sigma << std::endl;	
    
    TLatex *ltx3 = new TLatex();
    ltx3->DrawLatex(1, 15,Form("#sigma= %.1f#mum", sigma*1000));
    //TLatex *ltx4 = new TLatex();
    //ltx4->DrawLatex(1, 10,Form("weighted #sigma= %.1f#mum", weighted_sigma*1000));
    
    //TCanvas *extra3 = new TCanvas("extra3","extra3",800,600);
    //gStyle->SetOptFit(1111);
    //extra3->cd(1);
    //h_excluded_Tmm2Y->DrawCopy();
    //h_excluded_Tmm2Y->SetLineColor(kBlue);
    //h_excluded_Tmm2Y->SetAxisRange(0, 350, "Y");
    //h_included_Tmm2Y->SetLineColor(kBlack);
    //h_included_Tmm2Y->DrawCopy("sames");
    //h_included_Tmm2Y->SetAxisRange(0, 350, "Y"); 
   
    
	double entries_Tmm2 = h_cluster_position_Tmm2Y1->GetEntries();	
	double entries_Tmm21 = h_cluster_position_Tmm2Y->GetEntries();		
	std::cout << "Entries Tmm2: " << entries_Tmm2 << std::endl;			
	double entries_Tmm5 = h_cluster_position_Tmm5Y1->GetEntries();
	double entries_Tmm51 = h_cluster_position_Tmm5Y->GetEntries();
	std::cout << "Entries Tmm5: " << entries_Tmm5 << std::endl;			
	double entries_Tmm6 = h_cluster_position_Tmm6Y1->GetEntries();
	double entries_Tmm61 = h_cluster_position_Tmm6Y->GetEntries();
	std::cout << "Entries Tmm6: " << entries_Tmm6 << std::endl;
	double entries_NTUA_MM3 = h_cluster_position_NTUA_MM3Y1->GetEntries();	
	double entries_NTUA_MM31 = h_cluster_position_NTUA_MM3Y->GetEntries();		
	std::cout << "Entries NTUA_MM3: " << entries_NTUA_MM3 << std::endl;	
	double entries_NTUA_MM2 = h_cluster_position_NTUA_MM2Y1->GetEntries();	
	double entries_NTUA_MM21 = h_cluster_position_NTUA_MM2Y->GetEntries();		
	std::cout << "Entries NTUA_MM2: " << entries_NTUA_MM2 << std::endl;	
	double eff_Tmm2 = (entries_Tmm2)/(entries_Tmm6);
	double eff_Tmm21 = (entries_Tmm21)/(entries_Tmm61);	
	std::cout << "Efficiency Tmm2: " << eff_Tmm2 << std::endl;
	double eff_Tmm5 = (entries_Tmm5)/(entries_Tmm6);
	double eff_Tmm51 = (entries_Tmm51)/(entries_Tmm61);	
	std::cout << "Efficiency Tmm5: " << eff_Tmm5 << std::endl;
	double eff_Tmm6 = (entries_Tmm6)/(entries_Tmm6);
	double eff_Tmm61 = (entries_Tmm61)/(entries_Tmm61);
	std::cout << "Efficiency Tmm6: " << eff_Tmm6 << std::endl;
	double eff_NTUA_MM3 = (entries_NTUA_MM3)/(entries_Tmm6);
	double eff_NTUA_MM31 = (entries_NTUA_MM31)/(entries_Tmm61);
	std::cout << "Efficiency NTUA_MM3: " << eff_NTUA_MM3 << std::endl;
	double eff_NTUA_MM2 = (entries_NTUA_MM2)/(entries_Tmm6);
	double eff_NTUA_MM21 = (entries_NTUA_MM21)/(entries_Tmm61);
	std::cout << "Efficiency NTUA_MM2: " << eff_NTUA_MM2 << std::endl;
	
	const Int_t n2 = 3;
	Double_t x_axis[n2]={1,2,3}; 
	Double_t y_axis[n2] = {eff_NTUA_MM3, eff_NTUA_MM2, eff_Tmm6}; 	
	//for (int k=0; k<n2; k++)
	//{
	//	x_axis=k;
	//}	
	std::string names[n2] = {"NTUA_MM3", "NTUA_MM2", "Tmm6"};
	TGraph *eff1 = new TGraph(n2, x_axis, y_axis);
	TAxis *ax = eff1->GetHistogram()->GetXaxis();
    Double_t x1 = ax->GetBinLowEdge(1);
    Double_t x2 = ax->GetBinUpEdge(ax->GetNbins());
    eff1->GetHistogram()->GetXaxis()->Set(3,x1,x2);
    for(int l=0; l<n2; l++)
    {
		eff1->GetHistogram()->GetXaxis()->SetBinLabel(l+1,names[l].c_str());
    }
    
    const Int_t n3 = 3;
	Double_t x_axis1[n3]={1,2,3}; 
	Double_t y_axis1[n3] = {eff_NTUA_MM31, eff_NTUA_MM21, eff_Tmm61}; 	
	//for (int k=0; k<n2; k++)
	//{
	//	x_axis=k;
	//}	
	std::string names1[n3] = {"NTUA_MM3", "NTUA_MM2", "Tmm6"};
	TGraph *eff2 = new TGraph(n3, x_axis1, y_axis1);
	TAxis *ax1 = eff2->GetHistogram()->GetXaxis();
    Double_t x11 = ax1->GetBinLowEdge(1);
    Double_t x21 = ax1->GetBinUpEdge(ax1->GetNbins());
    eff2->GetHistogram()->GetXaxis()->Set(3,x11,x21);
    eff2->SetMarkerColor(kGreen+3);
    for(int m=0; m<n3; m++)
    {
		eff2->GetHistogram()->GetXaxis()->SetBinLabel(m+1,names1[m].c_str());
    }
	
	
    TCanvas *efficiency = new TCanvas("efficiency","efficiency",800,600);
    //efficiency->Divide(2,1);
    //efficiency->cd(1);
    //eff1->Draw("A[]*");
    //eff1->SetTitle("Efficiency");
    //eff1->SetLineWidth(3);
    //eff1->SetLineColor(kGreen+3);
    //efficiency->cd(2);
    eff2->Draw("A[]*");
    eff2->SetTitle("Efficiency");
    //eff2->SetLineWidth(3);
    //eff2->SetLineColor(kRed);
    
	TF1 *f_line = new TF1("f_line", "pol0", -100, 100);
	
	TCanvas *inefficiency = new TCanvas("inefficiency","inefficiency",800,600);
	//inefficiency->Divide(2,1);
    //inefficiency->cd(1);
	//h_inefficiency_Tmm2Y = (TH1F*)h_expected_Tmm2Y->Clone("h_inefficiency_Tmm2Y");
	//h_inefficiency_Tmm2Y->Divide(h_observed_Tmm2Y);
	//h_inefficiency_Tmm2Y->Draw();
	//inefficiency->cd(2);
	h_inefficiency_NTUA_MM3Y1->Divide(h_observed_NTUA_MM3Y, h_expected_NTUA_MM3Y, 1.,1.,"b");
	h_inefficiency_NTUA_MM3Y1->Draw();
	h_inefficiency_NTUA_MM3Y1->Fit("f_line");
	
	double eff0 = f_line->GetParameter(0);
	//TString d5;
    //d5 = "efficiency=";
    //d5 += eff0;
	//TLatex *ltx5 = new TLatex(0.2,0.7,d5.Data());
	//ltx5->DrawLatex(-20, 0.75, d5);
	//TLatex *ltx5 = new TLatex();
	//ltx5->DrawLatex(-25, 0.75,Form("efficiency= %.1f %", eff0*100));
	//ltx5->DrawLatex(-25, 0.75,"efficiency= 0.9931");
	
	TCanvas *track = new TCanvas("track","track",800,600);
	track->Divide(2,1);
	track->cd(1);
	f1->Draw();
	track->cd(2);
	f2->Draw();

}
