#include "tracking.h"
#include <stdio.h>
#include "TDirectory.h"
#include "TLatex.h"
#include "TNamed.h"
#include "TArrayI.h"
#include "TColor.h"



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

void total (string file){
    
    
    load_tree_objects(file.c_str());
    
    size_t nEntries = clu_tracking1->fChain->GetEntries();
    
    std::cout << "Entries : " << nEntries << std::endl;
    
    TH1F *h_beam_profile_Tmm2Y = new TH1F ("beam_profile_Tmm2Y", "beam_profile_Tmm2Y", 800, -60, 60);
    TH1F *h_cluster_width_Tmm2Y = new TH1F ("cluster_width_Tmm2Y", "cluster_width_Tmm2Y", 30, 0, 30);
    TH1F *h_cluster_charge_Tmm2Y = new TH1F ("cluster_charge_Tmm2Y", "cluster_charge_Tmm2Y", 500, 0, 1000);
    TH1F *h_number_of_clusters_Tmm2Y = new TH1F ("number_of_clusters_Tmm2Y", "number_of_clusters_Tmm2Y", 10, 0, 10);
    
    TH1F *h_cluster_position_Tmm2Y1 = new TH1F ("cluster_position_Tmm2Y1", "cluster_position_Tmm2Y1", 600, -60, 60);
    TH1F *h_cluster_position_Tmm2Y2 = new TH1F ("cluster_position_Tmm2Y2", "cluster_position_Tmm2Y2", 600, -60, 60);
    TH1F *h_cluster_position_Tmm2Y3 = new TH1F ("cluster_position_Tmm2Y3", "cluster_position_Tmm2Y3", 600, -60, 60);
    TH1F *h_cluster_position_Tmm2Y4 = new TH1F ("cluster_position_Tmm2Y4", "cluster_position_Tmm2Y4", 600, -60, 60);
    TH1F *h_cluster_position_Tmm2Y5 = new TH1F ("cluster_position_Tmm2Y5", "cluster_position_Tmm2Y5", 600, -60, 60);
    
    TH1F *h_cluster_width_Tmm2Y1 = new TH1F ("cluster_width_Tmm2Y1", "cluster_width_Tmm2Y1", 30, 0, 30);
    TH1F *h_cluster_width_Tmm2Y2 = new TH1F ("cluster_width_Tmm2Y2", "cluster_width_Tmm2Y2", 30, 0, 30);
    TH1F *h_cluster_width_Tmm2Y3 = new TH1F ("cluster_width_Tmm2Y3", "cluster_width_Tmm2Y3", 30, 0, 30);
    TH1F *h_cluster_width_Tmm2Y4 = new TH1F ("cluster_width_Tmm2Y4", "cluster_width_Tmm2Y4", 30, 0, 30);
     
    TH1F *h_cluster_charge_Tmm2Y1 = new TH1F ("cluster_charge_Tmm2Y1", "cluster_charge_Tmm2Y1", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm2Y2 = new TH1F ("cluster_charge_Tmm2Y2", "cluster_charge_Tmm2Y2", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm2Y3 = new TH1F ("cluster_charge_Tmm2Y3", "cluster_charge_Tmm2Y3", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm2Y4 = new TH1F ("cluster_charge_Tmm2Y4", "cluster_charge_Tmm2Y4", 500, 0, 1000); 
                                                                                                    //end of Tmm2Y histos
                                                                                                    
    TH1F *h_beam_profile_Tmm2X = new TH1F ("beam_profile_Tmm2X", "beam_profile_Tmm2X", 500, -60, 60);  
    TH1F *h_cluster_position_Tmm2X1 = new TH1F ("cluster_position_Tmm2X1", "cluster_position_Tmm2X1", 500, -60, 60);
    TH1F *h_cluster_position_Tmm2X2 = new TH1F ("cluster_position_Tmm2X2", "cluster_position_Tmm2X2", 500, -60, 60); 
    TH1F *h_cluster_position_Tmm2X3 = new TH1F ("cluster_position_Tmm2X3", "cluster_position_Tmm2X3", 500, -60, 60);   
    TH1F *h_cluster_width_Tmm2X = new TH1F ("cluster_width_Tmm2X", "cluster_width_Tmm2X", 15, 0, 15);
    TH1F *h_cluster_charge_Tmm2X = new TH1F ("cluster_charge_Tmm2X", "cluster_charge_Tmm2X", 300, 0, 6000);
    TH1F *h_number_of_clusters_Tmm2X = new TH1F ("number_of_clusters_Tmm2X", "number_of_clusters_Tmm2X", 10, 0, 10);    
																										//end of Tmm2X histos
    
    TH1F *h_beam_profile_Tmm5Y = new TH1F ("beam_profile_Tmm5Y", "beam_profile_Tmm5Y", 800, -60, 60);
    TH1F *h_cluster_width_Tmm5Y = new TH1F ("cluster_width_Tmm5Y", "cluster_width_Tmm5Y", 30, 0, 30);
    TH1F *h_cluster_charge_Tmm5Y = new TH1F ("cluster_charge_Tmm5Y", "cluster_charge_Tmm5Y", 500, 0, 1000);
    TH1F *h_number_of_clusters_Tmm5Y = new TH1F ("number_of_clusters_Tmm5Y", "number_of_clusters_Tmm5Y", 10, 0, 10);
    
    TH1F *h_cluster_position_Tmm5Y1 = new TH1F ("cluster_position_Tmm5Y1", "cluster_position_Tmm5Y1", 600, -60, 60);
    TH1F *h_cluster_position_Tmm5Y2 = new TH1F ("cluster_position_Tmm5Y2", "cluster_position_Tmm5Y2", 600, -60, 60);
    TH1F *h_cluster_position_Tmm5Y3 = new TH1F ("cluster_position_Tmm5Y3", "cluster_position_Tmm5Y3", 600, -60, 60);
    TH1F *h_cluster_position_Tmm5Y4 = new TH1F ("cluster_position_Tmm5Y4", "cluster_position_Tmm5Y4", 600, -60, 60);
    TH1F *h_cluster_position_Tmm5Y5 = new TH1F ("cluster_position_Tmm5Y5", "cluster_position_Tmm5Y5", 600, -60, 60);
    
    TH1F *h_cluster_width_Tmm5Y1 = new TH1F ("cluster_width_Tmm5Y1", "cluster_width_Tmm5Y1", 30, 0, 30);
    TH1F *h_cluster_width_Tmm5Y2 = new TH1F ("cluster_width_Tmm5Y2", "cluster_width_Tmm5Y2", 30, 0, 30);
    TH1F *h_cluster_width_Tmm5Y3 = new TH1F ("cluster_width_Tmm5Y3", "cluster_width_Tmm5Y3", 30, 0, 30);
    TH1F *h_cluster_width_Tmm5Y4 = new TH1F ("cluster_width_Tmm5Y4", "cluster_width_Tmm5Y4", 30, 0, 30);
     
    TH1F *h_cluster_charge_Tmm5Y1 = new TH1F ("cluster_charge_Tmm5Y1", "cluster_charge_Tmm5Y1", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm5Y2 = new TH1F ("cluster_charge_Tmm5Y2", "cluster_charge_Tmm5Y2", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm5Y3 = new TH1F ("cluster_charge_Tmm5Y3", "cluster_charge_Tmm5Y3", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm5Y4 = new TH1F ("cluster_charge_Tmm5Y4", "cluster_charge_Tmm5Y4", 500, 0, 1000);
																								//end of Tmm5Y histos
																								
	TH1F *h_beam_profile_Tmm5X = new TH1F ("beam_profile_Tmm5X", "beam_profile_Tmm5X", 500, -60, 60);  
    TH1F *h_cluster_position_Tmm5X1 = new TH1F ("cluster_position_Tmm5X1", "cluster_position_Tmm5X1", 500, -60, 60);
    TH1F *h_cluster_position_Tmm5X2 = new TH1F ("cluster_position_Tmm5X2", "cluster_position_Tmm5X2", 500, -60, 60); 
    TH1F *h_cluster_position_Tmm5X3 = new TH1F ("cluster_position_Tmm5X3", "cluster_position_Tmm5X3", 500, -60, 60);   
    TH1F *h_cluster_width_Tmm5X = new TH1F ("cluster_width_Tmm5X", "cluster_width_Tmm5X", 15, 0, 15);
    TH1F *h_cluster_charge_Tmm5X = new TH1F ("cluster_charge_Tmm5X", "cluster_charge_Tmm5X", 300, 0, 6000);
    TH1F *h_number_of_clusters_Tmm5X = new TH1F ("number_of_clusters_Tmm5X", "number_of_clusters_Tmm5X", 10, 0, 10);    
																										//end of Tmm5X histos																							
																								
	TH1F *h_beam_profile_Tmm6Y = new TH1F ("beam_profile_Tmm6Y", "beam_profile_Tmm6Y", 1000, -60, 60);
    TH1F *h_cluster_width_Tmm6Y = new TH1F ("cluster_width_Tmm6Y", "cluster_width_Tmm6Y", 30, 0, 30);
    TH1F *h_cluster_charge_Tmm6Y = new TH1F ("cluster_charge_Tmm6Y", "cluster_charge_Tmm6Y", 500, 0, 1000);
    TH1F *h_number_of_clusters_Tmm6Y = new TH1F ("number_of_clusters_Tmm6Y", "number_of_clusters_Tmm6Y", 10, 0, 10);
    
    TH1F *h_cluster_position_Tmm6Y1 = new TH1F ("cluster_position_Tmm6Y1", "cluster_position_Tmm6Y1", 500, -60, 60);
    TH1F *h_cluster_position_Tmm6Y2 = new TH1F ("cluster_position_Tmm6Y2", "cluster_position_Tmm6Y2", 500, -60, 60);
    TH1F *h_cluster_position_Tmm6Y3 = new TH1F ("cluster_position_Tmm6Y3", "cluster_position_Tmm6Y3", 500, -60, 60);
    TH1F *h_cluster_position_Tmm6Y4 = new TH1F ("cluster_position_Tmm6Y4", "cluster_position_Tmm6Y4", 500, -60, 60);
    TH1F *h_cluster_position_Tmm6Y5 = new TH1F ("cluster_position_Tmm6Y5", "cluster_position_Tmm6Y5", 500, -60, 60);

    TH1F *h_cluster_width_Tmm6Y1 = new TH1F ("cluster_width_Tmm6Y1", "cluster_width_Tmm6Y1", 30, 0, 30);
    TH1F *h_cluster_width_Tmm6Y2 = new TH1F ("cluster_width_Tmm6Y2", "cluster_width_Tmm6Y2", 30, 0, 30);
    TH1F *h_cluster_width_Tmm6Y3 = new TH1F ("cluster_width_Tmm6Y3", "cluster_width_Tmm6Y3", 30, 0, 30);
    TH1F *h_cluster_width_Tmm6Y4 = new TH1F ("cluster_width_Tmm6Y4", "cluster_width_Tmm6Y4", 30, 0, 30);
     
    TH1F *h_cluster_charge_Tmm6Y1 = new TH1F ("cluster_charge_Tmm6Y1", "cluster_charge_Tmm6Y1", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm6Y2 = new TH1F ("cluster_charge_Tmm6Y2", "cluster_charge_Tmm6Y2", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm6Y3 = new TH1F ("cluster_charge_Tmm6Y3", "cluster_charge_Tmm6Y3", 500, 0, 1000);
    TH1F *h_cluster_charge_Tmm6Y4 = new TH1F ("cluster_charge_Tmm6Y4", "cluster_charge_Tmm6Y4", 500, 0, 1000);
																								//end of Tmm6Y histos	
																								
	TH1F *h_beam_profile_Tmm6X = new TH1F ("beam_profile_Tmm6X", "beam_profile_Tmm6X", 500, -60, 60);  
    TH1F *h_cluster_position_Tmm6X1 = new TH1F ("cluster_position_Tmm6X1", "cluster_position_Tmm6X1", 500, -60, 60);
    TH1F *h_cluster_position_Tmm6X2 = new TH1F ("cluster_position_Tmm6X2", "cluster_position_Tmm6X2", 500, -60, 60); 
    TH1F *h_cluster_position_Tmm6X3 = new TH1F ("cluster_position_Tmm6X3", "cluster_position_Tmm6X3", 500, -60, 60);   
    TH1F *h_cluster_width_Tmm6X = new TH1F ("cluster_width_Tmm6X", "cluster_width_Tmm6X", 15, 0, 15);
    TH1F *h_cluster_charge_Tmm6X = new TH1F ("cluster_charge_Tmm6X", "cluster_charge_Tmm6X", 300, 0, 6000);
    TH1F *h_number_of_clusters_Tmm6X = new TH1F ("number_of_clusters_Tmm6X", "number_of_clusters_Tmm6X", 10, 0, 10);    
																										//end of Tmm6X histos
	
	TH1F *h_beam_profile_NTUA_MM2Y = new TH1F ("beam_profile_NTUA_MM2Y", "beam_profile_NTUA_MM2Y", 500, -60, 60);
    TH1F *h_cluster_width_NTUA_MM2Y = new TH1F ("cluster_width_NTUA_MM2Y", "cluster_width_NTUA_MM2Y", 30, 0, 30);
    TH1F *h_cluster_charge_NTUA_MM2Y = new TH1F ("cluster_charge_NTUA_MM2Y", "cluster_charge_NTUA_MM2Y", 500, 0, 1000);
    TH1F *h_number_of_clusters_NTUA_MM2Y = new TH1F ("number_of_clusters_NTUA_MM2Y", "number_of_clusters_NTUA_MM2Y", 10, 0, 10);
    
    TH1F *h_cluster_position_NTUA_MM2Y1 = new TH1F ("cluster_position_NTUA_MM2Y1", "cluster_position_NTUA_MM2Y1", 500, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2Y2 = new TH1F ("cluster_position_NTUA_MM2Y2", "cluster_position_NTUA_MM2Y2", 500, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2Y3 = new TH1F ("cluster_position_NTUA_MM2Y3", "cluster_position_NTUA_MM2Y3", 500, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2Y4 = new TH1F ("cluster_position_NTUA_MM2Y4", "cluster_position_NTUA_MM2Y4", 500, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2Y5 = new TH1F ("cluster_position_NTUA_MM2Y5", "cluster_position_NTUA_MM2Y5", 500, -60, 60);
    
    TH1F *h_cluster_width_NTUA_MM2Y1 = new TH1F ("cluster_width_NTUA_MM2Y1", "cluster_width_NTUA_MM2Y1", 30, 0, 30);
    TH1F *h_cluster_width_NTUA_MM2Y2 = new TH1F ("cluster_width_NTUA_MM2Y2", "cluster_width_NTUA_MM2Y2", 30, 0, 30);
    TH1F *h_cluster_width_NTUA_MM2Y3 = new TH1F ("cluster_width_NTUA_MM2Y3", "cluster_width_NTUA_MM2Y3", 30, 0, 30);
    TH1F *h_cluster_width_NTUA_MM2Y4 = new TH1F ("cluster_width_NTUA_MM2Y4", "cluster_width_NTUA_MM2Y4", 30, 0, 30);
     
    TH1F *h_cluster_charge_NTUA_MM2Y1 = new TH1F ("cluster_charge_NTUA_MM2Y1", "cluster_charge_NTUA_MM2Y1", 500, 0, 1000);
    TH1F *h_cluster_charge_NTUA_MM2Y2 = new TH1F ("cluster_charge_NTUA_MM2Y2", "cluster_charge_NTUA_MM2Y2", 500, 0, 1000);
    TH1F *h_cluster_charge_NTUA_MM2Y3 = new TH1F ("cluster_charge_NTUA_MM2Y3", "cluster_charge_NTUA_MM2Y3", 500, 0, 1000);
    TH1F *h_cluster_charge_NTUA_MM2Y4 = new TH1F ("cluster_charge_NTUA_MM2Y4", "cluster_charge_NTUA_MM2Y4", 500, 0, 1000); 
                                                                                                    //end of NTUA_MM2Y histos
                                                                                                    
    TH1F *h_beam_profile_NTUA_MM2X = new TH1F ("beam_profile_NTUA_MM2X", "beam_profile_NTUA_MM2X", 500, -60, 60);  
    TH1F *h_cluster_position_NTUA_MM2X1 = new TH1F ("cluster_position_NTUA_MM2X1", "cluster_position_NTUA_MM2X1", 500, -60, 60);
    TH1F *h_cluster_position_NTUA_MM2X2 = new TH1F ("cluster_position_NTUA_MM2X2", "cluster_position_NTUA_MM2X2", 500, -60, 60); 
    TH1F *h_cluster_position_NTUA_MM2X3 = new TH1F ("cluster_position_NTUA_MM2X3", "cluster_position_NTUA_MM2X3", 500, -60, 60);   
    TH1F *h_cluster_width_NTUA_MM2X = new TH1F ("cluster_width_NTUA_MM2X", "cluster_width_NTUA_MM2X", 15, 0, 15);
    TH1F *h_cluster_charge_NTUA_MM2X = new TH1F ("cluster_charge_NTUA_MM2X", "cluster_charge_NTUA_MM2X", 300, 0, 6000);
    TH1F *h_number_of_clusters_NTUA_MM2X = new TH1F ("number_of_clusters_NTUA_MM2X", "number_of_clusters_NTUA_MM2X", 10, 0, 10);    
																										//end of NTUA_MM2X histos
    																										
    TH1F *h_beam_profile_NTUA_MM3Y = new TH1F ("beam_profile_NTUA_MM3Y", "beam_profile_NTUA_MM3Y", 800, -60, 60);
    TH1F *h_cluster_width_NTUA_MM3Y = new TH1F ("cluster_width_NTUA_MM3Y", "cluster_width_NTUA_MM3Y", 30, 0, 30);
    TH1F *h_cluster_charge_NTUA_MM3Y = new TH1F ("cluster_charge_NTUA_MM3Y", "cluster_charge_NTUA_MM3Y", 500, 0, 1000);
    TH1F *h_number_of_clusters_NTUA_MM3Y = new TH1F ("number_of_clusters_NTUA_MM3Y", "number_of_clusters_NTUA_MM3Y", 10, 0, 10);
    
    TH1F *h_cluster_position_NTUA_MM3Y1 = new TH1F ("cluster_position_NTUA_MM3Y1", "cluster_position_NTUA_MM3Y1", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3Y2 = new TH1F ("cluster_position_NTUA_MM3Y2", "cluster_position_NTUA_MM3Y2", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3Y3 = new TH1F ("cluster_position_NTUA_MM3Y3", "cluster_position_NTUA_MM3Y3", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3Y4 = new TH1F ("cluster_position_NTUA_MM3Y4", "cluster_position_NTUA_MM3Y4", 800, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3Y5 = new TH1F ("cluster_position_NTUA_MM3Y5", "cluster_position_NTUA_MM3Y5", 800, -60, 60);
    
    TH1F *h_cluster_width_NTUA_MM3Y1 = new TH1F ("cluster_width_NTUA_MM3Y1", "cluster_width_NTUA_MM3Y1", 30, 0, 30);
    TH1F *h_cluster_width_NTUA_MM3Y2 = new TH1F ("cluster_width_NTUA_MM3Y2", "cluster_width_NTUA_MM3Y2", 30, 0, 30);
    TH1F *h_cluster_width_NTUA_MM3Y3 = new TH1F ("cluster_width_NTUA_MM3Y3", "cluster_width_NTUA_MM3Y3", 40, 0, 40);
    TH1F *h_cluster_width_NTUA_MM3Y4 = new TH1F ("cluster_width_NTUA_MM3Y4", "cluster_width_NTUA_MM3Y4", 30, 0, 30);
     
    TH1F *h_cluster_charge_NTUA_MM3Y1 = new TH1F ("cluster_charge_NTUA_MM3Y1", "cluster_charge_NTUA_MM3Y1", 500, 0, 1000);
    TH1F *h_cluster_charge_NTUA_MM3Y2 = new TH1F ("cluster_charge_NTUA_MM3Y2", "cluster_charge_NTUA_MM3Y2", 500, 0, 1000);
    TH1F *h_cluster_charge_NTUA_MM3Y3 = new TH1F ("cluster_charge_NTUA_MM3Y3", "cluster_charge_NTUA_MM3Y3", 500, 0, 1000);
    TH1F *h_cluster_charge_NTUA_MM3Y4 = new TH1F ("cluster_charge_NTUA_MM3Y4", "cluster_charge_NTUA_MM3Y4", 500, 0, 1000); 
                                                                                                    //end of NTUA_MM3Y histos
                                                                                                    
    TH1F *h_beam_profile_NTUA_MM3X = new TH1F ("beam_profile_NTUA_MM3X", "beam_profile_NTUA_MM3X", 500, -60, 60);  
    TH1F *h_cluster_position_NTUA_MM3X1 = new TH1F ("cluster_position_NTUA_MM3X1", "cluster_position_NTUA_MM3X1", 500, -60, 60);
    TH1F *h_cluster_position_NTUA_MM3X2 = new TH1F ("cluster_position_NTUA_MM3X2", "cluster_position_NTUA_MM3X2", 500, -60, 60); 
    TH1F *h_cluster_position_NTUA_MM3X3 = new TH1F ("cluster_position_NTUA_MM3X3", "cluster_position_NTUA_MM3X3", 500, -60, 60);   
    TH1F *h_cluster_width_NTUA_MM3X = new TH1F ("cluster_width_NTUA_MM3X", "cluster_width_NTUA_MM3X", 15, 0, 15);
    TH1F *h_cluster_charge_NTUA_MM3X = new TH1F ("cluster_charge_NTUA_MM3X", "cluster_charge_NTUA_MM3X", 300, 0, 6000);
    TH1F *h_number_of_clusters_NTUA_MM3X = new TH1F ("number_of_clusters_NTUA_MM3X", "number_of_clusters_NTUA_MM3X", 10, 0, 10);    
																										//end of NTUA_MM3X histos
    																																																																						
																								
	TH1F *h_cluster_position_subtraction_Tmm2Y_Tmm5Y = new TH1F ("h_cluster_position_subtraction_Tmm2Y_Tmm5Y", "h_cluster_position_subtraction_Tmm2Y_Tmm5Y", 360, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm2Y_Tmm6Y = new TH1F ("h_cluster_position_subtraction_Tmm2Y_Tmm6Y", "h_cluster_position_subtraction_Tmm2Y_Tmm6Y", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm5Y_Tmm6Y = new TH1F ("h_cluster_position_subtraction_Tmm5Y_Tmm6Y", "h_cluster_position_subtraction_Tmm5Y_Tmm6Y", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm2Y_Tmm5Y1 = new TH1F ("h_cluster_position_subtraction_Tmm2Y_Tmm5Y1", "h_cluster_position_subtraction_Tmm2Y_Tmm5Y1", 360, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm2Y_Tmm6Y1 = new TH1F ("h_cluster_position_subtraction_Tmm2Y_Tmm6Y1", "h_cluster_position_subtraction_Tmm2Y_Tmm6Y1", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm5Y_Tmm6Y1 = new TH1F ("h_cluster_position_subtraction_Tmm5Y_Tmm6Y1", "h_cluster_position_subtraction_Tmm5Y_Tmm6Y1", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y = new TH1F ("h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y", "h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y = new TH1F ("h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y", "h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y = new TH1F ("h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y", "h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y = new TH1F ("h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y", "h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y = new TH1F ("h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y", "h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y", 120, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y = new TH1F ("h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y", "h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y", 180, -2, 2);
    TH1F *h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y = new TH1F ("h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y", "h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y", 150, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1 = new TH1F ("h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1", "h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1", 2500, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1 = new TH1F ("h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1", "h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1", 2500, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1 = new TH1F ("h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1", "h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1 = new TH1F ("h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1", "h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1", 2500, -100, 100);
    TH1F *h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1 = new TH1F ("h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1", "h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1", 120, -2, 2);
    TH1F *h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1 = new TH1F ("h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1", "h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1", 180, -2, 2);
    TH1F *h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1 = new TH1F ("h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1", "h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1", 150, -2, 2);
    
    
    TH1F *h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y = new TH1F ("h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y", "h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y", 1500, -100, 100);
    TH1F *h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y = new TH1F ("h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y", "h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y", 2500, -3, 2);
    TH1F *h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y = new TH1F ("h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y", "h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y", 1500, -100, 100);
   
	
	TH2F *h_cluster_position_Tmm2XY = new TH2F("cluster_position_Tmm2XY","cluster_position_Tmm2XY", 100, -20, 20, 100, -20, 20);
	TH2F *h_cluster_position_Tmm2XY1 = new TH2F("cluster_position_Tmm2XY1","cluster_position_Tmm2XY1", 200, -20, 20, 200, -20, 20);
	TH2F *h_cluster_position_Tmm2XY2 = new TH2F("cluster_position_Tmm2XY2","cluster_position_Tmm2XY2", 200, -20, 20, 200, -20, 20);
	
	TH2F *h_cluster_position_Tmm5XY = new TH2F("cluster_position_Tmm5XY","cluster_position_Tmm5XY", 100, -20, 20, 100, -20, 20);
	TH2F *h_cluster_position_Tmm5XY1 = new TH2F("cluster_position_Tmm5XY1","cluster_position_Tmm5XY1", 500, -20, 20, 500, -20, 20);
	TH2F *h_cluster_position_Tmm5XY2 = new TH2F("cluster_position_Tmm5XY2","cluster_position_Tmm5XY2", 500, -20, 20, 500, -20, 20);
	
	TH2F *h_cluster_position_Tmm6XY = new TH2F("cluster_position_Tmm6XY","cluster_position_Tmm6XY", 100, -20, 20, 100, -20, 20);
	TH2F *h_cluster_position_Tmm6XY1 = new TH2F("cluster_position_Tmm6XY1","cluster_position_Tmm6XY1", 500, -20, 20, 500, -20, 20);
	TH2F *h_cluster_position_Tmm6XY2 = new TH2F("cluster_position_Tmm6XY2","cluster_position_Tmm6XY2", 500, -20, 20, 500, -20, 20);
	
	TH2F *h_cluster_position_NTUA_MM2XY = new TH2F("cluster_position_NTUA_MM2XY","cluster_position_NTUA_MM2XY", 3000, -10, 15, 3000, -10, 15);
	TH2F *h_cluster_position_NTUA_MM3XY = new TH2F("cluster_position_NTUA_MM3XY","cluster_position_NTUA_MM3XY", 500, -20, 15, 500, -20, 15);
	
      
     
    //Loop over ENTRIES!
    for(size_t iEntry=0; iEntry < nEntries; iEntry++)
    {
        
        clu_tracking1->GetEntry(iEntry);
        cout<<"* ENTRY["<<iEntry<<"]"<< endl;
        
        float ch_name = 0;        
        int nclu = 0;
        float cluster_width = 0;
        float cluster_charge = 0;
        float cl_pos = 29999;
        float cl_pos_single_cluster = 29999;
        float cl_pos_single_cluster1 = 29999;
        float cluster_width1 = 0;
        float cluster_charge1 = 0;
        float cl_pos1 = 28999;
        float cl_pos_single_cluster2 = 28999;
        float cl_pos_single_cluster3 = 28999;
        float cluster_width2 = 0;
        float cluster_charge2 = 0;
        float cl_pos2 = 27999;
        float cl_pos_single_cluster4 = 27999;
        float cl_pos_single_cluster5 = 27999;
        float cluster_width3 = 0;
        float cluster_charge3 = 0;
        float cl_pos3 = 26999;
        float cl_pos_single_cluster6 = 26999;
        float cl_pos_single_cluster7 = 26999;
        float cluster_width4 = 0;
        float cluster_charge4 = 0;
        float cl_pos4 = 25999;
        float cl_pos_single_cluster8 = 25999;
        float cl_pos_single_cluster9 = 25999;
        float cl_pos_single_cluster_NTUA_MM3X = 25999;
        ch_name = clu_tracking1->cl_chamber_name->size();
        nclu = clu_tracking1->cl_nclu->size();
        bool ena = false;
        bool dyo = false;
        bool tria = false;
        bool tessera = false;
        bool pente = false;
        bool eksi = false;
        bool efta = false;
        bool okto = false;
        bool ennia = false;
        bool deka = false;
        bool ena_Tmm2 = false;
        bool dyo_Tmm5 = false;
        bool tria_Tmm6 = false;
        bool tessera_Tmm2X = false;
        bool pente_Tmm5X = false;
        bool eksi_Tmm6X = false;
        bool efta_NTUA_MM2 = false;
        bool okto_NTUA_MM3 = false;
        bool ennia_NTUA_MM2X = false;
        bool deka_NTUA_MM3X = false;
        float cl_pos_Tmm2X = 0;
        float cl_pos_Tmm2X_single_cluster = 0;
        float cl_pos_Tmm2X_single_cluster1 = 0;
        float cluster_width_Tmm2X = 0;
        float cluster_charge_Tmm2X = 0;
        float cl_pos_Tmm5X = 0;
        float cl_pos_Tmm6X = 0;
        float cluster_width_Tmm5X = 0;
        float cluster_charge_Tmm5X = 0;
        float cluster_width_Tmm6X = 0;
        float cluster_charge_Tmm6X = 0;
        float cl_pos_Tmm5X_single_cluster = 0;
        float cl_pos_Tmm5X_single_cluster1 = 0;
        float cl_pos_Tmm6X_single_cluster = 0;
        float cl_pos_Tmm6X_single_cluster1 = 0;
        float cl_pos_NTUA_MM2X = 0;
        float cluster_width_NTUA_MM2X = 0;
        float cluster_charge_NTUA_MM2X = 0;
        float cl_pos_NTUA_MM3X = 0;
        float cluster_width_NTUA_MM3X = 0;
        float cluster_charge_NTUA_MM3X = 0;
                
        for(int jEntry=0; jEntry< ch_name; jEntry++)
        
               {   
				   //std::cout<<clu_tracking1->cl_chamber_name->at(jEntry)<<endl;
				   //std::cout<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
				   
				   if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm2" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm2Y
					{
						cl_pos = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
						//cluster_charge = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width = clu_tracking1->cl_width->at(jEntry) ;     
						////std::cout<<"position:"<<cl_pos<<endl;
						////std::cout<<"width:"<<cluster_width<<endl;
						////std::cout<<"charge:"<<cluster_charge<<endl;
						////std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
						h_beam_profile_Tmm2Y->Fill(cl_pos);
						//h_cluster_width_Tmm2Y->Fill(cluster_width);
						//h_cluster_charge_Tmm2Y->Fill(cluster_charge);
						//ena_Tmm2 = true;
						
						if(ena==false){							
					        
					        //std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
                            h_number_of_clusters_Tmm2Y->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            ena= true;
                            
                            //cl_pos = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
							cluster_charge = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width = clu_tracking1->cl_width->at(jEntry) ;     
							//std::cout<<"position:"<<cl_pos<<endl;
							//std::cout<<"width:"<<cluster_width<<endl;
							//std::cout<<"charge:"<<cluster_charge<<endl;
							//std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
							//h_beam_profile_Tmm2Y->Fill(cl_pos);
							h_cluster_width_Tmm2Y->Fill(cluster_width);
							h_cluster_charge_Tmm2Y->Fill(cluster_charge);
							ena_Tmm2 = true;
						
                            
                            if (clu_tracking1->cl_nclu->at(jEntry)>1){
								h_cluster_position_Tmm2Y1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm2Y1->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm2Y1->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)>2){
			                    h_cluster_position_Tmm2Y2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm2Y2->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm2Y2->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
								//cl_pos_single_cluster = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_Tmm2Y3->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));             
								h_cluster_width_Tmm2Y3->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm2Y3->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
								cl_pos_single_cluster1 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_Tmm2Y4->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm2Y4->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm2Y4->Fill(clu_tracking1->cl_charge->at(jEntry));
							} 
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1) {
								
								cl_pos_single_cluster = clu_tracking1->cl_pos_cm_mm->at(jEntry);
							}
						}                           
						
			        } //endif Tmm2Y 
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm2" && clu_tracking1->cl_readout_name->at(jEntry)=="X")       //Tmm2X
					{
						cl_pos_Tmm2X = clu_tracking1->cl_pos_cm_mm->at(jEntry); 
						//cluster_charge_Tmm2X = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width_Tmm2X = clu_tracking1->cl_width->at(jEntry) ;							
						h_beam_profile_Tmm2X->Fill(cl_pos_Tmm2X);
						//h_cluster_width_Tmm2X->Fill(cluster_width_Tmm2X);
						//h_cluster_charge_Tmm2X->Fill(cluster_charge_Tmm2X);
						tessera_Tmm2X = true;
						
						if (tessera==false){
							
							h_number_of_clusters_Tmm2X->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            tessera = true;
                            cluster_charge_Tmm2X = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width_Tmm2X = clu_tracking1->cl_width->at(jEntry) ;	
							h_cluster_width_Tmm2X->Fill(cluster_width_Tmm2X);
							h_cluster_charge_Tmm2X->Fill(cluster_charge_Tmm2X);
						
						}
							
						
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
									cl_pos_Tmm2X_single_cluster = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_Tmm2X1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
									cl_pos_Tmm2X_single_cluster1 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_Tmm2X2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}								
														
					}	//endif Tmm2X
						
						
						
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm5" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm5Y
					{
						cl_pos1 = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
						//cluster_charge1 = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width1 = clu_tracking1->cl_width->at(jEntry) ;     
						////std::cout<<"position:"<<cl_pos1<<endl;
						////std::cout<<"width:"<<cluster_width1<<endl;
						////std::cout<<"charge:"<<cluster_charge1<<endl;
						h_beam_profile_Tmm5Y->Fill(cl_pos1);
						//h_cluster_width_Tmm5Y->Fill(cluster_width1);
						//h_cluster_charge_Tmm5Y->Fill(cluster_charge1);
						//dyo_Tmm5 = true;

						if(dyo==false){						
					        
						    //std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;						    
                            h_number_of_clusters_Tmm5Y->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            dyo = true;
                            //cl_pos1 = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
							cluster_charge1 = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width1 = clu_tracking1->cl_width->at(jEntry) ;     
							//std::cout<<"position:"<<cl_pos1<<endl;
							//std::cout<<"width:"<<cluster_width1<<endl;
							//std::cout<<"charge:"<<cluster_charge1<<endl;
							//h_beam_profile_Tmm5Y->Fill(cl_pos1);
							h_cluster_width_Tmm5Y->Fill(cluster_width1);
							h_cluster_charge_Tmm5Y->Fill(cluster_charge1);
							dyo_Tmm5 = true;
						
                            
                            if (clu_tracking1->cl_nclu->at(jEntry)>1){
								h_cluster_position_Tmm5Y1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm5Y1->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm5Y1->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)>2){
			                    h_cluster_position_Tmm5Y2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm5Y2->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm5Y2->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
								//cl_pos_single_cluster2 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_Tmm5Y3->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));             
								h_cluster_width_Tmm5Y3->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm5Y3->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
								cl_pos_single_cluster3 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_Tmm5Y4->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm5Y4->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm5Y4->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1) {
								
								cl_pos_single_cluster2 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
							}
						}
							
					}//endif Tmm5Y
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm5" && clu_tracking1->cl_readout_name->at(jEntry)=="X")       //Tmm2X
					{
						cl_pos_Tmm5X = clu_tracking1->cl_pos_cm_mm->at(jEntry); 
						//cluster_charge_Tmm5X = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width_Tmm5X = clu_tracking1->cl_width->at(jEntry) ;							
						h_beam_profile_Tmm5X->Fill(cl_pos_Tmm5X);
						//h_cluster_width_Tmm5X->Fill(cluster_width_Tmm5X);
						//h_cluster_charge_Tmm5X->Fill(cluster_charge_Tmm5X);
						pente_Tmm5X = true;
						
						if (pente==false){
							
							h_number_of_clusters_Tmm5X->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            pente = true;
                            cluster_charge_Tmm5X = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width_Tmm5X = clu_tracking1->cl_width->at(jEntry) ;	
							h_cluster_width_Tmm5X->Fill(cluster_width_Tmm5X);
							h_cluster_charge_Tmm5X->Fill(cluster_charge_Tmm5X);
						}
							
						
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
									cl_pos_Tmm5X_single_cluster = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_Tmm5X1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
									cl_pos_Tmm5X_single_cluster1 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_Tmm5X2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}								
														
					}	//endif Tmm5X
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm6" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //Tmm6Y
					{
						cl_pos2 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
						//cluster_charge2 = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width2 = clu_tracking1->cl_width->at(jEntry) ;     
						////std::cout<<"position:"<<cl_pos2<<endl;
						////std::cout<<"width:"<<cluster_width2<<endl;
						////std::cout<<"charge:"<<cluster_charge2<<endl;
						h_beam_profile_Tmm6Y->Fill(cl_pos2);
						//h_cluster_width_Tmm6Y->Fill(cluster_width2);
						//h_cluster_charge_Tmm6Y->Fill(cluster_charge2);
						//tria_Tmm6 = true;
						
						if(tria==false){						
					        
						    //std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;						    
                            h_number_of_clusters_Tmm6Y->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            tria = true;
						
						
						
							//cl_pos2 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
							cluster_charge2 = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width2 = clu_tracking1->cl_width->at(jEntry) ;     
							//std::cout<<"position:"<<cl_pos2<<endl;
							//std::cout<<"width:"<<cluster_width2<<endl;
							//std::cout<<"charge:"<<cluster_charge2<<endl;
							//h_beam_profile_Tmm6Y->Fill(cl_pos2);
							h_cluster_width_Tmm6Y->Fill(cluster_width2);
							h_cluster_charge_Tmm6Y->Fill(cluster_charge2);
							tria_Tmm6 = true;
					
                            
                            if (clu_tracking1->cl_nclu->at(jEntry)>1){
								h_cluster_position_Tmm6Y1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm6Y1->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm6Y1->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)>2){
			                    h_cluster_position_Tmm6Y2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm6Y2->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm6Y2->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
								//cl_pos_single_cluster4 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_Tmm6Y3->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));             
								h_cluster_width_Tmm6Y3->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm6Y3->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
								cl_pos_single_cluster5 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_Tmm6Y4->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_Tmm6Y4->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_Tmm6Y4->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1) {
								
								cl_pos_single_cluster4 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
							}
						}
							
                     }//endif Tmm6Y
                     
                     if(clu_tracking1->cl_chamber_name->at(jEntry)=="Tmm6" && clu_tracking1->cl_readout_name->at(jEntry)=="X")       //Tmm2X
					{
						cl_pos_Tmm6X = clu_tracking1->cl_pos_cm_mm->at(jEntry); 
						//cluster_charge_Tmm6X = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width_Tmm6X = clu_tracking1->cl_width->at(jEntry) ;							
						h_beam_profile_Tmm6X->Fill(cl_pos_Tmm6X);
						//h_cluster_width_Tmm6X->Fill(cluster_width_Tmm6X);
						//h_cluster_charge_Tmm6X->Fill(cluster_charge_Tmm6X);
						eksi_Tmm6X = true;
						
						if (eksi==false){
							
							h_number_of_clusters_Tmm6X->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            eksi = true;
                            cluster_charge_Tmm6X = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width_Tmm6X = clu_tracking1->cl_width->at(jEntry) ;	
							h_cluster_width_Tmm6X->Fill(cluster_width_Tmm6X);
							h_cluster_charge_Tmm6X->Fill(cluster_charge_Tmm6X);
						}
							
						
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
									cl_pos_Tmm6X_single_cluster = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_Tmm6X1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
									cl_pos_Tmm6X_single_cluster1 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_Tmm6X2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}								
														
					}	//endif Tmm6X
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="NTUA_MM2" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //NTUA_MM2Y
					{
						cl_pos3 = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
						//cluster_charge3 = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width3 = clu_tracking1->cl_width->at(jEntry) ;     
						////std::cout<<"position:"<<cl_pos3<<endl;
						////std::cout<<"width:"<<cluster_width3<<endl;
						////std::cout<<"charge:"<<cluster_charge3<<endl;
						////std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
						h_beam_profile_NTUA_MM2Y->Fill(cl_pos3);
						//h_cluster_width_NTUA_MM2Y->Fill(cluster_width3);
						//h_cluster_charge_NTUA_MM2Y->Fill(cluster_charge3);
						//efta_NTUA_MM2 = true;
						
						if(efta==false){							
					        
					        //std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
                            h_number_of_clusters_NTUA_MM2Y->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            efta= true;
                            
                            //cl_pos3 = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
							cluster_charge3 = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width3 = clu_tracking1->cl_width->at(jEntry) ;     
							//std::cout<<"position:"<<cl_pos3<<endl;
							//std::cout<<"width:"<<cluster_width3<<endl;
							//std::cout<<"charge:"<<cluster_charge3<<endl;
							//std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
							//h_beam_profile_NTUA_MM2Y->Fill(cl_pos3);
							h_cluster_width_NTUA_MM2Y->Fill(cluster_width3);
							h_cluster_charge_NTUA_MM2Y->Fill(cluster_charge3);
							efta_NTUA_MM2 = true;
                            
						
                            
                            if (clu_tracking1->cl_nclu->at(jEntry)>1){
								h_cluster_position_NTUA_MM2Y1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_NTUA_MM2Y1->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM2Y1->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)>2){
			                    h_cluster_position_NTUA_MM2Y2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_NTUA_MM2Y2->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM2Y2->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
								//cl_pos_single_cluster6 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_NTUA_MM2Y3->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));             
								h_cluster_width_NTUA_MM2Y3->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM2Y3->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
								cl_pos_single_cluster7 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_NTUA_MM2Y4->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_NTUA_MM2Y4->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM2Y4->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1) {
								
								cl_pos_single_cluster6 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
							}
						}                            
						
			        } //endif NTUA_MM2Y 
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="NTUA_MM2" && clu_tracking1->cl_readout_name->at(jEntry)=="X")       //NTUA_MM2X
					{
						cl_pos_NTUA_MM2X = clu_tracking1->cl_pos_cm_mm->at(jEntry); 
						//cluster_charge_NTUA_MM2X = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width_NTUA_MM2X = clu_tracking1->cl_width->at(jEntry) ;							
						h_beam_profile_NTUA_MM2X->Fill(cl_pos_NTUA_MM2X);
						//h_cluster_width_NTUA_MM2X->Fill(cluster_width_NTUA_MM2X);
						//h_cluster_charge_NTUA_MM2X->Fill(cluster_charge_NTUA_MM2X);
						ennia_NTUA_MM2X = true;
						
						if (ennia==false){
							
							h_number_of_clusters_NTUA_MM2X->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            ennia = true;
                            cluster_charge_NTUA_MM2X = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width_NTUA_MM2X = clu_tracking1->cl_width->at(jEntry) ;	
							h_cluster_width_NTUA_MM2X->Fill(cluster_width_NTUA_MM2X);
							h_cluster_charge_NTUA_MM2X->Fill(cluster_charge_NTUA_MM2X);
						}
							
						
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){  
									h_cluster_position_NTUA_MM2X1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){
									h_cluster_position_NTUA_MM2X2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}								
														
					}	//endif NTUA_MM2X
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="NTUA_MM3" && clu_tracking1->cl_readout_name->at(jEntry)=="Y")       //NTUA_MM3Y
					{
						cl_pos4 = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
						//cluster_charge4 = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width4 = clu_tracking1->cl_width->at(jEntry) ;     
						////std::cout<<"position:"<<cl_pos4<<endl;
						////std::cout<<"width:"<<cluster_width4<<endl;
						////std::cout<<"charge:"<<cluster_charge4<<endl;
						////std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
						h_beam_profile_NTUA_MM3Y->Fill(cl_pos4);
						//h_cluster_width_NTUA_MM3Y->Fill(cluster_width4);
						//h_cluster_charge_NTUA_MM3Y->Fill(cluster_charge4);
						//okto_NTUA_MM3 = true;
						
						if(okto==false){							
					        
					        //std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
                            h_number_of_clusters_NTUA_MM3Y->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            okto= true;
                            //cl_pos4 = clu_tracking1->cl_pos_cm_mm->at(jEntry);  
							cluster_charge4 = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width4 = clu_tracking1->cl_width->at(jEntry) ;     
							//std::cout<<"position:"<<cl_pos4<<endl;
							//std::cout<<"width:"<<cluster_width4<<endl;
							//std::cout<<"charge:"<<cluster_charge4<<endl;
							//std::cout<<"nclu:"<<clu_tracking1->cl_nclu->at(jEntry)<<endl;
							//h_beam_profile_NTUA_MM3Y->Fill(cl_pos4);
							h_cluster_width_NTUA_MM3Y->Fill(cluster_width4);
							h_cluster_charge_NTUA_MM3Y->Fill(cluster_charge4);
							okto_NTUA_MM3 = true;
						
                            
                            if (clu_tracking1->cl_nclu->at(jEntry)>1){
								h_cluster_position_NTUA_MM3Y1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_NTUA_MM3Y1->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM3Y1->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)>2){
			                    h_cluster_position_NTUA_MM3Y2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_NTUA_MM3Y2->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM3Y2->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){              //single cluster
								//cl_pos_single_cluster8 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_NTUA_MM3Y3->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));             
								h_cluster_width_NTUA_MM3Y3->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM3Y3->Fill(clu_tracking1->cl_charge->at(jEntry));
							}
						 
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){             //single cluster
								cl_pos_single_cluster9 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
								h_cluster_position_NTUA_MM3Y4->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								h_cluster_width_NTUA_MM3Y4->Fill(clu_tracking1->cl_width->at(jEntry));
								h_cluster_charge_NTUA_MM3Y4->Fill(clu_tracking1->cl_charge->at(jEntry));
							}  
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1) {
								
								cl_pos_single_cluster8 = clu_tracking1->cl_pos_cm_mm->at(jEntry);
							}
						}                          
						
			        } //endif NTUA_MM3Y 
					
					if(clu_tracking1->cl_chamber_name->at(jEntry)=="NTUA_MM3" && clu_tracking1->cl_readout_name->at(jEntry)=="X")       //NTUA_MM3X
					{
						cl_pos_NTUA_MM3X = clu_tracking1->cl_pos_cm_mm->at(jEntry); 
						//cluster_charge_NTUA_MM3X = clu_tracking1->cl_charge->at(jEntry) ; 
					    //cluster_width_NTUA_MM3X = clu_tracking1->cl_width->at(jEntry) ;							
						h_beam_profile_NTUA_MM3X->Fill(cl_pos_NTUA_MM3X);
						//h_cluster_width_NTUA_MM3X->Fill(cluster_width_NTUA_MM3X);
						//h_cluster_charge_NTUA_MM3X->Fill(cluster_charge_NTUA_MM3X);
						deka_NTUA_MM3X = true;
						
						if (deka==false){
							
							h_number_of_clusters_NTUA_MM3X->Fill(clu_tracking1->cl_nclu->at(jEntry));
                            deka = true;
                            cluster_charge_NTUA_MM3X = clu_tracking1->cl_charge->at(jEntry) ; 
							cluster_width_NTUA_MM3X = clu_tracking1->cl_width->at(jEntry) ;	
							h_cluster_width_NTUA_MM3X->Fill(cluster_width_NTUA_MM3X);
							h_cluster_charge_NTUA_MM3X->Fill(cluster_charge_NTUA_MM3X);
						}
							
						
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>1){ 
									cl_pos_single_cluster_NTUA_MM3X = clu_tracking1->cl_pos_cm_mm->at(jEntry);
									h_cluster_position_NTUA_MM3X1->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}
							
							if (clu_tracking1->cl_nclu->at(jEntry)==1 && clu_tracking1->cl_width->at(jEntry)>2){
									h_cluster_position_NTUA_MM3X2->Fill(clu_tracking1->cl_pos_cm_mm->at(jEntry));
								}								
														
					}	//endif NTUA_MM3X
										
	            } //jEntry
	            
	            if(ena_Tmm2==true){
					h_cluster_position_Tmm2Y5->Fill(cl_pos);
				}
				
				if(dyo_Tmm5==true){
					h_cluster_position_Tmm5Y5->Fill(cl_pos1);
				}
					
				if(tria_Tmm6==true){
					h_cluster_position_Tmm6Y5->Fill(cl_pos2);	
				}
				
				if(tessera_Tmm2X==true){
					h_cluster_position_Tmm2X3->Fill(cl_pos_Tmm2X);
				}
				
				if(pente_Tmm5X==true){
					h_cluster_position_Tmm5X3->Fill(cl_pos_Tmm5X);
				}
				
				if(eksi_Tmm6X==true){
					h_cluster_position_Tmm6X3->Fill(cl_pos_Tmm6X);
				}
				
				if(efta_NTUA_MM2==true){
					h_cluster_position_NTUA_MM2Y5->Fill(cl_pos3);
				}
				
				if(okto_NTUA_MM3==true){
					h_cluster_position_NTUA_MM3Y5->Fill(cl_pos4);
				}
				
				if(ennia_NTUA_MM2X==true){
					h_cluster_position_NTUA_MM2X3->Fill(cl_pos_NTUA_MM2X);
				}
				
				if(deka_NTUA_MM3X==true){
					h_cluster_position_NTUA_MM3X3->Fill(cl_pos_NTUA_MM3X);
				}
	            
	            if(ena_Tmm2==true && tessera_Tmm2X==true){                                                                       //Tmm2XY
					h_cluster_position_Tmm2XY->Fill(cl_pos_Tmm2X, cl_pos);
				}
				
				if(dyo_Tmm5==true && pente_Tmm5X==true){                                                                       //Tmm2XY
					h_cluster_position_Tmm5XY->Fill(cl_pos_Tmm5X, cl_pos1);
				}
				
				if(tria_Tmm6==true && eksi_Tmm6X==true){                                                                       //Tmm2XY
					h_cluster_position_Tmm6XY->Fill(cl_pos_Tmm6X, cl_pos2);
				}
				
				if(efta_NTUA_MM2==true && ennia_NTUA_MM2X==true){                                                                       //Tmm2XY
					h_cluster_position_NTUA_MM2XY->Fill(cl_pos_NTUA_MM2X, cl_pos3);
				}	
				
				if(okto_NTUA_MM3==true && deka_NTUA_MM3X==true){                                                                       //Tmm2XY
					h_cluster_position_NTUA_MM3XY->Fill(cl_pos_NTUA_MM3X, cl_pos4);
				}	
	            
	            if (ena_Tmm2==true && dyo_Tmm5==true){
					h_cluster_position_subtraction_Tmm2Y_Tmm5Y->Fill(cl_pos_single_cluster1-cl_pos_single_cluster3);
					//double mean1 = 0;
					double mean1 = h_cluster_position_subtraction_Tmm2Y_Tmm5Y->GetMean();
					h_cluster_position_subtraction_Tmm2Y_Tmm5Y1->Fill(cl_pos_single_cluster1-cl_pos_single_cluster3-mean1);
					//h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y->Fill(cl_pos_single_cluster-cl_pos_single_cluster2);
				}
				
				if (ena_Tmm2==true && tria_Tmm6==true){
					h_cluster_position_subtraction_Tmm2Y_Tmm6Y->Fill(cl_pos_single_cluster-cl_pos_single_cluster4);
					//double mean2 = 0;
					double mean2 = h_cluster_position_subtraction_Tmm2Y_Tmm6Y->GetMean();
					h_cluster_position_subtraction_Tmm2Y_Tmm6Y1->Fill(cl_pos_single_cluster-cl_pos_single_cluster4-mean2);
					//h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y->Fill(cl_pos_single_cluster-cl_pos_single_cluster4);

				}
				
				if (dyo_Tmm5==true && tria_Tmm6==true){
					h_cluster_position_subtraction_Tmm5Y_Tmm6Y->Fill(cl_pos1-cl_pos2);
					//double mean3 = 0;
					double mean3 = h_cluster_position_subtraction_Tmm5Y_Tmm6Y->GetMean();
					h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->Fill(cl_pos1-cl_pos2-mean3);
					h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y->Fill(cl_pos_single_cluster2-cl_pos_single_cluster4);

				}
				
				if (ena_Tmm2==true && efta_NTUA_MM2==true){
					h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y->Fill(cl_pos-cl_pos3);
					//double mean4 = 0;
					double mean4 = h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y->GetMean();
					h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1->Fill(cl_pos-cl_pos3-mean4);
				}
				
				if (ena_Tmm2==true && okto_NTUA_MM3==true){
					h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y->Fill(cl_pos-cl_pos4);
					//double mean5 = 0;
					double mean5 = h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y->GetMean();
					h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1->Fill(cl_pos-cl_pos4-mean5);
				}
				
				if (dyo_Tmm5==true && efta_NTUA_MM2==true){
					h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y->Fill(cl_pos1-cl_pos3);
					//double mean6 = 0;
					double mean6 = h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y->GetMean();
					h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1->Fill(cl_pos1-cl_pos3-mean6);

				}
				
				if (dyo_Tmm5==true && okto_NTUA_MM3==true){
					h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y->Fill(cl_pos1-cl_pos4);
					//double mean7 = 0;
					double mean7 = h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y->GetMean();
					h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1->Fill(cl_pos1-cl_pos4-mean7);

				}
				
				if (tria_Tmm6==true && efta_NTUA_MM2==true){
					h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y->Fill(cl_pos_single_cluster5-cl_pos_single_cluster7);
					//double mean8 = 0;
					double mean8 = h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y->GetMean();
					h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1->Fill(cl_pos_single_cluster5-cl_pos_single_cluster7-mean8);

				}
				
				if (tria_Tmm6==true && okto_NTUA_MM3==true){
					h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y->Fill(cl_pos_single_cluster5-cl_pos_single_cluster9);
					//double mean9 = 0;
					double mean9 = h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y->GetMean();
					h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1->Fill(cl_pos_single_cluster5-cl_pos_single_cluster9-mean9);

				}
				
				if (efta_NTUA_MM2==true && okto_NTUA_MM3==true){
					h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y->Fill(cl_pos_single_cluster7-cl_pos_single_cluster9);
					//double mean10 = 0;
					double mean10 = h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y->GetMean();
					h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1->Fill(cl_pos_single_cluster7-cl_pos_single_cluster9-mean10);

				}
	}  //iEntry
    
    //TF1 *f_gaus = new TF1("f_gaus", "gaus", -30, 30);                                                 //fit_Tmm2
    //f_gaus->SetParameters(100, h_beam_profile_Tmm2Y->GetMean(), h_beam_profile_Tmm2Y->GetRMS());
    //TF1 *f_landau = new TF1("f_landau", "landau", 0, 4000);                                            //fit_Tmm2
    //f_landau->SetParameters(h_cluster_charge_Tmm2Y->GetMean(), h_cluster_charge_Tmm2Y->GetRMS());
    //TF1 *f_gaus1 = new TF1("f_gaus1", "gaus", -30, 30);                                               //fit_Tmm5
    //f_gaus1->SetParameters(100, h_beam_profile_Tmm5Y->GetMean(), h_beam_profile_Tmm5Y->GetRMS());
    //TF1 *f_landau1 = new TF1("f_landau1", "landau", 0, 4000);                                            //fit_Tmm5
    //f_landau1->SetParameters(h_cluster_charge_Tmm5Y->GetMean(), h_cluster_charge_Tmm5Y->GetRMS());
    //TF1 *f_gaus2 = new TF1("f_gaus2", "gaus", -30, 30);                                               //fit_Tmm6
    //f_gaus2->SetParameters(100, h_beam_profile_Tmm6Y->GetMean(), h_beam_profile_Tmm6Y->GetRMS());
    //TF1 *f_landau2 = new TF1("f_landau2", "landau", 0, 4000);                                            //fit_Tmm6
    //f_landau2->SetParameters(h_cluster_charge_Tmm6Y->GetMean(), h_cluster_charge_Tmm6Y->GetRMS());
    TF1 *f_doublegaus = new TF1("f_doublegaus", "gaus(0)+gaus(3)", -0.5, 0.5);                                                 //fit_Tmm2_Tmm5
    f_doublegaus->SetParameter(0, 240);
    f_doublegaus->SetParameter(1, 0);
    f_doublegaus->SetParameter(2, 0.05);
    f_doublegaus->SetParameter(3, 20);
    f_doublegaus->SetParameter(4, 0);
    f_doublegaus->SetParameter(5, 0.4);
    f_doublegaus->SetParLimits(0, 0, 1000);
    f_doublegaus->SetParLimits(1, -0.15, 0.15);
    f_doublegaus->SetParLimits(2, 0, 10);
    f_doublegaus->SetParLimits(3, 0, 1000);
    f_doublegaus->SetParLimits(4, -0.5, 0.5);
    f_doublegaus->SetParLimits(5, 0, 10);
    TF1 *f_doublegaus1 = new TF1("f_doublegaus1", "gaus(0)+gaus(3)", -0.5, 0.5);                                                 //fit_Tmm2_Tmm6
    f_doublegaus1->SetParameter(0, 70);
    f_doublegaus1->SetParameter(1, 0);
    f_doublegaus1->SetParameter(2, 0.08);
    f_doublegaus1->SetParameter(3, 10);
    f_doublegaus1->SetParameter(4, 0);
    f_doublegaus1->SetParameter(5, 0.2);
    f_doublegaus1->SetParLimits(0, 0, 1000);
    f_doublegaus1->SetParLimits(1, -0.15, 0.15);
    f_doublegaus1->SetParLimits(2, 0, 10);
    f_doublegaus1->SetParLimits(3, 0, 100);
    f_doublegaus1->SetParLimits(4, -0.5, 0.5);
    f_doublegaus1->SetParLimits(5, 0, 10);
    TF1 *f_doublegaus2 = new TF1("f_doublegaus2", "gaus(0)+gaus(3)", -0.5, 0.5);                                                 //fit_Tmm5_Tmm6
    f_doublegaus2->SetParameter(0, 160);
    f_doublegaus2->SetParameter(1, 0);
    f_doublegaus2->SetParameter(2, 0.08);
    f_doublegaus2->SetParameter(3, 10);
    f_doublegaus2->SetParameter(4, 0);
    f_doublegaus2->SetParameter(5, 0.15);
    f_doublegaus2->SetParLimits(0, 0, 1000);
    f_doublegaus2->SetParLimits(1, -0.15, 0.15);
    f_doublegaus2->SetParLimits(2, 0, 10);
    f_doublegaus2->SetParLimits(3, 0, 1000);
    f_doublegaus2->SetParLimits(4, -0.5, 0.5);
    f_doublegaus2->SetParLimits(5, 0, 10);
    TF1 *f_doublegaus3 = new TF1("f_doublegaus3", "gaus(0)+gaus(3)", -0.5, 0.5);                                                 //fit_Tmm2_Tmm5
    f_doublegaus3->SetParameter(0, 75);
    f_doublegaus3->SetParameter(1, 0);
    f_doublegaus3->SetParameter(2, 0.08);
    f_doublegaus3->SetParameter(3, 10);
    f_doublegaus3->SetParameter(4, 0);
    f_doublegaus3->SetParameter(5, 0.15);
    f_doublegaus3->SetParLimits(0, 0, 1000);
    f_doublegaus3->SetParLimits(1, -0.15, 0.15);
    f_doublegaus3->SetParLimits(2, 0, 10);
    f_doublegaus3->SetParLimits(3, 0, 1000);
    f_doublegaus3->SetParLimits(4, -0.5, 0.5);
    f_doublegaus3->SetParLimits(5, 0, 10);
    
        
    
    TLatex *prwto = new TLatex();   

    
    TCanvas *Tmm2Y_total = new TCanvas("Tmm2Y_total","Tmm2Y_total",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm2Y_total->SetFillColor(kOrange+2);
    Tmm2Y_total->Divide(2,2);
    Tmm2Y_total->cd(1);
    //Tmm2Y_total->SetFillColor(kCyan-2);
    h_beam_profile_Tmm2Y->Draw();
    //h_beam_profile_Tmm2Y->Fit("f_gaus");
    h_beam_profile_Tmm2Y->SetXTitle("cluster position");
    h_beam_profile_Tmm2Y->SetYTitle("Events");
    Tmm2Y_total->cd(2);
    h_cluster_width_Tmm2Y->Draw();
    h_cluster_width_Tmm2Y->SetXTitle("cluster width");
    h_cluster_width_Tmm2Y->SetYTitle("Events");
    Tmm2Y_total->cd(3);
    h_cluster_charge_Tmm2Y->Draw();
    //h_cluster_charge_Tmm2Y->Fit("f_landau");
    h_cluster_charge_Tmm2Y->SetXTitle("cluster charge");
    h_cluster_charge_Tmm2Y->SetYTitle("Events");
    Tmm2Y_total->cd(4);
    h_number_of_clusters_Tmm2Y->Draw();
    h_number_of_clusters_Tmm2Y->SetXTitle("number of clusters");
    h_number_of_clusters_Tmm2Y->SetYTitle("Events");
    
    // save canvas as PDF file
    //Tmm2Y_total->Print("full_Z2Y_new.pdf");
    // save canvas as ROOT file
    //Tmm2Y_total->Print("full_Z2Y_new.root"); 
    
    TCanvas *Tmm2Y_cluster_position = new TCanvas("Tmm2Y_cluster_position","Tmm2Y_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm2Y_cluster_position->SetFillColor(kOrange+2);
    Tmm2Y_cluster_position->Divide(2,2);
    //Tmm2Y_cluster_position->cd(1);
    ////Tmm2Y_cluster_position->SetFillColor(kCyan-2);
    //h_beam_profile_Tmm2Y->Draw();
    //h_beam_profile_Tmm2Y->SetLineColor(kRed);
    ////h_beam_profile_Tmm2Y->SetAxisRange(0, 2000, "Y");
    Tmm2Y_cluster_position->cd(1);
    h_cluster_position_Tmm2Y1->Draw();
    h_cluster_position_Tmm2Y1->SetLineColor(kGreen+3);
    h_cluster_position_Tmm2Y1->SetAxisRange(0, 2000, "Y");
    prwto->DrawLatex(20, 700, "number of clusters > 1"); 
    //Tmm2Y_cluster_position->cd(3);
    //h_cluster_position_Tmm2Y2->Draw();
    //h_cluster_position_Tmm2Y2->SetAxisRange(0, 2000, "Y");
    //prwto->DrawLatex(20, 700, "number of clusters > 2");
    Tmm2Y_cluster_position->cd(2);
    h_cluster_position_Tmm2Y3->Draw();  
    h_cluster_position_Tmm2Y3->SetAxisRange(0, 2000, "Y");
    prwto->DrawLatex(20, 700, "Single Cluster");
    prwto->DrawLatex(20, 500, "cluster width > 1");
    Tmm2Y_cluster_position->cd(3);
    h_cluster_position_Tmm2Y4->Draw();
    h_cluster_position_Tmm2Y4->SetAxisRange(0, 2000, "Y");
    prwto->DrawLatex(20, 700, "Single Cluster");
    prwto->DrawLatex(20, 500, "cluster width > 2");
    Tmm2Y_cluster_position->cd(4);
    h_cluster_position_Tmm2Y5->Draw();
    h_cluster_position_Tmm2Y5->SetAxisRange(0, 2000, "Y");
    
    TCanvas *Tmm2Y_cluster_width = new TCanvas("Tmm2Y_cluster_width","Tmm2Y_cluster_width",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm2Y_cluster_position->SetFillColor(kOrange+2);
    Tmm2Y_cluster_width->Divide(2,3);
    Tmm2Y_cluster_width->cd(1);
    //Tmm2Y_cluster_position->SetFillColor(kCyan-2);
    h_cluster_width_Tmm2Y->Draw();
    h_cluster_width_Tmm2Y->SetAxisRange(0, 9000, "Y");
    Tmm2Y_cluster_width->cd(2);
    h_cluster_width_Tmm2Y1->Draw();
    h_cluster_width_Tmm2Y1->SetLineColor(kRed);
    h_cluster_width_Tmm2Y1->SetAxisRange(0, 9000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 1"); 
    Tmm2Y_cluster_width->cd(3);
    h_cluster_width_Tmm2Y2->Draw();
    h_cluster_width_Tmm2Y2->SetLineColor(kGreen+3);
    h_cluster_width_Tmm2Y2->SetAxisRange(0, 9000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 2");
    Tmm2Y_cluster_width->cd(4);
    h_cluster_width_Tmm2Y3->Draw(); 
    h_cluster_width_Tmm2Y3->SetAxisRange(0, 9000, "Y"); 
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 1");
    Tmm2Y_cluster_width->cd(5);
    h_cluster_width_Tmm2Y4->Draw();
    h_cluster_width_Tmm2Y4->SetAxisRange(0, 9000, "Y");
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 2");
    Tmm2Y_cluster_width->cd(6);
    h_cluster_width_Tmm2Y->Draw();
    h_cluster_width_Tmm2Y1->Draw("same");
    h_cluster_width_Tmm2Y2->Draw("same");
    
    
    TCanvas *Tmm2Y_cluster_charge = new TCanvas("Tmm2Y_cluster_charge","Tmm2Y_cluster_charge",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm2Y_cluster_charge->SetFillColor(kOrange+2);
    Tmm2Y_cluster_charge->Divide(2,3);
    Tmm2Y_cluster_charge->cd(1);
    //Tmm2Y_cluster_charge->SetFillColor(kCyan-2);
    h_cluster_charge_Tmm2Y->Draw();
    h_cluster_charge_Tmm2Y->SetAxisRange(0, 400, "Y");
    h_cluster_charge_Tmm2Y->SetLineColor(kRed);
    Tmm2Y_cluster_charge->cd(2);
    h_cluster_charge_Tmm2Y1->Draw();
    h_cluster_charge_Tmm2Y1->SetAxisRange(0, 400, "Y");
    h_cluster_charge_Tmm2Y1->SetLineColor(kGreen+3);
    prwto->DrawLatex(700, 150, "number of clusters > 1"); 
    Tmm2Y_cluster_charge->cd(3);
    h_cluster_charge_Tmm2Y2->Draw();
    h_cluster_charge_Tmm2Y2->SetAxisRange(0, 400, "Y");
    prwto->DrawLatex(700, 150, "number of clusters > 2"); 
    Tmm2Y_cluster_charge->cd(4);
    h_cluster_charge_Tmm2Y3->Draw();
    h_cluster_charge_Tmm2Y3->SetAxisRange(0, 400, "Y"); 
    prwto->DrawLatex(700, 150, "Single Cluster");
    prwto->DrawLatex(700, 100, "cluster width > 1");
    Tmm2Y_cluster_charge->cd(5);
    h_cluster_charge_Tmm2Y4->Draw();
    h_cluster_charge_Tmm2Y4->SetAxisRange(0, 400, "Y");
    prwto->DrawLatex(700, 150, "Single Cluster");
    prwto->DrawLatex(700, 100, "cluster width > 2");
    Tmm2Y_cluster_charge->cd(6);
    h_cluster_charge_Tmm2Y->Draw();
    h_cluster_charge_Tmm2Y1->Draw("same");
    h_cluster_charge_Tmm2Y2->Draw("same");
    
                                                                       //end of Tmm2Y canvases
    
    
    TCanvas *Tmm5Y_total = new TCanvas("Tmm5Y_total","Tmm5Y_total",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm5Y_total->SetFillColor(kOrange+2);
    Tmm5Y_total->Divide(2,2);
    Tmm5Y_total->cd(1);
    //Tmm5Y_total->SetFillColor(kCyan-2);
    h_beam_profile_Tmm5Y->Draw();
    //h_beam_profile_Tmm5Y->Fit("f_gaus1");
    h_beam_profile_Tmm5Y->SetXTitle("cluster position");
    h_beam_profile_Tmm5Y->SetYTitle("Events");
    Tmm5Y_total->cd(2);
    h_cluster_width_Tmm5Y->Draw();
    h_cluster_width_Tmm5Y->SetXTitle("cluster width");
    h_cluster_width_Tmm5Y->SetYTitle("Events");
    Tmm5Y_total->cd(3);
    h_cluster_charge_Tmm5Y->Draw();
    //h_cluster_charge_Tmm5Y->Fit("f_landau1");
    h_cluster_charge_Tmm5Y->SetXTitle("cluster charge");
    h_cluster_charge_Tmm5Y->SetYTitle("Events");
    Tmm5Y_total->cd(4);
    h_number_of_clusters_Tmm5Y->Draw();
    h_number_of_clusters_Tmm5Y->SetXTitle("number of clusters");
    h_number_of_clusters_Tmm5Y->SetYTitle("Events");
    
    //// save canvas as PDF file
    ////Tmm5Y_total->Print("full_Z2Y_new.pdf");
    //// save canvas as ROOT file
    ////Tmm5Y_total->Print("full_Z2Y_new.root"); 
    
    TCanvas *Tmm5Y_cluster_position = new TCanvas("Tmm5Y_cluster_position","Tmm5Y_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm5Y_cluster_position->SetFillColor(kOrange+2);
    Tmm5Y_cluster_position->Divide(2,2);
    //Tmm5Y_cluster_position->cd(1);
    ////Tmm5Y_cluster_position->SetFillColor(kCyan-2);
    //h_beam_profile_Tmm5Y->Draw();
    //h_beam_profile_Tmm5Y->SetLineColor(kRed);
    ////h_beam_profile_Tmm5Y->SetAxisRange(0, 1700, "Y");
    Tmm5Y_cluster_position->cd(1);
    h_cluster_position_Tmm5Y1->Draw();
    h_cluster_position_Tmm5Y1->SetLineColor(kGreen+3);
    h_cluster_position_Tmm5Y1->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 500, "number of clusters > 1"); 
    //Tmm5Y_cluster_position->cd(3);
    //h_cluster_position_Tmm5Y2->Draw();
    //h_cluster_position_Tmm5Y2->SetAxisRange(0, 1700, "Y");
    //prwto->DrawLatex(20, 500, "number of clusters > 2");
    Tmm5Y_cluster_position->cd(2);
    h_cluster_position_Tmm5Y3->Draw();  
    h_cluster_position_Tmm5Y3->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 500, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 1");
    Tmm5Y_cluster_position->cd(3);
    h_cluster_position_Tmm5Y4->Draw();
    h_cluster_position_Tmm5Y4->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 500, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 2");
    Tmm5Y_cluster_position->cd(4);
    h_cluster_position_Tmm5Y5->Draw();
    h_cluster_position_Tmm5Y5->SetAxisRange(0, 1700, "Y");
    
    TCanvas *Tmm5Y_cluster_width = new TCanvas("Tmm5Y_cluster_width","Tmm5Y_cluster_width",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm5Y_cluster_position->SetFillColor(kOrange+2);
    Tmm5Y_cluster_width->Divide(2,3);
    Tmm5Y_cluster_width->cd(1);
    //Tmm5Y_cluster_position->SetFillColor(kCyan-2);
    h_cluster_width_Tmm5Y->Draw();
    h_cluster_width_Tmm5Y->SetAxisRange(0, 10000, "Y");
    Tmm5Y_cluster_width->cd(2);
    h_cluster_width_Tmm5Y1->Draw();
    h_cluster_width_Tmm5Y1->SetLineColor(kRed);
    h_cluster_width_Tmm5Y1->SetAxisRange(0, 10000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 1"); 
    Tmm5Y_cluster_width->cd(3);
    h_cluster_width_Tmm5Y2->Draw();
    h_cluster_width_Tmm5Y2->SetLineColor(kGreen+3);
    h_cluster_width_Tmm5Y2->SetAxisRange(0, 10000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 2");
    Tmm5Y_cluster_width->cd(4);
    h_cluster_width_Tmm5Y3->Draw(); 
    h_cluster_width_Tmm5Y3->SetAxisRange(0, 10000, "Y"); 
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 1");
    Tmm5Y_cluster_width->cd(5);
    h_cluster_width_Tmm5Y4->Draw();
    h_cluster_width_Tmm5Y4->SetAxisRange(0, 10000, "Y");
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 2");
    Tmm5Y_cluster_width->cd(6);
    h_cluster_width_Tmm5Y->Draw();
    h_cluster_width_Tmm5Y1->Draw("same");
    h_cluster_width_Tmm5Y2->Draw("same");
    
    
    TCanvas *Tmm5Y_cluster_charge = new TCanvas("Tmm5Y_cluster_charge","Tmm5Y_cluster_charge",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm5Y_cluster_charge->SetFillColor(kOrange+2);
    Tmm5Y_cluster_charge->Divide(2,3);
    Tmm5Y_cluster_charge->cd(1);
    //Tmm5Y_cluster_charge->SetFillColor(kCyan-2);
    h_cluster_charge_Tmm5Y->Draw();
    h_cluster_charge_Tmm5Y->SetLineColor(kRed);
    h_cluster_charge_Tmm5Y->SetAxisRange(0, 500, "Y");
    Tmm5Y_cluster_charge->cd(2);
    h_cluster_charge_Tmm5Y1->Draw();
    h_cluster_charge_Tmm5Y1->SetLineColor(kGreen+3);
    h_cluster_charge_Tmm5Y1->SetAxisRange(0, 500, "Y");
    prwto->DrawLatex(700, 150, "number of clusters > 1"); 
    Tmm5Y_cluster_charge->cd(3);
    h_cluster_charge_Tmm5Y2->Draw();
    h_cluster_charge_Tmm5Y2->SetAxisRange(0, 500, "Y");
    prwto->DrawLatex(700, 150, "number of clusters > 2"); 
    Tmm5Y_cluster_charge->cd(4);
    h_cluster_charge_Tmm5Y3->Draw();
    h_cluster_charge_Tmm5Y3->SetAxisRange(0, 500, "Y"); 
    prwto->DrawLatex(700, 150, "Single Cluster");
    prwto->DrawLatex(700, 100, "cluster width > 1");
    Tmm5Y_cluster_charge->cd(5);
    h_cluster_charge_Tmm5Y4->Draw();
    h_cluster_charge_Tmm5Y4->SetAxisRange(0, 500, "Y");
    prwto->DrawLatex(700, 150, "Single Cluster");
    prwto->DrawLatex(700, 100, "cluster width > 2");
    Tmm5Y_cluster_charge->cd(6);
    h_cluster_charge_Tmm5Y->Draw();
    h_cluster_charge_Tmm5Y1->Draw("same");
    h_cluster_charge_Tmm5Y2->Draw("same");
    
                                                                       //end of Tmm5Y canvases
                                                                       
    TCanvas *Tmm6Y_total = new TCanvas("Tmm6Y_total","Tmm6Y_total",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm6Y_total->SetFillColor(kOrange+2);
    Tmm6Y_total->Divide(2,2);
    Tmm6Y_total->cd(1);
    //Tmm6Y_total->SetFillColor(kCyan-2);
    h_beam_profile_Tmm6Y->Draw();
    //h_beam_profile_Tmm6Y->Fit("f_gaus2");
    h_beam_profile_Tmm6Y->SetXTitle("cluster position");
    h_beam_profile_Tmm6Y->SetYTitle("Events");
    Tmm6Y_total->cd(2);
    h_cluster_width_Tmm6Y->Draw();
    h_cluster_width_Tmm6Y->SetXTitle("cluster width");
    h_cluster_width_Tmm6Y->SetYTitle("Events");
    Tmm6Y_total->cd(3);
    h_cluster_charge_Tmm6Y->Draw();
    //h_cluster_charge_Tmm6Y->Fit("f_landau2");
    h_cluster_charge_Tmm6Y->SetXTitle("cluster charge");
    h_cluster_charge_Tmm6Y->SetYTitle("Events");
    Tmm6Y_total->cd(4);
    h_number_of_clusters_Tmm6Y->Draw();
    h_number_of_clusters_Tmm6Y->SetXTitle("number of clusters");
    h_number_of_clusters_Tmm6Y->SetYTitle("Events");
    
    // save canvas as PDF file
    //Tmm5Y_total->Print("full_Z2Y_new.pdf");
    // save canvas as ROOT file
    //Tmm5Y_total->Print("full_Z2Y_new.root"); 
    
    TCanvas *Tmm6Y_cluster_position = new TCanvas("Tmm6Y_cluster_position","Tmm6Y_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm6Y_cluster_position->SetFillColor(kOrange+2);
    Tmm6Y_cluster_position->Divide(2,2);
    //Tmm6Y_cluster_position->cd(1);
    ////Tmm6Y_cluster_position->SetFillColor(kCyan-2);
    //h_beam_profile_Tmm6Y->Draw();
    //h_beam_profile_Tmm6Y->SetLineColor(kRed);
    ////h_beam_profile_Tmm6Y->SetAxisRange(0, 1500, "Y");
    Tmm6Y_cluster_position->cd(1);
    h_cluster_position_Tmm6Y1->Draw();
    h_cluster_position_Tmm6Y1->SetLineColor(kGreen+3);
    h_cluster_position_Tmm6Y1->SetAxisRange(0, 2200, "Y");
    prwto->DrawLatex(20, 500, "number of clusters > 1"); 
    //Tmm6Y_cluster_position->cd(3);
    //h_cluster_position_Tmm6Y2->Draw();
    //h_cluster_position_Tmm6Y2->SetAxisRange(0, 1500, "Y");
    //prwto->DrawLatex(20, 500, "number of clusters > 2");
    Tmm6Y_cluster_position->cd(2);
    h_cluster_position_Tmm6Y3->Draw();  
    h_cluster_position_Tmm6Y3->SetAxisRange(0, 2200, "Y");
    prwto->DrawLatex(20, 500, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 1");
    Tmm6Y_cluster_position->cd(3);
    h_cluster_position_Tmm6Y4->Draw();
    h_cluster_position_Tmm6Y4->SetAxisRange(0, 2200, "Y");
    prwto->DrawLatex(20, 500, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 2");
    Tmm6Y_cluster_position->cd(4);
    h_cluster_position_Tmm6Y5->Draw();
    h_cluster_position_Tmm6Y5->SetAxisRange(0, 2200, "Y");
    
    TCanvas *Tmm6Y_cluster_width = new TCanvas("Tmm6Y_cluster_width","Tmm6Y_cluster_width",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm6Y_cluster_position->SetFillColor(kOrange+2);
    Tmm6Y_cluster_width->Divide(2,3);
    Tmm6Y_cluster_width->cd(1);
    //Tmm6Y_cluster_position->SetFillColor(kCyan-2);
    h_cluster_width_Tmm6Y->Draw();
    h_cluster_width_Tmm6Y->SetAxisRange(0, 12000, "Y");
    Tmm6Y_cluster_width->cd(2);
    h_cluster_width_Tmm6Y1->Draw();
    h_cluster_width_Tmm6Y1->SetLineColor(kRed);
    h_cluster_width_Tmm6Y1->SetAxisRange(0, 12000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 1"); 
    Tmm6Y_cluster_width->cd(3);
    h_cluster_width_Tmm6Y2->Draw();
    h_cluster_width_Tmm6Y2->SetLineColor(kGreen+3);
    h_cluster_width_Tmm6Y2->SetAxisRange(0, 12000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 2");
    Tmm6Y_cluster_width->cd(4);
    h_cluster_width_Tmm6Y3->Draw(); 
    h_cluster_width_Tmm6Y3->SetAxisRange(0, 12000, "Y"); 
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 1");
    Tmm6Y_cluster_width->cd(5);
    h_cluster_width_Tmm6Y4->Draw();
    h_cluster_width_Tmm6Y4->SetAxisRange(0, 12000, "Y");
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 2");
    Tmm6Y_cluster_width->cd(6);
    h_cluster_width_Tmm6Y->Draw();
    h_cluster_width_Tmm6Y1->Draw("same");
    h_cluster_width_Tmm6Y2->Draw("same");
    
    
    TCanvas *Tmm6Y_cluster_charge = new TCanvas("Tmm6Y_cluster_charge","Tmm6Y_cluster_charge",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm6Y_cluster_charge->SetFillColor(kOrange+2);
    Tmm6Y_cluster_charge->Divide(2,3);
    Tmm6Y_cluster_charge->cd(1);
    //Tmm6Y_cluster_charge->SetFillColor(kCyan-2);
    h_cluster_charge_Tmm6Y->Draw();
    h_cluster_charge_Tmm6Y->SetLineColor(kRed);
    h_cluster_charge_Tmm6Y->SetAxisRange(0, 800, "Y");
    Tmm6Y_cluster_charge->cd(2);
    h_cluster_charge_Tmm6Y1->Draw();
    h_cluster_charge_Tmm6Y1->SetLineColor(kGreen+3);
    h_cluster_charge_Tmm6Y1->SetAxisRange(0, 800, "Y");
    prwto->DrawLatex(700, 300, "number of clusters > 1"); 
    Tmm6Y_cluster_charge->cd(3);
    h_cluster_charge_Tmm6Y2->Draw();
    h_cluster_charge_Tmm6Y2->SetAxisRange(0, 800, "Y");
    prwto->DrawLatex(700, 300, "number of clusters > 2"); 
    Tmm6Y_cluster_charge->cd(4);
    h_cluster_charge_Tmm6Y3->Draw();
    h_cluster_charge_Tmm6Y3->SetAxisRange(0, 800, "Y"); 
    prwto->DrawLatex(700, 300, "Single Cluster");
    prwto->DrawLatex(700, 200, "cluster width > 1");
    Tmm6Y_cluster_charge->cd(5);
    h_cluster_charge_Tmm6Y4->Draw();
    h_cluster_charge_Tmm6Y4->SetAxisRange(0, 800, "Y");
    prwto->DrawLatex(700, 300, "Single Cluster");
    prwto->DrawLatex(700, 200, "cluster width > 2");
    Tmm6Y_cluster_charge->cd(6);
    h_cluster_charge_Tmm6Y->Draw();
    h_cluster_charge_Tmm6Y1->Draw("same");
    h_cluster_charge_Tmm6Y2->Draw("same");
    
                                                                       //end of Tmm6Y canvases  
                                                                       
    TCanvas *NTUA_MM2Y_total = new TCanvas("NTUA_MM2Y_total","NTUA_MM2Y_total",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM2Y_total->SetFillColor(kOrange+2);
    NTUA_MM2Y_total->Divide(2,2);
    NTUA_MM2Y_total->cd(1);
    //NTUA_MM2Y_total->SetFillColor(kCyan-2);
    h_beam_profile_NTUA_MM2Y->Draw();
    //h_beam_profile_NTUA_MM2Y->Fit("f_gaus");
    h_beam_profile_NTUA_MM2Y->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM2Y->SetYTitle("Events");
    NTUA_MM2Y_total->cd(2);
    h_cluster_width_NTUA_MM2Y->Draw();
    h_cluster_width_NTUA_MM2Y->SetXTitle("cluster width");
    h_cluster_width_NTUA_MM2Y->SetYTitle("Events");
    NTUA_MM2Y_total->cd(3);
    h_cluster_charge_NTUA_MM2Y->Draw();
    //h_cluster_charge_Tmm2Y->Fit("f_landau");
    h_cluster_charge_NTUA_MM2Y->SetXTitle("cluster charge");
    h_cluster_charge_NTUA_MM2Y->SetYTitle("Events");
    NTUA_MM2Y_total->cd(4);
    h_number_of_clusters_NTUA_MM2Y->Draw();
    h_number_of_clusters_NTUA_MM2Y->SetXTitle("number of clusters");
    h_number_of_clusters_NTUA_MM2Y->SetYTitle("Events");
    
    // save canvas as PDF file
    //Tmm2Y_total->Print("full_Z2Y_new.pdf");
    // save canvas as ROOT file
    //Tmm2Y_total->Print("full_Z2Y_new.root"); 
    
    TCanvas *NTUA_MM2Y_cluster_position = new TCanvas("NTUA_MM2Y_cluster_position","NTUA_MM2Y_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm2Y_cluster_position->SetFillColor(kOrange+2);
    NTUA_MM2Y_cluster_position->Divide(2,2);
    //NTUA_MM2Y_cluster_position->cd(1);
    ////NTUA_MM2Y_cluster_position->SetFillColor(kCyan-2);
    //h_beam_profile_NTUA_MM2Y->Draw();
    //h_beam_profile_NTUA_MM2Y->SetLineColor(kRed);
    ////h_beam_profile_NTUA_MM2Y->SetAxisRange(0, 2300, "Y");
    NTUA_MM2Y_cluster_position->cd(1);
    h_cluster_position_NTUA_MM2Y1->Draw();
    h_cluster_position_NTUA_MM2Y1->SetLineColor(kGreen+3);
    h_cluster_position_NTUA_MM2Y1->SetAxisRange(0, 2300, "Y");
    prwto->DrawLatex(20, 700, "number of clusters > 1"); 
    //NTUA_MM2Y_cluster_position->cd(3);
    //h_cluster_position_NTUA_MM2Y2->Draw();
    //h_cluster_position_NTUA_MM2Y2->SetAxisRange(0, 2300, "Y");
    //prwto->DrawLatex(20, 700, "number of clusters > 2");
    NTUA_MM2Y_cluster_position->cd(2);
    h_cluster_position_NTUA_MM2Y3->Draw();  
    h_cluster_position_NTUA_MM2Y3->SetAxisRange(0, 2300, "Y");
    prwto->DrawLatex(20, 700, "Single Cluster");
    prwto->DrawLatex(20, 500, "cluster width > 1");
    NTUA_MM2Y_cluster_position->cd(3);
    h_cluster_position_NTUA_MM2Y4->Draw();
    h_cluster_position_NTUA_MM2Y4->SetAxisRange(0, 2300, "Y");
    prwto->DrawLatex(20, 700, "Single Cluster");
    prwto->DrawLatex(20, 500, "cluster width > 2");
    NTUA_MM2Y_cluster_position->cd(4);
    h_cluster_position_NTUA_MM2Y5->Draw();
    h_cluster_position_NTUA_MM2Y5->SetAxisRange(0, 2300, "Y");
    
    TCanvas *NTUA_MM2Y_cluster_width = new TCanvas("NTUA_MM2Y_cluster_width","NTUA_MM2Y_cluster_width",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM2Y_cluster_position->SetFillColor(kOrange+2);
    NTUA_MM2Y_cluster_width->Divide(2,3);
    NTUA_MM2Y_cluster_width->cd(1);
    //NTUA_MM2Y_cluster_position->SetFillColor(kCyan-2);
    h_cluster_width_NTUA_MM2Y->Draw();
    h_cluster_width_NTUA_MM2Y->SetAxisRange(0, 12000, "Y");
    NTUA_MM2Y_cluster_width->cd(2);
    h_cluster_width_NTUA_MM2Y1->Draw();
    h_cluster_width_NTUA_MM2Y1->SetLineColor(kRed);
    h_cluster_width_NTUA_MM2Y1->SetAxisRange(0, 12000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 1"); 
    NTUA_MM2Y_cluster_width->cd(3);
    h_cluster_width_NTUA_MM2Y2->Draw();
    h_cluster_width_NTUA_MM2Y2->SetLineColor(kGreen+3);
    h_cluster_width_NTUA_MM2Y2->SetAxisRange(0, 12000, "Y");
    prwto->DrawLatex(20, 3000, "number of clusters > 2");
    NTUA_MM2Y_cluster_width->cd(4);
    h_cluster_width_NTUA_MM2Y3->Draw(); 
    h_cluster_width_NTUA_MM2Y3->SetAxisRange(0, 12000, "Y"); 
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 1");
    NTUA_MM2Y_cluster_width->cd(5);
    h_cluster_width_NTUA_MM2Y4->Draw();
    h_cluster_width_NTUA_MM2Y4->SetAxisRange(0, 12000, "Y");
    prwto->DrawLatex(20, 3000, "Single Cluster");
    prwto->DrawLatex(20, 2000, "cluster width > 2");
    NTUA_MM2Y_cluster_width->cd(6);
    h_cluster_width_NTUA_MM2Y->Draw();
    h_cluster_width_NTUA_MM2Y1->Draw("same");
    h_cluster_width_NTUA_MM2Y2->Draw("same");
    
    
    TCanvas *NTUA_MM2Y_cluster_charge = new TCanvas("NTUA_MM2Y_cluster_charge","NTUA_MM2Y_cluster_charge",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM2Y_cluster_charge->SetFillColor(kOrange+2);
    NTUA_MM2Y_cluster_charge->Divide(2,3);
    NTUA_MM2Y_cluster_charge->cd(1);
    //NTUA_MM2Y_cluster_charge->SetFillColor(kCyan-2);
    h_cluster_charge_NTUA_MM2Y->Draw();
    h_cluster_charge_NTUA_MM2Y->SetAxisRange(0, 800, "Y");
    h_cluster_charge_NTUA_MM2Y->SetLineColor(kRed);
    NTUA_MM2Y_cluster_charge->cd(2);
    h_cluster_charge_NTUA_MM2Y1->Draw();
    h_cluster_charge_NTUA_MM2Y1->SetAxisRange(0, 800, "Y");
    h_cluster_charge_NTUA_MM2Y1->SetLineColor(kGreen+3);
    prwto->DrawLatex(700, 300, "number of clusters > 1"); 
    NTUA_MM2Y_cluster_charge->cd(3);
    h_cluster_charge_NTUA_MM2Y2->Draw();
    h_cluster_charge_NTUA_MM2Y2->SetAxisRange(0, 800, "Y");
    prwto->DrawLatex(700, 300, "number of clusters > 2"); 
    NTUA_MM2Y_cluster_charge->cd(4);
    h_cluster_charge_NTUA_MM2Y3->Draw();
    h_cluster_charge_NTUA_MM2Y3->SetAxisRange(0, 800, "Y"); 
    prwto->DrawLatex(700, 300, "Single Cluster");
    prwto->DrawLatex(700, 200, "cluster width > 1");
    NTUA_MM2Y_cluster_charge->cd(5);
    h_cluster_charge_NTUA_MM2Y4->Draw();
    h_cluster_charge_NTUA_MM2Y4->SetAxisRange(0, 800, "Y");
    prwto->DrawLatex(700, 300, "Single Cluster");
    prwto->DrawLatex(700, 200, "cluster width > 2");
    NTUA_MM2Y_cluster_charge->cd(6);
    h_cluster_charge_NTUA_MM2Y->Draw();
    h_cluster_charge_NTUA_MM2Y1->Draw("same");
    h_cluster_charge_NTUA_MM2Y2->Draw("same");
    
                                                                       ////end of NTUA_MM2Y canvases            
                                                                       
    TCanvas *NTUA_MM3Y_total = new TCanvas("NTUA_MM3Y_total","NTUA_MM3Y_total",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_total->SetFillColor(kOrange+2);
    NTUA_MM3Y_total->Divide(2,2);
    NTUA_MM3Y_total->cd(1);
    //NTUA_MM3Y_total->SetFillColor(kCyan-2);
    h_beam_profile_NTUA_MM3Y->Draw();
    //h_beam_profile_NTUA_MM3Y->Fit("f_gaus");
    h_beam_profile_NTUA_MM3Y->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM3Y->SetYTitle("Events");
    NTUA_MM3Y_total->cd(2);
    h_cluster_width_NTUA_MM3Y->Draw();
    h_cluster_width_NTUA_MM3Y->SetXTitle("cluster width");
    h_cluster_width_NTUA_MM3Y->SetYTitle("Events");
    NTUA_MM3Y_total->cd(3);
    h_cluster_charge_NTUA_MM3Y->Draw();
    //h_cluster_charge_Tmm3Y->Fit("f_landau");
    h_cluster_charge_NTUA_MM3Y->SetXTitle("cluster charge");
    h_cluster_charge_NTUA_MM3Y->SetYTitle("Events");
    NTUA_MM3Y_total->cd(4);
    h_number_of_clusters_NTUA_MM3Y->Draw();
    h_number_of_clusters_NTUA_MM3Y->SetXTitle("number of clusters");
    h_number_of_clusters_NTUA_MM3Y->SetYTitle("Events");
    
    // save canvas as PDF file
    //Tmm2Y_total->Print("full_Z2Y_new.pdf");
    // save canvas as ROOT file
    //Tmm2Y_total->Print("full_Z2Y_new.root"); 
    
    TCanvas *NTUA_MM3Y_cluster_position = new TCanvas("NTUA_MM3Y_cluster_position","NTUA_MM3Y_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm3Y_cluster_position->SetFillColor(kOrange+2);
    NTUA_MM3Y_cluster_position->Divide(2,2);
    //NTUA_MM3Y_cluster_position->cd(1);
    ////NTUA_MM3Y_cluster_position->SetFillColor(kCyan-2);
    //h_beam_profile_NTUA_MM3Y->Draw();
    //h_beam_profile_NTUA_MM3Y->SetLineColor(kRed);
    ////h_beam_profile_NTUA_MM3Y->SetAxisRange(0, 1400, "Y");
    NTUA_MM3Y_cluster_position->cd(1);
    h_cluster_position_NTUA_MM3Y1->Draw();
    h_cluster_position_NTUA_MM3Y1->SetLineColor(kGreen+3);
    h_cluster_position_NTUA_MM3Y1->SetAxisRange(0, 1400, "Y");
    prwto->DrawLatex(20, 500, "number of clusters > 1"); 
    //NTUA_MM3Y_cluster_position->cd(3);
    //h_cluster_position_NTUA_MM3Y2->Draw();
    //h_cluster_position_NTUA_MM3Y2->SetAxisRange(0, 1400, "Y");
    //prwto->DrawLatex(20, 500, "number of clusters > 2");
    NTUA_MM3Y_cluster_position->cd(2);
    h_cluster_position_NTUA_MM3Y3->Draw();  
    h_cluster_position_NTUA_MM3Y3->SetAxisRange(0, 1400, "Y");
    prwto->DrawLatex(20, 500, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 1");
    NTUA_MM3Y_cluster_position->cd(3);
    h_cluster_position_NTUA_MM3Y4->Draw();
    h_cluster_position_NTUA_MM3Y4->SetAxisRange(0, 1400, "Y");
    prwto->DrawLatex(20, 500, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 2");
    NTUA_MM3Y_cluster_position->cd(4);
    h_cluster_position_NTUA_MM3Y5->Draw();
    h_cluster_position_NTUA_MM3Y5->SetAxisRange(0, 1400, "Y");
    
    TCanvas *NTUA_MM3Y_cluster_width = new TCanvas("NTUA_MM3Y_cluster_width","NTUA_MM3Y_cluster_width",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_cluster_width->SetFillColor(kOrange+2);
    NTUA_MM3Y_cluster_width->Divide(2,3);
    NTUA_MM3Y_cluster_width->cd(1);
    //NTUA_MM3Y_cluster_width->SetFillColor(kCyan-2);
    h_cluster_width_NTUA_MM3Y->Draw();
    h_cluster_width_NTUA_MM3Y->SetAxisRange(0, 6000, "Y");
    NTUA_MM3Y_cluster_width->cd(2);
    h_cluster_width_NTUA_MM3Y1->Draw();
    h_cluster_width_NTUA_MM3Y1->SetLineColor(kRed);
    h_cluster_width_NTUA_MM3Y1->SetAxisRange(0, 6000, "Y");
    prwto->DrawLatex(20, 2000, "number of clusters > 1"); 
    NTUA_MM3Y_cluster_width->cd(3);
    h_cluster_width_NTUA_MM3Y2->Draw();
    h_cluster_width_NTUA_MM3Y2->SetLineColor(kGreen+3);
    h_cluster_width_NTUA_MM3Y2->SetAxisRange(0, 6000, "Y");
    prwto->DrawLatex(20, 2000, "number of clusters > 2");
    NTUA_MM3Y_cluster_width->cd(4);
    h_cluster_width_NTUA_MM3Y3->Draw(); 
    h_cluster_width_NTUA_MM3Y3->SetAxisRange(0, 6000, "Y"); 
    prwto->DrawLatex(20, 2000, "Single Cluster");
    prwto->DrawLatex(20, 1000, "cluster width > 1");
    NTUA_MM3Y_cluster_width->cd(5);
    h_cluster_width_NTUA_MM3Y4->Draw();
    h_cluster_width_NTUA_MM3Y4->SetAxisRange(0, 6000, "Y");
    prwto->DrawLatex(20, 2000, "Single Cluster");
    prwto->DrawLatex(20, 1000, "cluster width > 2");
    NTUA_MM3Y_cluster_width->cd(6);
    h_cluster_width_NTUA_MM3Y->Draw();
    h_cluster_width_NTUA_MM3Y1->Draw("same");
    h_cluster_width_NTUA_MM3Y2->Draw("same");
    
    
    TCanvas *NTUA_MM3Y_cluster_charge = new TCanvas("NTUA_MM3Y_cluster_charge","NTUA_MM3Y_cluster_charge",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_cluster_charge->SetFillColor(kOrange+2);
    NTUA_MM3Y_cluster_charge->Divide(2,3);
    NTUA_MM3Y_cluster_charge->cd(1);
    //NTUA_MM3Y_cluster_charge->SetFillColor(kCyan-2);
    h_cluster_charge_NTUA_MM3Y->Draw();
    h_cluster_charge_NTUA_MM3Y->SetAxisRange(0, 700, "Y");
    h_cluster_charge_NTUA_MM3Y->SetLineColor(kRed);
    NTUA_MM3Y_cluster_charge->cd(2);
    h_cluster_charge_NTUA_MM3Y1->Draw();
    h_cluster_charge_NTUA_MM3Y1->SetAxisRange(0, 700, "Y");
    h_cluster_charge_NTUA_MM3Y1->SetLineColor(kGreen+3);
    prwto->DrawLatex(700, 300, "number of clusters > 1"); 
    NTUA_MM3Y_cluster_charge->cd(3);
    h_cluster_charge_NTUA_MM3Y2->Draw();
    h_cluster_charge_NTUA_MM3Y2->SetAxisRange(0, 700, "Y");
    prwto->DrawLatex(700, 300, "number of clusters > 2"); 
    NTUA_MM3Y_cluster_charge->cd(4);
    h_cluster_charge_NTUA_MM3Y3->Draw();
    h_cluster_charge_NTUA_MM3Y3->SetAxisRange(0, 700, "Y"); 
    prwto->DrawLatex(700, 300, "Single Cluster");
    prwto->DrawLatex(700, 200, "cluster width > 1");
    NTUA_MM3Y_cluster_charge->cd(5);
    h_cluster_charge_NTUA_MM3Y4->Draw();
    h_cluster_charge_NTUA_MM3Y4->SetAxisRange(0, 700, "Y");
    prwto->DrawLatex(700, 300, "Single Cluster");
    prwto->DrawLatex(700, 200, "cluster width > 2");
    NTUA_MM3Y_cluster_charge->cd(6);
    h_cluster_charge_NTUA_MM3Y->Draw();
    h_cluster_charge_NTUA_MM3Y1->Draw("same");
    h_cluster_charge_NTUA_MM3Y2->Draw("same");
    
    TCanvas *NTUA_MM3Y_beam_profile = new TCanvas("NTUA_MM3Y_beam_profile","NTUA_MM3Y_beam_profile",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_beam_profile->SetFillColor(kRed-8);
    //NTUA_MM3Y_beam_profile->SetFrameFillColor(kGreen-6);
    h_beam_profile_NTUA_MM3Y->Draw();
    h_beam_profile_NTUA_MM3Y->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM3Y->SetYTitle("Events");
    
    TCanvas *NTUA_MM3Y_cluster_charge = new TCanvas("NTUA_MM3Y_cluster_charge","NTUA_MM3Y_cluster_charge",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_cluster_charge->SetFillColor(kRed-8);
    //NTUA_MM3Y_cluster_charge->SetFrameFillColor(kGreen-6);
    h_cluster_charge_NTUA_MM3Y->Draw();
    h_cluster_charge_NTUA_MM3Y->SetXTitle("cluster charge");
    h_cluster_charge_NTUA_MM3Y->SetYTitle("Events");
    
    TCanvas *NTUA_MM3Y_cluster_width = new TCanvas("NTUA_MM3Y_cluster_width","NTUA_MM3Y_cluster_width",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_cluster_width->SetFillColor(kRed-8);
    //NTUA_MM3Y_cluster_width->SetFrameFillColor(kGreen-6);
    h_cluster_width_NTUA_MM3Y3->Draw();
    prwto->DrawLatex(25, 400, "Single Cluster");
    prwto->DrawLatex(25, 300, "cluster width > 1");
    h_cluster_width_NTUA_MM3Y3->SetXTitle("cluster width");
    h_cluster_width_NTUA_MM3Y3->SetYTitle("Events");
    
    TCanvas *NTUA_MM3Y_number_of_clusters = new TCanvas("NTUA_MM3Y_number_of_clusters","NTUA_MM3Y_number_of_clusters",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3Y_number_of_clusters->SetFillColor(kRed-8);
    //NTUA_MM3Y_number_of_clusters->SetFrameFillColor(kGreen-6);
    h_number_of_clusters_NTUA_MM3Y->Draw();
    h_number_of_clusters_NTUA_MM3Y->SetXTitle("number of clusters");
    h_number_of_clusters_NTUA_MM3Y->SetYTitle("Events");
    
                                                                       //end of NTUA_MM3Y canvases                                                     
                                                                       
    TCanvas *Tmm2Y_Tmm5Y_cluster_position_subtraction = new TCanvas("Tmm2Y_Tmm5Y_cluster_position_subtraction","Tmm2Y_Tmm5Y_cluster_position_subtraction",800,600);
    gStyle->SetOptFit(1111);
    //Tmm2Y_Tmm5Y_cluster_position_subtraction->SetFillColor(kOrange+2);
    //Tmm2Y_Tmm5Y_cluster_position_subtraction->SetFrameFillColor(kCyan-2);
    //Tmm2Y_Tmm5Y_cluster_position_subtraction->Divide(2,1);
    //Tmm2Y_Tmm5Y_cluster_position_subtraction->cd(1);   
    //h_cluster_position_subtraction_Tmm2Y_Tmm5Y->Draw();
    //h_cluster_position_subtraction_Tmm2Y_Tmm5Y->SetXTitle("cluster position Tmm2 - cluster position Tmm5");
    //h_cluster_position_subtraction_Tmm2Y_Tmm5Y->SetYTitle("Events");
    //prwto->DrawLatex(1, 200, "#sigma=0.062883");
    //Tmm2Y_Tmm5Y_cluster_position_subtraction->cd(2);
    h_cluster_position_subtraction_Tmm2Y_Tmm5Y1->Draw();
    h_cluster_position_subtraction_Tmm2Y_Tmm5Y1->SetXTitle("cluster position Tmm2 - cluster position Tmm5");
    h_cluster_position_subtraction_Tmm2Y_Tmm5Y1->SetYTitle("Events");
    h_cluster_position_subtraction_Tmm2Y_Tmm5Y1->Fit("f_doublegaus");
    
    double subtraction_resolution = 0;
    double total_resolution = 0; 
    subtraction_resolution = f_doublegaus->GetParameter(2);
    //double fit_resolution = 0;
    double weighted_sigma = 0;
    double constant1 = f_doublegaus->GetParameter(0);
    double constant2 = f_doublegaus->GetParameter(3);
    double sigma1=f_doublegaus->GetParameter(2);
    double sigma2=f_doublegaus->GetParameter(5);
    weighted_sigma = (((constant1)*TMath::Power(sigma1,2))+((constant2)*TMath::Power(sigma2,2)))/((constant1*sigma1)+(constant2*sigma2)) ;
    //weighted_sigma ::SetMaxDigits(5);
		
    total_resolution = subtraction_resolution / sqrt(2);
    //total_resolution->SetMaxDigits(5);
    //fit_resolution = 0.08893 / sqrt(2) ;
    std::cout << "subtraction_resolution:" << subtraction_resolution << endl;
    std::cout << "total_resolution:" << total_resolution << endl;
    std::cout << "weighted_sigma:" << weighted_sigma << endl;
    //std::cout << "fit_resolution:" << fit_resolution << endl;	 
    
    //TString d;
    //d = "#sigma=";
    //d += total_resolution*1000;
    TLatex *deytero = new TLatex();
    deytero->DrawLatex(0.6, 80,Form("#sigma= %.1f#mum", total_resolution*1000));
    //TString dw;
    //dw = "weighted #sigma=";
    //dw += weighted_sigma*1000;
    //TLatex *weighted = new TLatex();
    //weighted->DrawLatex(0.6, 50, Form( "weighted #sigma= %.1f#mum", weighted_sigma*1000));
   
    
    //TCanvas *Tmm2Y_Tmm6Y_cluster_position_subtraction = new TCanvas("Tmm2Y_Tmm6Y_cluster_position_subtraction","Tmm2Y_Tmm6Y_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    ////Tmm2Y_Tmm6Y_cluster_position_subtraction->Divide(2,1);
    ////Tmm2Y_Tmm6Y_cluster_position_subtraction->cd(1);
    ////h_cluster_position_subtraction_Tmm2Y_Tmm6Y->Draw();
    ////h_cluster_position_subtraction_Tmm2Y_Tmm6Y->SetXTitle("cluster position Tmm2 - cluster position Tmm6");
    ////h_cluster_position_subtraction_Tmm2Y_Tmm6Y->SetYTitle("Events");
    ////prwto->DrawLatex(-2.5, 200, "#sigma=0.0696217");
    ////Tmm2Y_Tmm6Y_cluster_position_subtraction->cd(2);
    //h_cluster_position_subtraction_Tmm2Y_Tmm6Y1->Draw();
    //h_cluster_position_subtraction_Tmm2Y_Tmm6Y1->SetXTitle("cluster position Tmm2 - cluster position Tmm6");
    //h_cluster_position_subtraction_Tmm2Y_Tmm6Y1->SetYTitle("Events");
    ////h_cluster_position_subtraction_Tmm2Y_Tmm6Y1->Fit("f_doublegaus1");
    
    //double subtraction_resolution1 = 0;
    //double total_resolution1 = 0; 
    ////double fit_resolution1 = 0;
    //subtraction_resolution1 = f_doublegaus1->GetParameter(2);
    ////fit_resolution1 = 0.09846 / sqrt(2) ;
    //double weighted_sigma1 = 0;
    //double constant11 = f_doublegaus1->GetParameter(0);
    //double constant21 = f_doublegaus1->GetParameter(3);
    //double sigma11=f_doublegaus1->GetParameter(2);
    //double sigma21=f_doublegaus1->GetParameter(5);
    //weighted_sigma1 = (((constant11)*TMath::Power(sigma11,2))+((constant21)*TMath::Power(sigma21,2)))/((constant11*sigma11)+(constant21*sigma21)) ;
		
    //total_resolution1 = subtraction_resolution1 / sqrt(2);
    //std::cout << "subtraction_resolution:" << subtraction_resolution1 << endl;
    //std::cout << "total_resolution:" << total_resolution1 << endl;	 
    //std::cout << "weighted_sigma:" << weighted_sigma1 << endl;
    ////std::cout << "fit_resolution:" << fit_resolution1 << endl;	 
    
    ////TString d1;
    ////d1 = "#sigma=";
    ////d1 += total_resolution1*1000;
    //TLatex *trito = new TLatex();
    //trito->DrawLatex(-0.2, 80, Form("#sigma= %.1f#mum", total_resolution1*1000));
    ////TString dw1;
    ////dw1 = "weighted #sigma=";
    ////dw1 += weighted_sigma1*1000;
    //TLatex *weighted1 = new TLatex();
    //weighted1->DrawLatex(-0.2, 40, Form( "weighted #sigma= %.1f#mum", weighted_sigma1*1000));
    
    //TCanvas *Tmm5Y_Tmm6Y_cluster_position_subtraction = new TCanvas("Tmm5Y_Tmm6Y_cluster_position_subtraction","Tmm5Y_Tmm6Y_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    ////Tmm5Y_Tmm6Y_cluster_position_subtraction->Divide(2,1);
    ////Tmm5Y_Tmm6Y_cluster_position_subtraction->cd(1);    
    ////h_cluster_position_subtraction_Tmm5Y_Tmm6Y->Draw();
    ////h_cluster_position_subtraction_Tmm5Y_Tmm6Y->SetXTitle("cluster position Tmm5 - cluster position Tmm6");
    ////h_cluster_position_subtraction_Tmm5Y_Tmm6Y->SetYTitle("Events");
    ////prwto->DrawLatex(-2.5, 200, "#sigma=0.0664963");
    ////Tmm5Y_Tmm6Y_cluster_position_subtraction->cd(2);
    //h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->Draw();
    //h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->SetXTitle("cluster position Tmm5 - cluster position Tmm6");
    //h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->SetYTitle("Events");
    ////h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->Fit("f_doublegaus2");
    
    //double subtraction_resolution2 = 0;
    //double total_resolution2 = 0; 
    ////double fit_resolution2 = 0;
    //subtraction_resolution2 = f_doublegaus2->GetParameter(5);
    ////fit_resolution2 = 0.09404 / sqrt(2);
    //double weighted_sigma2 = 0;
    //double constant12 = f_doublegaus2->GetParameter(0);
    //double constant22 = f_doublegaus2->GetParameter(3);
    //double sigma12=f_doublegaus2->GetParameter(2);
    //double sigma22=f_doublegaus2->GetParameter(5);
    //weighted_sigma2 = (((constant12)*TMath::Power(sigma12,2))+((constant22)*TMath::Power(sigma22,2)))/((constant12*sigma12)+(constant22*sigma22)) ;
		
    //total_resolution2 = subtraction_resolution2 / sqrt(2);
    //std::cout << "subtraction_resolution:" << subtraction_resolution2 << endl;
    //std::cout << "total_resolution:" << total_resolution2 << endl;
    //std::cout << "weighted_sigma:" << weighted_sigma2 << endl;	
    ////std::cout << "fit_resolution:" << fit_resolution2 << endl; 
    
    ////TString d2;
    ////d2 = "#sigma=";
    ////d2 += total_resolution2*1000;
    //TLatex *tetarto = new TLatex();
    //tetarto->DrawLatex(30, 200, Form("#sigma= %.1f#mum", total_resolution2*1000));
    ////TString dw2;
    ////dw2 = "weighted #sigma=";
    ////dw2 += weighted_sigma2*1000;
    ////TLatex *weighted2 = new TLatex();
    ////weighted2->DrawLatex(30, 100, Form( "weighted #sigma= %.1f#mum", weighted_sigma2*1000));
    
    
    //TCanvas *Tmm2Y_Tmm5Y_single_cluster_position_subtraction = new TCanvas("Tmm2Y_Tmm5Y_single_cluster_position_subtraction","Tmm2Y_Tmm5Y_single_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y->Draw();
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y->Fit("gaus");
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y->SetXTitle("cluster position Tmm2 - cluster position Tmm5");
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm5Y->SetYTitle("Events");
    //h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->Fit("f_doublegaus2");
    
    
    //TCanvas *Tmm2Y_Tmm6Y_single_cluster_position_subtraction = new TCanvas("Tmm2Y_Tmm6Y_single_cluster_position_subtraction","Tmm2Y_Tmm6Y_single_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y->Draw();
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y->Fit("gaus");
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y->SetXTitle("cluster position Tmm2 - cluster position Tmm6");
    //h_single_cluster_position_subtraction_Tmm2Y_Tmm6Y->SetYTitle("Events");
    //h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->Fit("f_doublegaus2");
    
    
    //TCanvas *Tmm5Y_Tmm6Y_single_cluster_position_subtraction = new TCanvas("Tmm5Y_Tmm6Y_single_cluster_position_subtraction","Tmm5Y_Tmm6Y_single_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y->Draw();
    //h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y->Fit("gaus");
    //h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y->SetXTitle("cluster position Tmm5 - cluster position Tmm6");
    //h_single_cluster_position_subtraction_Tmm5Y_Tmm6Y->SetYTitle("Events");
    //h_cluster_position_subtraction_Tmm5Y_Tmm6Y1->Fit("f_doublegaus2");
    
    //TCanvas *Tmm2Y_NTUA_MM2Y_cluster_position_subtraction = new TCanvas("Tmm2Y_NTUA_MM2Y_cluster_position_subtraction","Tmm2Y_NTUA_MM2Y_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1->Draw();
    //h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1->SetXTitle("cluster position Tmm2 - cluster position NTUA_MM2");
    //h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1->SetYTitle("Events");
    ////h_cluster_position_subtraction_Tmm2Y_NTUA_MM2Y1->Fit("f_doublegaus");
    
    //TCanvas *Tmm2Y_NTUA_MM3Y_cluster_position_subtraction = new TCanvas("Tmm2Y_NTUA_MM3Y_cluster_position_subtraction","Tmm2Y_NTUA_MM3Y_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1->Draw();
    //h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1->SetXTitle("cluster position Tmm2 - cluster position NTUA_MM3");
    //h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1->SetYTitle("Events");
    ////h_cluster_position_subtraction_Tmm2Y_NTUA_MM3Y1->Fit("f_doublegaus");
    
    //TCanvas *Tmm5Y_NTUA_MM2Y_cluster_position_subtraction = new TCanvas("Tmm5Y_NTUA_MM2Y_cluster_position_subtraction","Tmm5Y_NTUA_MM2Y_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1->Draw();
    //h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1->SetXTitle("cluster position Tmm5 - cluster position NTUA_MM2");
    //h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1->SetYTitle("Events");
    ////h_cluster_position_subtraction_Tmm5Y_NTUA_MM2Y1->Fit("f_doublegaus");
    
    //TCanvas *Tmm5Y_NTUA_MM3Y_cluster_position_subtraction = new TCanvas("Tmm5Y_NTUA_MM3Y_cluster_position_subtraction","Tmm5Y_NTUA_MM3Y_cluster_position_subtraction",800,600);
    //gStyle->SetOptFit(1111);
    //h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1->Draw();
    //h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1->SetXTitle("cluster position Tmm5 - cluster position NTUA_MM3");
    //h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1->SetYTitle("Events");
    ////h_cluster_position_subtraction_Tmm5Y_NTUA_MM3Y1->Fit("f_doublegaus");
    
    TCanvas *Tmm6Y_NTUA_MM2Y_cluster_position_subtraction = new TCanvas("Tmm6Y_NTUA_MM2Y_cluster_position_subtraction","Tmm6Y_NTUA_MM2Y_cluster_position_subtraction",800,600);
    gStyle->SetOptFit(1111);
    //Tmm6Y_NTUA_MM2Y_cluster_position_subtraction->SetFillColor(kOrange+2);
    //Tmm6Y_NTUA_MM2Y_cluster_position_subtraction->SetFrameFillColor(kCyan-2);
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1->Draw();
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1->SetXTitle("cluster position Tmm6 - cluster position NTUA_MM2");
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1->SetYTitle("Events");
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM2Y1->Fit("f_doublegaus1");
    
    double subtraction_resolution1 = 0;
    double total_resolution1 = 0; 
    subtraction_resolution1 = f_doublegaus1->GetParameter(2);
    double weighted_sigma1 = 0;
    double constant11 = f_doublegaus1->GetParameter(0);
    double constant21 = f_doublegaus1->GetParameter(3);
    double sigma11=f_doublegaus1->GetParameter(2);
    double sigma21=f_doublegaus1->GetParameter(5);
    weighted_sigma1 = (((constant11)*TMath::Power(sigma11,2))+((constant21)*TMath::Power(sigma21,2)))/((constant11*sigma11)+(constant21*sigma21)) ;
    
		
    total_resolution1 = subtraction_resolution1 / sqrt(2);
    std::cout << "subtraction_resolution:" << subtraction_resolution1 << endl;
    std::cout << "total_resolution:" << total_resolution1 << endl;
    std::cout << "weighted_sigma:" << weighted_sigma1 << endl;
    
    TLatex *trito = new TLatex();
    trito->DrawLatex(1, 20,Form("#sigma= %.1f#mum", total_resolution1*1000));
    
    //TLatex *weighted1 = new TLatex();
    //weighted1->DrawLatex(1, 10, Form( "weighted #sigma= %.1f#mum", weighted_sigma1*1000));
    
    
    
    TCanvas *Tmm6Y_NTUA_MM3Y_cluster_position_subtraction = new TCanvas("Tmm6Y_NTUA_MM3Y_cluster_position_subtraction","Tmm6Y_NTUA_MM3Y_cluster_position_subtraction",800,600);
    gStyle->SetOptFit(1111);
    //Tmm6Y_NTUA_MM3Y_cluster_position_subtraction->SetFillColor(kOrange+2);
    //Tmm6Y_NTUA_MM3Y_cluster_position_subtraction->SetFrameFillColor(kCyan-2);
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1->Draw();
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1->SetXTitle("cluster position Tmm6 - cluster position NTUA_MM3");
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1->SetYTitle("Events");
    h_cluster_position_subtraction_Tmm6Y_NTUA_MM3Y1->Fit("f_doublegaus2");
    
    double subtraction_resolution2 = 0;
    double total_resolution2 = 0; 
    subtraction_resolution2 = f_doublegaus2->GetParameter(2);
    double weighted_sigma2 = 0;
    double constant12 = f_doublegaus2->GetParameter(0);
    double constant22 = f_doublegaus2->GetParameter(3);
    double sigma12=f_doublegaus2->GetParameter(2);
    double sigma22=f_doublegaus2->GetParameter(5);
    weighted_sigma2 = (((constant12)*TMath::Power(sigma12,2))+((constant22)*TMath::Power(sigma22,2)))/((constant12*sigma12)+(constant22*sigma22)) ;
    
		
    total_resolution2 = subtraction_resolution2 / sqrt(2);
    std::cout << "subtraction_resolution:" << subtraction_resolution2 << endl;
    std::cout << "total_resolution:" << total_resolution2 << endl;
    std::cout << "weighted_sigma:" << weighted_sigma2 << endl;
    
    TLatex *tetarto = new TLatex();
    tetarto->DrawLatex(1, 30,Form("#sigma= %.1f#mum", total_resolution2*1000));
    
    //TLatex *weighted2 = new TLatex();
    //weighted2->DrawLatex(1, 20, Form( "weighted #sigma= %.1f#mum", weighted_sigma2*1000));
    
    
    
    
    TCanvas *NTUA_MM2Y_NTUA_MM3Y_cluster_position_subtraction = new TCanvas("NTUA_MM2Y_NTUA_MM3Y_cluster_position_subtraction","NTUA_MM2Y_NTUA_MM3Y_cluster_position_subtraction",800,600);
    gStyle->SetOptFit(1111);
    //NTUA_MM2Y_NTUA_MM3Y_cluster_position_subtraction->SetFillColor(kOrange+2);
    //NTUA_MM2Y_NTUA_MM3Y_cluster_position_subtraction->SetFrameFillColor(kCyan-2);
    h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1->Draw();
    h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1->SetXTitle("cluster position NTUA_MM2 - cluster position NTUA_MM3");
    h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1->SetYTitle("Events");
    h_cluster_position_subtraction_NTUA_MM2Y_NTUA_MM3Y1->Fit("f_doublegaus3");
    
    double subtraction_resolution3 = 0;
    double total_resolution3 = 0; 
    subtraction_resolution3 = f_doublegaus3->GetParameter(2);
    double weighted_sigma3 = 0;
    double constant13 = f_doublegaus3->GetParameter(0);
    double constant23 = f_doublegaus3->GetParameter(3);
    double sigma13=f_doublegaus3->GetParameter(2);
    double sigma23=f_doublegaus3->GetParameter(5);
    weighted_sigma3 = (((constant13)*TMath::Power(sigma13,2))+((constant23)*TMath::Power(sigma23,2)))/((constant13*sigma13)+(constant23*sigma23)) ;
    
		
    total_resolution3 = subtraction_resolution3 / sqrt(2);
    std::cout << "subtraction_resolution:" << subtraction_resolution3 << endl;
    std::cout << "total_resolution:" << total_resolution3 << endl;
    std::cout << "weighted_sigma:" << weighted_sigma3 << endl;
    
    TLatex *pempto = new TLatex();
    pempto->DrawLatex(1, 20,Form("#sigma= %.1f#mum", total_resolution3*1000));
    
    //TLatex *weighted3 = new TLatex();
    //weighted3->DrawLatex(1, 10, Form( "weighted #sigma= %.1f#mum", weighted_sigma3*1000));
        
    
    TCanvas *Tmm2X_total = new TCanvas("Tmm2X_total","Tmm2X_total",800,600);
    //Tmm2X_total->SetFillColor(kOrange+2);
    Tmm2X_total->Divide(2,2);
    Tmm2X_total->cd(1);
    //Tmm2X_total->SetFillColor(kCyan-2);
    h_beam_profile_Tmm2X->Draw();
    h_beam_profile_Tmm2X->SetXTitle("cluster position");
    h_beam_profile_Tmm2X->SetYTitle("Events");
    Tmm2X_total->cd(2);
    h_cluster_width_Tmm2X->Draw();
    h_cluster_width_Tmm2X->SetXTitle("cluster width");
    h_cluster_width_Tmm2X->SetYTitle("Events");
    Tmm2X_total->cd(3);
    h_cluster_charge_Tmm2X->Draw();
    h_cluster_charge_Tmm2X->SetXTitle("cluster charge");
    h_cluster_charge_Tmm2X->SetYTitle("Events");
    Tmm2X_total->cd(4);
    h_number_of_clusters_Tmm2X->Draw();
    h_number_of_clusters_Tmm2X->SetXTitle("number of clusters");
    h_number_of_clusters_Tmm2X->SetYTitle("Events");

    
    TCanvas *Tmm2X_cluster_position = new TCanvas("Tmm2X_cluster_position","Tmm2X_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm2Y_cluster_position->SetFillColor(kOrange+2);
    Tmm2X_cluster_position->Divide(2,2);
    Tmm2X_cluster_position->cd(1);
    //Tmm2Y_cluster_position->SetFillColor(kCyan-2);
    h_beam_profile_Tmm2X->Draw();
    h_beam_profile_Tmm2X->SetLineColor(kRed);
    h_beam_profile_Tmm2X->SetAxisRange(0, 2200, "Y");
    h_beam_profile_Tmm2X->SetXTitle("cluster position");
    h_beam_profile_Tmm2X->SetYTitle("Events");
    Tmm2X_cluster_position->cd(2);
    h_cluster_position_Tmm2X1->Draw();
    h_cluster_position_Tmm2X1->SetLineColor(kGreen+3);
    h_cluster_position_Tmm2X1->SetAxisRange(0, 2200, "Y");
    prwto->DrawLatex(20, 700, "Single Cluster");
    prwto->DrawLatex(20, 500, "cluster width > 1");
    h_cluster_position_Tmm2X1->SetXTitle("cluster position");
    h_cluster_position_Tmm2X1->SetYTitle("Events");
    Tmm2X_cluster_position->cd(3);
    h_cluster_position_Tmm2X2->Draw();
    h_cluster_position_Tmm2X2->SetAxisRange(0, 2200, "Y");
    prwto->DrawLatex(20, 700, "Single Cluster");
    prwto->DrawLatex(20, 500, "cluster width > 3");
    h_cluster_position_Tmm2X2->SetXTitle("cluster position");
    h_cluster_position_Tmm2X2->SetYTitle("Events");
    Tmm2X_cluster_position->cd(4);
    h_cluster_position_Tmm2X3->Draw();
    h_cluster_position_Tmm2X3->SetAxisRange(0, 2200, "Y");
    h_cluster_position_Tmm2X3->SetXTitle("cluster position");
    h_cluster_position_Tmm2X3->SetYTitle("Events");
    
    TCanvas *Tmm2XY = new TCanvas("Tmm2XY","Tmm2XY",800,600);
    h_cluster_position_Tmm2XY->Draw();
    h_cluster_position_Tmm2XY->SetXTitle("cluster position X");
    h_cluster_position_Tmm2XY->SetYTitle("cluster position Y");
                                                                                     
                                                                                     //end of Tmm2X canvases
                                                                                     
    TCanvas *Tmm5X_total = new TCanvas("Tmm5X_total","Tmm5X_total",800,600);
    //Tmm5X_total->SetFillColor(kOrange+2);
    Tmm5X_total->Divide(2,2);
    Tmm5X_total->cd(1);
    //Tmm5X_total->SetFillColor(kCyan-2);
    h_beam_profile_Tmm5X->Draw();
    h_beam_profile_Tmm5X->SetXTitle("cluster position");
    h_beam_profile_Tmm5X->SetYTitle("Events");
    Tmm5X_total->cd(2);
    h_cluster_width_Tmm5X->Draw();
    h_cluster_width_Tmm5X->SetXTitle("cluster width");
    h_cluster_width_Tmm5X->SetYTitle("Events");
    Tmm5X_total->cd(3);
    h_cluster_charge_Tmm5X->Draw();
    h_cluster_charge_Tmm5X->SetXTitle("cluster charge");
    h_cluster_charge_Tmm5X->SetYTitle("Events");
    Tmm5X_total->cd(4);
    h_number_of_clusters_Tmm5X->Draw();
    h_number_of_clusters_Tmm5X->SetXTitle("number of clusters");
    h_number_of_clusters_Tmm5X->SetYTitle("Events");                                                                                 
    
    TCanvas *Tmm5X_cluster_position = new TCanvas("Tmm5X_cluster_position","Tmm5X_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm5X_cluster_position->SetFillColor(kOrange+2);
    Tmm5X_cluster_position->Divide(2,2);
    Tmm5X_cluster_position->cd(1);
    //Tmm5X_cluster_position->SetFillColor(kCyan-2);
    h_beam_profile_Tmm5X->Draw();
    h_beam_profile_Tmm5X->SetLineColor(kRed);
    h_beam_profile_Tmm5X->SetAxisRange(0, 1700, "Y");
    h_beam_profile_Tmm5X->SetXTitle("cluster position");
    h_beam_profile_Tmm5X->SetYTitle("Events");
    Tmm5X_cluster_position->cd(2);
    h_cluster_position_Tmm5X1->Draw();
    h_cluster_position_Tmm5X1->SetLineColor(kGreen+3);
    h_cluster_position_Tmm5X1->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 600, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 1");
    h_cluster_position_Tmm5X1->SetXTitle("cluster position");
    h_cluster_position_Tmm5X1->SetYTitle("Events");
    Tmm5X_cluster_position->cd(3);
    h_cluster_position_Tmm5X2->Draw();
    h_cluster_position_Tmm5X2->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 600, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 3");
    h_cluster_position_Tmm5X2->SetXTitle("cluster position");
    h_cluster_position_Tmm5X2->SetYTitle("Events");
    Tmm5X_cluster_position->cd(4);
    h_cluster_position_Tmm5X3->Draw();
    h_cluster_position_Tmm5X3->SetAxisRange(0, 1700, "Y");
    h_cluster_position_Tmm5X3->SetXTitle("cluster position");
    h_cluster_position_Tmm5X3->SetYTitle("Events");
    
    TCanvas *Tmm5XY = new TCanvas("Tmm5XY","Tmm5XY",800,600);
    h_cluster_position_Tmm5XY->Draw();
    h_cluster_position_Tmm5XY->SetXTitle("cluster position X");
    h_cluster_position_Tmm5XY->SetYTitle("cluster position Y");                    
    
                                                                                          //end of Tmm5X canvases
    
    TCanvas *Tmm6X_total = new TCanvas("Tmm6X_total","Tmm6X_total",800,600);
    //Tmm6X_total->SetFillColor(kOrange+2);
    Tmm6X_total->Divide(2,2);
    Tmm6X_total->cd(1);
    //Tmm6X_total->SetFillColor(kCyan-2);
    h_beam_profile_Tmm6X->Draw();
    h_beam_profile_Tmm6X->SetXTitle("cluster position");
    h_beam_profile_Tmm6X->SetYTitle("Events");
    Tmm6X_total->cd(2);
    h_cluster_width_Tmm6X->Draw();
    h_cluster_width_Tmm6X->SetXTitle("cluster width");
    h_cluster_width_Tmm6X->SetYTitle("Events");
    Tmm6X_total->cd(3);
    h_cluster_charge_Tmm6X->Draw();
    h_cluster_charge_Tmm6X->SetXTitle("cluster charge");
    h_cluster_charge_Tmm6X->SetYTitle("Events");
    Tmm6X_total->cd(4);
    h_number_of_clusters_Tmm6X->Draw();
    h_number_of_clusters_Tmm6X->SetXTitle("number of clusters");
    h_number_of_clusters_Tmm6X->SetYTitle("Events");
    
    TCanvas *Tmm6X_cluster_position = new TCanvas("Tmm6X_cluster_position","Tmm6X_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //Tmm6X_cluster_position->SetFillColor(kOrange+2);
    Tmm6X_cluster_position->Divide(2,2);
    Tmm6X_cluster_position->cd(1);
    //Tmm6X_cluster_position->SetFillColor(kCyan-2);
    h_beam_profile_Tmm6X->Draw();
    h_beam_profile_Tmm6X->SetLineColor(kRed);
    h_beam_profile_Tmm6X->SetAxisRange(0, 1700, "Y");
    h_beam_profile_Tmm6X->SetXTitle("cluster position");
    h_beam_profile_Tmm6X->SetYTitle("Events");
    Tmm6X_cluster_position->cd(2);
    h_cluster_position_Tmm6X1->Draw();
    h_cluster_position_Tmm6X1->SetLineColor(kGreen+3);
    h_cluster_position_Tmm6X1->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 600, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 1");
    h_cluster_position_Tmm6X1->SetXTitle("cluster position");
    h_cluster_position_Tmm6X1->SetYTitle("Events");
    Tmm6X_cluster_position->cd(3);
    h_cluster_position_Tmm6X2->Draw();
    h_cluster_position_Tmm6X2->SetAxisRange(0, 1700, "Y");
    prwto->DrawLatex(20, 600, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 3");
    h_cluster_position_Tmm6X2->SetXTitle("cluster position");
    h_cluster_position_Tmm6X2->SetYTitle("Events");
    Tmm6X_cluster_position->cd(4);
    h_cluster_position_Tmm6X3->Draw();
    h_cluster_position_Tmm6X3->SetAxisRange(0, 1700, "Y");
    h_cluster_position_Tmm6X3->SetXTitle("cluster position");
    h_cluster_position_Tmm6X3->SetYTitle("Events");
    
    TCanvas *Tmm6XY = new TCanvas("Tmm6XY","Tmm6XY",800,600);
    h_cluster_position_Tmm6XY->Draw();
    h_cluster_position_Tmm6XY->SetXTitle("cluster position X");
    h_cluster_position_Tmm6XY->SetYTitle("cluster position Y");
                                                                                        //end of Tmm6X canvases
    
    TCanvas *NTUA_MM2X_total = new TCanvas("NTUA_MM2X_total","NTUA_MM2X_total",800,600);
    //NTUA_MM2X_total->SetFillColor(kOrange+2);
    NTUA_MM2X_total->Divide(2,2);
    NTUA_MM2X_total->cd(1);
    //NTUA_MM2X_total->SetFillColor(kCyan-2);
    h_beam_profile_NTUA_MM2X->Draw();
    h_beam_profile_NTUA_MM2X->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM2X->SetYTitle("Events");
    NTUA_MM2X_total->cd(2);
    h_cluster_width_NTUA_MM2X->Draw();
    h_cluster_width_NTUA_MM2X->SetXTitle("cluster width");
    h_cluster_width_NTUA_MM2X->SetYTitle("Events");
    NTUA_MM2X_total->cd(3);
    h_cluster_charge_NTUA_MM2X->Draw();
    h_cluster_charge_NTUA_MM2X->SetXTitle("cluster charge");
    h_cluster_charge_NTUA_MM2X->SetYTitle("Events");
    NTUA_MM2X_total->cd(4);
    h_number_of_clusters_NTUA_MM2X->Draw();
    h_number_of_clusters_NTUA_MM2X->SetXTitle("number of clusters");
    h_number_of_clusters_NTUA_MM2X->SetYTitle("Events");

    
    TCanvas *NTUA_MM2X_cluster_position = new TCanvas("NTUA_MM2X_cluster_position","NTUA_MM2X_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM2X_cluster_position->SetFillColor(kOrange+2);
    NTUA_MM2X_cluster_position->Divide(2,2);
    NTUA_MM2X_cluster_position->cd(1);
    //NTUA_MM2X_cluster_position->SetFillColor(kCyan-2);
    h_beam_profile_NTUA_MM2X->Draw();
    h_beam_profile_NTUA_MM2X->SetLineColor(kRed);
    h_beam_profile_NTUA_MM2X->SetAxisRange(0, 1800, "Y");
    h_beam_profile_NTUA_MM2X->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM2X->SetYTitle("Events");
    NTUA_MM2X_cluster_position->cd(2);
    h_cluster_position_NTUA_MM2X1->Draw();
    h_cluster_position_NTUA_MM2X1->SetLineColor(kGreen+3);
    h_cluster_position_NTUA_MM2X1->SetAxisRange(0, 1800, "Y");
    prwto->DrawLatex(20, 600, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 1");
    h_cluster_position_NTUA_MM2X1->SetXTitle("cluster position");
    h_cluster_position_NTUA_MM2X1->SetYTitle("Events");
    NTUA_MM2X_cluster_position->cd(3);
    h_cluster_position_NTUA_MM2X2->Draw();
    h_cluster_position_NTUA_MM2X2->SetAxisRange(0, 1800, "Y");
    prwto->DrawLatex(20, 600, "Single Cluster");
    prwto->DrawLatex(20, 300, "cluster width > 3");
    h_cluster_position_NTUA_MM2X2->SetXTitle("cluster position");
    h_cluster_position_NTUA_MM2X2->SetYTitle("Events");
    NTUA_MM2X_cluster_position->cd(4);
    h_cluster_position_NTUA_MM2X3->Draw();
    h_cluster_position_NTUA_MM2X3->SetAxisRange(0, 1800, "Y");
    h_cluster_position_NTUA_MM2X3->SetXTitle("cluster position");
    h_cluster_position_NTUA_MM2X3->SetYTitle("Events");
    
    TCanvas *NTUA_MM2XY = new TCanvas("NTUA_MM2XY","NTUA_MM2XY",800,600);
    h_cluster_position_NTUA_MM2XY->Draw();
    h_cluster_position_NTUA_MM2XY->SetXTitle("cluster position X");
    h_cluster_position_NTUA_MM2XY->SetYTitle("cluster position Y");
                                                                                     
                                                                                     //end of NTUA_MM2X canvases
                                                                                     
    TCanvas *NTUA_MM3X_total = new TCanvas("NTUA_MM3X_total","NTUA_MM3X_total",800,600);
    //NTUA_MM3X_total->SetFillColor(kOrange+2);
    NTUA_MM3X_total->Divide(2,2);
    NTUA_MM3X_total->cd(1);
    //NTUA_MM3X_total->SetFillColor(kCyan-2);
    h_beam_profile_NTUA_MM3X->Draw();
    h_beam_profile_NTUA_MM3X->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM3X->SetYTitle("Events");
    NTUA_MM3X_total->cd(2);
    h_cluster_width_NTUA_MM3X->Draw();
    h_cluster_width_NTUA_MM3X->SetXTitle("cluster width");
    h_cluster_width_NTUA_MM3X->SetYTitle("Events");
    NTUA_MM3X_total->cd(3);
    h_cluster_charge_NTUA_MM3X->Draw();
    h_cluster_charge_NTUA_MM3X->SetXTitle("cluster charge");
    h_cluster_charge_NTUA_MM3X->SetYTitle("Events");
    NTUA_MM3X_total->cd(4);
    h_number_of_clusters_NTUA_MM3X->Draw();
    h_number_of_clusters_NTUA_MM3X->SetXTitle("number of clusters");
    h_number_of_clusters_NTUA_MM3X->SetYTitle("Events");

    
    TCanvas *NTUA_MM3X_cluster_position = new TCanvas("NTUA_MM3X_cluster_position","NTUA_MM3X_cluster_position",800,600);
    //gStyle->SetOptFit(1111);
    //NTUA_MM3X_cluster_position->SetFillColor(kOrange+2);
    NTUA_MM3X_cluster_position->Divide(2,2);
    NTUA_MM3X_cluster_position->cd(1);
    //NTUA_MM3X_cluster_position->SetFillColor(kCyan-2);
    h_beam_profile_NTUA_MM3X->Draw();
    h_beam_profile_NTUA_MM3X->SetLineColor(kRed);
    h_beam_profile_NTUA_MM3X->SetAxisRange(0, 1200, "Y");
    h_beam_profile_NTUA_MM3X->SetXTitle("cluster position");
    h_beam_profile_NTUA_MM3X->SetYTitle("Events");
    NTUA_MM3X_cluster_position->cd(2);
    h_cluster_position_NTUA_MM3X1->Draw();
    h_cluster_position_NTUA_MM3X1->SetLineColor(kGreen+3);
    h_cluster_position_NTUA_MM3X1->SetAxisRange(0, 1200, "Y");
    prwto->DrawLatex(20, 400, "Single Cluster");
    prwto->DrawLatex(20, 200, "cluster width > 1");
    h_cluster_position_NTUA_MM3X1->SetXTitle("cluster position");
    h_cluster_position_NTUA_MM3X1->SetYTitle("Events");
    NTUA_MM3X_cluster_position->cd(3);
    h_cluster_position_NTUA_MM3X2->Draw();
    h_cluster_position_NTUA_MM3X2->SetAxisRange(0, 1200, "Y");
    prwto->DrawLatex(20, 400, "Single Cluster");
    prwto->DrawLatex(20, 200, "cluster width > 3");
    h_cluster_position_NTUA_MM3X2->SetXTitle("cluster position");
    h_cluster_position_NTUA_MM3X2->SetYTitle("Events");
    NTUA_MM3X_cluster_position->cd(4);
    h_cluster_position_NTUA_MM3X3->Draw();
    h_cluster_position_NTUA_MM3X3->SetAxisRange(0, 1200, "Y");
    h_cluster_position_NTUA_MM3X3->SetXTitle("cluster position");
    h_cluster_position_NTUA_MM3X3->SetYTitle("Events");
    
    TCanvas *NTUA_MM3XY = new TCanvas("NTUA_MM3XY","NTUA_MM3XY",800,600);
    gStyle->SetPalette(102);
    //h_cluster_position_NTUA_MM3XY->Fill(0.,0.,-5.);
    h_cluster_position_NTUA_MM3XY->Draw("COLZ");   
    h_cluster_position_NTUA_MM3XY->SetXTitle("cluster position X");
    h_cluster_position_NTUA_MM3XY->SetYTitle("cluster position Y");
                                                                                     
                                                                                     //end of NTUA_MM3X canvases

}//end macro

