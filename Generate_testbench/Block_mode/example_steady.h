/******************************************************/
/***This file is used to simulated in systemc-ams. ****/
/***                     EDA                       ****/
/******************************************************/



#include "systemc-ams.h"



#define NUM 6000

SCA_TDF_MODULE (testbench)
{
		 //Interface declaration: output
		 sca_tdf::sca_out<double> L2_left_p; // Power of the L2_left 
		 sca_tdf::sca_out<double> L2_p; // Power of the L2 
		 sca_tdf::sca_out<double> L2_right_p; // Power of the L2_right 
		 sca_tdf::sca_out<double> Icache_p; // Power of the Icache 
		 sca_tdf::sca_out<double> Dcache_p; // Power of the Dcache 
		 sca_tdf::sca_out<double> Bpred_0_p; // Power of the Bpred_0 
		 sca_tdf::sca_out<double> Bpred_1_p; // Power of the Bpred_1 
		 sca_tdf::sca_out<double> Bpred_2_p; // Power of the Bpred_2 
		 sca_tdf::sca_out<double> DTB_0_p; // Power of the DTB_0 
		 sca_tdf::sca_out<double> DTB_1_p; // Power of the DTB_1 
		 sca_tdf::sca_out<double> DTB_2_p; // Power of the DTB_2 
		 sca_tdf::sca_out<double> FPAdd_0_p; // Power of the FPAdd_0 
		 sca_tdf::sca_out<double> FPAdd_1_p; // Power of the FPAdd_1 
		 sca_tdf::sca_out<double> FPReg_0_p; // Power of the FPReg_0 
		 sca_tdf::sca_out<double> FPReg_1_p; // Power of the FPReg_1 
		 sca_tdf::sca_out<double> FPReg_2_p; // Power of the FPReg_2 
		 sca_tdf::sca_out<double> FPReg_3_p; // Power of the FPReg_3 
		 sca_tdf::sca_out<double> FPMul_0_p; // Power of the FPMul_0 
		 sca_tdf::sca_out<double> FPMul_1_p; // Power of the FPMul_1 
		 sca_tdf::sca_out<double> FPMap_0_p; // Power of the FPMap_0 
		 sca_tdf::sca_out<double> FPMap_1_p; // Power of the FPMap_1 
		 sca_tdf::sca_out<double> IntMap_p; // Power of the IntMap 
		 sca_tdf::sca_out<double> IntQ_p; // Power of the IntQ 
		 sca_tdf::sca_out<double> IntReg_0_p; // Power of the IntReg_0 
		 sca_tdf::sca_out<double> IntReg_1_p; // Power of the IntReg_1 
		 sca_tdf::sca_out<double> IntExec_p; // Power of the IntExec 
		 sca_tdf::sca_out<double> FPQ_p; // Power of the FPQ 
		 sca_tdf::sca_out<double> LdStQ_p; // Power of the LdStQ 
		 sca_tdf::sca_out<double> ITB_0_p; // Power of the ITB_0 
		 sca_tdf::sca_out<double> ITB_1_p; // Power of the ITB_1 


		 //Interface declaration: input
		 sca_tdf::sca_in<double> L2_left_t; // Power of the L2_left 
		 sca_tdf::sca_in<double> L2_t; // Power of the L2 
		 sca_tdf::sca_in<double> L2_right_t; // Power of the L2_right 
		 sca_tdf::sca_in<double> Icache_t; // Power of the Icache 
		 sca_tdf::sca_in<double> Dcache_t; // Power of the Dcache 
		 sca_tdf::sca_in<double> Bpred_0_t; // Power of the Bpred_0 
		 sca_tdf::sca_in<double> Bpred_1_t; // Power of the Bpred_1 
		 sca_tdf::sca_in<double> Bpred_2_t; // Power of the Bpred_2 
		 sca_tdf::sca_in<double> DTB_0_t; // Power of the DTB_0 
		 sca_tdf::sca_in<double> DTB_1_t; // Power of the DTB_1 
		 sca_tdf::sca_in<double> DTB_2_t; // Power of the DTB_2 
		 sca_tdf::sca_in<double> FPAdd_0_t; // Power of the FPAdd_0 
		 sca_tdf::sca_in<double> FPAdd_1_t; // Power of the FPAdd_1 
		 sca_tdf::sca_in<double> FPReg_0_t; // Power of the FPReg_0 
		 sca_tdf::sca_in<double> FPReg_1_t; // Power of the FPReg_1 
		 sca_tdf::sca_in<double> FPReg_2_t; // Power of the FPReg_2 
		 sca_tdf::sca_in<double> FPReg_3_t; // Power of the FPReg_3 
		 sca_tdf::sca_in<double> FPMul_0_t; // Power of the FPMul_0 
		 sca_tdf::sca_in<double> FPMul_1_t; // Power of the FPMul_1 
		 sca_tdf::sca_in<double> FPMap_0_t; // Power of the FPMap_0 
		 sca_tdf::sca_in<double> FPMap_1_t; // Power of the FPMap_1 
		 sca_tdf::sca_in<double> IntMap_t; // Power of the IntMap 
		 sca_tdf::sca_in<double> IntQ_t; // Power of the IntQ 
		 sca_tdf::sca_in<double> IntReg_0_t; // Power of the IntReg_0 
		 sca_tdf::sca_in<double> IntReg_1_t; // Power of the IntReg_1 
		 sca_tdf::sca_in<double> IntExec_t; // Power of the IntExec 
		 sca_tdf::sca_in<double> FPQ_t; // Power of the FPQ 
		 sca_tdf::sca_in<double> LdStQ_t; // Power of the LdStQ 
		 sca_tdf::sca_in<double> ITB_0_t; // Power of the ITB_0 
		 sca_tdf::sca_in<double> ITB_1_t; // Power of the ITB_1 


		 //Vectors to store the value read from .pptrace file
		 double L2_left_val[NUM]; 
		 double L2_val[NUM]; 
		 double L2_right_val[NUM]; 
		 double Icache_val[NUM]; 
		 double Dcache_val[NUM]; 
		 double Bpred_0_val[NUM]; 
		 double Bpred_1_val[NUM]; 
		 double Bpred_2_val[NUM]; 
		 double DTB_0_val[NUM]; 
		 double DTB_1_val[NUM]; 
		 double DTB_2_val[NUM]; 
		 double FPAdd_0_val[NUM]; 
		 double FPAdd_1_val[NUM]; 
		 double FPReg_0_val[NUM]; 
		 double FPReg_1_val[NUM]; 
		 double FPReg_2_val[NUM]; 
		 double FPReg_3_val[NUM]; 
		 double FPMul_0_val[NUM]; 
		 double FPMul_1_val[NUM]; 
		 double FPMap_0_val[NUM]; 
		 double FPMap_1_val[NUM]; 
		 double IntMap_val[NUM]; 
		 double IntQ_val[NUM]; 
		 double IntReg_0_val[NUM]; 
		 double IntReg_1_val[NUM]; 
		 double IntExec_val[NUM]; 
		 double FPQ_val[NUM]; 
		 double LdStQ_val[NUM]; 
		 double ITB_0_val[NUM]; 
		 double ITB_1_val[NUM]; 


		 //Store sum 
		 double sum_L2_left; 
		 double sum_L2; 
		 double sum_L2_right; 
		 double sum_Icache; 
		 double sum_Dcache; 
		 double sum_Bpred_0; 
		 double sum_Bpred_1; 
		 double sum_Bpred_2; 
		 double sum_DTB_0; 
		 double sum_DTB_1; 
		 double sum_DTB_2; 
		 double sum_FPAdd_0; 
		 double sum_FPAdd_1; 
		 double sum_FPReg_0; 
		 double sum_FPReg_1; 
		 double sum_FPReg_2; 
		 double sum_FPReg_3; 
		 double sum_FPMul_0; 
		 double sum_FPMul_1; 
		 double sum_FPMap_0; 
		 double sum_FPMap_1; 
		 double sum_IntMap; 
		 double sum_IntQ; 
		 double sum_IntReg_0; 
		 double sum_IntReg_1; 
		 double sum_IntExec; 
		 double sum_FPQ; 
		 double sum_LdStQ; 
		 double sum_ITB_0; 
		 double sum_ITB_1; 


		 //Store avg 
		 double avg_L2_left; 
		 double avg_L2; 
		 double avg_L2_right; 
		 double avg_Icache; 
		 double avg_Dcache; 
		 double avg_Bpred_0; 
		 double avg_Bpred_1; 
		 double avg_Bpred_2; 
		 double avg_DTB_0; 
		 double avg_DTB_1; 
		 double avg_DTB_2; 
		 double avg_FPAdd_0; 
		 double avg_FPAdd_1; 
		 double avg_FPReg_0; 
		 double avg_FPReg_1; 
		 double avg_FPReg_2; 
		 double avg_FPReg_3; 
		 double avg_FPMul_0; 
		 double avg_FPMul_1; 
		 double avg_FPMap_0; 
		 double avg_FPMap_1; 
		 double avg_IntMap; 
		 double avg_IntQ; 
		 double avg_IntReg_0; 
		 double avg_IntReg_1; 
		 double avg_IntExec; 
		 double avg_FPQ; 
		 double avg_LdStQ; 
		 double avg_ITB_0; 
		 double avg_ITB_1; 


		 //Store value from thermal model 
		 double temp_L2_left; 
		 double temp_L2; 
		 double temp_L2_right; 
		 double temp_Icache; 
		 double temp_Dcache; 
		 double temp_Bpred_0; 
		 double temp_Bpred_1; 
		 double temp_Bpred_2; 
		 double temp_DTB_0; 
		 double temp_DTB_1; 
		 double temp_DTB_2; 
		 double temp_FPAdd_0; 
		 double temp_FPAdd_1; 
		 double temp_FPReg_0; 
		 double temp_FPReg_1; 
		 double temp_FPReg_2; 
		 double temp_FPReg_3; 
		 double temp_FPMul_0; 
		 double temp_FPMul_1; 
		 double temp_FPMap_0; 
		 double temp_FPMap_1; 
		 double temp_IntMap; 
		 double temp_IntQ; 
		 double temp_IntReg_0; 
		 double temp_IntReg_1; 
		 double temp_IntExec; 
		 double temp_FPQ; 
		 double temp_LdStQ; 
		 double temp_ITB_0; 
		 double temp_ITB_1; 
		 ofstream mytempfile;

		 int counter;
		 SCA_CTOR(testbench):  L2_left_p("L2_left_p"),  L2_p("L2_p"),  L2_right_p("L2_right_p"),  Icache_p("Icache_p"),  Dcache_p("Dcache_p"),  Bpred_0_p("Bpred_0_p"),  Bpred_1_p("Bpred_1_p"),  Bpred_2_p("Bpred_2_p"),  DTB_0_p("DTB_0_p"),  DTB_1_p("DTB_1_p"),  DTB_2_p("DTB_2_p"),  FPAdd_0_p("FPAdd_0_p"),  FPAdd_1_p("FPAdd_1_p"),  FPReg_0_p("FPReg_0_p"),  FPReg_1_p("FPReg_1_p"),  FPReg_2_p("FPReg_2_p"),  FPReg_3_p("FPReg_3_p"),  FPMul_0_p("FPMul_0_p"),  FPMul_1_p("FPMul_1_p"),  FPMap_0_p("FPMap_0_p"),  FPMap_1_p("FPMap_1_p"),  IntMap_p("IntMap_p"),  IntQ_p("IntQ_p"),  IntReg_0_p("IntReg_0_p"),  IntReg_1_p("IntReg_1_p"),  IntExec_p("IntExec_p"),  FPQ_p("FPQ_p"),  LdStQ_p("LdStQ_p"),  ITB_0_p("ITB_0_p"),  ITB_1_p("ITB_1_p"),  counter(0) {
	 } 


		 void set_attributes(); 

		 void initialize(); 

		 void processing(); 


};
