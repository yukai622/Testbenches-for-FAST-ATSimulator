/******************************************************/
/***This file is used to simulated in systemc-ams. ****/
/***                     EDA                       ****/
/******************************************************/



#include "testbench.h"



void testbench::set_attributes() 
{
	 L2_left_p.set_timestep(1,sc_core::SC_MS); 
	 L2_p.set_timestep(1,sc_core::SC_MS); 
	 L2_right_p.set_timestep(1,sc_core::SC_MS); 
	 Icache_p.set_timestep(1,sc_core::SC_MS); 
	 Dcache_p.set_timestep(1,sc_core::SC_MS); 
	 Bpred_0_p.set_timestep(1,sc_core::SC_MS); 
	 Bpred_1_p.set_timestep(1,sc_core::SC_MS); 
	 Bpred_2_p.set_timestep(1,sc_core::SC_MS); 
	 DTB_0_p.set_timestep(1,sc_core::SC_MS); 
	 DTB_1_p.set_timestep(1,sc_core::SC_MS); 
	 DTB_2_p.set_timestep(1,sc_core::SC_MS); 
	 FPAdd_0_p.set_timestep(1,sc_core::SC_MS); 
	 FPAdd_1_p.set_timestep(1,sc_core::SC_MS); 
	 FPReg_0_p.set_timestep(1,sc_core::SC_MS); 
	 FPReg_1_p.set_timestep(1,sc_core::SC_MS); 
	 FPReg_2_p.set_timestep(1,sc_core::SC_MS); 
	 FPReg_3_p.set_timestep(1,sc_core::SC_MS); 
	 FPMul_0_p.set_timestep(1,sc_core::SC_MS); 
	 FPMul_1_p.set_timestep(1,sc_core::SC_MS); 
	 FPMap_0_p.set_timestep(1,sc_core::SC_MS); 
	 FPMap_1_p.set_timestep(1,sc_core::SC_MS); 
	 IntMap_p.set_timestep(1,sc_core::SC_MS); 
	 IntQ_p.set_timestep(1,sc_core::SC_MS); 
	 IntReg_0_p.set_timestep(1,sc_core::SC_MS); 
	 IntReg_1_p.set_timestep(1,sc_core::SC_MS); 
	 IntExec_p.set_timestep(1,sc_core::SC_MS); 
	 FPQ_p.set_timestep(1,sc_core::SC_MS); 
	 LdStQ_p.set_timestep(1,sc_core::SC_MS); 
	 ITB_0_p.set_timestep(1,sc_core::SC_MS); 
	 ITB_1_p.set_timestep(1,sc_core::SC_MS); 


	 L2_left_p.set_delay(1); 
	 L2_p.set_delay(1); 
	 L2_right_p.set_delay(1); 
	 Icache_p.set_delay(1); 
	 Dcache_p.set_delay(1); 
	 Bpred_0_p.set_delay(1); 
	 Bpred_1_p.set_delay(1); 
	 Bpred_2_p.set_delay(1); 
	 DTB_0_p.set_delay(1); 
	 DTB_1_p.set_delay(1); 
	 DTB_2_p.set_delay(1); 
	 FPAdd_0_p.set_delay(1); 
	 FPAdd_1_p.set_delay(1); 
	 FPReg_0_p.set_delay(1); 
	 FPReg_1_p.set_delay(1); 
	 FPReg_2_p.set_delay(1); 
	 FPReg_3_p.set_delay(1); 
	 FPMul_0_p.set_delay(1); 
	 FPMul_1_p.set_delay(1); 
	 FPMap_0_p.set_delay(1); 
	 FPMap_1_p.set_delay(1); 
	 IntMap_p.set_delay(1); 
	 IntQ_p.set_delay(1); 
	 IntReg_0_p.set_delay(1); 
	 IntReg_1_p.set_delay(1); 
	 IntExec_p.set_delay(1); 
	 FPQ_p.set_delay(1); 
	 LdStQ_p.set_delay(1); 
	 ITB_0_p.set_delay(1); 
	 ITB_1_p.set_delay(1); 
}


void testbench::initialize()
{
int j;

ifstream in("../powertrace.txt");
if(!in) {
cout<<"Cannot open file."<<endl;
exit(-1);
}
cout<<"Power value read..."<<endl;
for(j=0;j<NUM;j++) {
in  >> L2_left_val[j] >> L2_val[j] >> L2_right_val[j] >> Icache_val[j] >> Dcache_val[j] >> Bpred_0_val[j] >> Bpred_1_val[j] >> Bpred_2_val[j] >> DTB_0_val[j] >> DTB_1_val[j] >> DTB_2_val[j] >> FPAdd_0_val[j] >> FPAdd_1_val[j] >> FPReg_0_val[j] >> FPReg_1_val[j] >> FPReg_2_val[j] >> FPReg_3_val[j] >> FPMul_0_val[j] >> FPMul_1_val[j] >> FPMap_0_val[j] >> FPMap_1_val[j] >> IntMap_val[j] >> IntQ_val[j] >> IntReg_0_val[j] >> IntReg_1_val[j] >> IntExec_val[j] >> FPQ_val[j] >> LdStQ_val[j] >> ITB_0_val[j] >> ITB_1_val[j];
}
in.close();


mytempfile.open("../temptrace.txt");


}

void testbench::processing()
{
int i;
 	 sum_L2_left =0;
 	 sum_L2 =0;
 	 sum_L2_right =0;
 	 sum_Icache =0;
 	 sum_Dcache =0;
 	 sum_Bpred_0 =0;
 	 sum_Bpred_1 =0;
 	 sum_Bpred_2 =0;
 	 sum_DTB_0 =0;
 	 sum_DTB_1 =0;
 	 sum_DTB_2 =0;
 	 sum_FPAdd_0 =0;
 	 sum_FPAdd_1 =0;
 	 sum_FPReg_0 =0;
 	 sum_FPReg_1 =0;
 	 sum_FPReg_2 =0;
 	 sum_FPReg_3 =0;
 	 sum_FPMul_0 =0;
 	 sum_FPMul_1 =0;
 	 sum_FPMap_0 =0;
 	 sum_FPMap_1 =0;
 	 sum_IntMap =0;
 	 sum_IntQ =0;
 	 sum_IntReg_0 =0;
 	 sum_IntReg_1 =0;
 	 sum_IntExec =0;
 	 sum_FPQ =0;
 	 sum_LdStQ =0;
 	 sum_ITB_0 =0;
 	 sum_ITB_1 =0;


for(i=0;i<NUM;i++){
 	 sum_L2_left +=L2_left_val[i];
 	 sum_L2 +=L2_val[i];
 	 sum_L2_right +=L2_right_val[i];
 	 sum_Icache +=Icache_val[i];
 	 sum_Dcache +=Dcache_val[i];
 	 sum_Bpred_0 +=Bpred_0_val[i];
 	 sum_Bpred_1 +=Bpred_1_val[i];
 	 sum_Bpred_2 +=Bpred_2_val[i];
 	 sum_DTB_0 +=DTB_0_val[i];
 	 sum_DTB_1 +=DTB_1_val[i];
 	 sum_DTB_2 +=DTB_2_val[i];
 	 sum_FPAdd_0 +=FPAdd_0_val[i];
 	 sum_FPAdd_1 +=FPAdd_1_val[i];
 	 sum_FPReg_0 +=FPReg_0_val[i];
 	 sum_FPReg_1 +=FPReg_1_val[i];
 	 sum_FPReg_2 +=FPReg_2_val[i];
 	 sum_FPReg_3 +=FPReg_3_val[i];
 	 sum_FPMul_0 +=FPMul_0_val[i];
 	 sum_FPMul_1 +=FPMul_1_val[i];
 	 sum_FPMap_0 +=FPMap_0_val[i];
 	 sum_FPMap_1 +=FPMap_1_val[i];
 	 sum_IntMap +=IntMap_val[i];
 	 sum_IntQ +=IntQ_val[i];
 	 sum_IntReg_0 +=IntReg_0_val[i];
 	 sum_IntReg_1 +=IntReg_1_val[i];
 	 sum_IntExec +=IntExec_val[i];
 	 sum_FPQ +=FPQ_val[i];
 	 sum_LdStQ +=LdStQ_val[i];
 	 sum_ITB_0 +=ITB_0_val[i];
 	 sum_ITB_1 +=ITB_1_val[i];
}


 	 avg_L2_left = sum_L2_left/NUM;
 	 avg_L2 = sum_L2/NUM;
 	 avg_L2_right = sum_L2_right/NUM;
 	 avg_Icache = sum_Icache/NUM;
 	 avg_Dcache = sum_Dcache/NUM;
 	 avg_Bpred_0 = sum_Bpred_0/NUM;
 	 avg_Bpred_1 = sum_Bpred_1/NUM;
 	 avg_Bpred_2 = sum_Bpred_2/NUM;
 	 avg_DTB_0 = sum_DTB_0/NUM;
 	 avg_DTB_1 = sum_DTB_1/NUM;
 	 avg_DTB_2 = sum_DTB_2/NUM;
 	 avg_FPAdd_0 = sum_FPAdd_0/NUM;
 	 avg_FPAdd_1 = sum_FPAdd_1/NUM;
 	 avg_FPReg_0 = sum_FPReg_0/NUM;
 	 avg_FPReg_1 = sum_FPReg_1/NUM;
 	 avg_FPReg_2 = sum_FPReg_2/NUM;
 	 avg_FPReg_3 = sum_FPReg_3/NUM;
 	 avg_FPMul_0 = sum_FPMul_0/NUM;
 	 avg_FPMul_1 = sum_FPMul_1/NUM;
 	 avg_FPMap_0 = sum_FPMap_0/NUM;
 	 avg_FPMap_1 = sum_FPMap_1/NUM;
 	 avg_IntMap = sum_IntMap/NUM;
 	 avg_IntQ = sum_IntQ/NUM;
 	 avg_IntReg_0 = sum_IntReg_0/NUM;
 	 avg_IntReg_1 = sum_IntReg_1/NUM;
 	 avg_IntExec = sum_IntExec/NUM;
 	 avg_FPQ = sum_FPQ/NUM;
 	 avg_LdStQ = sum_LdStQ/NUM;
 	 avg_ITB_0 = sum_ITB_0/NUM;
 	 avg_ITB_1 = sum_ITB_1/NUM;


 	 L2_left_p.write(avg_L2_left);
 	 L2_p.write(avg_L2);
 	 L2_right_p.write(avg_L2_right);
 	 Icache_p.write(avg_Icache);
 	 Dcache_p.write(avg_Dcache);
 	 Bpred_0_p.write(avg_Bpred_0);
 	 Bpred_1_p.write(avg_Bpred_1);
 	 Bpred_2_p.write(avg_Bpred_2);
 	 DTB_0_p.write(avg_DTB_0);
 	 DTB_1_p.write(avg_DTB_1);
 	 DTB_2_p.write(avg_DTB_2);
 	 FPAdd_0_p.write(avg_FPAdd_0);
 	 FPAdd_1_p.write(avg_FPAdd_1);
 	 FPReg_0_p.write(avg_FPReg_0);
 	 FPReg_1_p.write(avg_FPReg_1);
 	 FPReg_2_p.write(avg_FPReg_2);
 	 FPReg_3_p.write(avg_FPReg_3);
 	 FPMul_0_p.write(avg_FPMul_0);
 	 FPMul_1_p.write(avg_FPMul_1);
 	 FPMap_0_p.write(avg_FPMap_0);
 	 FPMap_1_p.write(avg_FPMap_1);
 	 IntMap_p.write(avg_IntMap);
 	 IntQ_p.write(avg_IntQ);
 	 IntReg_0_p.write(avg_IntReg_0);
 	 IntReg_1_p.write(avg_IntReg_1);
 	 IntExec_p.write(avg_IntExec);
 	 FPQ_p.write(avg_FPQ);
 	 LdStQ_p.write(avg_LdStQ);
 	 ITB_0_p.write(avg_ITB_0);
 	 ITB_1_p.write(avg_ITB_1);
 	 temp_L2_left = L2_left_t.read()+313.15;
 	 temp_L2 = L2_t.read()+313.15;
 	 temp_L2_right = L2_right_t.read()+313.15;
 	 temp_Icache = Icache_t.read()+313.15;
 	 temp_Dcache = Dcache_t.read()+313.15;
 	 temp_Bpred_0 = Bpred_0_t.read()+313.15;
 	 temp_Bpred_1 = Bpred_1_t.read()+313.15;
 	 temp_Bpred_2 = Bpred_2_t.read()+313.15;
 	 temp_DTB_0 = DTB_0_t.read()+313.15;
 	 temp_DTB_1 = DTB_1_t.read()+313.15;
 	 temp_DTB_2 = DTB_2_t.read()+313.15;
 	 temp_FPAdd_0 = FPAdd_0_t.read()+313.15;
 	 temp_FPAdd_1 = FPAdd_1_t.read()+313.15;
 	 temp_FPReg_0 = FPReg_0_t.read()+313.15;
 	 temp_FPReg_1 = FPReg_1_t.read()+313.15;
 	 temp_FPReg_2 = FPReg_2_t.read()+313.15;
 	 temp_FPReg_3 = FPReg_3_t.read()+313.15;
 	 temp_FPMul_0 = FPMul_0_t.read()+313.15;
 	 temp_FPMul_1 = FPMul_1_t.read()+313.15;
 	 temp_FPMap_0 = FPMap_0_t.read()+313.15;
 	 temp_FPMap_1 = FPMap_1_t.read()+313.15;
 	 temp_IntMap = IntMap_t.read()+313.15;
 	 temp_IntQ = IntQ_t.read()+313.15;
 	 temp_IntReg_0 = IntReg_0_t.read()+313.15;
 	 temp_IntReg_1 = IntReg_1_t.read()+313.15;
 	 temp_IntExec = IntExec_t.read()+313.15;
 	 temp_FPQ = FPQ_t.read()+313.15;
 	 temp_LdStQ = LdStQ_t.read()+313.15;
 	 temp_ITB_0 = ITB_0_t.read()+313.15;
 	 temp_ITB_1 = ITB_1_t.read()+313.15;
 	 mytempfile <<std::setprecision(10)<< temp_L2_left <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_L2 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_L2_right <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_Icache <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_Dcache <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_Bpred_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_Bpred_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_Bpred_2 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_DTB_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_DTB_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_DTB_2 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPAdd_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPAdd_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPReg_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPReg_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPReg_2 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPReg_3 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPMul_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPMul_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPMap_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPMap_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_IntMap <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_IntQ <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_IntReg_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_IntReg_1 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_IntExec <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_FPQ <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_LdStQ <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_ITB_0 <<"\t";
 	 mytempfile <<std::setprecision(10)<< temp_ITB_1 <<"\t";
}
