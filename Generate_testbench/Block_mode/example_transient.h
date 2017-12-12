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
		 //Vectors to store the value read from .pptrace file
		 double L2_left_tmp[NUM]; 
		 double L2_tmp[NUM]; 
		 double L2_right_tmp[NUM]; 
		 double Icache_tmp[NUM]; 
		 double Dcache_tmp[NUM]; 
		 double Bpred_0_tmp[NUM]; 
		 double Bpred_1_tmp[NUM]; 
		 double Bpred_2_tmp[NUM]; 
		 double DTB_0_tmp[NUM]; 
		 double DTB_1_tmp[NUM]; 
		 double DTB_2_tmp[NUM]; 
		 double FPAdd_0_tmp[NUM]; 
		 double FPAdd_1_tmp[NUM]; 
		 double FPReg_0_tmp[NUM]; 
		 double FPReg_1_tmp[NUM]; 
		 double FPReg_2_tmp[NUM]; 
		 double FPReg_3_tmp[NUM]; 
		 double FPMul_0_tmp[NUM]; 
		 double FPMul_1_tmp[NUM]; 
		 double FPMap_0_tmp[NUM]; 
		 double FPMap_1_tmp[NUM]; 
		 double IntMap_tmp[NUM]; 
		 double IntQ_tmp[NUM]; 
		 double IntReg_0_tmp[NUM]; 
		 double IntReg_1_tmp[NUM]; 
		 double IntExec_tmp[NUM]; 
		 double FPQ_tmp[NUM]; 
		 double LdStQ_tmp[NUM]; 
		 double ITB_0_tmp[NUM]; 
		 double ITB_1_tmp[NUM]; 
		 ofstream mytempfile;

		 int counter;
		 SCA_CTOR(testbench):  L2_left_p("L2_left_p"),  L2_p("L2_p"),  L2_right_p("L2_right_p"),  Icache_p("Icache_p"),  Dcache_p("Dcache_p"),  Bpred_0_p("Bpred_0_p"),  Bpred_1_p("Bpred_1_p"),  Bpred_2_p("Bpred_2_p"),  DTB_0_p("DTB_0_p"),  DTB_1_p("DTB_1_p"),  DTB_2_p("DTB_2_p"),  FPAdd_0_p("FPAdd_0_p"),  FPAdd_1_p("FPAdd_1_p"),  FPReg_0_p("FPReg_0_p"),  FPReg_1_p("FPReg_1_p"),  FPReg_2_p("FPReg_2_p"),  FPReg_3_p("FPReg_3_p"),  FPMul_0_p("FPMul_0_p"),  FPMul_1_p("FPMul_1_p"),  FPMap_0_p("FPMap_0_p"),  FPMap_1_p("FPMap_1_p"),  IntMap_p("IntMap_p"),  IntQ_p("IntQ_p"),  IntReg_0_p("IntReg_0_p"),  IntReg_1_p("IntReg_1_p"),  IntExec_p("IntExec_p"),  FPQ_p("FPQ_p"),  LdStQ_p("LdStQ_p"),  ITB_0_p("ITB_0_p"),  ITB_1_p("ITB_1_p"),  counter(0) {
	 } 


		 void set_attributes(); 

		 void initialize(); 

		 void processing(); 


};
