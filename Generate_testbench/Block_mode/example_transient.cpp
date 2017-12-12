/******************************************************/
/***This file is used to simulated in systemc-ams. ****/
/***                  Yukai Chen                   ****/
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
 	 L2_left_p.write(L2_left_val[counter]);
 	 L2_p.write(L2_val[counter]);
 	 L2_right_p.write(L2_right_val[counter]);
 	 Icache_p.write(Icache_val[counter]);
 	 Dcache_p.write(Dcache_val[counter]);
 	 Bpred_0_p.write(Bpred_0_val[counter]);
 	 Bpred_1_p.write(Bpred_1_val[counter]);
 	 Bpred_2_p.write(Bpred_2_val[counter]);
 	 DTB_0_p.write(DTB_0_val[counter]);
 	 DTB_1_p.write(DTB_1_val[counter]);
 	 DTB_2_p.write(DTB_2_val[counter]);
 	 FPAdd_0_p.write(FPAdd_0_val[counter]);
 	 FPAdd_1_p.write(FPAdd_1_val[counter]);
 	 FPReg_0_p.write(FPReg_0_val[counter]);
 	 FPReg_1_p.write(FPReg_1_val[counter]);
 	 FPReg_2_p.write(FPReg_2_val[counter]);
 	 FPReg_3_p.write(FPReg_3_val[counter]);
 	 FPMul_0_p.write(FPMul_0_val[counter]);
 	 FPMul_1_p.write(FPMul_1_val[counter]);
 	 FPMap_0_p.write(FPMap_0_val[counter]);
 	 FPMap_1_p.write(FPMap_1_val[counter]);
 	 IntMap_p.write(IntMap_val[counter]);
 	 IntQ_p.write(IntQ_val[counter]);
 	 IntReg_0_p.write(IntReg_0_val[counter]);
 	 IntReg_1_p.write(IntReg_1_val[counter]);
 	 IntExec_p.write(IntExec_val[counter]);
 	 FPQ_p.write(FPQ_val[counter]);
 	 LdStQ_p.write(LdStQ_val[counter]);
 	 ITB_0_p.write(ITB_0_val[counter]);
 	 ITB_1_p.write(ITB_1_val[counter]);

if(counter == 0){ 
	 mytempfile  <<"L2_left"<<"\t" <<"L2"<<"\t" <<"L2_right"<<"\t" <<"Icache"<<"\t" <<"Dcache"<<"\t" <<"Bpred_0"<<"\t" <<"Bpred_1"<<"\t" <<"Bpred_2"<<"\t" <<"DTB_0"<<"\t" <<"DTB_1"<<"\t" <<"DTB_2"<<"\t" <<"FPAdd_0"<<"\t" <<"FPAdd_1"<<"\t" <<"FPReg_0"<<"\t" <<"FPReg_1"<<"\t" <<"FPReg_2"<<"\t" <<"FPReg_3"<<"\t" <<"FPMul_0"<<"\t" <<"FPMul_1"<<"\t" <<"FPMap_0"<<"\t" <<"FPMap_1"<<"\t" <<"IntMap"<<"\t" <<"IntQ"<<"\t" <<"IntReg_0"<<"\t" <<"IntReg_1"<<"\t" <<"IntExec"<<"\t" <<"FPQ"<<"\t" <<"LdStQ"<<"\t" <<"ITB_0"<<"\t" <<"ITB_1"<<"\t"<<"\n"; 
}


 	 L2_left_tmp[counter] = L2_left_t.read() + 313.15-273.15;
 	 L2_tmp[counter] = L2_t.read() + 313.15-273.15;
 	 L2_right_tmp[counter] = L2_right_t.read() + 313.15-273.15;
 	 Icache_tmp[counter] = Icache_t.read() + 313.15-273.15;
 	 Dcache_tmp[counter] = Dcache_t.read() + 313.15-273.15;
 	 Bpred_0_tmp[counter] = Bpred_0_t.read() + 313.15-273.15;
 	 Bpred_1_tmp[counter] = Bpred_1_t.read() + 313.15-273.15;
 	 Bpred_2_tmp[counter] = Bpred_2_t.read() + 313.15-273.15;
 	 DTB_0_tmp[counter] = DTB_0_t.read() + 313.15-273.15;
 	 DTB_1_tmp[counter] = DTB_1_t.read() + 313.15-273.15;
 	 DTB_2_tmp[counter] = DTB_2_t.read() + 313.15-273.15;
 	 FPAdd_0_tmp[counter] = FPAdd_0_t.read() + 313.15-273.15;
 	 FPAdd_1_tmp[counter] = FPAdd_1_t.read() + 313.15-273.15;
 	 FPReg_0_tmp[counter] = FPReg_0_t.read() + 313.15-273.15;
 	 FPReg_1_tmp[counter] = FPReg_1_t.read() + 313.15-273.15;
 	 FPReg_2_tmp[counter] = FPReg_2_t.read() + 313.15-273.15;
 	 FPReg_3_tmp[counter] = FPReg_3_t.read() + 313.15-273.15;
 	 FPMul_0_tmp[counter] = FPMul_0_t.read() + 313.15-273.15;
 	 FPMul_1_tmp[counter] = FPMul_1_t.read() + 313.15-273.15;
 	 FPMap_0_tmp[counter] = FPMap_0_t.read() + 313.15-273.15;
 	 FPMap_1_tmp[counter] = FPMap_1_t.read() + 313.15-273.15;
 	 IntMap_tmp[counter] = IntMap_t.read() + 313.15-273.15;
 	 IntQ_tmp[counter] = IntQ_t.read() + 313.15-273.15;
 	 IntReg_0_tmp[counter] = IntReg_0_t.read() + 313.15-273.15;
 	 IntReg_1_tmp[counter] = IntReg_1_t.read() + 313.15-273.15;
 	 IntExec_tmp[counter] = IntExec_t.read() + 313.15-273.15;
 	 FPQ_tmp[counter] = FPQ_t.read() + 313.15-273.15;
 	 LdStQ_tmp[counter] = LdStQ_t.read() + 313.15-273.15;
 	 ITB_0_tmp[counter] = ITB_0_t.read() + 313.15-273.15;
 	 ITB_1_tmp[counter] = ITB_1_t.read() + 313.15-273.15;
 	 mytempfile <<std::setprecision(10)<< L2_left_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< L2_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< L2_right_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< Icache_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< Dcache_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< Bpred_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< Bpred_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< Bpred_2_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< DTB_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< DTB_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< DTB_2_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPAdd_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPAdd_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPReg_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPReg_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPReg_2_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPReg_3_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPMul_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPMul_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPMap_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPMap_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< IntMap_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< IntQ_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< IntReg_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< IntReg_1_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< IntExec_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< FPQ_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< LdStQ_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< ITB_0_tmp[counter] <<"\t";
 	 mytempfile <<std::setprecision(10)<< ITB_1_tmp[counter] <<"\t";


	 counter++; 
if(counter == NUM){
	 sc_stop();
}
}
